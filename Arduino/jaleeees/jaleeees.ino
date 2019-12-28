#include "BluetoothSerial.h"
#include "WiFi.h"
#include "HTTPClient.h"

char* wifi_ssid = "MGG5";
char* wifi_pwd = "drowssapp";
String cse_ip = "192.168.43.106";
const int trigPin = 18;
const int echoPin = 19;
long duration;
int distance;
int a=1;
BluetoothSerial SerialBT;
String cse_port = "8080";
String server = "http://"+cse_ip+":"+cse_port+"/~/in-cse/in-name/";
String createCI(String server, String ae, String cnt, String val)
{
  HTTPClient http;
  http.begin(server + ae + "/" + cnt + "/");                    
  http.addHeader("X-M2M-Origin", "admin:admin");
  http.addHeader("Content-Type", "application/json;ty=4");
  http.addHeader("Content-Length", "100");
  http.addHeader("Connection", "close");
  int code = http.POST("{\"m2m:cin\": {\"con\":\"" + String(val) + "\"}}");
  http.end();
  Serial.print(code);
  delay(300);
}
void setup()
{
 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  SerialBT.begin("ESP32");
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  WiFi.begin(wifi_ssid, wifi_pwd);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
  Serial.println("Setup done");
  Serial.begin(115200); 
}
void loop()
{
  if(WiFi.status() != WL_CONNECTED) {
    Serial.println("Connecting to Wifi " + String(wifi_ssid) + " with password " + String(wifi_pwd));
    WiFi.begin(wifi_ssid, wifi_pwd);
    while(WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
  }
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10 );
  digitalWrite(trigPin, LOW);
//  duration = pulseIn(echoPin, HIGH);
//  distance= (duration*0.034)/2;
//  Serial.println(distance);
//  if(distance<15){
SerialBT.write(0);
delay(5000);
//Serial.println(0);
//}
//if(distance>=15){
//SerialBT.write(1);
//Serial.println(1);
//}
 // SerialBT.println(distance);
//  String sensor1 = "(" + String(distance) + ")";
  String sensor_string;// = sensor1 ;
//  sensor_string = "\"" + sensor_string + "\""; // DO NOT CHANGE THIS LINE
//  SerialBT.write(0);
//  if(a==1)
//    {
//      createCI(server, "Team24_Audio_volume_control_based_on_distance_of_students", "node_1", sensor_string);
    sensor_string = "HEllo Test";
    createCI(server, "Team5_Audio_volume_control_based_on_distance_of_students", "node_1", sensor_string);
//    }
//    a=2;
    delay(5000);
}
