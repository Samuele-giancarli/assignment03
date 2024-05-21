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
	maven {
        url("https://repo.eclipse.org/content/repositories/paho-snapshots/")
    }
}

dependencies {
	implementation("org.springframework.boot:spring-boot-starter-web")
	testImplementation("org.springframework.boot:spring-boot-starter-test")
	testRuntimeOnly("org.junit.platform:junit-platform-launcher")
	compile('org.eclipse.paho:org.eclipse.paho.client.mqttv3:1.0.2')
    compile('org.eclipse.paho:org.eclipse.paho.android.service:1.0.2')
}

tasks.withType<Test> {
	useJUnitPlatform()
}
