package com.java.Java;

 import com.hivemq.client.mqtt.datatypes.MqttQos;
 import com.hivemq.client.mqtt.mqtt5.Mqtt5AsyncClient;
 import com.hivemq.client.mqtt.mqtt5.Mqtt5Client;
 
 import java.util.concurrent.TimeUnit;
 
 /**
  * Small completely asynchronous example.
  *
  * @author Silvio Giebl
  */
 public class AsyncDemo {
 
     public static void main(final String[] args) throws InterruptedException {
 
         final Mqtt5AsyncClient client = Mqtt5Client.builder().serverHost("broker.hivemq.com").buildAsync();
 
         client.connect()
                 .thenAccept(connAck -> System.out.println("connected " + connAck))
                 .thenCompose(v -> client.publishWith().topic("demo/topic/b").qos(MqttQos.EXACTLY_ONCE).send())
                 .thenAccept(publishResult -> System.out.println("published " + publishResult))
                 .thenCompose(v -> client.disconnect())
                 .thenAccept(v -> System.out.println("disconnected"));
 
         System.out.println("see that everything above is async");
         for (int i = 0; i < 5; i++) {
             TimeUnit.MILLISECONDS.sleep(50);
             System.out.println("...");
         }
     }
 }