/*
  with this message you can request data from a node
  and you will get sensor data as return continuously
  with interval you've written
  
  First field of the function is ID
  of the node you want data from for node FF-K12 id would be K12
  
  next named timeRange id the unit of measurement you want:
      4 meaning miliseconds
      3 meaning seconds
      2 meaning minutes
      1 meaning hours
  
  and interval is the time interval you want
  05 would mean 5 units of measurement

  NOTE: if you pick miliseconds as timeRange 01 mean 100 miliseconds and 10 means 1 second

  writing 3 as timeRange and 05 as interval would mean you will get data every 5 seconds
  
   NOTE: if you want to  have an interval which is described with only 1 number like 9 you have to write 0 infront
   due to the protocol. Mmeaning 1 would be 01 always use 2 characters.
 */
void FFContinuousResponse(char id[3], char timeRange[1], char interval[2]) {
    delay(5000);
    Serial.print("\n");
    Serial.print(id);
    Serial.print(1);
    Serial.print(timeRange);
    Serial.print(interval);
    Serial.print("\r");
}

/*
  with this message you can kill continuous response from a specific FlyTag
  
  here you only write the id of the node you want to stop responding for node FF-K12 id would be K12
 */
void FFKillContinuous(char id[3]) {
    delay(5000);
    Serial.print("\n");
    Serial.print(id);
    Serial.print(2);
    Serial.print("xxx");
    Serial.print("\r");
}

/*
  with this message you can get data from a specific FlyTag node but you will only get it once.
  
  here you only write the id of the node you want to get data from for node FF-K12 id would be K12
 */
void FFRespondOnce(char id[3]) {
    delay(5000);
    Serial.print("\n");
    Serial.print(id);
    Serial.print(0);
    Serial.print("xxx");
    Serial.print("\r");
}

/*
  with this message you can turn on/off sensors on a node

  First field of the function os id of the FlyTag node for example FF-K12 you will write K12, capital letters are important!
  
  Set value to 1 if you want sensor to be on 0 for it to be off.
  
  NOTE here, if the value you select here specifies only humidity sensor
  to be turned on, any other sensor that is currently turned on, will be turned off when
  you send this command
 */
void FFSetSensors(char id[3], int lux, int rh, int temp, int mag, int accel, int gyro) {
    delay(5000);
    Serial.print("\n");
    Serial.print(id);
    Serial.print(4);
    int sensors = 0;
    sensors = sensors | (lux   << 0);
    sensors = sensors | (rh    << 1);
    sensors = sensors | (temp  << 2);
    sensors = sensors | (mag   << 3);
    sensors = sensors | (accel << 4);
    sensors = sensors | (gyro  << 5);
    sensors = sensors | (1 << 6);
    Serial.print(char(sensors));
    Serial.print("xx\r");
}

/*
  First field of the function os id of the FlyTag node for example FF-K12 you will write K12, capital letters are important!
  
  parameters you can change are:
  
  LED1 //turns LED1 ON or OFF (0 means on 1 means off)
  LED2 //turns LED2 ON or OFF (0 means on 1 means off)
  LED3 //turns LED3 ON or OFF (0 means on 1 means off)
  p0_15 //writes value to pin p0-15 (you can set it to 0 or 1)
  p0_27 //writes value to pin p0-27 (you can set it to 0 or 1)
 */
void FFSetOutput(char id[3], int LED1, int LED2, int LED3, int p0_15, int p0_27) {
    delay(5000);
    Serial.print("\n");
    Serial.print(id);
    Serial.print(3);
    int output = 0;
    output = output | (LED1   << 0);
    output = output | (LED2   << 1);
    output = output | (LED3   << 2);
    output = output | (p0_15  << 3);
    output = output | (p0_27  << 4);
    output = output | (1 << 6);
    Serial.print(char(output));
    Serial.print("xx\r");
}

