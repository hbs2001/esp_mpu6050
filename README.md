
# ESP32 MPU6050 Example

## 项目介绍
因为乐鑫官方的mpu6050的demo使用的是旧版的I2C驱动，在添加到最近项目中出现了兼容问题，因此使用新版的I2C驱动重新编写了mpu6050的demo。

## How to use example

1. 下载项目代码
2. 连接MPU6050模块到ESP32模块（本例程使用的是ESP32-P4，SCL链接GPIO8，SDA链接GPIO7，可在mpu_i2c.h中修改）
3. 编译并烧录项目代码
4. 运行项目代码

ps：使用IDF版本为5.4.1，使用的开发板是ESP32-P4-Function-EV-Board