package com.hellosanket;

import java.io.PrintStream;

/**
 * Created by sanket on 7/11/16.
 */

public class DiningPhilosophers {
   // The shared resource objects aka the chopsticks
   private Object[] chopsticks;

   private Philosopher[] philosophers;

   // private to this package so `main` method can access
   private DiningPhilosophers(int numPhilosophers) {
      // philosophers will have to share chopsticks
      // there is a dearth of free chopsticks
      chopsticks = new Object[numPhilosophers];

      // Remember we have to first create the array
      // object
      philosophers = new Philosopher[numPhilosophers];

      for (int i=0; i<numPhilosophers; i++) {
         int chopstick1 = i;
         int chopstick2 = (i + 1) % numPhilosophers;

         if (i == 0) {
            philosophers[i] = new Philosopher(i, chopstick2, chopstick1);
         } else {
            philosophers[i] = new Philosopher(i, chopstick1, chopstick2);
         }

         chopsticks[i] = new Object();
      }

   }

   private void Eat() throws InterruptedException {
      Thread[] threads = new Thread[philosophers.length];
      // Start the philosophers
      for (int i = 0; i < philosophers.length; i++) {
         threads[i] = new Thread(philosophers[i]);
         threads[i].start();
      }

      // This prevents program from exiting since
      // the first philosopher will not be done
      // threads[0].join();
   }

   private class Philosopher implements Runnable{
      int id;
      int leftChopStick;
      int rightChopStick;

      Philosopher(int id, int left, int right) {
         this.id = id;
         this.leftChopStick = left;
         this.rightChopStick = right;
      }

      @Override
      public void run() {
         Status("Sitting at table");
         Status("Ready to eat with chopstick " + leftChopStick + " and chopstick " + rightChopStick);
         Pause(200);

         while (true) {
            Status("Try to pick up chopstick " + leftChopStick);
            synchronized (chopsticks[leftChopStick]) {
               Status("Try to pick up chopstick " + rightChopStick);
               synchronized (chopsticks[rightChopStick]) {
                  Status("Eating");
               }
            }
            Pause(50);
         }
      }

      private void Pause(int t) {
         try {
            Thread.sleep(t);
         } catch (InterruptedException e) {
            e.printStackTrace();
         }
      }


      private void Status(final String msg) {
         System.out.println("Philosopher " + id + ": " + msg);
      }
   }

   public static void main(String[] args) {
      DiningPhilosophers diningPhilosophers = new DiningPhilosophers(5);
      try {
         diningPhilosophers.Eat();
      } catch (InterruptedException e) {
         e.printStackTrace();
      }
   }

}
