import java.util.Scanner;

public class task1 {
    public static void findFailingGrades(int[] grades) {
        System.out.print("Failing grades: ");
        for (int grade : grades) {
            if (grade < 40) {
                System.out.print(grade + " ");
            }
        }
        System.out.println();
    }

    public static void calculateAverage(int[] grades) {
        int sum = 0;
        for (int grade : grades) {
            sum += grade;
        }
        double average = (double) sum / grades.length;
        System.out.println("Average grade: " + average);
    }
}
