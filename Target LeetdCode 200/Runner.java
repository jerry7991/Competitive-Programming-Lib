import java.util.ArrayList;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.io.FileWriter;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Node {
    public int data;
    public Node next, prev;

    Node(int data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}

public class Runner {

    private static int t;
    private static ArrayList<Node > allLists;
    private static ArrayList<Integer > allPos;
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    private static Node linkedListInput() throws IOException {
        String [] data;
        data = br.readLine().trim().split(" ");

        Node head = null;
        Node tail = null;
        int index = 0;

        while (Integer.parseInt(data[index]) != -1) {
            Node newNode = new Node(Integer.parseInt(data[index++]));
            if (head == null) {
                head = newNode;
                tail = newNode;
            } else {
                tail.next = newNode;
                newNode.prev = tail;
                tail = tail.next;
            }
        }

        return head;
    }

    private static void takeInput() throws IOException {

        t = Integer.parseInt(br.readLine().trim().split(" ")[0]);

        allLists = new ArrayList<Node>(t);
        allPos = new ArrayList<Integer>(t);

        for (int i = 0; i < t; i++) {
            allLists.add(linkedListInput());
            allPos.add(Integer.parseInt(br.readLine().trim().split(" ")[0]));

        }
    }

    private static Node copyLinkedList(Node head) {
        if (head == null) {
            return null;
        }
        Node newLinkedList = new Node(head.data);
        Node cur = newLinkedList;
        head = head.next;
        while (head != null) {
            cur.next = new Node(head.data);
            cur = cur.next;
            head = head.next;
        }
        return newLinkedList;
    }

    private static void execute() {
        for (int i = 0; i < t; i++) {
            Node head = copyLinkedList(allLists.get(i));

            Node result = Solution.deleteNode(head, allPos.get(i));

        }
    }

    private static void executeAndPrintOutput() {
        for (int i = 0; i < t; i++) {
            Node head = copyLinkedList(allLists.get(i));
            Node ans = Solution.deleteNode(head, allPos.get(i));

            while (ans != null) {
                System.out.print(ans.data + " ");
                ans = ans.next;
            }
            System.out.println(-1);


        }
    }

    public static void main(String[] args) throws IOException {
        takeInput();
        // executeAndPrintOutput();

        int execCount = Integer.parseInt(System.getenv("EXECUTION_COUNT"));

        if (execCount == 1) {
            executeAndPrintOutput();
        } else {

            FileWriter writer = new FileWriter(System.getenv("EXEC_COUNTER_FILE"));

            for (int i = 0; i < execCount; i++) {
                execute();
                writer.write(String.valueOf(i + 1) + "\n");
                writer.flush();
            }

            writer.close();
        }
    }
}