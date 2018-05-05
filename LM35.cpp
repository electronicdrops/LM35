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

LM35::~LM35(){}

LM35::LM35(int t_pin):m_sensor_pin(t_pin){}

LM35::LM35(int t_pin, int t_resolution, int t_adc, float t_voltage) : m_sensor_pin(t_pin), m_resolution(t_resolution),m_adc_reference(t_adc), m_voltage_reference(t_voltage){}

void LM35::begin(){}

void LM35::update(){

  float values = 0;

  for (int i = 0; i < m_resolution; i++){
    values += analogRead(m_sensor_pin);
  }
  values /= m_resolution;
  m_milivolts = ( values / m_adc_reference) * (m_voltage_reference * 1000);
  
  m_temperature = m_milivolts / 10;

  checkAlarm();
  
}

float LM35::getTemperature(){
  return m_temperature;
}

float LM35::getTemperature(char scale){
    switch (scale){
    case 'C':
        return m_temperature;
      break;
    case 'K':
        return (m_temperature + 273);
      break;
    case 'F':
        return ((m_temperature * 1.8) + 32);    
      break;
  }
}

float LM35::getMilivolts(){
  return m_milivolts;
}

void LM35::setPin(int t_pin){
  m_sensor_pin = t_pin;
}

boolean LM35::setResolution(int t_resolution){
  if (t_resolution <= 0) {
    return false;
  }
  
  m_resolution = t_resolution;
  return true;
}

void LM35::setAdcReference(int t_adc){
  m_adc_reference = t_adc;
}

void LM35::setVoltageReference(float t_voltage){
  m_voltage_reference = t_voltage;
}

void LM35::checkAlarm(){
    if (m_temperature >= m_temp_alarm_high){
    m_alarm_high = 1;
  } else {
    m_alarm_high = 0;
  }
  if (m_temperature <= m_temp_alarm_low){
    m_alarm_low = 1;
  } else {
    m_alarm_low = 0;
  }
}

boolean LM35::setHighLimitAlarm(float t_temp){
  
  if (t_temp < LM35_MIN_TEMPERATURE || t_temp > LM35_MAX_TEMPERATURE){
    return false;
  }

  m_temp_alarm_high = t_temp;
  return true;  
}

boolean LM35::setLowLimitAlarm(float t_temp){
  
  if (t_temp < LM35_MIN_TEMPERATURE || t_temp > LM35_MAX_TEMPERATURE){
    return false;
  }

  m_temp_alarm_low = t_temp;
  return true;
}

boolean LM35::getHighAlarm(){
  return m_alarm_high;
}

boolean LM35::getLowAlarm(){
  return m_alarm_low;
}
