package server;

import java.io.IOException;
import java.net.InetSocketAddress;

import com.sun.net.httpserver.HttpServer;


public class Server {

    public void start() throws IOException {
        HttpServer server = HttpServer.create(new InetSocketAddress(8000), 0);
        server.createContext("/applications/myapp", new HttpServerHandler());
        server.setExecutor(null); // creates a default executor
        server.start(); 
    }

}


