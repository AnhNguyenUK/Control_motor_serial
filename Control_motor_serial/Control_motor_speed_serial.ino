#define IA1 4
#define IA2 5 //PWM
#define MAX_SPEED 255
#define MIN_SPEED 0
int vel = 0;
void speed_up(int speed){
  speed = constrain(speed,MIN_SPEED, MAX_SPEED);
  digitalWrite(IA1,1);
  analogWrite(IA2,255-speed);
}
void Backward(int speed){
  speed = constrain(speed,MIN_SPEED,MAX_SPEED);
  digitalWrite(IA1,0);
  analogWrite(IA2,speed);
}
void setup() {
  // put your setup code here, to run once:
pinMode(IA1,OUTPUT);
pinMode(IA2,OUTPUT);
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
while(Serial.available()){
  vel = Serial.parseInt();
  speed_up(vel);
  delay(1000);
  Backward(vel);
  delay(1000);
  
}
}
