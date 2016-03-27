package com.hellosanket;

/**
 * Created by signa on 3/26/2016.
 */
public class MyThreadRunner implements Runnable{
    private ThreadLocal threadLocalString = new ThreadLocal<String>() {
        @Override
        // This value will be seen by all threads
        protected String initialValue() {
            return "Abracadabra";
        }
    };

    @Override
    public void run() {
        MyUtils.say("Initial value = " + threadLocalString.get());
        threadLocalString.set(Thread.currentThread().getName());
        MyUtils.say("Napping for a bit");
        try {
            Thread.sleep(2000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        MyUtils.say("New value = " + threadLocalString.get());
    }
}
