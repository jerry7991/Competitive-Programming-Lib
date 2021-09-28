class Student {
    String name;
    int rollNo;
    Student(int n) {
        rollNo = n;
    }
    void print() {
        System.out.print(rollNo + " " + name + " ");
    }
}

public class Use {
    public static void main(String[] args) {
        Student s = new Student(56);
        s.print();
    }
}