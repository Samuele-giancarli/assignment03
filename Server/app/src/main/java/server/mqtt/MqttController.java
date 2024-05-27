package server.mqtt;

import java.nio.charset.StandardCharsets;
import java.util.UUID;

import com.hivemq.client.mqtt.MqttGlobalPublishFilter;
import com.hivemq.client.mqtt.datatypes.MqttQos;
import com.hivemq.client.mqtt.mqtt5.Mqtt5AsyncClient;
import com.hivemq.client.mqtt.mqtt5.Mqtt5Client;
import com.hivemq.embedded.EmbeddedHiveMQ;
import com.hivemq.embedded.EmbeddedHiveMQBuilder;

public class MqttController {
    private static final String BROKER_ADDRESS = "broker.hivemq.com";
	private static final String WATER_LEVEL_TOPIC = "water-level-topic";

    private static Mqtt5AsyncClient client;

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
}
