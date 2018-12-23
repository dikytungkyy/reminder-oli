

#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <ESP8266HTTPClient.h>

#define USE_SERIAL Serial
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); //alamat lcd
ESP8266WiFiMulti WiFiMulti;
const int sensor = A0;
int data =  0;
int cetak = 0;
int kmAwal = 0;
int kmAkhir = 0;
int kmService = 0;
int kmSekarang = 0;
void setup() {
  USE_SERIAL.begin(9600);
  Wire.begin(D4,D3);
  
  pinMode(sensor, INPUT);
  USE_SERIAL.println();
  USE_SERIAL.println();
  USE_SERIAL.println();

//  for (uint8_t t = 4; t > 0; t--) {
//    USE_SERIAL.printf("[SETUP] WAIT %d...\n", t);
//    USE_SERIAL.flush();
//    delay(1000);
//  }

//  WiFi.mode(WIFI_STA);
//  WiFiMulti.addAP("Kedai ichi", "fishandchips30k");

}

void loop() {
  data = ambildata();
  tampillcd(data);

  
// wait for WiFi connection
//  if ((WiFiMulti.run() == WL_CONNECTED)) {
//
//    HTTPClient http;
//
//    USE_SERIAL.print("[HTTP] begin...\n");
//    int data=ambildata();
//    tampillcd(data);
//    String dataCetak = String(kmService);
//    // configure traged server and url
//    //http.begin("https://192.168.1.12/test.html", "7a 9c f4 db 40 d3 62 5a 6e 21 bc 5c cc 66 c8 3e a1 45 59 38"); //HTTPS
//    http.begin("http://localhost/xampp/latihan/SETTER.php?km="+dataCetak); //HTTP
//
//    USE_SERIAL.print("[HTTP] GET...\n");
//    // start connection and send HTTP header
//    int httpCode = http.GET();
//
//    // httpCode will be negative on error
//    if (httpCode > 0) {
//      // HTTP header has been send and Server response header has been handled
//      USE_SERIAL.printf("[HTTP] GET... code: %d\n", httpCode);
//
//      // file found at server
//      if (httpCode == HTTP_CODE_OK) {
//        String payload = http.getString();
//        USE_SERIAL.println(payload);
//      }
//    } else {
//      USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
//    }
//
//    http.end();
//  }
//
//  delay(10000);
}

void tampillcd(int data){
  String cetak=String(data);
  kmSekarang = data;
  kmAkhir = kmSekarang;
  kmService += kmSekarang;
  Serial.print(kmSekarang);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("waktunya service");
  lcd.setCursor(0,1);
  lcd.print("Input=");
  delay(1000);
  lcd.print ("Reminder Ganti Oli");
  lcd.setCursor(0,1);
  lcd.print(cetak);
  lcd.backlight();
}

int ambildata(){
  int datakmRata=0;
for (int i = 0;i<5;i++ ){
  data = analogRead(sensor);
  int dataKm = map (data, 0,1023,0,120);
  datakmRata += dataKm;
  delay(500);
}
cetak = datakmRata/5;
return datakmRata;
delay(1000);
}
