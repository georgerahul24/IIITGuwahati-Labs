from copy import deepcopy


class Puzzle:
    data: list[list[int]] = list()
    parent = None

    def zeroPosition(self):

        for rowNumber, row in enumerate(self.data):
            for columnNumber, col in enumerate(row):
                if col == 9:
                    return (rowNumber, columnNumber)


def drawPuzzle(puzzle: Puzzle) -> None:
    print("-" * 12)
    for row in puzzle.data:
        print(
            f"| {row[0] if row[0] != 9 else ' '}  | {row[1] if row[1] != 9 else ' '} | {row[2] if row[2] != 9 else ' '} |")

    print("-" * 12)


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


def generateStates(current_state: Puzzle):
    """ State 1 is replacing by Up
    State 2 is replacing left
    State 3 is replacing right
    State 4 is replacing down"""
    newStates = []
    state1, state2, state3, state4 = deepcopy(current_state), deepcopy(current_state), deepcopy(
        current_state), deepcopy(current_state)

    state1.parent, state2.parent, state3.parent, state4.parent = current_state, current_state, current_state, current_state

    x, y = current_state.zeroPosition()
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

    return newStates


def checkEqual(puzzle: Puzzle) -> bool:
    for row1, row2 in zip(puzzle.data, goalState):
        for col1, col2 in zip(row1, row2):
            if col1 != col2:
                return False
    else:
        return True


openList = []
closedList: list[Puzzle] = list()

initialState = [[3, 8, 1], [6, 2, 5], [4, 7, 9]]

goalState = [[3, 8, 1], [6, 9, 5], [4, 2, 7]]


def misplaced(puzzle: Puzzle) -> int:
    misplacedNumber = 0
    for row1, row2 in zip(puzzle.data, goalState):
        for col1, col2 in zip(row1, row2):
            if col1 != col2:
                misplacedNumber += 1
    return misplacedNumber


if __name__ == "__main__":
    puzzle: Puzzle = Puzzle()
    puzzle.data = initialState
    numberofIteration = 0

    while True:
        numberofIteration += 1
        print(numberofIteration, len(openList), len(closedList), misplaced(puzzle))
        # drawPuzzle(puzzle)
        newState = generateStates(puzzle)

        openList.extend(newState)
        if not len(openList):
            print("No solution found")
            break

        if checkEqual(puzzle):
            print("Solved the puzzle")
            break

        closedList.append(puzzle)
        puzzle = openList.pop(0)


while puzzle is not None:
    drawPuzzle(puzzle)
    puzzle=puzzle.parent
