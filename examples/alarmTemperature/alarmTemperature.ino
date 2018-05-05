/*
 * alarmTemperature.ino - Example of LM35 library use

 * author Danilo Queiroz Barbosa
 * member of electronicdrops.com
 * daniloqb@electronicdrops.com
 * 2018-04-28
 * 
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * 
 * This sketch is a simple example of how to use alarm functions
 * When high temperature is reach pin 10 is activated.
 * Only will be deactivated when low temperature is reached.
 * 
 */

#include "LM35.h"

LM35 sensor = LM35(A0);

int  lamp_alarm = 10;

boolean state = 0;

void setup() {
  Serial.begin(9600);
  sensor.begin();

  sensor.setHighLimitAlarm(30.0);
  sensor.setLowLimitAlarm(25.0);

  pinMode(lamp_alarm,10);
  digitalWrite(lamp_alarm,LOW);
}

void loop() {
  float temperature;
  
  sensor.update();
  temperature = sensor.getTemperature();

  Serial.print("Temperature: ");
  Serial.println(temperature);

  if (state == 0 && sensor.getHighAlarm() == 1){
    state = 1;
    digitalWrite(lamp_alarm,HIGH); 
    Serial.println("Temperature is High");
  } else{
    if (state == 1 && sensor.getLowAlarm() == 1){
      state = 0;
      digitalWrite(lamp_alarm,LOW);
      Serial.println("Normal Operation");
    }
  } 

  Serial.println();

delay(1000);

}
