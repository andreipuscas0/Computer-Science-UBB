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

    public static void roundGrades(int[] grades) {
        System.out.print("Round grades: ");
        for (int grade : grades) {
            if (grade >= 38 && (5 - (grade % 5)) < 3) {
                System.out.print(grade + " ");
            }
            System.out.println();
        }
    }

    public static void findMaxRoundedGrade(int[] grades) {
        int maxGrade = 0;
        for (int grade : grades) {
            if (grade >= 38 && (5 - (grade % 5)) < 3) {
                grade += 5 - (grade % 5);
            }
            if (grade > maxGrade) {
                maxGrade = grade;
            }
        }
        System.out.println("Max rounded grade: " + maxGrade);
    }

    public static void main(String[] args) {
        int[] grades = {29, 37, 38, 41, 84, 67};

        findFailingGrades(grades);
        calculateAverage(grades);
        roundGrades(grades);
        findMaxRoundedGrade(grades);
    }
}
