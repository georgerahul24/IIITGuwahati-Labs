import random

N = 53


class Node:
    level: bool  # level = False means min else max
    remainingNumberOfSticks: int
    parent: object
    childList: list
    successValue: int
    alpha: int = -100  # Let this be infinity
    beta: int = 100  # Let this be infinity

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
    print("Parent Node: ", root.remainingNumberOfSticks, "Min" if not root.level else "Max", root.successValue,
          root.alpha, root.beta)
    for successor in root.childList:
        if successor is None:
            print("None")
        else:
            print(successor.remainingNumberOfSticks, successor.successValue)
    print("Child List Ends")
    for child in root.childList:
        if child is not None:
            printTree(child)



def propogateAlphaBeta(root):
    if root is None or root.childList is None:
        return

    else:
        for _successor in root.childList:
            _successor.alpha = max(root.alpha,_successor.alpha)
            _successor.beta = min(root.beta,_successor.beta)
            propogateAlphaBeta(_successor)


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
        if parentNode.alpha < parentNode.beta:
            if successor is not None:
                assignUtility(successor)

    if parentNode.level:
        # Logic for Maximising
        parentNode.successValue = max([successor.successValue for successor in parentNode.childList])
        # Here, we have to update the value of alpha

        parentNode.alpha = max(parentNode.alpha,
                               parentNode.successValue)


    else:
        # Logic for Minimising
        parentNode.successValue = min([successor.successValue for successor in parentNode.childList])
        # Here, we have to update the value of beta
        parentNode.beta = min(parentNode.beta,
                              parentNode.successValue)
    if parentNode.successValue in [1,-1]:
        childAlpha, childBeta = parentNode.successValue, parentNode.successValue
        tempParent = parentNode
        while tempParent is not None:
            if tempParent.level:
                # Here, parent's alpha gets updated
                tempParent.alpha = tempParent.alpha if tempParent.alpha < childBeta else childBeta
                pass

            else:
                # Here, parent's beta gets updated
                tempParent.beta = tempParent.beta if tempParent.beta > childAlpha else childAlpha
                pass

            tempParent = tempParent.parent
        # Now, propagate the values down
        global rootNode
        propogateAlphaBeta(rootNode)


toss = random.randint(0, 1)
# toss = True
remainingSticks = N
print("Value of N is: ", N)
rootNode: Node = None

if toss:
    parentNode = Node(N, None, None, True)

    while True:
        rootNode = parentNode
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
        else:
            print("AI plays this: ", remainingSticks - parentNode.childList[0].remainingNumberOfSticks)
            remainingSticks -= remainingSticks - parentNode.childList[0].remainingNumberOfSticks
            print("Remaining Sticks is ", remainingSticks)

        numberOfSticksByHuman = int(input("How many Sticks do you want?: "))
        if 1 <= numberOfSticksByHuman <= 3:
            remainingSticks -= numberOfSticksByHuman
            parentNode = Node(remainingSticks, None, None, True)
            rootNode = parentNode
            if remainingSticks == 0:
                print("Human wins this ")
                exit(0)

else:
    while True:
        numberOfSticksByHuman = int(input("How many Sticks do you want?: "))
        if 1 <= numberOfSticksByHuman <= 3:
            remainingSticks -= numberOfSticksByHuman
            parentNode = Node(remainingSticks, None, None, False)
            rootNode = parentNode
            if remainingSticks == 0:
                print("Human wins this ")
                exit(0)

        generateTree(parentNode)
        assignUtility(parentNode)
        # printTree(parentNode)
        if parentNode.childList is None and remainingSticks in [1, 2, 3]:
            print("AI Plays", remainingSticks)
            print("AI Wins")
            exit(0)
        for successor in parentNode.childList:
            if successor.successValue == -1:
                print("AI plays this: ", remainingSticks - successor.remainingNumberOfSticks)
                remainingSticks -= remainingSticks - successor.remainingNumberOfSticks
                print("Remaining Sticks is ", remainingSticks)
                break

        else:
            print("AI plays this: ", remainingSticks - parentNode.childList[0].remainingNumberOfSticks)
            remainingSticks -= remainingSticks - parentNode.childList[0].remainingNumberOfSticks
            print("Remaining Sticks is ", remainingSticks)
