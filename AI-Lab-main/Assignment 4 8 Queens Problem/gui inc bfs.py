import pygame
import sys

# Define constants
WIDTH, HEIGHT = 600, 600
BOARD_SIZE = 8
SQUARE_SIZE = WIDTH // BOARD_SIZE
QUEEN_COLOR = (255, 0, 0)  # Red color for queens

# Initialize Pygame
pygame.init()
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("N-Queens Problem")


class Queen:
    def __init__(self, row, col):
        self.row = row
        self.col = col

    def draw(self):
        x = self.col * SQUARE_SIZE + SQUARE_SIZE // 2
        y = self.row * SQUARE_SIZE + SQUARE_SIZE // 2
        radius = SQUARE_SIZE // 4
        pygame.draw.circle(screen, QUEEN_COLOR, (x, y), radius)


def draw_board():
    for row in range(BOARD_SIZE):
        for col in range(BOARD_SIZE):
            color = (255, 255, 255) if (row + col) % 2 == 0 else (0, 0, 0)
            pygame.draw.rect(screen, color, (col * SQUARE_SIZE, row * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE))


def print_board(queens):
    print("\n\nBoard\n")
    for i in range(BOARD_SIZE):
        print("____" * BOARD_SIZE)
        for j in range(BOARD_SIZE):
            if any(queen.row == i and queen.col == j for queen in queens):
                print(f"| Q", end=" ")
            else:
                print("|  ", end=" ")
        print()


def main():
    open_list = []
    results = []
    number_of_iterations = 0
    first_board_found = False
    first_board_number_of_iterations = 0

    queens = []

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()

        if len(queens) == 8:
            results.append(queens)
            if not first_board_found:
                first_board_found = True
                first_board_number_of_iterations = number_of_iterations

        if not first_board_found:
            first_board_number_of_iterations += 1

        if len(open_list) == 0:
            if len(queens) == 8:
                print_board(queens)
                queens = []
            else:
                queens = open_list.pop(0)
                print_board(queens)
                queens = []

        if len(queens) < 8:
            number_of_iterations += 1
            i = len(queens)
            for j in range(8):
                copy_queens = queens.copy()
                new_queen = Queen(i, j)
                copy_queens.append(new_queen)
                if all(not _check_checks(new_queen, queen) for queen in copy_queens[:-1]):
                    open_list.append(copy_queens)

        screen.fill((0, 0, 0))
        draw_board()

        for queen in queens:
            queen.draw()

        pygame.display.flip()


def _check_checks(queen1, queen2):
    """Returns true if there is a check"""

    # Checking if they are in the same row or column
    if queen1.row == queen2.row or queen1.col == queen2.col:
        return True

    # Checking the diagonals
    if abs(queen1.row - queen2.row) == abs(queen1.col - queen2.col):
        return True

    return False


if __name__ == "__main__":
    main()
