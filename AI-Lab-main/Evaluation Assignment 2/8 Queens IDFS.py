from copy import deepcopy


class Puzzle:
    data: list[list[int]] = list()
    parent = None
    depth = None
    manhattanDistance = None
    totalCost = None

    def __init__(self, data, depth):
        self.data = data
        self.depth = depth

    def zeroPosition(self):

        for rowNumber, row in enumerate(self.data):
            for columnNumber, col in enumerate(row):
                if col == 9:
                    return (rowNumber, columnNumber)

    def __str__(self):
        returnString = "-" * 12 + "\n"
        for row in self.data:
            returnString += f"| {row[0] if row[0] != 9 else ' '}  | {row[1] if row[1] != 9 else ' '} | {row[2] if row[2] != 9 else ' '} |\n"

        returnString += "-" * 12
        return returnString

    def __eq__(self, other):

        for row1, row2 in zip(self.data, other.data):
            for col1, col2 in zip(row1, row2):
                if col1 != col2:
                    return False

        return True

    def calculateManhattanDistance(self):
        return 0

    def calculateTotalCost(self):
        return 0


def generateStates(current_state: Puzzle, maxDepth):
    """ State 1 is replacing by Up
    State 2 is replacing left
    State 3 is replacing right
    State 4 is replacing down"""

    if maxDepth < current_state.depth + 1:
        return None

    state1, state2, state3, state4 = deepcopy(current_state), deepcopy(current_state), deepcopy(
        current_state), deepcopy(current_state)

    state1.parent, state2.parent, state3.parent, state4.parent = current_state, current_state, current_state, current_state
    state1.depth, state2.depth, state3.depth, state4.depth = current_state.depth + 1, current_state.depth + 1, current_state.depth + 1, current_state.depth + 1

    x, y = current_state.zeroPosition()
    global numberOfNodesGenerated
    if x - 1 >= 0:
        state1.data[x][y], state1.data[x - 1][y] = state1.data[x - 1][y], state1.data[x][y]
        if state1 not in closedList and state1 not in openList:
            numberOfNodesGenerated += 1
            openList.append(state1)
    if y - 1 >= 0:
        state2.data[x][y], state2.data[x][y - 1] = state2.data[x][y - 1], state2.data[x][y]
        if state2 not in closedList and state2 not in openList:
            numberOfNodesGenerated += 1
            openList.append(state2)
    if y + 1 <= 2:
        state3.data[x][y], state3.data[x][y + 1] = state3.data[x][y + 1], state3.data[x][y]
        if state3 not in closedList and state3 not in openList:
            numberOfNodesGenerated += 1
            openList.append(state3)
    if x + 1 <= 2:
        state4.data[x][y], state4.data[x + 1][y] = state4.data[x + 1][y], state4.data[x][y]
        if state4 not in closedList and state4 not in openList:
            numberOfNodesGenerated += 1
            openList.append(state4)


openList = []
closedList: list[Puzzle] = list()

initialState = [[4, 1, 2], [8, 7, 9], [3, 5, 6]]
goalState = Puzzle([[1, 2, 3], [4, 5, 6], [7, 8, 9]], -1)

numberOfNodesGenerated: int = 0
numberOfNodesEvaluated: int = 0
maxLengthOfOpenList: int = 0


def solution(maxDepth):
    global openList, closedList, numberOfNodesEvaluated, maxLengthOfOpenList
    openList = [Puzzle(initialState, 0)]

    closedList = []

    while True:
        # drawPuzzle(puzzle)
        puzzle = openList.pop(-1)  # TO make sure that it is DFS
        if len(openList) > maxLengthOfOpenList:
            maxLengthOfOpenList = len(openList)
        if puzzle == goalState:
            print("Solved the puzzle")
            return True, puzzle
        numberOfNodesEvaluated += 1
        closedList.append(puzzle)
        generateStates(puzzle, maxDepth)

        if not len(openList):
            return False, None


depth = 0

while True:
    solved, puzzle = solution(depth)
    depth += 1
    if solved:

        path = []
        while puzzle is not None:
            path.append(puzzle)
            puzzle = puzzle.parent

        print("The solution is:")
        for state in path[::-1]:
            print(state)

        print("Number of Nodes Expanded:", len(closedList))
        print("Number of Nodes Generated:", len(openList) + len(closedList))
        print("Maximum Length of the Open List:", maxLengthOfOpenList)
        print("Length of the path:", len(path))
        exit(0)
    else:
        print("No solution found in depth", depth)
