package com.hellosanket;

import javax.lang.model.element.ExecutableElement;
import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;
import java.util.concurrent.Executor;
import java.util.concurrent.Executors;

/**
 * A poor man's webserver.
 * An example
 */
public class Main {
    private static final int NTHREADS = 80;
    private static final Executor exec =
            Executors.newFixedThreadPool(NTHREADS);

    private static void say(String s) {
        System.out.println(Thread.currentThread().getName() + ": " + s);
    }

    public static void main(String[] args) {
        try {
            ServerSocket socket = new ServerSocket(4000);
            while (true) {
                // make this final since we pass it in to callback
                final Socket connection = socket.accept();
                say("accept connection");
                Runnable runnable = new Runnable() {
                    @Override
                    public void run() {
                        handleRequest(connection);
                    }
                };
                exec.execute(runnable);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    private static void handleRequest(Socket connection) {
        PrintStream out = null;

        try {

            try (BufferedReader input = new BufferedReader(new InputStreamReader(connection.getInputStream()))) {
                String s = input.readLine();
                say(s);
                out = new PrintStream(new BufferedOutputStream(connection.getOutputStream()));

                // if we get '/something' taunt the user
                if (s.contains("something")) {
                    out.println("HTTP/1.0 200 OK\r\n"+
                            "Content-type: text/html\r\n\r\n"+
                            "<html><head></head><body>" +
                            "You gotta know what you want!!!! " +
                            "</body></html>\n");
                } else {
                    out.println("HTTP/1.0 200 OK\r\n" +
                            "Content-type: text/html\r\n\r\n" +
                            "<html><head></head><body>" +
                            "Welcome friend!" +
                            "</body></html>\n");
                }
                out.close();
            }

        } catch (SocketException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
