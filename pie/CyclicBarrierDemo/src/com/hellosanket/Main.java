package com.hellosanket;

import java.util.Random;
import java.util.concurrent.BrokenBarrierException;
import java.util.concurrent.CyclicBarrier;

public class Main {
    public final int numThreads = 3;
    final Random rand = new Random();

    public static void say(String msg) {
        System.out.println(Thread.currentThread().getName() + ": " + msg);
    }

    // barrier action will be called by the last waiting thread
    // i.e. when barrier await returns 0
    final public Runnable barrierAction = new Runnable() {
        @Override
        public void run() {
            say("Barrier action called");
            // do something crucial now
        }
    };

    final public Runnable threadRunner = new Runnable() {
        @Override
        public void run() {
            say("Thread snoozing");
            int t = (int) Math.abs(Math.round(rand.nextGaussian() * 4 + 3));
            try {
                Thread.sleep(t*1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            try {
                say("Barrier index = " + barrier.await());
            } catch (InterruptedException e) {
                e.printStackTrace();
            } catch (BrokenBarrierException e) {
                e.printStackTrace();
            }
        }
    };
    final public CyclicBarrier barrier = new CyclicBarrier(numThreads, barrierAction);

    public static void main(String[] args) {
        Main app = new Main();

        for (int i=0; i<app.numThreads; i++) {
            new Thread(app.threadRunner).start();
        }

        /*say("Waiting at barrier");
        app.barrier.await();*/
        say("Exit main thread");

    }
}
