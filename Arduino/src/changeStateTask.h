#ifndef __CHANGESTATETASK__
#define __CHANGESTATETASK__

class ChangeStateTask {

    public:
    ChangeStateTask();

    void init();

    void setAngle(int newAngle);
    int getAngle();

    void setStateAutomatic();
    bool isStateAutomatic();

    void setStateManual();
    bool isStateManual();

    private:
    enum {MAN, AUTO} state;
    double currentAngle;

};

#endif