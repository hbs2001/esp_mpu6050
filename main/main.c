#include <stdio.h>
#include "esp_log.h" 
#include"freertos/FreeRTOS.h"
#include"freertos/task.h"
#include "mpu60xx.h"

static const char* TAG = "Main";

void mpu60xx_test(void)
{
    // float pitch=0,roll=0,yaw=0;                 //娆ф媺瑙?
	short aacx,aacy,aacz;		//加速度传感器原始数据
	short gyrox,gyroy,gyroz;	//陀螺仪原始数据
	float temp;					//温度	
	
    if(mpu60xx_get_accelerometer(&aacx,&aacy,&aacz)==ESP_OK){
        temp=mpu60xx_get_temperature();	//得到温度值
        //mpu60xx_get_accelerometer(&aacx,&aacy,&aacz);	//得到加速度传感器数据
        mpu60xx_get_gyroscope(&gyrox,&gyroy,&gyroz);	//得到陀螺仪数据
        printf("Temp=%.02f,AccX=%0d,AccY=%0d,AccZ=%0d,GyroX=%0d,GyroY=%0d,GyroZ=%0d\r\n",temp,aacx,aacy,aacz,gyrox,gyroy,gyroz);
    }
}
void app_main(void)
{
	while(mpu60xx_init())
    {
        vTaskDelay(pdMS_TO_TICKS(500));
        ESP_LOGI(TAG,"mpu init failed");
    }
     while(1)
    {    
    	mpu60xx_test();
        vTaskDelay(pdTICKS_TO_MS(10));
   }
}