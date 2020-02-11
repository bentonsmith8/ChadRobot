#include <RobotLib.h>

float const balance = 0.6;
double const m = .25;

int const R_SENSOR = 2;
int const L_SENSOR = 10;
int const M_SENSOR = 9;
//int const SWITCH_W = 9;
//int const SWITCH_R = 11;
/*
int const R_MOTOR_F = 5;
int const R_MOTOR_R = 6;
int const L_MOTOR_F = 7;
int const L_MOTOR_R = 8;
*/

void setup() {
  // put your setup code here, to run once:
  pinMode(R_SENSOR, INPUT);
  pinMode(M_SENSOR, INPUT);
  pinMode(L_SENSOR, INPUT);

  /*
  pinMode(SWITCH_W, OUTPUT);
  pinMode(SWITCH_R, INPUT);
  */
  /*
  pinMode(L_MOTOR_F, OUTPUT);
  pinMode(L_MOTOR_R, OUTPUT);
  pinMode(R_MOTOR_F, OUTPUT);
  pinMode(R_MOTOR_R, OUTPUT);
  */
  pinMode(13, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  Motor motorR;
  motorR.begin(4, 5, 3); //.setDefaultOnZero(LOW);
  Motor motorL;
  motorL.begin(7, 8, 6).reverse();  //.setDefaultOnZero(LOW);

  bool run = true;
  /* This dont work but we wanted a ripcord because that would be cool or whatever
   * 
  digitalWrite(SWITCH_W, HIGH);
  if (digitalRead(SWITCH_R) == HIGH)
  {
    digitalWrite(13, HIGH);
    run = true;
  }
  else
  {
    digitalWrite(13, LOW);
    run  = false;
  }
  */
  

  if (run)
  {
  //Only middle sees; swerve right
  if ((digitalRead(L_SENSOR) == LOW) && (digitalRead(M_SENSOR) == HIGH) && (digitalRead(R_SENSOR) == LOW))
  {
    motorL.output(.8*m);
    motorR.output(.6*m*balance);
  }
  //When middle doesn't see it; swerve left
  else if ((digitalRead(L_SENSOR) == LOW) && (digitalRead(M_SENSOR) == LOW) && (digitalRead(R_SENSOR) == LOW))
  {
    motorL.output(.8*m);
    motorR.output(1*m*balance);
  }
 
  //If all see line (loop); full speed ahead
  /*
  else if ((digitalRead(L_SENSOR) == HIGH) && (digitalRead(M_SENSOR) == HIGH) && (digitalRead(R_SENSOR) == HIGH))  {
    motorR.output(1*m);
    motorL.output(1*m);
  }  
  */
  
  else
  {
    motorR.output(0);
    motorL.output(0);
  }
  }

  /*
   * Testing to see if the damn motors move at the same speed.
   */
//  motorL.output(1 * m);
//  motorR.output(1 * balance * m);

  
}
