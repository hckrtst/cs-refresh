package com.hellosanket;

@NotThreadsafe
public class Main {
    private static boolean ready;
    private static int number;

    private static class ReaderThread extends Thread{
        private int yielded = 0;

        @Override
        public void run() {

            while (!ready) {
                yielded++;
                Thread.yield();
            }
            System.out.println(Thread.currentThread().getName() + ": number = " + number + "yielded = " + yielded);
        }
    }

    public static void main(String[] args) {
	    System.out.println("Thread id = " + Thread.currentThread().getName());
        new ReaderThread().start();

        // setting ready first and adding sleep to show that
        // re-ordering in writer by user or JVM (when opcodes re-ordered) can have strange results
        ready = true;
        try {
            Thread.sleep(190);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        number = 42;

    }
}
