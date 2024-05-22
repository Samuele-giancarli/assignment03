plugins {
	java
	id("org.springframework.boot") version "3.2.5"
	id("io.spring.dependency-management") version "1.1.4"
}

group = "com.java"
version = "0.0.1-SNAPSHOT"

java {
	sourceCompatibility = JavaVersion.VERSION_17
}

repositories {
	mavenCentral()
}

dependencies {
	implementation("org.springframework.boot:spring-boot-starter-web")
	testImplementation("org.springframework.boot:spring-boot-starter-test")
	testRuntimeOnly("org.junit.platform:junit-platform-launcher")

	implementation("io.vertx:vertx-core:4.5.7")
	implementation("io.netty:netty-all:4.1.109.Final")
	implementation("io.vertx:vertx-mqtt:4.5.7")
	implementation("io.vertx:vertx-ext:38")

  	implementation("com.hivemq:hivemq-mqtt-client:1.3.0")
	implementation("com.hivemq:hivemq-community-edition-embedded:2024.3")

}

tasks.withType<Test> {
	useJUnitPlatform()
}
