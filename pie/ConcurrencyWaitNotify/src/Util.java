/**
 * Created by signa on 3/19/2016.
 */
public class Util {
    // Display a message, preceded by
    // the name of the current thread
    static void threadPrint(String message) {
        String threadName =
                Thread.currentThread().getName();
        System.out.format("%s: %s%n",
                threadName,
                message);
    }
}
