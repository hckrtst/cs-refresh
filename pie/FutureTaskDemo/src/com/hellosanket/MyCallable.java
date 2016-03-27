package com.hellosanket;

import javax.swing.plaf.TableHeaderUI;
import java.util.concurrent.Callable;

/**
 * Created by signa on 3/27/2016.
 */
public class MyCallable implements Callable{
    int mSnoozeTime;

    /**
     * snooze time in seconds
     * @param t
     */
    public MyCallable(int t) {
        mSnoozeTime = t*1000;
    }

    @Override
    public Object call() throws Exception {
        Main.say("snoozing for " + mSnoozeTime/1000 + " sec");
        try {
            Thread.sleep(mSnoozeTime);
        }catch (InterruptedException e) {
            Main.say("Interrupted!");
            Thread.currentThread().interrupt();
        }
        return Thread.currentThread().getName();
    }
}
