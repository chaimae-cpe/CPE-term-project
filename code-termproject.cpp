#include <M5Core2.h>
#include <Arduino.h>
#include "Adafruit_ESP8266.h"
#include "WiFi.h"

 float ratio;
 float distance;
 
// Set WiFi credentials
#define WIFI_SSID "Shajeeah"
#define WIFI_PASS "shajeeah"
 
// Set AP credentials
#define AP_SSID "boardA"
#define AP_PASS ""
  
void setup() {
  Serial.begin(115200);
  M5.begin(115200);
 }

void loop() {
      //connecting to WiFi in both AP and STA mode                
       WiFi.mode(WIFI_AP_STA);
     
      // Begin Access Point
       WiFi.softAP(AP_SSID, AP_PASS);   
      delay(2000);
      
      // returns the number of nearby WiFi networks found
      int n = WiFi.scanNetworks();
     
      if (n != 0) {
        for (int i = 0; i < n; ++i) {          
          //searching for second M5Stack device
        if (WiFi.SSID(i) == "boardB"){
            
            //condition for device being less than 6 feet
            if (WiFi.RSSI(i)>-47){
            
              //emitting alert on device
                        M5.Lcd.fillScreen(RED);
                        M5.Lcd.setCursor(110, 100);
                        M5.Lcd.setTextSize(2);
                        M5.Lcd.setTextColor(BLACK);
                        M5.Lcd.print("Caution! ");
                        M5.Lcd.setTextSize(1.85);
                        M5.Lcd.setCursor(55, 140);
                      
                        M5.Lcd.print("Please maintain a safe distance. ");
                        M5.Lcd.setCursor(130, 215);
                        M5.Lcd.setTextSize(2);
                        M5.Lcd.setTextColor(WHITE);
                        M5.Lcd.print("STAYAWAY COVID");
                        M5.Axp.SetLDOEnable(3,true);   //Open the vibration.   
                        delay(1000);
                        M5.Axp.SetLDOEnable(3,false);   //Open the vibration. 
                        delay(500);  
            }
            else{
                    M5.Lcd.fillScreen(GREEN);
                    M5.Lcd.setCursor(100, 100);
                    M5.Lcd.setTextSize(3);
                    M5.Lcd.setTextColor(BLACK);
                    M5.Lcd.print("Safe :)");
                    M5.Lcd.setCursor(130, 215);
                    M5.Lcd.setTextSize(2);
                    M5.Lcd.setTextColor(NAVY);
                    M5.Lcd.print("STAYAWAY COVID");
                    delay(2000);          
                }
           }            
         }
    }        
  };



