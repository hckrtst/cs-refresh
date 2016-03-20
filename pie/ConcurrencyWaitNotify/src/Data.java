/**
 * Created by signa on 3/19/2016.
 */
public class Data {
    private int index;
    private int[] buffer = new int[5];

    /**
     * Add an int
     * @param num
     */
    synchronized void add(int num) {
        while (index >= buffer.length) {
           try {
               Util.threadPrint("now waiting");
               wait();
           } catch (InterruptedException e) {
               e.printStackTrace();
           }
        }
        Util.threadPrint("resuming");
        buffer[index++] = num;
        dumpBuffer();
        notifyAll();
        return;
    }

    /**
     * remove int from buffer
     * @return
     */
    synchronized int remove() {
        while (index <= 0) {
            try {
                Util.threadPrint("now waiting");
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        Util.threadPrint("resuming");
        // We incremented index in add, so the last known data is in (index- 1)
        int num = buffer[--index];
        // clear consumed data for clarity
        buffer[index] = 0;
        dumpBuffer();
        notifyAll();
        return num;
    }

    private void dumpBuffer() {
        StringBuilder sb = new StringBuilder();
        //sb.append("|");
        //int index = 0;
        for (int d: buffer) {
            sb.append(d);
            sb.append(",");
            //index += 2;
        }
        //sb.replace(index,index, "]");
        Util.threadPrint(sb.toString());
    }
}
