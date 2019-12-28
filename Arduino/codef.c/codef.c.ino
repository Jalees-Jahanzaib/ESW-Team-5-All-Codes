#include "BluetoothSerial.h"
BluetoothSerial ESP_BT;
// defines pins numbers
const int trigPin = 27;  //D4
const int echoPin = 26;  //D3

// defines variables
long duration;
int distance,count=0;
//int incoming;
//int LED_BUILTIN = 2;


void setup() {
Serial.begin(115200); //Start Serial monitor in 9600
ESP_BT.begin("ESP32_LED_Control"); //Name of your Bluetooth Signal
Serial.println("Bluetooth Device is Ready to Pair");
//pinMode (LED_BUILTIN, OUTPUT);//Specify that LED pin is output

pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
//Serial.begin(9600); // Starts the serial communication
}

void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
  if(distance<2000)
    count++;
  else
  count=0;

Serial.print("Distance: ");
Serial.println(distance);

 if (ESP_BT.available()) //Check if we receive anything from Bluetooth
  {
    if(distance>=500)
          ESP_BT.println(1);
      else
          ESP_BT.println(0);
           //ESP_BT.println(distance);
          
  }
delay(2000);
}
