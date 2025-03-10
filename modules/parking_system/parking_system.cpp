//=====[Libraries]=============================================================

#include "arm_book_lib.h"
#include "matrix_keypad.h"
#include "mbed.h"

#include "parking_system.h"

#include "sirens.h"
#include "display.h"
#include "pc_serial_com.h"
#include "code.h"
#include "move_gate.h"
#include "car_at_entrance.h"
#include "entrance_subsystem.h"

//=====[Declaration of private defines]========================================

#define UPDATE_TIME_MS                 10

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

/**
* Initializes the smart car system by initializing the subsystems
*/
void parkingSystemInit()
{    
    sirensInit();

    displayInit();

    pcSerialComInit(); // should not be initialized elsewhere

    matrixKeypadInit(UPDATE_TIME_MS);

    moveGateInit();
    
    carAtEntranceInit();

    entranceSubsystemInit();

    resetCode();
}


void parkingSystemUpdate()
{
    entranceSubsystemUpdate();
    
    delay(SYSTEM_TIME_INCREMENT_MS);
}

//=====[Implementations of private functions]==================================