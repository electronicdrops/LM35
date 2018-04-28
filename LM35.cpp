/*
 * LM35.cpp - LM35 sensor library for microcontrollers  version 1.0
 * 
 * author Danilo Queiroz Barbosa
 * member of electronicdrops.com
 * daniloqb@electronicdrops.com
 * 
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * 
 * This library intended to facilitate the use of LM35 temperature sensor with microcontrollers
 * 
 * 
 */

#include "Arduino.h"
#include "LM35.h"


LM35::LM35(int pin_, int resolution_) {

  sensor_pin = pin_;
  resolution = resolution_;
  adc_reference = LM35_ADC_REF;
  voltage_reference = LM35_VOL_REF;
  tempAlarmHigh = LM35_MAX_TEMPERATURE;
  tempAlarmLow = LM35_MIN_TEMPERATURE;  
}

LM35::LM35(int pin_, int resolution_, int adc_, float voltage_){
  sensor_pin = pin_;
  resolution = resolution_;
  adc_reference = adc_;
  voltage_reference = voltage_; 
  tempAlarmHigh = LM35_MAX_TEMPERATURE;
  tempAlarmLow = LM35_MIN_TEMPERATURE;  
}

void LM35::begin(){
  
}

void LM35::update(){

  float values = 0;

  for (int i = 0; i < resolution; i++){
    values += analogRead(sensor_pin);
  }
  values /= resolution;
  milivolts = ( values / adc_reference) * (voltage_reference * 1000);
  
  temperature = milivolts / 10;

  checkAlarm();
  
}

float LM35::getTemperature(char scale){
    switch (scale){
    case 'C':
        return temperature;
      break;
    case 'K':
        return (temperature + 273);
      break;
    case 'F':
        return ((temperature * 1.8) + 32);    
      break;
  }
}

float LM35::getMilivolts(){
  return milivolts;
}
    


void LM35::setPin(int pin_){
  sensor_pin = pin_;
}

boolean LM35::setResolution(int resolution_){
  if (resolution <= 0) {
    return false;
  }
  
  resolution = resolution_;
  return true;
}

void LM35::setAdcReference(int adc_){
  adc_reference = adc_;
}

void LM35::setVoltageReference(float voltage_){
  voltage_reference = voltage_;
}


void LM35::checkAlarm(){
    if (temperature >= tempAlarmHigh){
    alarmHigh = 1;
  } else {
    alarmHigh = 0;
  }
  if (temperature <= tempAlarmLow){
    alarmLow = 1;
  } else {
    alarmLow = 0;
  }
}

boolean LM35::setHighLimitAlarm(float temp){
  
  if (temp < LM35_MIN_TEMPERATURE || temp > LM35_MAX_TEMPERATURE){
    return false;
  }

  tempAlarmHigh = temp;
  return true;
  
}

boolean LM35::setLowLimitAlarm(float temp){
  
  if (temp < LM35_MIN_TEMPERATURE || temp > LM35_MAX_TEMPERATURE){
    return false;
  }

  tempAlarmLow = temp;
  return true;
  
}

boolean LM35::getHighAlarm(){
  return alarmHigh;
}

boolean LM35::getLowAlarm(){
  return alarmLow;
}


