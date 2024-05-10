N = 18


class Node:
    level: bool  # level = False means min else max
    remainingNumberOfSticks: int
    parent: object
    childList: list
    successValue: int

    def __init__(self, numberOfSticks, parent, childList, level):
        self.remainingNumberOfSticks = numberOfSticks
        self.childList = childList
        self.parent = parent
        self.level = level
        self.successValue = "Not Defined"


def generateTree(parentNode):
    successors = []
    if parentNode.remainingNumberOfSticks in [1, 2, 3]:
        successors = None
    elif parentNode.remainingNumberOfSticks == 0:
        successors = None
    else:
        if parentNode.remainingNumberOfSticks - 1 > 0:
            successors.append(Node(parentNode.remainingNumberOfSticks - 1, parentNode, None, not parentNode.level))
        if parentNode.remainingNumberOfSticks - 2 > 0:
            successors.append(Node(parentNode.remainingNumberOfSticks - 2, parentNode, None, not parentNode.level))
        if parentNode.remainingNumberOfSticks - 3 > 0:
            successors.append(Node(parentNode.remainingNumberOfSticks - 3, parentNode, None, not parentNode.level))

    if successors is not None:
        parentNode.childList = successors
        for child in parentNode.childList:
            generateTree(child)


def printTree(root):
    if root is None:
        return
    if root.childList is None:
        return
    print("Parent Node: ", root.remainingNumberOfSticks, "Min" if not root.level else "Max", root.successValue)
    for successor in root.childList:
        if successor is None:
            print("None")
        else:
            print(successor.remainingNumberOfSticks, successor.successValue)
    print("Child List Ends")
    for child in root.childList:
        if child is not None:
            printTree(child)


def assignUtility(parentNode):
    if parentNode.childList is None:
        # This means that this is the terminal node
        if parentNode.level:
            parentNode.successValue = 1
            return
        elif not parentNode.level:
            parentNode.successValue = -1
            return
    for successor in parentNode.childList:
        if successor is not None:
            assignUtility(successor)

    if parentNode.level:
        # Logic for Maximising
        parentNode.successValue = max([successor.successValue for successor in parentNode.childList])
        pass
    else:
        # Logic for Minimising
        parentNode.successValue = min([successor.successValue for successor in parentNode.childList])
        pass


parentNode = Node(N, None, None, True)
remainingSticks = N
print("Value of N is: ", N)
while True:
    generateTree(parentNode)
    assignUtility(parentNode)
    # printTree(parentNode)
    if parentNode.childList is None and remainingSticks in [1, 2, 3]:
        print("AI Plays", remainingSticks)
        print("AI Wins")
        exit(0)
    for successor in parentNode.childList:
        if successor.successValue == 1:
            print("AI plays this: ", remainingSticks - successor.remainingNumberOfSticks)
            remainingSticks -= remainingSticks - successor.remainingNumberOfSticks
            print("Remaining Sticks is ", remainingSticks)
            break
        if remainingSticks == 0:
            print("AI Wins")
            exit(0)

    numberOfSticksByHuman = int(input("How many Sticks do you want?: "))
    if 1 <= numberOfSticksByHuman <= 3:
        remainingSticks -= numberOfSticksByHuman
        parentNode = Node(remainingSticks, None, None, True)
        if remainingSticks == 0:
            print("Human wins this ")
            exit(0)
