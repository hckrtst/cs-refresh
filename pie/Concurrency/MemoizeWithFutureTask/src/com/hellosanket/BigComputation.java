package com.hellosanket;

import java.math.BigInteger;
import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.*;

/**
 * This class tries to be smart and uses an internal cache
 * for prevously computed values. However, since it synchronizes
 * on 'this', performance takes a hit since only one thread can
 * compute at any given time.
 */
public class BigComputation implements Computable<Integer, BigInteger> {
    final Map cache = new ConcurrentHashMap<Integer, Future<BigInteger>>();

    @Override
    public synchronized BigInteger compute(final Integer i) throws InterruptedException {
        // look up cache first
        Future<BigInteger> f = (Future<BigInteger>) cache.get(i);

        if (f == null) {
            Callable<BigInteger> eval = new Callable<BigInteger>() {
                @Override
                public BigInteger call() throws Exception {
                    BigInteger biggie = new BigInteger(String.valueOf(100 * i));
                    // simulate some busy work
                    Thread.sleep(2000);
                    return biggie;
                }
            };

            FutureTask<BigInteger> ft = new FutureTask<BigInteger>(eval);
            f = ft;
            cache.put(i, ft);
            ft.run(); // this runs the eval
        }

        try {
            return f.get();
        } catch (ExecutionException e) {
            e.printStackTrace();
            Thread.currentThread().interrupt();
        }
        return null;
    }
}
