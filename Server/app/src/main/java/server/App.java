package server;

import java.io.IOException;

public class App {

    public static void main(String[] args) throws InterruptedException, IOException {
        
        Server simpleHttpServer = new Server();
 
        // Start the server
        simpleHttpServer.start();
        System.out.println("Server is started and listening on port "+ 8000);
    }

}