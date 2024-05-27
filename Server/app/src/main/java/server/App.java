package server;

import java.io.IOException;

public class App {

    private static final String CONTEXT = "/app";
    private static final int PORT = 8000;

    public static void main(String[] args) throws InterruptedException, IOException {
        
        Server simpleHttpServer = new Server(PORT, CONTEXT,
                new HttpServerHandler());
 
        // Start the server
        simpleHttpServer.start();
        System.out.println("Server is started and listening on port "+ PORT);
    }

}