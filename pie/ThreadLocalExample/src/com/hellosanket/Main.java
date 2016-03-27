package com.hellosanket;

public class Main {
    public static void main(String[] args) {
        MyThreadRunner runner = new MyThreadRunner();
        Thread t1 = new Thread(runner);
        Thread t2 = new Thread(runner);

        t1.start();
        t2.start();

        try {
            t1.join();
            t2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

    }
}
