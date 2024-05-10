M: int = 5
N: int = 3
D: int = 2


class State:
    m: int
    n: int
    parent = None

    def __init__(self, m, n):
        self.m = m
        self.n = n

    def __eq__(self, other):
        return self.m == other.m and self.n == other.n

    def in_closed_list(self) -> bool:
        for state in closedList:
            if state == self:
                return True
        return False

    def in_open_list(self) -> bool:
        for state in openList:
            if state == self:
                return True
        return False

    def is_goal_states(self) -> bool:
        return (self.m + self.n) == D

    def __str__(self):
        return "M: " + str(self.m) + " N: " + str(self.n) + "\n"


def generateSuccessors(currentState: State) -> list:
    newStates = []
    # One jug is made empty cases
    newStates.append(State(0, currentState.n))

    newStates.append(State(currentState.m, 0))

    # One jug is made full from tap
    newStates.append(State(M, currentState.n))
    newStates.append(State(currentState.m, N))

    # Both are made full or empty
    newStates.append(State(M, N))
    newStates.append(State(0, 0))

    # Pouring from one jug to another
    if M >= currentState.m + currentState.n:
        newStates.append(State(currentState.m + currentState.n, 0))
    else:
        newStates.append(State(M, currentState.m + currentState.n - M))

    if N >= currentState.m + currentState.n:
        newStates.append(State(0, currentState.m + currentState.n))
    else:
        newStates.append(State(currentState.m + currentState.n - N, N))

    results = []
    for state in newStates:
        if not state.in_closed_list() and not state.in_open_list():
            state.parent = currentState
            openList.append(state)

    return results


openList: list[State] = [State(0, 0)]
closedList: list[State] = []
currentState = None

numberOfIterations = 0

if __name__ == "__main__":
    while True:
        numberOfIterations += 1
        currentState = openList.pop(0)
        if currentState.is_goal_states():
            break
        else:
            closedList.append(currentState)
            generateSuccessors(currentState)

path = []
while currentState is not None:
    path.append(currentState)
    currentState = currentState.parent

for state in path[::-1]:
    print(state)
print("Total Number of iterations is ", numberOfIterations)
