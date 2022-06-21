 const int Trigger=2;
const int Echo=3;
const int Led=6;
const int Led2=7;
const int CuadranteS1=1;
const int SensorEnCuadranteS1 =1;
int ContadorC1=1;
bool OcupadoS1= false;


const int Trigger2=8;
const int Echo2=9;
const int Led3=12;
const int Led4=13;
const int CuadranteS2=2;
const int SensorEnCuadranteS2=1;
int ContadorC2=1;
bool OcupadoS2=false;



void setup() {
  Serial.begin(9600);
  Serial3.begin(9600);
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
  digitalWrite(Trigger,LOW);
  pinMode(Led,OUTPUT);
  pinMode(Led2,OUTPUT);
  
  pinMode(Trigger2, OUTPUT);
  pinMode(Echo2, INPUT);
  digitalWrite(Trigger2,LOW);
  pinMode(Led3,OUTPUT);
  pinMode(Led4,OUTPUT);
}

void loop() {
 long t;
 long d;
 long t2;
 long d2;

 digitalWrite(Trigger, HIGH);
 delayMicroseconds(10);
 digitalWrite(Trigger, LOW);
 t = pulseIn(Echo, HIGH);
 d = t/59;

 if(d<100){
  digitalWrite(Led, LOW);
  digitalWrite(Led2,HIGH);
  OcupadoS1=true;
  Serial.println(CuadranteS1);
  Serial.println(SensorEnCuadranteS1);
  Serial.println(OcupadoS1);
  
 } else {
  digitalWrite(Led, HIGH);
  digitalWrite(Led2, LOW);
  OcupadoS1=false;
  Serial.println(CuadranteS1);
  Serial.println(SensorEnCuadranteS2);
  Serial.println(OcupadoS1);
 }
 if(Serial.available() !=0){
 Serial.println(CuadranteS1);
 ContadorC1 = Serial.read();
 
 }

 delay(1000);
 
 digitalWrite(Trigger2, HIGH);
 delayMicroseconds(10);
 digitalWrite(Trigger2,LOW);
 t2 = pulseIn(Echo2, HIGH);
 d2 = t2/59;

 
 if(d2 < 100){
  digitalWrite(Led3, HIGH);
  digitalWrite(Led4, LOW);
  OcupadoS2=true;
  Serial.println(CuadranteS2);
  Serial.println(SensorEnCuadranteS2);
  Serial.println(OcupadoS2);
 } else {
  digitalWrite(Led3, LOW);
  digitalWrite(Led4, HIGH);
  OcupadoS2=false;
  Serial.println(CuadranteS2);
  Serial.println(SensorEnCuadranteS1);
  Serial.println(OcupadoS2);
 }



 if(Serial.available() !=0){
  Serial.println(CuadranteS2);
  ContadorC2 = Serial.read();
  
 }
 //Serial.print("Distancia: ");
 //Serial.print(d);

 //Serial.print("cm");
 //Serial.println();
 delay(100);
}
