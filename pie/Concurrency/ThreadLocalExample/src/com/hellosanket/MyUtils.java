package com.hellosanket;

/**
 * Created by signa on 3/26/2016.
 */
public final class MyUtils {
    public static void say(final String s) {
        StringBuilder sb = new StringBuilder();
        sb.append(Thread.currentThread().getName());
        sb.append(": ");
        sb.append(s);
        System.out.println(sb.toString());
    }
}
