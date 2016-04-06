package com.hellosanket;

import java.math.BigInteger;
import java.util.HashMap;
import java.util.Map;
import java.util.Random;
import java.util.concurrent.ConcurrentHashMap;

/**
 * We use a concurrent HashMap to avoid blocking
 * other threads from accessing compute() while one
 * is running.
 * But the problem with this apprpach is that if a bunch o threads
 * happen to try getting the same value the first time, they will
 * all start computations for the same value. This is still
 * wasteful
 */
public class BigComputation implements Computable<Integer, BigInteger> {
    final Map cache = new ConcurrentHashMap<Integer, BigInteger>();
    final Random r = new Random();

    @Override
    public BigInteger compute(Integer i) throws InterruptedException {
        // look up cache first
        if (cache.containsKey(i)) {
            Helper.say("Found " + i);
            return (BigInteger) cache.get(i);
        }
        BigInteger biggie = new BigInteger(String.valueOf(100 * i));
        // simulate some bust work
        Helper.say("zzz");
        int t = (int) Math.abs(Math.round(r.nextGaussian() * 3 + 6));
        Thread.sleep(t*700);
        cache.put(i, biggie);
        return biggie;
    }
}
