#ifndef WIDGET_CLOUDLIGHT_H_
#define WIDGET_CLOUDLIGHT_H_

#include "application.h"

class WidgetCloudlight: public WidgetBaseClass
{
    public:
        WidgetCloudlight(uint8_t ucItem = 0);
        ~WidgetCloudlight();
        void begin(void (*UserCallBack)(void) = NULL);
        char getCloudSwitch(void);
        void displayCloudStatus(uint8_t ucVal);
        void control(uint8_t ucPin, uint8_t ucVal);

    private:
        char pCmdSwitchTopic[64];
        char pDataStatusTopic[64];
        char _switchKey = 0;
        uint8_t _Item = 0;
        void (*_EventCb)(void);
        void widgetBaseCallBack(uint8_t *payload, uint32_t len);
};

#endif
