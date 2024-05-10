import pygame
import sys

openList = []
closedListLeft = []  # Closed list for the left bank
closedListRight = []  # Closed List for the right bank


class State:
    p = 3  # This is for the left bank only
    c = 3
    total_cost = -1
    boatDirection = -1  # 0 boat is in the left bank  and 1 means boat is in the right bank
    parent = None

    def __init__(self, p, c, bd, parent):
        self.p = p
        self.c = c
        self.boatDirection = bd
        self.parent = parent

    def __eq__(self, other):
        return self.p == other.p and self.c == other.c

    def __str__(self):
        return f"""
        Left Bank : {self.p}M {self.c}C
        Right Bank : {3 - self.p}M {3 - self.c}C
        Boat Direction : {"R" if self.boatDirection else "L"}
        """


def inClosedList(current_state, closedList):
    for state in closedList:
        if current_state == state:
            return True
    return False


def isAValidState(state):
    pl = state.p
    cl = state.c
    pr = 3 - state.p
    cr = 3 - state.c

    if cr > pr > 0:  # This is to handle the edge case in which the priest might not be there in the bank at all
        return False
    if cl > pl > 0:
        return False

    return True


def generateStatesWhenGoingToTheLeftbank(currentState):
    newStates = []

    p, c = currentState.p, currentState.c

    if (p + 2) <= 3:
        state = State(p + 2, c, 0, currentState)
        if not inClosedList(state, closedListLeft) and isAValidState(state):
            newStates.append(state)

    if (c + 2) <= 3:
        state = State(p, c + 2, 0, currentState)
        if not inClosedList(state, closedListLeft) and isAValidState(state):
            newStates.append(state)
    if (p + 1) <= 3 and (c + 1) <= 3:
        state = State(p + 1, c + 1, 0, currentState)
        if not inClosedList(state, closedListLeft) and isAValidState(state):
            newStates.append(state)

    if (p + 1) <= 3:
        state = State(p + 1, c, 0, currentState)
        if not inClosedList(state, closedListLeft) and isAValidState(state):
            newStates.append(state)
    if (c + 1) <= 3:
        state = State(p, c + 1, 0, currentState)
        if not inClosedList(state, closedListLeft) and isAValidState(state):
            newStates.append(state)
    return newStates


def generateStateWhenGoingToTheRightbank(currentState):
    newStates = []

    p, c = currentState.p, currentState.c

    if (p - 2) >= 0:
        state = State(p - 2, c, 1, currentState)
        if not inClosedList(state, closedListLeft) and isAValidState(state):
            newStates.append(state)

    if (c - 2) >= 0:
        state = State(p, c - 2, 1, currentState)
        if not inClosedList(state, closedListLeft) and isAValidState(state):
            newStates.append(state)
    if (p - 1) >= 0 and (c - 1) >= 0:
        state = State(p - 1, c - 1, 1, currentState)
        if not inClosedList(state, closedListLeft) and isAValidState(state):
            newStates.append(state)

    if (p - 1) >= 0:
        state = State(p - 1, c, 1, currentState)
        if not inClosedList(state, closedListLeft) and isAValidState(state):
            newStates.append(state)
    if (c - 1) >= 0:
        state = State(p, c - 1, 1, currentState)
        if not inClosedList(state, closedListLeft) and isAValidState(state):
            newStates.append(state)

    return newStates


# Initialize Pygame
pygame.init()

# Set up colors
WHITE = (255, 255, 255)
BLUE = (0, 0, 255)
RED = (255, 0, 0)
BROWN = (139, 69, 19)
BLACK = (0, 0, 0)

# Set up screen
WIDTH, HEIGHT = 500, 300
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Missionaries and Cannibals")

# Set up game variables
state = State(3, 3, 0, None)

closedListRight.append(state)
openList.append(state)

clock = pygame.time.Clock()
font = pygame.font.Font(None, 36)


def draw_board(state):
    if state is not None:
        screen.fill(WHITE)
        pygame.draw.rect(screen, BLACK, (50, 50, 400, 200), 2)  # River
        draw_bank(1, state.p, state.c)
        draw_bank(2, 3 - state.p, 3 - state.c)
        draw_boat(state)


def draw_bank(bank_num, num_missionaries, num_cannibals):
    x_offset = 100 if bank_num == 1 else 300
    y_offset = 150
    for i in range(num_missionaries):
        pygame.draw.circle(screen, BLUE, (x_offset + 20, y_offset - i * 40 + 20), 15)
    for i in range(num_cannibals):
        pygame.draw.circle(screen, RED, (x_offset + 60, y_offset - i * 40 + 20), 15)


def draw_boat(state):
    x_offset = 230 if state.boatDirection == 0 else 270
    pygame.draw.rect(screen, BROWN, (x_offset, 100, 40, 80))


def draw_message(message):
    text = font.render(message, True, BLUE)
    screen.blit(text, (50, 10))


startSolving = False
numberOfIterations = 0
# Main game loop
running = True
path: list[State] = []
index = 0
# ... (previous code)

while running:
    if not startSolving:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_SPACE:
                    while state != State(0, 0, 1, None):
                        if state.boatDirection == 0:
                            newStates = generateStateWhenGoingToTheRightbank(state)
                            openList.extend(newStates)
                            for genState in newStates:
                                openList.extend(generateStatesWhenGoingToTheLeftbank(genState))

                        else:
                            newStates = generateStatesWhenGoingToTheLeftbank(state)
                            openList.extend(newStates)
                            for genState in newStates:
                                openList.extend(generateStateWhenGoingToTheRightbank(genState))

                        if state.boatDirection == 0:
                            closedListLeft.append(state)
                        else:
                            closedListRight.append(state)

                        state = openList.pop(0)
                        numberOfIterations += 1

                    startSolving = True

                    while state is not None:
                        path.insert(0, state)
                        state = state.parent
        draw_board(state)
    else:
        draw_board(path[index])
        index += 1
        if index == len(path) - 1:
            state = State(0, 0, 1, None)
            draw_board(state)
            startSolving = False
            index = 0

    pygame.display.flip()
    clock.tick(2)

print(numberOfIterations)
# Quit Pygame
pygame.quit()
sys.exit()
