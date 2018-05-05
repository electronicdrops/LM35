/*
 * getTemperature.ino - Example of LM35 library use

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
 * This sketch is a simple example. LM35 is connected on A0 pin.
 * 
 * 
 */

#include "LM35.h"

LM35 sensor = LM35(A0);

void setup() {
  Serial.begin(9600);
  sensor.begin();
}

void loop() {
sensor.update();
Serial.println("Reading Temperature");
Serial.println();

Serial.print(sensor.getTemperature());
Serial.println('C');

Serial.print(sensor.getTemperature('F'));
Serial.println('F');

Serial.print(sensor.getTemperature('K'));
Serial.println('K');

Serial.println();

delay(1000);

}
