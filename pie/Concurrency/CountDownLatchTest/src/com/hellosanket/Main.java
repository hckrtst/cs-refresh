package com.hellosanket;

import java.util.Queue;
import java.util.Random;
import java.util.concurrent.*;

public class Main {
    public static void say(String msg) {
        System.out.println(Thread.currentThread().getName() + ": " + msg);
    }

    // Use an unbounded queue for keeping order of completion
    private Queue leaderBoard = new ConcurrentLinkedQueue<String>();


    /**
     * Races a bunch of threads. You snooze you lose!
     * Contrived example to demo the use of CountdownLatch.
     */
    public void raceThreads(int numThreads) {

        final CountDownLatch startGate = new CountDownLatch(1);
        final CountDownLatch endGate = new CountDownLatch(numThreads);
        final Random random = new Random();

        for (int i=0; i < numThreads; i++) {
            Thread t = new Thread() {
                @Override
                public void run() {
                    try {
                        say("waiting to start");
                        startGate.await();
                        int time = (int) Math.round(random.nextGaussian() * 2 + 5);
                        say("Sleeping for " + time + " seconds zzzzz");
                        Thread.sleep(time*1000);
                        leaderBoard.offer(new String(Thread.currentThread().getName()));
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                        Thread.currentThread().interrupt();
                    } finally {
                        say("I'm awake");
                        endGate.countDown();
                    }
                }
            };
            t.start();
        }

        say("starting countdown");
        startGate.countDown();
        try {
            endGate.await();
            say("Game over!\n\n");
            StringBuilder sb = new StringBuilder();
            while (!leaderBoard.isEmpty()) {
                sb.append(leaderBoard.poll());
                sb.append(" ");
            }
            say("****** Leaderboard ******");
            say(sb.toString());
            say("*************************");

        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        Main myMain = new Main();
        myMain.raceThreads(3);
	}
}
