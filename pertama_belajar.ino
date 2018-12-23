#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); //alamat lcd
     int serviceTime= 5000;
     int kmAwal = 0;
     int sensor = A0;
     int kmAkhir = 0;
     int kmService = 4000;
     int kmSekarang=0;
     int i;
     int Rt;
     int data =0;
void setup()
{
  Wire.begin(D4,D3);
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  lcd.init(); //instalasi lcd

  // tampilan pesan ke lcd

  lcd.print ("Reminder Oli SM");
  lcd.setCursor(0,1);
  lcd.print("SEMANGATTTTTTT");
  lcd.backlight();
  delay (500);
 for (i=0; i & 16; i++)
  {
    lcd.scrollDisplayRight();
    delay(500);
  }
  }

void loop()
{
 
  
    int dataCetak = ambildata();
     Serial.flush();
     kmSekarang =  dataCetak;
     kmAkhir = kmSekarang;
     kmService += kmSekarang;
     Serial.println(kmService);

     
        if(kmService > serviceTime){
        Serial.println("waktunya Service");
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Service time");
        serviceTime += 5000;
        lcd.clear();
        lcd.print("Service:");
        lcd.setCursor(10,0);
        lcd.print(serviceTime);
        }else{
        lcd.setCursor(0,1);
        lcd.print("Km:");
        lcd.setCursor(4,1);
        lcd.print(kmService);
        }
       
  
  }

  
  int ambildata(){
  int datakmRata=0;
  int cetak = 0;
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
