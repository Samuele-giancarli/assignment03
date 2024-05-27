package server.state;

public class StateController {

    private StateEnum currStatEnum = StateEnum.NORMAL;
    
    public StateController() {
    }

    public void setState(Integer waterLevel) {
        if (waterLevel >= 0 && waterLevel < 10) {
            currStatEnum = StateEnum.ALARMTOOHIGHCRITIC;
        } else if (waterLevel >= 10 && waterLevel < 20) {
            currStatEnum = StateEnum.ALARMTOOHIGH;
        } else if (waterLevel >= 20 && waterLevel < 30) {
            currStatEnum = StateEnum.PREALARMTOHIGH;
        } else if (waterLevel >= 30 && waterLevel < 40) {
            currStatEnum = StateEnum.NORMAL;
        } else if (waterLevel >= 40 && waterLevel < 50) {
            currStatEnum = StateEnum.ALARMTOOLOW;
        }
    }

    public StateEnum getStatEnum() {
        return currStatEnum;
    }

}
