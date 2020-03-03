#include <RobotLib.h>

float const balance = 0.6;
double const m = 1  ;
bool state = true;

int const R_SENSOR = 2;
int const L_SENSOR = 10;
int const M_SENSOR = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(R_SENSOR, INPUT);
  pinMode(M_SENSOR, INPUT);
  pinMode(L_SENSOR, INPUT);
  Serial.begin(9600);
  pinMode(13, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  Motor motorR;
  motorR.begin(4, 5, 3); //.setDefaultOnZero(LOW);
  Motor motorL;
  motorL.begin(7, 8, 6).reverse();  //.setDefaultOnZero(LOW);

  motorR.output(0);
  motorL.output(0);

  if (state == true)
  {
    motorL.output(1*m);
    motorR.output(.2*m*balance*0);
  }
  else
  {
    motorL.output(.2*m*0);
    motorR.output(1*m*balance);
  }

  if (state == true)
  {
    Serial.println("State is true");
    digitalWrite(13, HIGH);
  }
  else
  {
    Serial.println("State is false");
    digitalWrite(13, LOW);
  }
  
  // If either sensor reads, flip direction
  if (((digitalRead(L_SENSOR) == HIGH) && state) || (!state && (digitalRead(R_SENSOR) == HIGH)) && !((digitalRead(L_SENSOR) == HIGH) && (digitalRead(R_SENSOR) == HIGH)))
  {
    state = !state;
  }

//  delay(100); 
}
