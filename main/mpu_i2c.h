#ifndef __MPU6_I2C_H
#define __MPU6_I2C_H

// 根据错误提示，检查并修正头文件路径，若 i2c_master.h 不在 driver 目录下，需更新路径
// 假设 i2c_master.h 路径正确，仅作示例确认路径无误
#include "driver/i2c_master.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "esp_err.h"

#define MPU_SDA     7
#define MPU_SCL     8

#define MPU_ADDR        0x68        //设备地址,AD0->0时地址位0x68,AD0->1时地址位0x69,
#define MPU_SCL_SPEED   100000      //SCK时钟频率，100K




esp_err_t mpu_i2c_init();      //I2C 初始化         
esp_err_t mpu_write_byte(uint8_t reg,uint8_t byte); //I2C 写一byte数据
esp_err_t mpu_write_buf(uint8_t reg,uint16_t write_len,uint8_t *buf);//I2C 写一buf数据
uint8_t mpu_read_byte(uint8_t reg); //I2C 读byte数据
esp_err_t mpu_read_buf(uint8_t reg,uint16_t read_len,uint8_t *read_buf);    ////I2C 读一buf数据
#endif