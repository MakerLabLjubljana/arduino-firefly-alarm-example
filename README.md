<b>arduino-firefly-alarm-example</b><br>
Arduino sketch example, displaying the use of FireFly sensor tag for accelerometer alarm detection.

<b>Info:</b><br>
An example sketch featuring the process of reading data from a FireFly(www.firefly-iot.com)
sensor board and sending it to a ThingSpeak channel.

This example was created by Anže Kožar(@nzkozar) for Makerlab Ljubljana(www.maker.si)
and adapted from code by L-Tek Elektronika(http://www.l-tek.si)

This example was tested on Arduino Uno and Arduino Mega ADK using a Ethernet Shield and an XBee shield.

 <br>
 <b>FireFly communication functions:</b><br>
 <ul>
 
<li><b>void FFContinuousResponse(char id[3], char timeRange[1], char interval[2])</b>
  <br>
  With this message you can request data from a node
  and you will get sensor data as return continuously
  with interval you've written.<br>
  
  First field of the function is ID
  of the node you want data from for node FF-K12 id would be K12.<br>
  
  Next named timeRange id the unit of measurement you want:<br>
      4 meaning miliseconds<br>
      3 meaning seconds<br>
      2 meaning minutes<br>
      1 meaning hours<br>
  
  and interval is the time interval you want<br>
  05 would mean 5 units of measurement<br>

  NOTE: if you pick miliseconds as timeRange 01 mean 100 miliseconds and 10 means 1 second
  writing 3 as timeRange and 05 as interval would mean you will get data every 5 seconds<br>
  NOTE 1: if you want to  have an interval which is described with only 1 number like 9 you have to write 0 infront
  due to the protocol. Mmeaning 1 would be 01 always use 2 characters.<br>
</li>


<li><b>void FFKillContinuous(char id[3])</b>
  </br>
  With this message you can kill continuous response from a specific FlyTag.<br>
  Here you only write the id of the node you want to stop responding for node FF-K12 id would be K12
</li>

<li><b>void FFRespondOnce(char id[3])</b>
  </br>
  With this message you can get data from a specific FlyTag node but you will only get it once.<br>
  Here you only write the id of the node you want to get data from for node FF-K12 id would be K12.
</li>

<li><b>void FFSetSensors(char id[3], int lux, int rh, int temp, int mag, int accel, int gyro)</b><br>
  With this message you can turn on/off sensors on a node.<br>

  First field of the function os id of the FlyTag node for example FF-K12 you will write K12, capital letters are important!<br>
  
  Set value to 1 if you want sensor to be on 0 for it to be off.<br>
  
  NOTE: Here, if the value you select specifies only humidity sensor
  to be turned on, any other sensor that is currently turned on, will be turned off when
  you send this command.
</li>

<li><b>void FFSetOutput(char id[3], int LED1, int LED2, int LED3, int p0_15, int p0_27)</b><br>
  First field of the function os id of the FlyTag node for example FF-K12 you will write K12, capital letters are important!<br>
  
  Parameters you can change are:<br>
  -LED1 //turns LED1 ON or OFF (0 means on 1 means off)<br>
  -LED2 //turns LED2 ON or OFF (0 means on 1 means off)<br>
  -LED3 //turns LED3 ON or OFF (0 means on 1 means off)<br>
  -p0_15 //writes value to pin p0-15 (you can set it to 0 or 1)<br>
  -p0_27 //writes value to pin p0-27 (you can set it to 0 or 1)<br>
</li>
