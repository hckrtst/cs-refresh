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
                    Helper.say("Computation result = " + app.bc.compute(4));
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

        Thread t4 = new Thread() {
            @Override
            public void run() {
                Helper.say("running");
                try {
                    Helper.say("Computation result = " + app.bc.compute(40));
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        };

        Thread t5 = new Thread() {
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
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        t2.start();
        t4.start();
        t5.start();

    }
}
