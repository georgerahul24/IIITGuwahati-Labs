openList = []


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


def checkChecks(queens: list[Queen]) -> bool:
    """Returns true if there is a check"""
    for i in range(len(queens)):

        for j in range(i + 1, len(queens)):
            if _checkChecks(queens[i], queens[j]):
                return True

    return False


def generateStates(queens: list[Queen]):
    possibleStates = []
    i = len(queens)
    if i == 8:
        return None  # Since 8 queens have already been used

    for j in range(8):
        copy_queens = queens.copy()
        newQueen = Queen(f"{i + 1}", i, j)
        copy_queens.append(newQueen)
        if not checkChecks(copy_queens):
            possibleStates.append(copy_queens)
    return possibleStates


newState = []
results = []
numberOfIterations = 0
firstBoardFound = False
firstBoardNumberOfIterations = 0
try:
    while True:
        numberOfIterations += 1
        if not firstBoardFound:
            firstBoardNumberOfIterations += 1

        if (_states := generateStates(newState)) is not None:
            openList.extend(_states)

        newState = openList.pop(0)

        if len(newState) == 8:
            firstBoardFound = True
            results.append(newState)
            printBoard(newState)
            continue
except IndexError:
    # This means that all the possibles are explored
    pass

for board in results:
    printBoard(board)

print("Number of results are : ", len(results))
print("Number of iterations : ", numberOfIterations)
print("First board found: ", firstBoardNumberOfIterations)
