package prep.practice.threads;

/**
 * simpleThread
 */

class T1 implements Runnable {
    public void run() {
        System.out.println("Hello");
    }
}

public class simpleThread {

    public static void main(String[] args) {
        try {
            Thread t1 = new Thread(new T1());
            t1.start();
            t1.join();
        } catch (InterruptedException ie) {
            ie.printStackTrace();
        }
    }
}