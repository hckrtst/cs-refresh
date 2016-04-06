/**
 * Created by signa on 3/19/2016.
 */
public class Data {
    private int index;
    private int[] buffer = new int[5];

    // This will only syncrnize on the local object so
    // will not help
    // Once this thread goes into while loop, it will block
    // the other thread and as a result itself
    // since the other thread cannot proceed
    synchronized void add(int num) {
       while (true) {
           if (index < buffer.length) {
               System.out.println("1. adding " + num + "index =" + index);
               buffer[index++] = num;
               System.out.println("2. added " + num);
               return;
           }
       }
    }

    // This will only syncrnize on the local object so
    // will not help, will instead result in a deadlock
    // Once this thread goes into while loop, it will block
    // the other thread and as a result itself
    // since the other thread cannot proceed
    synchronized int remove() {
        while(true) {
            System.out.println("index = " + index);
            if (index > 0) {
                System.out.println("returning " + buffer[index - 1]);
                return buffer[--index];
            }
        }
    }
}
