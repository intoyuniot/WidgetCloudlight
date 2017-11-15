/*
 ************************************************************************
 * 作者:  IntoRobot Team
 * 版本:  V1.0.0
 * 日期:  16-11-15
 ************************************************************************
 功能描述：
 雷电云：雷声与闪电效果

 所需器件:
 1. RGB LED灯条（灯条所需电流较大需单独供电，建议5V2A电源）

 接线说明：
 灯条                         核心板
 1.GND                        GND
 2.DATA                       D0

 此例程目前只支持Atom核心板，但库不受限制
 */


/*This #include statement was automatically added by the IntoRobot IDE.*/
#include <Adafruit_NeoPixel.h>
#include <WidgetCloudlight.h>


#define PIXEL_PIN 		D0    //定义数据引脚
#define PIXEL_COUNT 	12     //定义RGB LED的数量
#define PIXEL_TYPE	 	WS2811 //定义RGB LED的驱动类型

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);
WidgetCloudlight cloud = WidgetCloudlight();


void cloudLight(void)
{
    Process p;
    p.begin("madplay");
    p.addParameter("/root/2629.mp3");
    p.addParameter("&");
    p.runAsynchronously();
    if (p.running())
    {
        delay(200);
    }

    for (int i = 0; i < 6; i++)
    {
        strip.setPixelColor(i, 255, 255, 255);
    }

    strip.show();
    delay(500);
    for (int i = 0; i < 6; i++)
    {
        strip.setPixelColor(i, 0, 0, 0);
    }
    strip.show();
    delay(200);

    for (int i = 6; i < 12; i++)
    {
        strip.setPixelColor(i, 255, 255, 255);
    }

    strip.show();
    delay(500);

    for (int i = 6; i < 12; i++)
    {
        strip.setPixelColor(i, 0, 0, 0);
    }

    strip.show();
    delay(200);

    for (int i = 0; i < 4; i++)
    {
        strip.setPixelColor(i, 255, 255, 255);
    }

    strip.show();
    delay(400);
    for (int i = 0; i < 4; i++)
    {
        strip.setPixelColor(i, 0, 0, 0);
    }
    strip.show();
    delay(100);


    for (int i = 0; i < 12; i++)
    {
        strip.setPixelColor(i, 255, 255, 255);
    }

    strip.show();
    delay(600);

    for (int i = 0; i < 12; i++)
    {
        strip.setPixelColor(i, 0, 0, 0);
    }

    strip.show();
    delay(1000);


    for (int i = 8; i < 12; i++)
    {
        strip.setPixelColor(i, 255, 255, 255);
    }

    strip.show();
    delay(400);
    for (int i = 8; i < 12; i++)
    {
        strip.setPixelColor(i, 0, 0, 0);
    }
    strip.show();
    delay(300);

    for (int i = 4; i < 8; i++)
    {
        strip.setPixelColor(i, 255, 255, 255);
    }

    strip.show();
    delay(500);
    for (int i = 4; i < 8; i++)
    {
        strip.setPixelColor(i, 0, 0, 0);
    }
    strip.show();
    delay(1000);
}

void cloudCb(void)
{
    if(cloud.getCloudSwitch())
    {
        cloud.displayCloudStatus(1);
        cloudLight();
        cloud.displayCloudStatus(0);
    }
}

void setup()
{
    //初始化灯条
    strip.begin();
    strip.setBrightness(255);
    strip.show();
    cloud.begin(cloudCb);
}

void loop()
{

}
