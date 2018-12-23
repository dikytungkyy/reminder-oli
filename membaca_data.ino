const int sensor = A0;
int data = 0;

void setup() {
  // put your setup code here, to run once:
pinMode(sensor, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

int datakmRata=0;
for (int i = 0;i<5;i++ ){
  data = analogRead(sensor);
  int dataKm = map (data, 0,1023,0,120);
  datakmRata += dataKm;
  delay(500);
}
int cetak = datakmRata/ 5;
Serial.println(cetak);
delay(1000);
}
