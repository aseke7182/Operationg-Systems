import java.util.Scanner;

public class Driver {
    public static void main(String args[]) {
        System.out.println("Inside : " + Thread.currentThread().getName()); // изначально мы находимся в главном потоке Main

        Scanner sc = new Scanner(System.in);
        String[] inputNumbersAsString = sc.nextLine().split(" ");
        int[] inputNumbers = new int[inputNumbersAsString.length];

        for (int i = 0; i < inputNumbersAsString.length; i++) {
            inputNumbers[i] = Integer.parseInt(inputNumbersAsString[i]);
        }

        System.out.println("Creating Runnable...");
        ThreadRunnableExample runnable = new ThreadRunnableExample(inputNumbers);

        System.out.println("Creating Thread...");
        Thread thread = new Thread(runnable);

        System.out.print("Before start() execution the numbers array looked as follows: ");
        for (int i : runnable.getNumbers())
            System.out.printf("%d ", i);

        System.out.println("\nStarting Thread...");
        thread.start(); // start() вызывает run(), если мы попытаемся вызвать run() напрямую, тогда никакой потом не будет создан, потому что как раз таки start() просит JVM запустить новый потом

        try {
            thread.join();
            System.out.print("After start() execution the numbers array looks as follows: ");
            for (int i : runnable.getNumbers())
                System.out.printf("%d ", i);
        } catch (InterruptedException ie) {
            ie.printStackTrace();
        }

    }
}
