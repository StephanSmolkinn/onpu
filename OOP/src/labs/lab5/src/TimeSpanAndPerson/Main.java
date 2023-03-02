package labs.lab5.src.TimeSpanAndPerson;

public class Main {
    public static void main(String[] args) {

        Student student1 = new Student("Smolkin", "Stephan", 19, 215, 45);
        Student student2 = new Student("Maks", "Orlov", 20, 215, 98);

        Lecturer lecturer1 = new Lecturer("Glava", "Maria", 60, "Computer science",
                20000);
        Lecturer lecturer2 = new Lecturer("Anisismov", "Volodymyr", 60, "Computer science",
                25000);

        Person[] person = {student1, student2, lecturer1, lecturer2};

        for (Person values : person)
            System.out.println(values.toString());
    }
}