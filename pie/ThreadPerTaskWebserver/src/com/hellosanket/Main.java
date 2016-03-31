package com.hellosanket;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;

/**
 * A poor man's webserver.
 * Please don't EVER do this for real
 * This atrocious thing creates a new thread everytime.
 * It's easily compromised by sending many many requests.
 */
public class Main {

    public static void say(String s) {
        System.out.println(Thread.currentThread().getName() + ": " + s);
    }

    public static void main(String[] args) {
        try {
            ServerSocket socket = new ServerSocket(4000);
            while (true) {
                // we make this final since it will be passed to runnable
                // for later processing
                final Socket connection = socket.accept();

                Runnable task = new Runnable() {
                    @Override
                    public void run() {
                        handleRequest(connection);
                    }
                };
                new Thread(task).start();

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

                } else if (s.contains("hello")){
                    out.println("HTTP/1.0 200 OK\r\n"+
                            "Content-type: text/html\r\n\r\n"+
                            "<html><head></head><body>" +
                            "<h2>Oh hello there :)</h2>" +
                            "</body></html>\n");

                }
                else {
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
