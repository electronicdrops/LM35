/*
 * LM35.h - LM35 sensor library for microcontrollers  version 1.0
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


#ifndef LM35_H
#define LM35_H


#include "Arduino.h"

#define LM35_RESOLUTION 16
#define LM35_ADC_REF 1024.0
#define LM35_VOL_REF 5.0

#define LM35_MAX_TEMPERATURE 150
#define LM35_MIN_TEMPERATURE -55

class LM35{

  private:
    float temperature;
    float milivolts;

    int sensor_pin;
    int resolution;
    int adc_reference;
    float voltage_reference;

    float tempAlarmHigh;
    float tempAlarmLow;
    boolean alarmHigh;
    boolean alarmLow;

    void checkAlarm();

  public:


    LM35(int pin_, int resolution_= LM35_RESOLUTION);
    LM35(int pin_, int resolution_, int adc_, float voltage_); 
    
    float getTemperature(char scale='C');
    float getMilivolts();
    
    void setPin(int pin_);
    boolean setResolution(int resolution_);
    void setAdcReference(int adc_);
    void setVoltageReference(float voltage_);

    boolean setHighLimitAlarm(float temp);
    boolean setLowLimitAlarm(float temp);
    boolean getHighAlarm();
    boolean getLowAlarm();

    
    void update();
    void begin();
  
};








#endif
