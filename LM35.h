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
#define LM35_ADC_REF 1024
#define LM35_VOL_REF 5.0

#define LM35_MAX_TEMPERATURE 150
#define LM35_MIN_TEMPERATURE -55

class LM35{

  private:
    float m_temperature;
    float m_milivolts;

    int m_sensor_pin;
    int m_resolution{LM35_RESOLUTION};
    int m_adc_reference{LM35_ADC_REF};
    float m_voltage_reference{LM35_VOL_REF};

    float m_temp_alarm_high{LM35_MAX_TEMPERATURE};
    float m_temp_alarm_low{LM35_MIN_TEMPERATURE};
    boolean m_alarm_high;
    boolean m_alarm_low;

    float getMilivolts();
    void checkAlarm();

  public:
    ~LM35();
    LM35(int t_pin);
    LM35(int t_pin, int t_resolution, int t_adc, float t_voltage); 
    
    float getTemperature();
    float getTemperature(char scale);
    
    void setPin(int t_pin);
    boolean setResolution(int t_resolution);
    void setAdcReference(int t_adc);
    void setVoltageReference(float t_voltage);

    boolean setHighLimitAlarm(float t_temp);
    boolean setLowLimitAlarm(float t_temp);
    boolean getHighAlarm();
    boolean getLowAlarm();

    void update();
    void begin();  
};

#endif
