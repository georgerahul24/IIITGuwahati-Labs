import copy


class Queen:
    queenName: str = ""
    x: int = ""
    y: int = ""

    def __init__(self, queenName: str, x, y):
        self.queenName = queenName
        self.x = x
        self.y = y

    def getPosition(self) -> tuple[int, int]:
        return self.x, self.y

    def isValidPosition(self) -> bool:
        return (0 <= self.x <= 7) and (0 <= self.y <= 7)

    def __eq__(self, other):
        return self.x == other.x and self.y == other.y

    @staticmethod
    def inQueens(queen, queens):
        for _queen in queens:
            if _queen == queen:
                return _queen
        return None

    @staticmethod
    def inClosedList(currentState: list, closedList: list[list]) -> bool:
        for closedState in closedList:
            matchnumber = 0
            for queen1, queen2 in zip(currentState, closedState):
                if queen1 == queen2:
                    matchnumber += 1
            if matchnumber == 8:
                return True
        return False

    def __str__(self):
        return str(self.queenName) + " ( " + str(self.x) + ", " + str(self.y) + " ) "


class State:
    depthLevel: int = 0
    queens: list[Queen] = []

    def __init__(self, depthLevel: int, queens: list[Queen]):
        self.depthLevel = depthLevel
        self.queens = queens


def printBoard(queens: list[Queen]) -> None:
    print("\n\nBoard\n")
    for i in range(8):
        print("____" * 8)
        for j in range(8):
            if (_q := Queen.inQueens(Queen("", i, j), queens)) is not None:
                print(f"| {_q.queenName}", end=" ")
            else:
                print("|  ", end=" ")
        print()


def _checkChecks(queen1: Queen, queen2: Queen) -> bool:
    """Returns true if there is a check"""

    # Checking if they are in the same row or column
    if queen1.x == queen2.x or queen1.y == queen2.y: return True

    # Checking the diagonals
    if abs(queen1.x - queen2.x) == abs(queen1.y - queen2.y):
        return True

    return False


def checkChecks(queenNumber: int, queens: list[Queen]) -> bool:
    """Returns true if there is a check for that particular queen"""
    for i in range(len(queens)):

        if _checkChecks(queens[queenNumber], queens[i]) and queenNumber != i:
            return True

    return False


def checkBoard(queens: list[Queen]) -> bool:
    """Returns true if there is a check"""
    for i in range(len(queens)):
        for j in range(i + 1, len(queens)):
            if _checkChecks(queens[i], queens[j]):
                return True

    return False


def generateStates(queens: list[Queen]):
    possibleStates = []

    for queenNumber in range(8):
        currentQueen = queens[queenNumber]
        for i in range(8):
            if (currentQueen.y != i):
                copy_queens = copy.deepcopy(queens)
                copy_queens[queenNumber].y = i
                if not checkChecks(queenNumber, copy_queens) and not Queen.inClosedList(copy_queens, closedList):
                    possibleStates.append(copy_queens)

    return possibleStates


initial_state = State(0, [Queen("0", 0, 0), Queen("1", 1, 0), Queen("2", 2, 0), Queen("3", 3, 0), Queen("4", 4, 0),
                          Queen("5", 5, 0),
                          Queen("6", 6, 0), Queen("7", 7, 0)])

newState: list[Queen] = []
_newState: State = None
i = 0

maxDepthFinal = 14
boardFound = False
for maxDepth in range(1, maxDepthFinal + 1):
    if boardFound:
        break
    running = True
    openList: list[State] = [initial_state
        , ]

    closedList: list[list[Queen]] = []
    while running:
        try:
            print(i, f"Open List: {len(openList)}", f"Closed List: {len(closedList)}")
            i += 1
            _newState = openList.pop(0)
            newState = _newState.queens
            closedList.append(newState)
            if not checkBoard(newState):
                boardFound = True
                break
            possibleState = generateStates(newState)
            if possibleState is not None and len(possibleState) > 0:
                if _newState.depthLevel < maxDepth:
                    for state in possibleState:
                        openList.insert(0, State(_newState.depthLevel + 1, state))
        except IndexError:
            print("No solution found in depth", maxDepth)
            running = False

if boardFound:
    print("Board Found at depth: ",_newState.depthLevel)
    printBoard(newState)
