public class task4 {
    public static void findCheapestKeyboard(int[] keyboards) {
        int min = keyboards[0];
        for (int k : keyboards) {
            if (k < min) {
                min = k;
            }
        }
        System.out.println("Cheapest Keyboard: " + min);
    }

    public static void findMostExpensiveItem(int[] keyboards, int[] usbs) {
        int max = 0;
        for (int k : keyboards) {
            if (k > max) {
                max = k;
            }
        }
        for (int u : usbs) {
            if (u > max) {
                max = u;
            }
        }
        System.out.println("Most Expensive Item: " + max);
    }
}
