package com.hellosanket;

/**
 * Created by sanket on 3/30/16.
 */

public interface Computable<A,V> {
    V compute(A arg) throws InterruptedException;

}
