package labs.src.lab2;

import java.util.Scanner;

public class Student {
    Scanner in = new Scanner(System.in);
    String name;
    int year;
    int count;
    String[] courseStudent = new String[10];

    Student(String name, int year) {
        this.name = name;
        this.year = year;
    }

    public void addCourse(String courseName) {
        System.out.println("Count of discipline -> ");
        count = in.nextInt();
        for (int i = 0; i < count; i++) {
            System.out.printf("%d -> ", i + 1);
            courseName = in.next();
            courseStudent[i] = courseName;
        }
    }

    public void dropAll() {
        for (int i = 0; i < count; i++) {
            courseStudent[i] = null;
        }
    }

    int getCourseCount() {
        return count;
    }

    String getName() {
        return name;
    }

    int getTuition() {
        int amount = 20000;
        amount = amount * year;
        return amount;
    }

    int getYear() {
        return year;
    }
}
