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
        Util.threadPrint("Consumer running");
        while(true) {
            int num = buffer.remove();
            // Force a delay to induce thread switch
            try {
                Thread.sleep(1);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
