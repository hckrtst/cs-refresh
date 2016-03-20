/**
 * Created by signa on 3/19/2016.
 */
public class Data {
    private int index;
    private int[] buffer = new int[5];


    synchronized void add(int num) {
       while () {
           if (index < buffer.length) {
               System.out.println("1. adding " + num + "index =" + index);
               buffer[index++] = num;
               System.out.println("2. added " + num);
               return;
           }
       }
    }

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
