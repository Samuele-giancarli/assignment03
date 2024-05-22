package com.java.Java;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.web.servlet.support.SpringBootServletInitializer;

import com.java.Java.mqtt.MqttController;


@SpringBootApplication
public class JavaApplication extends SpringBootServletInitializer {

	public static void main(String[] args) {
		MqttController mqttController = new MqttController();
        mqttController.start();

        SpringApplication.run(JavaApplication.class, args);
        
	}

}