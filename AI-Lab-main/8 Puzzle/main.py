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

if __name__ == "__main__":


    puzzle: Puzzle = Puzzle()
    puzzle.data = [[1, 3, 5], [8, 7, 2], [4, 6, 9]]
    misplaced(puzzle)
    calculateManhattanAndPositionOf9(puzzle)
    calculateTotalCost(puzzle)
    while True:
        newState = generateStates(puzzle)
        if not len(newState):
            print("No solution found")
            break

        newState.sort()
        print("Selected State")
        drawPuzzle(newState[0])
        if (newState[0].totalCost == 0):
            print("Solved the puzzle")
            break
        closedList.append(puzzle)
        puzzle = newState[0]
