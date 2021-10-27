# ESP-32_GC9A01_JPG
ESP32驱动GC9A01圆形屏幕显示图片/视频/时间  

![img](https://github.com/Myzhazha/ESP-32_GC9A01_JPG/blob/main/img/4.jpg)  
  
图片及视频  
在SD卡根目录创建一个img文件夹，把图片用工具裁剪/缩放成240x240大小，把图片放进img目录  
可以放多个图片，会每隔5秒自动更换，图片显示时长在JpegClass.ino文件的第110行代码更改，单位MS  
需要Arduino IDE并安装ESP32库和Arduino_GFX_Library库  


屏幕GND对应开发板GND  
屏幕VCC对应开发板3.3  
屏幕SCL对应开发板D14  
屏幕SDA对应开发板D15  
屏幕RES对应开发板D33  
屏幕DC对应开发板D27  
屏幕CS对应开发板D5  
屏幕BLK对应开发板D22  
  
SD卡GND对应开发板GND  
SD卡VCC对应开发板VIN  
SD卡MISO对应开发板D2  
SD卡MOSI对应开发板D15（和屏幕共用）  
SD卡SCK对应开发板D14（和屏幕共用）  
SD卡CS对应开发板D13  

![img](https://github.com/Myzhazha/ESP-32_GC9A01_JPG/blob/main/img/0.jpg)  

![img](https://github.com/Myzhazha/ESP-32_GC9A01_JPG/blob/main/img/1.jpg)  


![img](https://github.com/Myzhazha/ESP-32_GC9A01_JPG/blob/main/img/2.jpg)  

![img](https://github.com/Myzhazha/ESP-32_GC9A01_JPG/blob/main/img/3.jpg)  
