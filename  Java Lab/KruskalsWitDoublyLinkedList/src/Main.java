import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

class Edge{
    int weight;
    int u;
    int v;
}



class DoublyLinkedList {
    class Node {
        int data;
        Node prev;
        Node next;
        int representative;

        Node(int data) {
            prev = null;
            next = null;
            this.data = data;
            this.representative = data;
        }

        Node(int data, int representative) {
            prev = null;
            next = null;
            this.data = data;
            this.representative = representative;
        }
    }

    Node head;
    Node tail;
    int size;

    public DoublyLinkedList() {
        head = null;
        tail = null;
        size = 0;
    }

    public void push_back(int value) {
        Node newNode = new Node(value);
        if (tail == null) {
            head = tail = newNode;
        } else {
            newNode.prev = tail;
            tail.next = newNode;
            tail = newNode;
        }
        size++;
    }

    public void push_back(int value, int rep) {
        Node newNode = new Node(value, rep);
        if (tail == null) {
            head = tail = newNode;
        } else {
            newNode.prev = tail;
            tail.next = newNode;
            tail = newNode;
        }
        size++;
    }

    public void push_front(int value) {
        Node newNode = new Node(value);
        if (head == null) {
            head = tail = newNode;
        } else {
            newNode.next = head;
            head.prev = newNode;
            head = newNode;
        }
        size++;
    }

    public void pop_back() {
        if (tail != null) {
            Node temp = tail;
            if (tail == head) {
                head = tail = null;
            } else {
                tail = tail.prev;
                tail.next = null;
            }
            size--;
        }
    }

    public void pop_front() {
        if (head != null) {
            Node temp = head;
            if (head == tail) {
                head = tail = null;
            } else {
                head = head.next;
                head.prev = null;
            }
            size--;
        }
    }

    public int getSize() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public void display() {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + "(" + current.representative + ") -> ");
            current = current.next;
        }
        System.out.println();
    }

    public static void mergeAndChangeRepresentative(DoublyLinkedList l1, DoublyLinkedList l2) {
        l2.tail.next = null;
        l1.tail.next = l2.head;
        l1.tail = l2.tail;
        int rep = l1.head.representative;
        Node curr = l2.head;
        while (curr != null) {
            curr.representative = rep;
            curr = curr.next;
        }
        l1.size += l2.size;
    }

    public Node find(int value) {
        Node current = head;
        while (current != null) {
            if (current.data == value) {
                return current;
            }
            current = current.next;
        }
        return null;
    }
}


class Kruskal {
    private List<DoublyLinkedList> linkedLists;

    public int getRepresentative(int vertex, List<DoublyLinkedList> linkedLists, int[] index) {
        for (int i = 0; i < linkedLists.size(); i++) {
            DoublyLinkedList linkedList = linkedLists.get(i);
            DoublyLinkedList.Node ver = linkedList.find(vertex);
            if (ver != null) {
                index[0] = i;
                return ver.representative;
            }
        }
        return -1;
    }

    public Kruskal(String filename) {


        ArrayList<Edge> arr = new ArrayList<>();
        int n

        Collections.sort(arr, (i1, i2) -> Integer.compare(i2.weight, i1.weight));

        int numberOfEdges = 0;
        List<Edge> minEdges = new ArrayList<>();
        while (numberOfEdges < n - 1) {
            Edge e = arr.remove(G.edges.size() - 1);
            int[] index1 = new int[]{0};
            int[] index2 = new int[]{0};
            int ru = getRepresentative(e.u, linkedLists, index1);
            int rv = getRepresentative(e.v, linkedLists, index2);

            if (ru == rv) {
                continue;
            } else {
                // Different Representatives
                DoublyLinkedList.mergeAndChangeRepresentative(linkedLists.get(index1[0]), linkedLists.get(index2[0]));
                linkedLists.remove(index2[0]);
                numberOfEdges++;
                minEdges.add(e);
            }
        }

        for (Edge edge : minEdges) {
            System.out.printf("%d -> %d (%d)%n", edge.u.value, edge.v.value, edge.weight);
        }
    }
}

