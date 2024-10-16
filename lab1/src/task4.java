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

    public static void findMaxSpend(int[] keyboards, int[] usbs, int budget) {
        int maxSpend = -1;
        for (int k : keyboards) {
            for (int u : usbs) {
                if (k + u <= budget && k + u > maxSpend) {
                    maxSpend = k + u;
                }
            }
        }
        System.out.println("Max Spend: " + maxSpend);
    }

    public static void main(String[] args) {
        int[] keyboards = {40, 50, 60};
        int[] usbs = {8, 12};
        int budget = 60;

        findCheapestKeyboard(keyboards);
        findMostExpensiveItem(keyboards, usbs);
        findMaxSpend(keyboards, usbs, budget);
    }
}
