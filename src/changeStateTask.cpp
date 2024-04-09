#include "ChangeStateTask.h"
#include "Config.h"

ChangeStateTask::ChangeStateTask() {
}

void ChangeStateTask::init() {
    /* setta tutti i device che deve usare. E' da qui che prende le info dei vari device per fare i calcoli*/
}

void ChangeStateTask::setAngle(int newAngle) {
    this->currentAngle = newAngle;
}   

int ChangeStateTask::getAngle() {
    return this->currentAngle;
}

void ChangeStateTask::setStateAutomatic() {
    state=AUTO;
}
bool ChangeStateTask::isStateAutomatic(){
    return state==AUTO;
}

void ChangeStateTask::setStateManual(){
    state=MAN;
}
bool ChangeStateTask::isStateManual(){
    return state==MAN;
}