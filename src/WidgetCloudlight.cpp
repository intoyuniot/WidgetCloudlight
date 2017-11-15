#include "WidgetCloudlight.h"


WidgetCloudlight::WidgetCloudlight(uint8_t ucItem)
{
    _Item=ucItem;
    memset(pCmdSwitchTopic,0,sizeof(pCmdSwitchTopic));
    memset(pDataStatusTopic,0,sizeof(pDataStatusTopic));
    sprintf(pCmdSwitchTopic,"channel/cloudLight_%d/cmd/switch",_Item);
    sprintf(pDataStatusTopic,"channel/cloudLight_%d/data/status",_Item);
}

WidgetCloudlight::~WidgetCloudlight()
{

}

void WidgetCloudlight::begin(void (*UserCallBack)(void))
{
    _EventCb=UserCallBack;
    IntoRobot.subscribe(pCmdSwitchTopic, NULL, this);
}

char WidgetCloudlight::getCloudSwitch(void)
{
    return _switchKey;
}

void WidgetCloudlight::displayCloudStatus(uint8_t ucVal)
{
    IntoRobot.publish(pDataStatusTopic,ucVal);
}

void WidgetCloudlight::control(uint8_t ucPin, uint8_t ucVal)
{
    pinMode(ucPin,OUTPUT);
    digitalWrite(ucPin, ucVal);
    displayCloudStatus(ucVal);
}

void WidgetCloudlight::widgetBaseCallBack(uint8_t *payload, uint32_t len)
{
    if(payload[0] == '1')
    {
        _switchKey=1;
    }
    else
    {
        _switchKey=0;
    }
    _EventCb();
}
