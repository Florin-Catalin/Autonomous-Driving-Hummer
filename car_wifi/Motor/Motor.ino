#include<Wire.h>
bool flag1 = LOW;
bool flag2 = LOW;
bool flag3 = LOW;
bool flag4 = LOW;
byte x;


int E1 = 5; //PWMA
int M1 = 9; //PWMA
int E2 = 6; //PWMB
int M2 = 10; //PWMB
void setup() {
    Serial.begin(115200);
    Wire.begin(0x08);
   
 
    pinMode(E1, OUTPUT);
    digitalWrite(E1, LOW); // When not sending PWM, we want it low
    pinMode(M1, OUTPUT);
    digitalWrite(M1, LOW); // When not sending PWM, we want it low
    pinMode(E2, OUTPUT);
    digitalWrite(E2, LOW); // When not sending PWM, we want it low
    pinMode(M2, OUTPUT);
    digitalWrite(M2, LOW); // When not sending PWM, we want it low

       Wire.onReceive(receiveEvent);
      Wire.onRequest(sendEvent); 
}

void loop() {
	if ( flag1 == HIGH && flag2 == LOW && flag3 == LOW && flag4 == LOW )
  {
	//******** ******************************//forward
	analogWrite(M1, 0);
	analogWrite(E1, 0); //the speed value of motorA is 0
analogWrite(M2, 0);
	analogWrite(E2, 0); //the speed value of motorB is 0
	delay(1000);//********************************************//stop
	analogWrite(M1, 150);//the speed value of motorA is 150
	analogWrite(E1, 0);
	analogWrite(M2, 150);//the speed value of motorA is 150
	analogWrite(E2, 0);
  } else if ( flag1 == LOW && flag2 == HIGH && flag3 == LOW && flag4 == LOW ){
	delay(5000);//*********************************************//back
	analogWrite(M1, 0);
	analogWrite(E1, 0); //the speed value of motorA is 0
	analogWrite(M2, 0);
	analogWrite(E2, 0); //the speed value of motorB is 0
	delay(1000);
 


} else if ( flag1 == LOW && flag2 == LOW && flag3 == HIGH && flag4 == LOW ){
	//*******************************************//left
	analogWrite(M1, 0);
	analogWrite(E1, 0); //the speed value of motorA is 0
	analogWrite(M2, 0);
	analogWrite(E2, 0); //the speed value of motorB is 0

} else if ( flag1 == LOW && flag2 == LOW && flag3 == LOW && flag4 == HIGH ){
	delay(1000); //*******************************************//stop
	analogWrite (M1, 200); //the speed value of motorA is 200
	analogWrite(E1, 0);
	analogWrite (M2, 0);
	analogWrite(E2, 200); //the speed value of motorB is 200
	delay(3000);//*** ***************************************//right
}
}
