package com.hellosanket;

/**
 * Created by sanket on 3/27/16.
 */
public interface Computable<A,V> {
    V compute(A arg) throws InterruptedException;
}
