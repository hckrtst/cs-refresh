package com.hellosanket;

import java.util.concurrent.*;

public class Main {
    final MyCallable callable1 = new MyCallable(2);
    final MyCallable callable2 = new MyCallable(6);
    final FutureTask futureTask1 = new FutureTask<String>(callable1);
    final FutureTask futureTask2 = new FutureTask<String>(callable2);

    public static void say(String msg) {
        System.out.println(Thread.currentThread().getName() + ": " + msg);
    }

    /**
     * Start a bunch

     */
    public void startTasks() {
        Thread t1 = new Thread(futureTask1);
        Thread t2 = new Thread(futureTask2);

        t1.start();
        t2.start();

        try {
            say("Wait for future tasks");
            String t1Result = (String) futureTask1.get();
            say("FutureTask1 says: " + t1Result);
            String t2Result = (String) futureTask2.get(3L, TimeUnit.SECONDS);
            say("FutureTask2 says: " + t2Result);
        } catch (InterruptedException e) {
            e.printStackTrace();
        } catch (ExecutionException e) {
            e.printStackTrace();
        } catch (TimeoutException e) {
            e.printStackTrace();
            if (futureTask2.cancel(true)) {
                say("canceled task");
            }
        }

    }

    public static void main(String[] args) {
        new Main().startTasks();
    }
}
