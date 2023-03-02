package TimeSpanAndPerson;

public class Student extends Person{
    private int group;
    private int studentId;

    public Student(String name, String lastName, int age, int group, int studentId) {
        super(name, lastName, age);
        this.group = group;
        this.studentId = studentId;
    }

    public int getGroup() {
        return group;
    }

    public void setGroup(int group) {
        this.group = group;
    }

    public int getStudentId() {
        return studentId;
    }

    public void setStudentId(int studentId) {
        this.studentId = studentId;
    }

    public String toString() {
        return "Студент групи " + getGroup() + " , " + super.toString() + "." +
                " Номер студентського квитка: " + getStudentId();
    }

}
