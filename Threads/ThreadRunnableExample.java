public class ThreadRunnableExample implements Runnable {
    private int[] numbers;

    public ThreadRunnableExample(int... numbers) {
        this.numbers = numbers;
    }

    public int[] getNumbers() {
        return this.numbers;
    }

    public void setNumbers(int[] numbers) {
        this.numbers = numbers;
    }

    @Override
    public void run() {
        System.out.println("Inside : " + Thread.currentThread().getName());

        int temp = 0;
        int n = numbers.length;

        for (int i = 0; i < n; i++)
            for (int j = 1; j < n - i; j++)
                if (numbers[j - 1] > numbers[j]) {
                    temp = numbers[j - 1];
                    numbers[j - 1] = numbers[j];
                    numbers[j] = temp;
                }
    }
}
