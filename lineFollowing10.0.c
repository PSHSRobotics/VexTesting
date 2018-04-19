#pragma config(Sensor, in1,    lineFollowerRIGHT,   sensorLineFollower)
#pragma config(Sensor, in2,    lineFollowerCENTER,  sensorLineFollower)
#pragma config(Sensor, in3,    lineFollowerLEFT,    sensorLineFollower)
#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                             	    - Triple Sensor Line Tracking -                                   *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|
|*  This program uses 3 VEX Line Follower Sensors to track a black line on a light(er) surface.       *|
|*  There is a two second pause at the beginning of the program.                                      *|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)  Reversing 'rightMotor' (port 2) in the "Motors and Sensors Setup" is needed with the        *|
|*        "Squarebot" mode, but may not be needed for all robot configurations.                       *|
|*    2)  Lighting conditions, line darkness, and surface lightness change from place to place,       *|
|*        so the value of 'threshold' may need to be changed to better suit your environment.         *|
|*                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]          [Name]              [Type]                [Description]                     *|
|*    Motor  - Port 2     rightMotor          VEX 3-wire module     Right side motor                  *|
|*    Motor  - Port 3     leftMotor           VEX 3-wire module     Left side motor                   *|
|*    Analog - Port 1     lineFollowerRIGHT   VEX Light Sensor      Front-right, facing down          *|
|*    Analog - Port 2     lineFollowerCENTER  VEX Light Sensor      Front-center, facing down         *|
|*    Analog - Port 3     lineFollowerLEFT    VEX Light Sensor      Front-left, facing down           *|
\*-----------------------------------------------------------------------------------------------4246-*/

bool getRDark(){
	return SensorValue(lineFollowerRIGHT) > threshold
}

bool getCDark(){
	return SensorValue(lineFollowerCENTER) > threshold;
}

bool getLDark(){
	return SensorValue(lineFollowerLEFT) > threshold;
}

bool getRLight(){
	return SensorValue(lineFollowerRIGHT) < threshold;
}

bool getCLight(){
	return SensorValue(lineFollowerCENTER) < threshold;
}
bool getLLight(){
	return SensorValue(lineFollowerLEFT) < threshold;
}

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
  wait1Msec(2000);          // The program waits for 2000 milliseconds before continuing.

  int threshold = 505;      /* found by taking a reading on both DARK and LIGHT    */
  //int RDark = (SensorValue(lineFollowerRIGHT) > threshold);
  //int CDark = (SensorValue(lineFollowerCENTER) > threshold);
  //int LDark = (SensorValue(lineFollowerLEFT) > threshold);
  //int RLight = (SensorValue(lineFollowerRIGHT) < threshold);
  //int CLight = (SensorValue(lineFollowerCENTER) < threshold);
  //int LLight = (SensorValue(lineFollowerLEFT) < threshold);
  /* surfaces, adding them together, then dividing by 2. */
  while(true)
  {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -+
    displayLCDCenteredString(0, "LEFT  CNTR  RGHT");        //  Display   |
    displayLCDPos(1,0);                                     //  Sensor    |
    displayNextLCDNumber(SensorValue(lineFollowerLEFT));    //  Readings  |
    displayLCDPos(1,6);                                     //  to LCD.   |
    displayNextLCDNumber(SensorValue(lineFollowerCENTER));  //            |
    displayLCDPos(1,12);                                    //  L  C  R   |
    displayNextLCDNumber(SensorValue(lineFollowerRIGHT));   //  x  x  x   |
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -+

		///DDD
    if(LDark && CDark && RDark)
    {

    }
  ///DARK DARK LIGHT
    else if(LDark && CDark && RLight)
    {

    }
    ///LIGHT DARK DARK
    else if(LLight && CDark && RDark)
    {

    }
    else if(LDark && CLight && RDark){
    	
    }
		else if(LDark && CLight && RLight){
			
		}
		else if(LLight && CLight && RDark){
			
		}
		else if(LLight && CDark && RLight){
			
		}
		else{
			
		}
  }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
