//=====[Libraries]=============================================================

#include "arm_book_lib.h"

#include "car_at_entrance.h"

//=====[Declaration of private defines]========================================

#define CAR_PRESENT_LEVEL 70  
#define CAR_NOT_PRESENT_LEVEL 40     
#define LIGHT_SENSOR_SAMPLES 10 

//=====[Declaration of private data types]=====================================

float lightReadingsArray[LIGHT_SENSOR_SAMPLES];
static int lightSampleIndex = 0;

//=====[Declaration and initialization of public global objects]===============

AnalogIn lightsens(A0);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

bool carDetected;

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void carAtEntranceInit()
{   
    for (int i = 0; i < LIGHT_SENSOR_SAMPLES; i++) {
        lightReadingsArray[i] = 0.0;
        sensorUpdate();
    }
}

bool carIsDetected()
{
    float currentLightLevel = sensorUpdate();

    if (currentLightLevel >= CAR_PRESENT_LEVEL) {
        carDetected = true;  
    } else if (currentLightLevel < CAR_NOT_PRESENT_LEVEL) {
        carDetected = false; 
    }

    return carDetected;
}


float sensorUpdate() 
{
    lightReadingsArray[lightSampleIndex] = lightsens.read();
    lightSampleIndex++;
    
    if (lightSampleIndex >= LIGHT_SENSOR_SAMPLES) {
        lightSampleIndex = 0;
    }

    float lightReadingsSum = 0.0;
    for (int i = 0; i < LIGHT_SENSOR_SAMPLES; i++) {
        lightReadingsSum += lightReadingsArray[i];
    }

    float currentLightLevel = (1.0 - (lightReadingsSum / LIGHT_SENSOR_SAMPLES)) * 100.0;

    return currentLightLevel;
}

//=====[Implementations of public functions]===================================
