public class task3 {

    public static void sumLargeNumbers(int[] num1, int[] num2) {
        int carry = 0;
        int[] result = new int[num1.length + 1]; //cream un alt array pentru numarul nou
        for (int i = num1.length - 1; i >= 0; i--) {
            int sum = num1[i] + num2[i] + carry; //adunam cifrele si carry
            result[i] = sum % 10;
            carry = sum / 10;
        }
        printArray(result);
    }

//    public static void diffLargeNumbers(int[] num1, int[] num2) {
//        int[] result = new int[num1.length];
//        for (int i = num1.length - 1; i >= 0; i--) {
//            int diff = num1[i] - num2[i];
//            if (diff < 0) {
//                diff += 10;
//                num1[i - 1]--;
//            }
//            result[i] = diff;
//        }
//        printArray(result);
//    }

    public static void printArray(int[] arr) {
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }

    public static void multiplyLargeNumberByDigit(int[] num, int digit) {
        int carry = 0;
        int[] result = new int[num.length];
        for (int i = num.length - 1; i >= 0; i--) {
            int product = num[i] * digit + carry; //inmultim fiecare cifra cu nr si adaugam carry
            result[i] = product % 10;
            carry = product / 10;
        }
        printArray(result);
    }

    public static void divideLargeNumberByDigit(int[] num, int digit) {
        int carry = 0;
        int[] result = new int[num.length];
        for (int i = 0; i < num.length; i++) {
            int current = carry * 10 + num[i]; //adaugam carry la cifra actuala
            result[i] = current / digit;
            carry = current % digit; //actualizam carry-ul
        }
        printArray(result);
    }

    public static void main(String[] args) {
        int[] num1 = {1, 2, 0, 0, 0, 0, 0, 0, 0};
        int[] num2 = {8, 7, 0, 0, 0, 0, 0, 0, 0};

        System.out.print("Sum: ");
        sumLargeNumbers(num1, num2);

//        System.out.print("Difference: ");
//        diffLargeNumbers(num1, num2);

        System.out.print("Multiplication: ");
        multiplyLargeNumberByDigit(num1, 3);

        System.out.print("Division: ");
        divideLargeNumberByDigit(num1, 2);
    }
}
