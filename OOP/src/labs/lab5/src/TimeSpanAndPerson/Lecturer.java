package labs.lab5.src.TimeSpanAndPerson;

public class Lecturer extends Person{
    private String department;
    private double salary;

    public Lecturer(String name, String lastName, int age, String department, double salary) {
        super(name, lastName, age);
        this.department = department;
        this.salary = salary;
        if (salary < 0 )
            this.salary = 0;
    }

    public String getDepartment() {
        return department;
    }

    public void setDepartment(String department) {
        this.department = department;
    }

    public double getSalary() {
        return salary;
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }

    public String toString() {
        return "Викладач кафедри " + getDepartment() + " , " + super.toString() + ". Зарплата: " + getSalary();
    }

}
