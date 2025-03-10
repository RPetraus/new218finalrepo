//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "user_display.h"
#include "display.h"

//=====[Declaration of private defines]========================================

#define DISPLAY_REFRESH_TIME_MS              1000

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

/**
* Initializes the user display
*/
void userDisplayInit()
{
    displayInit();
    displayCharPositionWrite ( 0,0 );
    displayStringWrite( "Welcome!" );
}


// prob need to compile all of the lcd updates into here once it's working
void userDisplayUpdate()
{
    /*
    if ( car pulls up ) {
        displayCharPositionWrite ( 0,0 );
        displayStringWrite( "Welcome!" );
        displayCharPositionWrite ( 0,1 );
        displayStringWrite( "Please input code");
    }
    if ( gateUnlocked ) {
        displayCharPositionWrite( 0,0 );
        displayStringWrite( "Gate Unlocked" );
        displayCharPositionWrite( 0,1 );
        displayStringWrite( "Enter on Green");
    }

    if ( gateOpen ) {
        displayCharPositionWrite( 0,0 );
        displayStringWrite( "Gate Unlocked" );
        displayCharPositionWrite( 0,1 );
        displayStringWrite( "YOU MAY ENTER");
    }
    //maybe add a condition for when the car's leaving
    */
}

//=====[Implementations of private functions]==================================