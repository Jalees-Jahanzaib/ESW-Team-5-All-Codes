#include "BluetoothSerial.h" //Header File for Serial Bluetooth, will be added by default into Arduino

BluetoothSerial ESP_BT; //Object for Bluetooth

int incoming;
//int LED_BUILTIN = 2;

void setup() {
  Serial.begin(115200); //Start Serial monitor in 9600
  ESP_BT.begin("ESP32"); //Name of your Bluetooth Signal
  Serial.println("Bluetooth Device is Ready to Pair");

 // pinMode (LED_BUILTIN, OUTPUT);//Specify that LED pin is output
}


void loop() {
  
  if (ESP_BT.available()) //Check if we receive anything from Bluetooth
  {
   // incoming = ESP_BT.read(); //Read what we recevive 
    //Serial.print("Received:"); Serial.println(incoming);
    incoming=49;
    Serial.println("trusha");

    if (incoming == 49)
        {
   //     digitalWrite(LED_BUILTIN, HIGH);
        ESP_BT.println("LED turned ON");
        }
        
    if (incoming == 48)
        {
     //   digitalWrite(LED_BUILTIN, LOW);
        ESP_BT.println("LED turned OFF");
        }     
  }
  delay(20);
}