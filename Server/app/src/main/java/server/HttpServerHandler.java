package server;

import java.io.IOException;
import java.io.OutputStream;

import com.sun.net.httpserver.HttpExchange;
import com.sun.net.httpserver.HttpHandler;

class HttpServerHandler implements HttpHandler {
    public void handle(HttpExchange t) throws IOException {
        //Create a response form the request query parameters
        //URI uri = t.getRequestURI();
        String response = "Hello everyone";
        System.out.println("Response: " + response);
        //Set the response header status and length
        t.sendResponseHeaders(200, response.getBytes().length);
        //Write the response string
        OutputStream os = t.getResponseBody();
        os.write(response.getBytes());
        os.close();
    }
}