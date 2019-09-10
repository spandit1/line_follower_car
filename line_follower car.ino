#define LS 2 // left sensor
#define RS 3 // right sensor
#define LM 5 // left motor M1a
#define LM_ac 9 // left motor M2a
#define RM_ac 10 // right motor M2a
#define RM 6 // right motor M2b
void setup()
{
pinMode(LS, INPUT);
pinMode(RS, INPUT);
pinMode(LM, OUTPUT);
pinMode(LM_ac, OUTPUT);
pinMode(RM, OUTPUT);
pinMode(RM_ac, OUTPUT);
}
void loop()
{
if(digitalRead(LS) && digitalRead(RS)) // Move Forward on line
{
analogWrite(LM, 185);
analogWrite(LM_ac, 0);
analogWrite(RM, 185);
analogWrite(RM_ac, 0);
}
if(digitalRead(LS) && !(digitalRead(RS))) // turn right by rotationg left motors in forward and right ones in backward direction
{
analogWrite(LM, 185);
analogWrite(LM_ac, 0);
analogWrite(RM, 0);
analogWrite(RM_ac, 20);
}
if(!(digitalRead(LS)) && digitalRead(RS)) // Turn left by rotating right motors in forward and left ones in backward direction
{
analogWrite(LM, 0);
analogWrite(LM_ac, 20);
analogWrite(RM, 185);
analogWrite(RM_ac, 0);
}

if(!(digitalRead(LS)) && !(digitalRead(RS))) // Finish line, stop both the motors
{
analogWrite(LM, 0);
analogWrite(LM_ac, 0);
analogWrite(RM, 0);
analogWrite(RM_ac, 0);
}
}
