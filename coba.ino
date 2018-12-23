///www.berbageilmu.blogspot.co.id///
#include <LiquidCrystal.h>
//inisialisasi PIN LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);//pin LCD             
int i=0;
void setup() {
    lcd.begin(16, 2);// set lcd pada saat sistem dimulai
    lcd.print("    Dio Toar   ");
  delay(2000);
}
void loop()
 {
  for (int i=16; i > 4; i--) //Variabel i=panjang LCD "16" jika i lebih dari 4 maka kurangi panjang "16"
{
  //running teks mulai
  lcd.setCursor(0,0);
  lcd.print("    Dio Toar   ");
  lcd.setCursor(i, 1);
  lcd.print("Berbage Ilmu"); //setup awal runnng teks
  delay(200);
lcd.clear();
 }
 //jika teks berjalan dan sudah sampai pada baris ke 4 lcd
  lcd.setCursor(0,0);
  lcd.print("    Dio Toar   ");
  lcd.setCursor(4, 1); // set baris ke 4 LCD
  lcd.print("Berbage Ilmu");// tampilkan pada baris ke empat (POSISI TENGAH TEKS PADA LCD)
  delay (200);
  lcd.clear();
{
  for (int i=3; i >= 0; i--) // Jika posisi teks sudah pada posisi baris 0, maka tampilkan kembali teks dan lakukan pengurangan karaker
{
  lcd.setCursor(0,0);
  lcd.print("    Dio Toar   ");
  lcd.setCursor(i, 1);
  lcd.print("Berbage Ilmu"); //print panjang teks pada posisi baris pada posisi 0
  delay(200);
lcd.clear();
 }

//pengurangan karakter
lcd.setCursor(0,0);
  lcd.print("    Dio Toar   ");
  lcd.setCursor(0, 1);
  lcd.print("erbage Ilmu");
  delay(200);
lcd.clear();
//pengurangan karakter teks jika pada posisi 1
lcd.setCursor(0,0);
  lcd.print("    Dio Toar   ");
  lcd.setCursor(0, 1);
  lcd.print("rbage Ilmu");
  delay(200);
lcd.clear();
lcd.setCursor(0,0);
  lcd.print("    Dio Toar   ");
  lcd.setCursor(0, 1);
  lcd.print("bage Ilmu");
  delay(200);
lcd.clear();
lcd.setCursor(0,0);
  lcd.print("    Dio Toar   ");
  lcd.setCursor(0, 1);
  lcd.print("age Ilmu");
  delay(200);
lcd.clear();
lcd.setCursor(0,0);
  lcd.print("    Dio Toar   ");
  lcd.setCursor(0, 1);
  lcd.print("ge Ilmu");
  delay(200);
lcd.clear();
lcd.setCursor(0,0);
  lcd.print("    Dio Toar   ");
  lcd.setCursor(0, 1);
  lcd.print("e Ilmu");
  delay(200);
lcd.clear();

lcd.setCursor(0,0);
  lcd.print("    Dio Toar   ");
  lcd.setCursor(0, 1);
  lcd.print(" Ilmu");
  delay(200);
lcd.clear();
lcd.setCursor(0,0);
  lcd.print("    Dio Toar   ");
  lcd.setCursor(0, 1);
  lcd.print("Ilmu");
  delay(200);
lcd.clear();
lcd.setCursor(0,0);
  lcd.print("    Dio Toar   ");
  lcd.setCursor(0, 1);
  lcd.print("lmu");
  delay(200);
lcd.clear();
lcd.setCursor(0,0);
  lcd.print("    Dio Toar   ");
  lcd.setCursor(0, 1);
  lcd.print("mu");
  delay(200);
lcd.clear();
lcd.setCursor(0,0);
  lcd.print("    Dio Toar   ");
  lcd.setCursor(0, 1);
  lcd.print("u");
  delay(200);
lcd.clear();
//Akhir pengurangan karakter
//tampilkan Blank pada LCD
lcd.setCursor(0,0);
  lcd.print("    Dio Toar   ");
  delay(200);
lcd.clear();
}
}
