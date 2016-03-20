/**
 * Created by signa on 3/19/2016.
 */
public class Consumer implements Runnable{
    private Data buffer;

    public Consumer(Data buf) {
        this.buffer = buf;
    }

    @Override
    public void run() {
        System.out.println("Consumer running");
        while(true) {
            int num = buffer.remove();
            System.out.println("Consumed " + num);
            // Force a delay to induce thread switch
            try {
                Thread.sleep(1);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
