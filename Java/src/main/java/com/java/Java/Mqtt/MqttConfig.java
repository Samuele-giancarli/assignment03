package main.java.com.java.Java.Mqtt;

public abstract class MqttConfig {
   
    protected final String broker = "broker.mqtt-dashboard.com";
    protected final int qos = 1;
    protected Boolean hasSSL = false; /*By default SSL is disabled */
    protected Integer port = 1883; /* Default port */
    protected final String HTTP = "http://";
 
    /**
     * Custom Configuration
     * 
     * @param broker
     * @param port
     * @param ssl
     * @param withUserNamePass
     */
    protected abstract void config(String broker, Integer port, Boolean ssl, Boolean withUserNamePass);
 
    /**
     * Default Configuration
     */
    protected abstract void config();
    
 
 }