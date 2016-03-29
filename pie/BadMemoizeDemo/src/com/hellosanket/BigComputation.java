package com.hellosanket;

import java.math.BigInteger;
import java.util.HashMap;
import java.util.Map;

/**
 * This class tries to be smart and uses an internal cache
 * for prevously computed values. However, since it synchronizes
 * on 'this', performance takes a hit since only one thread can
 * compute at any given time.
 *
 * Created by sanket on 3/28/16.
 */
public class BigComputation implements Computable<Integer, BigInteger> {
    final Map cache = new HashMap<Integer, BigInteger>();

    @Override
    public synchronized BigInteger compute(Integer i) throws InterruptedException {
        // look up cache first
        if (cache.containsKey(i)) {
            Helper.say("Found " + i);
            return (BigInteger) cache.get(i);
        }
        BigInteger biggie = new BigInteger(String.valueOf(100 * i));
        // simulate some bust work
        Thread.sleep(2000);
        cache.put(i, biggie);
        return biggie;
    }
}
