#include<SoftwareSerial.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
char c;

SoftwareSerial bluetoothSerial(7, 8);
#define OLED_RESET LED_BUILTIN  //4
Adafruit_SSD1306 display(OLED_RESET);

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  bluetoothSerial.begin(9600);
  Serial.begin(115200);
  display.clearDisplay();
  display.println("   Smart    Minor");
  }

void loop() 
{
   if(bluetoothSerial.available()>0)
 {
  c=bluetoothSerial.read();
  
   Serial.print(c);
   
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);

  
  if (c=='h')
  {
     display.clearDisplay();
     display.println("      HI");
  }
  if (c=='c')
  {
    display.clearDisplay();
    
  }
   if (c=='9')
  {
     display.clearDisplay();
     display.println("How are      you ?");
  }
   if (c=='0')
  {
     display.clearDisplay();
     display.println("       Welcome To         Smart Glasses");
  }
   if (c=='8')
  {
     display.clearDisplay();
     display.println("Hari bhai");
  }
   if (c=='7')
  {
     display.clearDisplay();
     display.println("  Pretty     Girl");
  }
   if (c=='4')
  {
     display.clearDisplay();
     display.println("   Sorry  Priyanshee");
  }

  display.display();
 }
}
