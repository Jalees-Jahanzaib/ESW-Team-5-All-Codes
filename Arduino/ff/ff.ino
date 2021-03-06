#include "BluetoothSerial.h"
BluetoothSerial ESP_BT;
// defines pins numbers
const int trigPin = 27;
const int echoPin1 = 22;
const int echoPin2 = 23;
const int echoPin3 = 25;
const int echoPin4 = 26;
const int echoPin5 = 33;

const int pins[10]={22,23,25,26,33};


// defines variables
long duration;
int distance,count=0,mini;
//int incoming;
//int LED_BUILTIN = 2;


void setup() {
Serial.begin(115200); //Start Serial monitor in 9600
ESP_BT.begin("ESP32_LED_Control"); //Name of your Bluetooth Signal
Serial.println("Bluetooth Device is Ready to Pair");
//pinMode (LED_BUILTIN, OUTPUT);//Specify that LED pin is output

pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
pinMode(echoPin2,INPUT);
pinMode(echoPin3,INPUT);
pinMode(echoPin5,INPUT);
pinMode(echoPin4,INPUT);// Sets the echoPin as an Input
//Serial.begin(9600); // Starts the serial communication
}

void loop() {
mini=5000;
for (int i=0;i<=4;i++){
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(pins[i], HIGH);
// Calculating the distance
distance= duration*0.034/2;
if(distance<mini)
mini=distance;
// Prints the distance on the Serial Monitor
delay(100);
Serial.print("Distance for  Sensor");
Serial.print(i+1);
Serial.print(" : ");
Serial.println(distance);}

// if (ESP_BT.available()) //Check if we receive anything from Bluetooth
  {
    if(mini>=100)
          ESP_BT.println(1);
      else
          ESP_BT.println(2);
           //ESP_BT.println(distance);
          
  }
//delay(2000);//1000*60*5=300000

}
