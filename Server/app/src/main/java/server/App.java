package server;

import java.io.UnsupportedEncodingException;

import com.corundumstudio.socketio.AckRequest;
import com.corundumstudio.socketio.Configuration;
import com.corundumstudio.socketio.SocketIOClient;
import com.corundumstudio.socketio.SocketIOServer;
import com.corundumstudio.socketio.listener.*;

public class App {

    public static void main(String[] args) throws InterruptedException, UnsupportedEncodingException {

        Configuration config = new Configuration();
        config.setHostname("localhost");
        config.setPort(8080);

        final SocketIOServer server = new SocketIOServer(config);

        server.addConnectListener(new ConnectListener() {
            @Override
            public void onConnect(SocketIOClient client) {
                System.out.println("client connected!: "+client.toString());
            }
        });

        server.addEventListener("myEvent", String.class, new DataListener<String>() {
            @Override
            public void onData(final SocketIOClient client, String data, final AckRequest ackRequest) {
                System.out.println("myEvent triggered");

                System.out.println("Here is the query from the client: \n"+data);

                ackRequest.sendAckData("I am the answer from the Server!");
            }
        });

        server.addDisconnectListener(new DisconnectListener() {
            @Override
            public void onDisconnect(SocketIOClient client) {
                System.out.println("client disconnected !: "+client.toString());
            }
        });

        server.start();
        System.out.println("server started");

        Thread.sleep(20000);//Integer.MAX_VALUE);

        server.stop();
        System.out.println("server stopped");
    }

}