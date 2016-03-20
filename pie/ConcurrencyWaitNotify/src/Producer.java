import java.util.Random;

/**
 * Created by signa on 3/19/2016.
 */
public class Producer implements Runnable{
    private Data buffer;

    Producer(Data buf) {
        this.buffer = buf;
    }

    @Override
    public void run() {
        Util.threadPrint("Producer running");
        // Generate random numbers to fill the buffer
        Random r = new Random();
        while(true) {
            int num = r.nextInt();
            buffer.add(num);
            // Force a delay to induce thread switch
            try {
                Thread.sleep(1);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
