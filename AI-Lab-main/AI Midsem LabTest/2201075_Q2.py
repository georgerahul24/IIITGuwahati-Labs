M: int = 5
N: int = 3
D: int = 4


class State:
    m: int
    n: int
    parent: object

    def __init__(self, m, n, parent=None):
        self.m = m
        self.n = n
        self.parent = parent

    def __eq__(self, other):
        return self.m == other.m and self.n == other.n

    def __str__(self):
        return f'M: {self.m} N: {self.n}'

    def isGoal(self):
        return self.m + self.n == D


openList = [State(0, 0)]
closedList= list()


def generateStates(currentState):
    newStates= []

    # Normal Bases Cases (Mostly would only be beneficial once)
    newStates.append(State(0, 0))
    newStates.append(State(M, N))
    newStates.append(State(M, 0))
    newStates.append(State(0, N))

    # Removing water from one jug
    newStates.append(State(currentState.m, 0))
    newStates.append(State(0, currentState.n))

    # Filling water in one jug
    newStates.append(State(currentState.m, N))
    newStates.append(State(M, currentState.n))

    # Filling water from one jug to the next

    if (M <= currentState.m + currentState.n):
        # This means the water will overflow  in the first jug
        newStates.append(State(M, currentState.m + currentState.n - M))

    else:
        newStates.append(State(currentState.m + currentState.n, 0))

    if (N <= currentState.m + currentState.n):
        # This means the water will overflow  in the second jug
        newStates.append(State(currentState.m + currentState.n - N, N))

    else:
        newStates.append(State(0, currentState.m + currentState.n))

    for state in newStates:
        if state not in openList and state not in closedList:
            state.parent = currentState
            openList.append(state)


currentState = None
if (D > M + N) or D < 0:
    print(
        "This is not possible. Since You cannot measure more than the combined capacities of the water jugs/ You cannot measure negative value")
    exit(0)
while True:
    currentState = openList.pop(0)
    closedList.append(currentState)
    if currentState.isGoal():
        break
    generateStates(currentState)

pathList= []

while currentState is not None:
    pathList.append(currentState)
    currentState = currentState.parent

print("The path for the solution is:")
for state in pathList[::-1]:
    print(state)
