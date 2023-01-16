#include<ESP8266WiFi.h>
#include<ESP8266WebServer.h>
#include<FastLED.h>

#define SSID "Galaxy A20B7F2"
#define PWD "ze4T@78KJi"
#define LED_PIN 5 //D1
#define NUM_LEDS 298
#define BAUDRATE 9600
#define DELAY 1.50 //in minutes
#define SENSOR_PIN 2 //D4

void patternON(short int , short int , short int );
void patternOFF(short int , short int , short int );
String SendHTML();
void SensorGetValues();

ESP8266WebServer server(80);
CRGB leds[NUM_LEDS];
int val = 0;
bool sensorFlag = true;

void setup(){
  Serial.begin(BAUDRATE);

  //WS812b led setup segment
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS);

  //Sensor setup segment
  pinMode(SENSOR_PIN, INPUT);

  //wifi setup segment
  WiFi.begin(SSID, PWD);

  while(WiFi.status()!=WL_CONNECTED){
    LEDS.showColor(CRGB(255, 0, 0));
    delay(100);
    LEDS.showColor(CRGB(0, 0, 0));
    delay(100);
  }
  LEDS.showColor(CRGB(0, 255, 0));
  delay(500);
  LEDS.showColor(CRGB(0, 0, 0));
  Serial.print("\nConnected, IP address: ");
  Serial.print(WiFi.localIP());
  
  //specify what will run in specific directory
  server.on("/", handle_OnConnect);
  server.onNotFound(handle_NotFound);
  server.on("/SensorOff", SensorOff);
  server.on("/SensorOn", SensorOn);
  server.on("/LEDOn", LEDOn);
  server.on("/LEDOff", LEDOff);
  server.on("/red", red);
  server.on("/blue", blue);
  server.on("/green", green);
  server.on("/yellow", yellow);
  server.on("/lavender", lavender);
  server.on("/neon", neon);
  server.on("/seablue", seaBlue);
  server.on("/seagreen", seaGreen);
  server.on("/orange", orange);
  server.on("/white", white);
  server.on("/pink", pink);
  server.on("/brown", brown);
  server.on("/brightgreen", brightgreen);
  server.on("/skyblue", skyblue);
  server.on("/teagreen", teagreen);
  server.on("/mauvelous", mauvelous);
  server.on("/color", color);

  server.begin();

  LEDS.showColor(CRGB(0, 0, 255));
  delay(650);
  LEDS.showColor(CRGB(0, 0, 0));
}
void loop(void){
  if(WiFi.status()==WL_CONNECTED){
    server.handleClient();
    if(sensorFlag){
      SensorGetValues();
    }
  }
}

void handle_OnConnect(){
   //200 is Ok response code for https
  server.send(200, "text/html", SendHTML());
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}

String SendHTML(){
  String ptr = "  <!DOCTYPE html><html><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">  ";
  ptr+= "  <style>body{background-color: #92a8d1;}.center{margin: 0;position: absolute;top: 50%;left: 50%;-ms-transform: translate(-50%, -50%);transform: translate(-50%, -50%);}</style>  ";
  ptr+= "  <body> ";
  ptr+= "  <h1>Available Colors :)</h1>  ";
  ptr+= "  <a href=\"red\">Red</a><br>  ";
  ptr+= "  <a href=\"blue\">blue</a><br>  ";
  ptr+= "  <a href=\"green\">Green</a><br>  ";
  ptr+= "  <a href=\"white\">White</a><br>  ";
  ptr+= "  <a href=\"yellow\">Yellow</a><br>  ";
  ptr+= "  <a href=\"orange\">Orange</a><br>  ";
  ptr+= "  <a href=\"brown\">Brown</a><br>  ";
  ptr+= "  <a href=\"pink\">Pink</a><br>  ";
  ptr+= "  <a href=\"color\">Color</a><br>  ";
  ptr+= "  <a href=\"lavender\">lavender</a><br>  ";
  ptr+= "  <a href=\"neon\">neon</a><br>  ";
  ptr+= "  <a href=\"seablue\">Sea Blue</a><br>  ";
  ptr+= "  <a href=\"seagreen\">Sea Green</a><br>  ";
  ptr+= "  <a href=\"brightgreen\">Bright Green</a><br>  ";
  ptr+= "  <a href=\"skyblue\">Sky Blue</a><br>  ";
  ptr+= "  <a href=\"teagreen\">Teagreen</a><br>  ";
  ptr+= "  <a href=\"mauvelous\">Mauvelous</a><br></div>  ";
  ptr+= "  <div class=\"center\">   ";
  ptr+= "  <div class=\"ColorPicker\">  ";
  ptr+= "  <form><h3>ColorPicker</h3>  ";
  ptr+= "  <label for=\"chooseColor\"> Select Color </label>  ";
  ptr+= "  <input type=\"color\" id=\"chooseColor\" name=\"chooseColor\", vale=\"#ff0000\">  ";
  ptr+= "  <br><br><input type=\"submit\">  ";
  ptr+= "  </form></div>  ";
  ptr+= "  <div class=\"Sensor\">  ";
  ptr+= "  <br><h3> Sensor On/Off </h3>  ";
  ptr+= "  <a href=\"SensorOn\">On</a>  ";
  ptr+= "  <a href=\"SensorOff\">Off</a></div>  ";
  ptr+= "  <div class=\"LED\">  ";
  ptr+= "  <h3> LED On/Off </h3> ";
  ptr+= "  <a href=\"LEDOn\">On</a>  ";
  ptr+= "  <a href=\"LEDOff\">Off</a></div>  ";
  ptr+= "  <script>document.getElementById(\"SensorOff\").innerHTML = window.location.href + \"/SensorOff\";  ";
  ptr+= "  document.getElementById(\"SensorOn\").innerHTML = window.location.href + \"/SensorOn\";  ";
  ptr+= "  document.getElementById(\"LEDOff\").innerHTML = window.location.href + \"/LEDOff\";  ";
  ptr+= "  document.getElementById(\"LEDOn\").innerHTML = window.location.href + \"/LEDOn\";  ";
  ptr+= "  <script>document.getElementById(\"red\").innerHTML = window.location.href + \"/red\";  ";
  ptr+= "  document.getElementById(\"blue\").innerHTML = window.location.href + \"/blue\";  ";
  ptr+= "  document.getElementById(\"green\").innerHTML = window.location.href + \"/green\";  ";
  ptr+= "  document.getElementById(\"white\").innerHTML = window.location.href + \"/white\";  ";
  ptr+= "  document.getElementById(\"yellow\").innerHTML = window.location.href + \"/yellow\";  ";
  ptr+= "  document.getElementById(\"orange\").innerHTML = window.location.href + \"/orange\";  ";
  ptr+= "  document.getElementById(\"brown\").innerHTML = window.location.href + \"/brown\";  ";
  ptr+= "  document.getElementById(\"pink\").innerHTML = window.location.href + \"/pink\";  ";
  ptr+= "  document.getElementById(\"color\").innerHTML = window.location.href + \"/color\";  ";
  ptr+= "  document.getElementById(\"lavender\").innerHTML = window.location.href + \"/lavender\";  ";
  ptr+= "  document.getElementById(\"neon\").innerHTML = window.location.href + \"/neon\";  ";
  ptr+= "  document.getElementById(\"seablue\").innerHTML = window.location.href + \"/seablue\";  ";
  ptr+= "  document.getElementById(\"seagreen\").innerHTML = window.location.href + \"/seagreen\";  ";
  ptr+= "  document.getElementById(\"brightgreen\").innerHTML = window.location.href + \"/brightgreen\";  ";
  ptr+= "  document.getElementById(\"skyblue\").innerHTML = window.location.href + \"/skyblue\";  ";
  ptr+= "  document.getElementById(\"teagreen\").innerHTML = window.location.href + \"/teagreen\";  ";
  ptr+= "  document.getElementById(\"mauvelous\").innerHTML = window.location.href + \"/mauvelous\";  ";
  
  ptr+= "  </script></html>   ";
  return ptr;
}

void patternON(short int r, short int g, short int b){
  for(int i=0; i<NUM_LEDS/2; i++){ //n=2
    leds[i] = CRGB(r, g, b);
    leds[(NUM_LEDS/2)+i] = CRGB(r, g, b);
    FastLED.show();
    delay(50);
  }
}

void patternOFF(short r, short int g, short int b){
  for(int i=0; i<NUM_LEDS; i++){ //n=1
    leds[NUM_LEDS - i] = CRGB(r, g, b);
    leds[(NUM_LEDS/2)-i] = CRGB(r, g, b);
    FastLED.show();
    delay(50);
  }
}

void SensorOn(){
  String html="<!DOCTYPE html><html><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"><style>h1{margin: 0;position: absolute;top: 50%;left: 50%;-ms-transform: translate(-50%, -50%);transform: translate(-50%, -50%);}</style><h1>Sensor turned On!<br>GO Back</h1></html>";
  server.send(200, "text/html", html);
  sensorFlag = true;
}

void SensorOff(){
  String html="<!DOCTYPE html><html><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"><style>h1{margin: 0;position: absolute;top: 50%;left: 50%;-ms-transform: translate(-50%, -50%);transform: translate(-50%, -50%);}</style><h1>Sensor turned Off.<br>GO Back</h1></html>";
  server.send(200, "text/html", html);
  sensorFlag = false;
}

void LEDOn(){
  String html="<!DOCTYPE html><html><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"><style>h1{margin: 0;position: absolute;top: 50%;left: 50%;-ms-transform: translate(-50%, -50%);transform: translate(-50%, -50%);}</style><h1>LED turned On!<br>GO Back</h1></html>";
  server.send(200, "text/html", html);
  LEDS.showColor(CRGB(255, 136, 0));
}

void LEDOff(){
  String html="<!DOCTYPE html><html><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"><style>h1{margin: 0;position: absolute;top: 50%;left: 50%;-ms-transform: translate(-50%, -50%);transform: translate(-50%, -50%);}</style><h1>LED turned Off.<br>GO Back</h1></html>";
  server.send(200, "text/html", html);
  LEDS.showColor(CRGB(0,0,0));
}

void SensorGetValues(){
  val = digitalRead(SENSOR_PIN);
  if(val == HIGH){
    Serial.println("Motion detected!");
    patternON(255, 136, 0);
    //delay(DELAY);
  }
  else{
    Serial.println("Motion ended.");
    patternOFF(0, 0, 0);
  }
}

void red(){
  LEDS.showColor(CRGB(255,0,0));
}
void green(){
  LEDS.showColor(CRGB(0,255,0));
}
void blue(){
  LEDS.showColor(CRGB(0,0,255));
}
void lavender(){
  LEDS.showColor(CRGB(230,230,250));
}
void yellow(){
  LEDS.showColor(CRGB(255, 255, 0));
}
void neon(){
  while(true){
    LEDS.showColor(CRGB(199,36,177));delay(100);
    LEDS.showColor(CRGB(7,77,255));delay(100);
    LEDS.showColor(CRGB(224,231,34));delay(100);
    LEDS.showColor(CRGB(210,39,48));delay(100);
    LEDS.showColor(CRGB(219,62,177));delay(100);
    LEDS.showColor(CRGB(68,214,44));delay(100);
    break;
  }
}
void seaBlue(){
  LEDS.showColor(CRGB(0, 255, 213));
}
void seaGreen(){
  LEDS.showColor(CRGB(46, 139, 87));
}
void orange(){
  LEDS.showColor(CRGB(255, 165, 0));
}
void white(){
  LEDS.showColor(CRGB(255, 255, 255));
}
void color(){
  LEDS.showColor(CRGB(252, 3, 115));
}
void pink(){
  LEDS.showColor(CRGB(255, 0, 136));
}
void brown(){
  LEDS.showColor(CRGB(102, 39, 7));
}
void brightgreen(){
  LEDS.showColor(CRGB(102, 255, 0));
}
void skyblue(){
  LEDS.showColor(CRGB(99, 211, 219));
}
void teagreen(){
  LEDS.showColor(CRGB(202, 240, 193));
}
void mauvelous(){
  LEDS.showColor(CRGB(239, 167, 170));
}
