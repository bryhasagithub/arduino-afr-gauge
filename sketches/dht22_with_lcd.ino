/*
 * TFT LCD Text & DRAWING
 * with DHT22
 * 
 * learnelectronics
 * 4 APRIL 2017
 * 
 * www.youtube.com/c/learnelectronics
 * arduino0169@gmail.com
 */

#include <Adafruit_GFX.h>                                       //graphix library for drawing
#include <Adafruit_TFTLCD.h>                                    //LCD library to drive screen
#include "DHT.h"                                                //dht library

#define LCD_CS A3                                               // Chip Select goes to Analog 3
#define LCD_CD A2                                               // Command/Data goes to Analog 2
#define LCD_WR A1                                               // LCD Write goes to Analog 1
#define LCD_RD A0                                               // LCD Read goes to Analog 0

#define LCD_RESET A4                                            //LCD reset to analog 4
#define DHTPIN 53                                               //dht22 on digital 53 (Mega)
#define DHTTYPE DHT22                                           //define dht type (11,21,22)


#define	BLACK   0x0000                                          //hex colors to english
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET); //create instance of LCD called tft
DHT dht(DHTPIN, DHTTYPE);                                       //create instance of dht called dht
  
void setup(void) {
  Serial.begin(9600);                                           //serial comms for debug

  tft.reset();                                                  //reset the screen

  tft.begin(0x9341);                                            //start screen using chip identifier hex

}

void loop(void) {
  
  int f = dht.readTemperature(true);                            //read temp in F from dht22
  int h = dht.readHumidity();                                   //read humidity from dht
  
  tft.setRotation(1);                                           //set rotation for wide screen
  tft.fillScreen(BLACK);                                        //fill screen with black (ersatz clear)
  tft.setCursor(0, 0);                                          //cursor to upper left
  
  tft.setTextColor(WHITE);                                      //set text color white
  tft.setTextSize(2);                                           //set text size to 2 (1-6)
  tft.println("Temperature      Humidity");                     //print header to screen


 tft.drawRoundRect(10, 50, 100, 100, 6, WHITE);                 //draw rounded box (x,y,width,height,radius,color)
 tft.drawRoundRect(200, 50, 100, 100, 6, WHITE);                //draw rounded box (x,y,width,height,radius,color)
 tft.setTextColor(GREEN);                                       //set text color to green
 tft.setTextSize(4);                                            //set text size 4
 tft.setCursor(40, 85);                                         //put cursor in left box
 tft.print(f);                                                  //print the temperature


 tft.setCursor(230, 85);                                        //put cursor in right box
 tft.print(h);                                                  //print the humidity
 delay(3000);                                                   //wait 3 seconds
}
