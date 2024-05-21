package main.java.com.java.Java.Mqtt;

@Component
public class MqttPublisherImpl extends MqttConfig implements MqttCallback{

    private static final Logger logger = LoggerFactory.getLogger(MqttPublisherImpl.class);

   
    private MqttPublisherImpl() {
        this.config();
    }
    private MqttPublisherImpl(String broker, Integer port, Boolean ssl) {
        this.config(broker, port, ssl);
    }
   public static MqttPublisherImpl getInstance() {
        return new MqttPublisherImpl();
    }

   
    public static MqttPublisherImpl getInstance(String broker, Integer port, Boolean ssl) {
        return new MqttPublisherImpl(broker, port, ssl);
    }

    @Override
    public void publishMessage(String topic, String message) {

        try {
            MqttMessage mqttmessage = new MqttMessage(message.getBytes());
            mqttmessage.setQos(this.qos);
            mqttmessage.setRetained(false);
            this.mqttClient.publish(topic, mqttmessage);
        } catch (MqttException me) {
            logger.error("ERROR", me);
        }
        return;
    }

    @Override
    public void disconnect() {
        try {
            this.mqttClient.disconnect();
        } catch (MqttException me) {
            logger.error("ERROR", me);
        }
    }

    @Override
    public void connectionLost(Throwable arg0) {
        logger.info("Connection Lost");

    }

    @Override
    public void deliveryComplete(IMqttDeliveryToken arg0) {
        logger.info("delivery completed");

    }

    
    @Override
    public void messageArrived(String arg0, MqttMessage arg1) throws Exception {
        // Leave it blank for Publisher

    }@Override
    protected void config(String broker, Integer port, Boolean ssl) {
        // Like we did in MqttSubscribe
    }

    @Override
    protected void config() {
      // Like we did in MqttSubscribe       
    }
   

    }