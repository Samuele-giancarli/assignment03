package com.java.Java;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.web.servlet.support.SpringBootServletInitializer;


@SpringBootApplication
public class JavaApplication extends SpringBootServletInitializer {

	public static void main(String[] args) {
		MQTTAgent agent = new MQTTAgent();
        agent.start();
        SpringApplication.run(JavaApplication.class, args);
        
		System.out.println("Hello, i'm in main");
	}

}