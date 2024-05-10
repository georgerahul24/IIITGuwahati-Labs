import copy

N = 8


class Queen:
    x: int
    y: int

    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __eq__(self, other):
        return self.x == other.x and self.y == other.y


class Board:
    queens: list[Queen]

    def __init__(self, queens: list[Queen]):
        self.queens = copy.deepcopy(queens)

    def queenIsThere(self, x, y):
        for queen in self.queens:
            if queen.x == x and queen.y == y:
                return True
        return False

    def in_closed_list(self) -> bool:
        return self in closedList

    def in_open_list(self) -> bool:

        return self in openList

    def __eq__(self, other):
        count = 0
        for queen in self.queens:
            if queen in other.queens:
                count += 1
        return count == N

    def __str__(self):
        printString = """"""

        for i in range(N):
            for j in range(N):
                if self.queenIsThere(j, i):
                    printString += "Q "
                else:
                    printString += "- "
            printString += "\n"
        return printString


def _is_check_queen(current_state: Board, queen: Queen) -> bool:
    for another_queen in current_state.queens:
        if another_queen != queen:
            if (abs(queen.x - another_queen.x) ==
                    abs(queen.y - another_queen.y)
                    or queen.y == another_queen.y or queen.x == another_queen.x):
                return True

    return False


def is_check(currentState: Board):
    for queen in currentState.queens:
        if _is_check_queen(currentState, queen):
            return True
    return False


def generate_New_States(currentState: Board):
    newStates = []
    for i in range(N):
        for j in range(N):
            newState: Board = copy.deepcopy(currentState)
            newState.queens[i].x = j

            if not _is_check_queen(newState, newState.queens[i]):
                newStates.append(newState)

    for state in newStates:
        if not state.in_closed_list() and not state.in_open_list():
            openList.insert(0, state)


queens = [Queen(0, i) for i in range(N)]
openList: list[Board] = [Board(queens), ]
closedList: list[Board] = []

while True:
    currentState = openList.pop(0)
    closedList.append(currentState)
    generate_New_States(currentState)
    if not is_check(currentState):
        print(currentState)
        break
