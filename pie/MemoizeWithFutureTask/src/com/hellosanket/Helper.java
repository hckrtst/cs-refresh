package com.hellosanket;

/**
 * Created by sanket on 3/30/16.
 */

public final class Helper {
    public static void say(String s) {
        System.out.println(Thread.currentThread().getName() + ": " + s);
    }
}
