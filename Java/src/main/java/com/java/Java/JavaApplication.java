package com.java.Java;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class JavaApplication extends SpringBootServletInitializer {

	@Autowired
	Runnable MessageListener;

	@Override
	protected SpringApplicationBuilder configure(SpringApplicationBuilder application) {
		return application.sources(Application.class);
	}

	public static void main(String[] args) {
		SpringApplication.run(JavaApplication.class, args);
	}

	@Bean
	public CommandLineRunner schedulingRunner(TaskExecutor executor) {
	   return new CommandLineRunner() {
		  public void run(String... args) throws Exception {
			 executor.execute(MessageListener);
		  }
	   };
	}

}
