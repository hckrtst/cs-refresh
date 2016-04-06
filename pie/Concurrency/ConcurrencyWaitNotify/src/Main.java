/**
 * Created by signa on 3/19/2016.
 */
public class Main {
    public static void main(String args[]) {
        Data buffer = new Data();
        Thread t1 = new Thread(new Producer(buffer));
        Thread t2 = new Thread(new Consumer(buffer));
        Thread t3 = new Thread(new Producer(buffer));
        t1.setName("Producer1");
        t2.setName("Consumer1");
        t3.setName("Producer2");
        t1.start();
        t2.start();
        t3.start();

    }
}
