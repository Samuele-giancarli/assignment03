package com.java.Java.message;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.atomic.AtomicInteger;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.java.Java.state.StateController;


@RestController
@RequestMapping("/api/messages")
public class SpringMessageController {

    private final AtomicInteger counter = new AtomicInteger();
    private MessageController messageController = new MessageController();
    private StateController stateController = new StateController();
    private final List<SpringMessage> messages = new ArrayList<>();

    @GetMapping("/levels")
    public List<SpringMessage> getLevelsMap() {
        messages.clear();
        messageController.getLevels().forEach((k,v) -> {
            messages.add(new SpringMessage(counter.incrementAndGet(), v, k));
        });;
        return messages;
    }

    @GetMapping("/state")
    public String getSystemState() {
        return stateController.getStatEnum().name();
    }

    @GetMapping("/angle")
    public int getOpenAngle() {
        return 1;
    }

    @GetMapping("/mode")
    public int getSystemMode() {
        return 1;
    }

}
