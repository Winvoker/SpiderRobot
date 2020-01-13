/*
  0 sol ön gövdeye yakın olan
  1 sol ön orta
  2 sol ön uç
  3 sağ ön gövdeye yakın olan
  4 sağ ön orta
  5 sağ ön uç
  6 sol arka gövdeye yakın olan
  7 sol arka orta
  8 sol arka uç
  9 sağ arka gövdeye yakın olan
  10 sağ arka orta
  11 sağ arka uç
*/
#include <Wire.h>
#include <VirtualWire.h> // RF modül için gerekli Arduino kütüphanesi
#include <Adafruit_PWMServoDriver.h>
const int x=100;
int yon=0;
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
char*mesaj;  // Alınan mesajın yazıldığı değişken

#define SERVOMIN  150
#define SERVOMAX  600
char data='f';

void setup() {
  Serial.begin(9600);
  vw_set_ptt_inverted(true);
  vw_set_rx_pin(5);  //RF alıcı modü data çıkışı bağlı olduğu arduino piniu
  vw_setup(4000);
  vw_rx_start();
  
  pwm.begin();
  pwm.setPWMFreq(60);
  delay(10);  
  stand();
  // sabitle();
  Serial.write("ok");
}


void loop() {
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;
    if (vw_get_message(buf, &buflen))
    {
      if(buf[0]=='1'){
        Serial.println("1");
        fw();
      }
      else if(buf[0]=='2'){
      Serial.println("2");
      }
      else if(buf[0]=='3'){
      Serial.println("3");
        bw();
      }
      else if(buf[0]=='4'){
      Serial.println("4");
      }      
   }
   
}
void stand(){
  pwm.setPWM(2, 0, 375);
  delay(250);
  pwm.setPWM(5, 0, 375);
  delay(250);
  pwm.setPWM(8, 0, 375);
  delay(250);
  pwm.setPWM(11, 0, 375);
  delay(250);
  pwm.setPWM(1, 0, 450);
  delay(250);
  pwm.setPWM(4, 0, 450);
  delay(250);
  pwm.setPWM(7, 0, 250);
  delay(250);
  pwm.setPWM(10, 0, 250);
  delay(250);
  pwm.setPWM(2, 0, 375);
  delay(250);
  pwm.setPWM(5, 0, 375);
  delay(250);
  pwm.setPWM(0, 0, 375);
  delay(250);
  pwm.setPWM(3, 0, 375);
  delay(250);
  pwm.setPWM(6, 0, 375);
  delay(250);
  pwm.setPWM(9, 0, 375);
  delay(250);
  pwm.setPWM(1, 0, 375);
  delay(750);
  pwm.setPWM(4, 0, 375);
  delay(750);
  pwm.setPWM(7, 0, 375);
  delay(750);
  pwm.setPWM(10, 0, 375);
  delay(750);
  }
void sabitle(){
  pwm.setPWM(0, 0, 375);
  delay(50);
  pwm.setPWM(3, 0, 375);
  delay(50);
  pwm.setPWM(6, 0, 375);
  delay(50);
  pwm.setPWM(9, 0, 375);
  delay(50);
  pwm.setPWM(1, 0, 375);
  delay(50);
  pwm.setPWM(4, 0, 375);
  delay(50);
   pwm.setPWM(7, 0, 375);
  delay(50);
  pwm.setPWM(10, 0, 375);
  delay(50);
  }
void f_beginning() {
  pwm.setPWM(2, 0, 375);
  delay(250);
  pwm.setPWM(5, 0, 300);
  delay(250);
  pwm.setPWM(8, 0, 450); // ileri için azalt
  delay(250);
  pwm.setPWM(11, 0, 375);
  delay(250);
}
void fw() {
  if(yon!=1){
    f_beginning();
    yon=1;
    }
  pwm.setPWM(7, 0, 250);    // 7 ters havaya kalkması için azalt - 250
  delay(250);
  pwm.setPWM(8, 0, 375);
  delay(250);
  pwm.setPWM(7, 0, 375); // 7 ters havaya kalkması için azalt - 250
  delay(250);
  pwm.setPWM(1, 0, 500);
  delay(250);
  pwm.setPWM(2, 0, 450); // ileri gitmesi için arttır - 500
  delay(250);
  pwm.setPWM(1, 0, 375);
  delay(250);
  pwm.setPWM(10, 0, 250); // 10 ters havaya kalkması için azalt - 250
  delay(250);
  pwm.setPWM(11, 0, 300); // 250
  delay(250);
  pwm.setPWM(10, 0, 375);// 10 ters havaya kalkması için azalt - 250
  delay(250);
  pwm.setPWM(11, 0, 375);// gövde düzelt arka sol
  pwm.setPWM(8, 0, 450);// gövde düzelt ön sol
  delay(250);
  pwm.setPWM(4, 0, 425);
  delay(250);
  pwm.setPWM(5, 0, 375);
  delay(250);
  pwm.setPWM(4, 0, 375);// 
  delay(250);
  pwm.setPWM(5, 0, 300);// gövde düzelt arka sol
  pwm.setPWM(2, 0, 375); // gövde düzelt arka sağ
  delay(250);
  yon=1;
}

void bw() {
  if(yon!=3){
    back_beginning();
    yon=3;
    }
  pwm.setPWM(1, 0, 425);
  delay(250);
  pwm.setPWM(2, 0, 375);
  delay(250);
  pwm.setPWM(1, 0, 375);
  delay(250);
  pwm.setPWM(7, 0, 325);
  delay(250);
  pwm.setPWM(8, 0, 450);
  delay(250);
  pwm.setPWM(7, 0, 375);
  delay(250);
  pwm.setPWM(4, 0, 425);
  delay(250);
  pwm.setPWM(5, 0, 300);
  delay(250);
  pwm.setPWM(4, 0, 375);
  delay(250);
  pwm.setPWM(2, 0, 450);
  pwm.setPWM(5, 0, 375);
  delay(250);
  pwm.setPWM(10, 0, 325);
  delay(250);
  pwm.setPWM(11, 0, 375);
  delay(250);
  pwm.setPWM(10, 0, 375);
  delay(250);
  pwm.setPWM(8, 0, 375);
  pwm.setPWM(11, 0, 300);
  delay(250);
}
void back_beginning(){
  pwm.setPWM(2, 0, 450);// arka'ya giden ön ayak
  delay(300);
  pwm.setPWM(11, 0, 300); // arka'ya giden ön ayak
  delay(300);
  pwm.setPWM(5, 0, 375);
  delay(300);
  pwm.setPWM(8, 0, 375);
  delay(300);
  }
  
  void leftturn() {
  pwm.setPWM(0, 0, 375 + x);
  pwm.setPWM(1, 0, 375);
  pwm.setPWM(2, 0, 375);
  pwm.setPWM(3, 0, 375 + x);
  pwm.setPWM(4, 0, 375);
  pwm.setPWM(5, 0, 375);
  pwm.setPWM(6, 0, 375 - x);
  pwm.setPWM(7, 0, 375);
  pwm.setPWM(8, 0, 375);
  pwm.setPWM(9, 0, 375 - x);
  pwm.setPWM(10, 0, 375);
  pwm.setPWM(11, 0, 375);
  
}


void rightturn() {

  pwm.setPWM(0, 0, 375 - x);
  pwm.setPWM(1, 0, 375);
  pwm.setPWM(2, 0, 375);
  pwm.setPWM(3, 0, 375 - x);
  pwm.setPWM(4, 0, 375);
  pwm.setPWM(5, 0, 375);
  pwm.setPWM(6, 0, 375 + x);
  pwm.setPWM(7, 0, 375);
  pwm.setPWM(8, 0, 375);
  pwm.setPWM(9, 0, 375 + x);
  pwm.setPWM(10, 0, 375);
  pwm.setPWM(11, 0, 375);
}
