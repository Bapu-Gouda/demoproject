class Student {

    int id;
    static String school = "ABC School";

    void setData(int i) {
        id = i;
        System.out.println("ID: " + id);
    }
}

class Test {
    public static void main(String args[]) {

        Student s1 = new Student();

        s1.setData(101);

        System.out.println(Student.school);
    }
}