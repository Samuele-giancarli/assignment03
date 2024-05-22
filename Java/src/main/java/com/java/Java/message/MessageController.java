package com.java.Java.message;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;

import com.java.Java.state.StateController;


public class MessageController {

    private Map<String,Integer> levels = new HashMap<>();
    private static final Integer MAX_SIZE = 30;
    private StateController state = new StateController();

    public Map<String,Integer> getLevels() {
        return levels;
    }

    //EspMessageParser
    public void EspReceive(String msg) {
        Integer waterLevel = Integer.valueOf(msg);
        
        state.setState(waterLevel);

        Date date = new Date();
        SimpleDateFormat sdf = new SimpleDateFormat("MM/dd/yyyy h:mm:ss a");
        String formattedDate = sdf.format(date);

        levels.put(formattedDate, waterLevel);
        mapSizeCheck();
    }

    public String EspSend() {
        return state.getStatEnum().name();
    }

    private void mapSizeCheck() {
        if(levels.size()>MAX_SIZE) {
            levels.clear();
        }
    }

}
