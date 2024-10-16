public class task2 {

    public static void findMaxNumber(int[] numbers) {
        int max = numbers[0];
        for (int num : numbers) {
            if (num > max) {
                max = num;
            }
        }
        System.out.println("Max Number: " + max);
    }

    public static void findMinNumber(int[] numbers) {
        int min = numbers[0];
        for (int num : numbers) {
            if (num < min) {
                min = num;
            }
        }
        System.out.println("Min Number: " + min);
    }

    public static void findMaxSum(int[] numbers) {
        int sum = 0, min = numbers[0];
        for (int num : numbers) {
            sum += num;
            if (num < min) {
                min = num; //tinem minte nr minim
            }
        }
        System.out.println("Max Sum of n-1 Numbers: " + (sum - min)); //aflam suma max scazand nr minim
    }

    public static void findMinSum(int[] numbers) {
        int sum = 0, max = numbers[0];
        for (int num : numbers) {
            sum += num;
            if (num > max) {
                max = num; //tinem minte nr maxim
            }
        }
        System.out.println("Min Sum of n-1 Numbers: " + (sum - max)); //aflam suma minima scazand nr maxim
    }

    public static void main(String[] args) {
        int[] numbers = {4, 8, 3, 10, 17};

        findMaxNumber(numbers);
        findMinNumber(numbers);
        findMaxSum(numbers);
        findMinSum(numbers);
    }
}