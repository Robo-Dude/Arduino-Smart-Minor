#include <dht11.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#define OLED_ADDR   0x3C
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
dht11 DHT11; // create object of DHT11
#define dhtpin 3 // set the pin to connect to DHT11

void setup() {
    Serial.begin(9600);// setting up serial monitor
    Wire.begin();
    delay(3000);
    display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
    display.clearDisplay();
    display.display(); 
}

void loop() {
  DHT11.read(dhtpin);// initialize the reading
  //code for Robojax.com video
  int humidity = DHT11.humidity;// get humidity
   Serial.print("Temperture");
   Serial.print(getTemp('C'));
   Serial.print("C ");
   Serial.print(" humidity:");
   Serial.print (humidity);
   Serial.println("% ");
   Serial.println();
   delay(500);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print("Temperture   ");
  display.print(getTemp('C'));
  display.print(" C");

 
  
 
  display.display();
  delay(1000);
}
int getTemp(char type) {
    int temp = (float)DHT11.temperature;//get temp
  
   return temp; 
}
  
