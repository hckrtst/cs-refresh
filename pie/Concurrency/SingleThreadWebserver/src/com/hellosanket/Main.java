package com.hellosanket;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;

/**
 * A poor man's webserver.
 * Please don't EVER do this for real
 */
public class Main {


    public static void main(String[] args) {
        try {
            ServerSocket socket = new ServerSocket(4000);
            while (true) {
                Socket connection = socket.accept();
                handleRequest(connection);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    private static void handleRequest(Socket connection) {
        PrintStream out = null;
        // simulate network and processing delays
        try {
            Thread.sleep(2000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        try {

            try (BufferedReader input = new BufferedReader(new InputStreamReader(connection.getInputStream()))) {
                String s = input.readLine();
                System.out.println(s);
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
