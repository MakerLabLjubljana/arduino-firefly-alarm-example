#include <ArduinoJson.h>
#include "FireFly.h"

int SerialMessageLength = 200;
char data[200] = {}; //serial buffer
int index = 0;
bool messageRead = false;
char moduleId[] = "568";

void setup() {
  Serial.begin(115200);
  Serial.println("Serial ready!");
  
  //delay(5000);
  FFSetSensors(moduleId, 1, 1, 1, 1, 1, 1);
  FFContinuousResponse(moduleId, "4", "01");
}

void loop() {
  //Read sensor response
  while(Serial.available() > 0){
    //reading serial from FF1502 BLE module
    if(index < SerialMessageLength){
      data[index] = Serial.read();
      //Serial.print(data[index]);
      if(index == 0){
        if(data[index] == '!'){
          data[index] = ' ';
          index++;
        }
      }else{
        if(data[index] == '?'){ //Response message end
          data[index] = ' \0';
          index = 0;
          messageRead = true;
        }else if(data[index] == '!'){ //Response message start
          data[0] == ' ';
          index=1;
        }else{
          index++;
        }
      }
    }else{
      index = 0;
    }
    if(messageRead == true){
      Serial.println("message read");
      messageRead = false;
      
      StaticJsonBuffer<200> jsonBuffer;
      JsonObject& root = jsonBuffer.parseObject(data);

      if (!root.success()){
        Serial.println("parseObject() failed");
        return;
      }
      //here you extract parsed json data like you would from a table
      /*
      int lux = root["d"]["Lum"];
      float temp = root["d"]["Temp"];
      float hum = root["d"]["RelHum"];
      const char* id = root["d"]["ID"].asString();
      float gx = root["d"] ["gX"];
      float gy = root["d"] ["gY"];
      float gz = root["d"] ["gZ"];
      float ax = root["d"] ["aX"];
      float ay = root["d"] ["aY"];
      float az = root["d"] ["aZ"];
      float mx = root["d"] ["mX"];
      float my = root["d"] ["mY"];
      float mz = root["d"] ["mZ"];
      int analog = root["d"] ["Analog"]; //p0.26
      int button = root["d"] ["Button"];
      */
      int accthr = root["d"] ["AccThr"];

      Serial.println(accthr);
      //here you write values into fields of your ThingSpeak channel
      String data = "Alarm Status = "+String(accthr);
      //Serial.println(data);

      data[0] = '\0'; //clear data array
      data[0] = (char)0; //Just to be sure :D
      break;
    } 
  }
}
