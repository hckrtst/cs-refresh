package com.hellosanket;

// TODO consider using a threadpool
public class Main {
    final BigComputation bc = new BigComputation();

    public static void main(String[] args) {
        final Main app = new Main();

        Thread t1 = new Thread() {
            @Override
            public void run() {
                Helper.say("running");
                try {
                    Helper.say("Computation result = " + app.bc.compute(34));
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        };

        Thread t2 = new Thread() {
            @Override
            public void run() {
                Helper.say("running");
                try {
                    Helper.say("Computation result = " + app.bc.compute(34));
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        };

        Thread t3 = new Thread() {
            @Override
            public void run() {
                Helper.say("running");
                try {
                    Helper.say("Computation result = " + app.bc.compute(4));
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        };

        t1.start();
        t3.start();
        t2.start();

    }
}
