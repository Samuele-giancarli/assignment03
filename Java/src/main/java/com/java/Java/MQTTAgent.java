package com.java.Java;

import java.util.UUID;
import java.nio.charset.StandardCharsets;

import com.hivemq.client.mqtt.datatypes.MqttQos;
import com.hivemq.client.mqtt.mqtt5.Mqtt5AsyncClient;
import com.hivemq.client.mqtt.mqtt5.Mqtt5BlockingClient.Mqtt5Publishes;
import com.hivemq.client.mqtt.mqtt5.Mqtt5Client;
import com.hivemq.client.mqtt.MqttGlobalPublishFilter;
import com.hivemq.embedded.EmbeddedHiveMQ;
import com.hivemq.embedded.EmbeddedHiveMQBuilder;

/*
 * MQTT Agent
 */
public class MQTTAgent {
	
	private static final String BROKER_ADDRESS = "broker.hivemq.com";
	private String mqtt_username = "S_Nova";
	private String mqtt_password = "T3LNer9*";	
	private static final String WATER_LEVEL_TOPIC = "water-level-topic";
	private static final String SYSTEM_STATE_TOPIC = "system-state-topic";

	Mqtt5AsyncClient client;

	public MQTTAgent() {
	}

	public void start() {

        final EmbeddedHiveMQBuilder embeddedHiveMQBuilder = EmbeddedHiveMQBuilder.builder();
        final EmbeddedHiveMQ hiveMQ = embeddedHiveMQBuilder.build();
        try {
            hiveMQ.start().join();
            System.out.println("MQTT broker launched correctly");
        } catch (final Exception e) {
            System.out.println("Error while launching");
            e.printStackTrace();
        }

		client = Mqtt5Client.builder()
				.identifier(UUID.randomUUID().toString())
                .serverHost(BROKER_ADDRESS)
                .buildAsync();
		

        client.publishes(MqttGlobalPublishFilter.ALL, publishedData ->{
            System.out.println(new String(publishedData.getPayloadAsBytes(), StandardCharsets.UTF_8));
        });
        client.connect();
        client.subscribeWith().topicFilter(WATER_LEVEL_TOPIC).qos(MqttQos.AT_LEAST_ONCE).send();
        System.out.println("Mu sono sottoscritto");
	}

	private void subscribeToTopics() {
		client.subscribeWith()
        .topicFilter(WATER_LEVEL_TOPIC)
        .callback(publish -> {
            System.out.println("arrivato" + publish);
        })
        .send()
        .whenComplete((subAck, throwable) -> {
            if (throwable != null) {
                // Handle failure to subscribe
            } else {
                // Handle successful subscription, e.g. logging or incrementing a metric
            }
        });
    }

    private void publishMessage() {
		client.publishWith()
        .topic(SYSTEM_STATE_TOPIC)
        .qos(MqttQos.EXACTLY_ONCE)
        .send()
        .whenComplete((mqtt3Publish, throwable) -> {
            if (throwable != null) {
                // Handle failure to publish
            } else {
                // Handle successful publish, e.g. logging or incrementing a metric
            }
        });
    }
	

	private void log(String msg) {
		System.out.println("[MQTT AGENT] "+msg);
	}

}
