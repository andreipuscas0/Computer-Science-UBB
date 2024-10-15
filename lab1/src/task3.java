public class task3 {
    public static void sumLargeNumbers(int[] num1, int[] num2) {
        int carry = 0;
        int[] result = new int[num1.length];
        for (int i = num1.length - 1; i >= 0; i--) {
            int sum = num1[i] + num2[i] + carry;
            result[i] = sum % 10;
            carry = sum / 10;
        }
        System.out.println(result);
    }

    public static void diffLargeNumbers(int[] num1, int[] num2) {
        int[] result = new int[num1.length];
        for (int i = num1.length - 1; i >= 0; i--) {
            int diff = num1[i] - num2[i];
            if (diff < 0) {
                diff += 10;
                num1[i - 1]--;
            }
            result[i] = diff;
        }
        System.out.println(result);
    }
}
