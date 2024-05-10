import pygame
import sys
from main import *

from copy import deepcopy


class Puzzle:
    data: list[list[int]] = list()
    zeroPosition: list[int] = (0, 0)
    manhattanDistance: int = -1
    depth: int = -1
    numberOfMisplaced = -1
    totalCost = 0

    def __lt__(self, other):
        if self.totalCost != other.totalCost:
            return self.totalCost < other.totalCost
        else:
            return self.numberOfMisplaced < other.numberOfMisplaced




def drawPuzzle(puzzle: Puzzle) -> None:
    print("-" * 12)
    for row in puzzle.data:
        print(
            f"| {row[0] if row[0] != 9 else ' '}  | {row[1] if row[1] != 9 else ' '} | {row[2] if row[2] != 9 else ' '} |")

    print("-" * 12)
    print("Total Cost:", puzzle.totalCost, "Number of Misplaced: ", puzzle.numberOfMisplaced, "Manhattan Distance:",
          puzzle.manhattanDistance)


def misplaced(puzzle: Puzzle) -> None:
    i = 1
    misplacedNumber = 0
    for row in puzzle.data:
        for col in row:
            if col != i:
                misplacedNumber += 1
            i += 1
    puzzle.numberOfMisplaced = misplacedNumber


def inClosedList(current_state: Puzzle) -> bool:
    for solvedState in closedList:
        same = True
        for row1, row2 in zip(current_state.data, solvedState.data):
            for col1, col2 in zip(row1, row2):
                if col1 != col2:
                    same = False
                    break
        if same:
            return True

    return False


def calculateManhattanAndPositionOf9(puzzle: Puzzle) -> int:
    """To get the final state coordinates:
      x = x_current-1/3
      y = y_current-1%3
    """
    manhattanDistance: int = 0
    rowNumber = 0
    for row in puzzle.data:
        for expectedNumber, col in enumerate(row):
            # print(col, rowNumber, expectedNumber, int((col - 1) / 3), int((col - 1) % 3))
            manhattanDistance += abs(rowNumber - int((col - 1) / 3)) + abs(expectedNumber - int((col - 1) % 3))
            if (col == 9):
                puzzle.zeroPosition = (rowNumber, expectedNumber)
        rowNumber += 1

    puzzle.manhattanDistance = manhattanDistance

    return manhattanDistance


def calculateTotalCost(puzzle: Puzzle) -> None:
    calculateManhattanAndPositionOf9(puzzle)
    misplaced(puzzle)
    puzzle.totalCost = puzzle.manhattanDistance + puzzle.numberOfMisplaced


def generateStates(current_state: Puzzle):
    """ State 1 is replacing by Up
    State 2 is replacing left
    State 3 is replacing right
    State 4 is replacing down"""
    newStates = []
    state1, state2, state3, state4 = deepcopy(current_state), deepcopy(current_state), deepcopy(
        current_state), deepcopy(current_state)

    x, y = current_state.zeroPosition
    if x - 1 >= 0:
        state1.data[x][y], state1.data[x - 1][y] = state1.data[x - 1][y], state1.data[x][y]
        if not inClosedList(state1):
            newStates.append(state1)
    if y - 1 >= 0:
        state2.data[x][y], state2.data[x][y - 1] = state2.data[x][y - 1], state2.data[x][y]
        if not inClosedList(state2):
            newStates.append(state2)
    if y + 1 <= 2:
        state3.data[x][y], state3.data[x][y + 1] = state3.data[x][y + 1], state3.data[x][y]
        if not inClosedList(state3):
            newStates.append(state3)
    if x + 1 <= 2:
        state4.data[x][y], state4.data[x + 1][y] = state4.data[x + 1][y], state4.data[x][y]
        if not inClosedList(state4):
            newStates.append(state4)

    for state in newStates:
        calculateTotalCost(state)
        # drawPuzzle(state)
    return newStates


closedList: list[Puzzle] = list()
# Initialize Pygame
pygame.init()

# Constants
WIDTH, HEIGHT = 300, 350
PANE_SIZE = WIDTH // 3
PANE_MARGIN = 5
BUTTON_WIDTH, BUTTON_HEIGHT = 80, 30
PANE_COLORS = [(255, 255, 255) for _ in range(9)]  # Colors for each pane

# Create the initial puzzle state
puzzle_state =[[4, 1, 3], [2, 9, 5], [7, 8, 6]]  # Initial state

# Initialize Pygame window
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("8 Puzzle Game")
clock = pygame.time.Clock()
frameRate = 10



def draw_puzzle():
    for row in range(3):
        for col in range(3):
            value = puzzle_state[row][col]
            if value != 9:
                pygame.draw.rect(screen, PANE_COLORS[value - 1],
                                 (col * PANE_SIZE, row * PANE_SIZE, PANE_SIZE, PANE_SIZE))
                pygame.draw.rect(screen, (0, 0, 0), (col * PANE_SIZE, row * PANE_SIZE, PANE_SIZE, PANE_SIZE), 2)
                font = pygame.font.Font(None, 36)
                text = font.render(str(value), True, (0, 0, 0))
                text_rect = text.get_rect(center=(col * PANE_SIZE + PANE_SIZE // 2, row * PANE_SIZE + PANE_SIZE // 2))
                screen.blit(text, text_rect)


def draw_start_button():
    pygame.draw.rect(screen, (0, 255, 0), (WIDTH // 2 - BUTTON_WIDTH // 2, HEIGHT - 50, BUTTON_WIDTH, BUTTON_HEIGHT))
    font = pygame.font.Font(None, 24)
    text = font.render("Start", True, (0, 0, 0))
    text_rect = text.get_rect(center=(WIDTH // 2, HEIGHT - 35))
    screen.blit(text, text_rect)


def move_pane(direction):
    # Find the position of the blank pane (9)
    blank_row, blank_col = [(i, j) for i, row in enumerate(puzzle_state) for j, val in enumerate(row) if val == 9][0]

    # Check if the move is valid
    new_row, new_col = blank_row, blank_col
    if direction == "UP" and blank_row > 0:
        new_row -= 1
    elif direction == "DOWN" and blank_row < 2:
        new_row += 1
    elif direction == "LEFT" and blank_col > 0:
        new_col -= 1
    elif direction == "RIGHT" and blank_col < 2:
        new_col += 1

    # If a valid move, swap the positions
    if (new_row, new_col) != (blank_row, blank_col):
        puzzle_state[blank_row][blank_col], puzzle_state[new_row][new_col] = puzzle_state[new_row][new_col], \
            puzzle_state[blank_row][blank_col]


def get_puzzle_array():
    # Return a copy of the current puzzle state
    return [row[:] for row in puzzle_state]


startSolving = False
solved = False
puzzle = Puzzle()
totalMoves = 0
# Main game loop
while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_UP:
                move_pane("UP")
            elif event.key == pygame.K_DOWN:
                move_pane("DOWN")
            elif event.key == pygame.K_LEFT:
                move_pane("LEFT")
            elif event.key == pygame.K_RIGHT:
                move_pane("RIGHT")
        elif event.type == pygame.MOUSEBUTTONDOWN and event.button == 1:
            # Check if the mouse click is within the Start button area
            button_rect = pygame.Rect(WIDTH // 2 - BUTTON_WIDTH // 2, HEIGHT - 50, BUTTON_WIDTH, BUTTON_HEIGHT)
            if button_rect.collidepoint(event.pos):
                print("Start button clicked. Current puzzle array:", get_puzzle_array())
                puzzle.data = get_puzzle_array().copy()
                misplaced(puzzle)
                calculateManhattanAndPositionOf9(puzzle)
                calculateTotalCost(puzzle)
                closedList = []  # Resetting the closed list
                closedList.append(puzzle)
                startSolving = True
                solved = False
                totalMoves=0

    if startSolving:
        if not solved:
            newState = generateStates(puzzle)
            if not len(newState):
                print("No solution found")
                break

            newState.sort()
            print("Selected State")
            draw_puzzle()
            drawPuzzle(newState[0])
            pygame.display.flip()
            if newState[0].totalCost == 0:
                print("Solved the puzzle")
                print("Total Moves: ",totalMoves)
                solved = True
                startSolving = False
            puzzle = newState[0]
            closedList.append(puzzle)
            puzzle_state = puzzle.data
            totalMoves+=1

    # Clear the screen
    screen.fill((255, 255, 255))

    # Draw the puzzle
    draw_puzzle()

    # Draw the Start button
    draw_start_button()

    # Update the display
    pygame.display.flip()
    clock.tick(frameRate)
