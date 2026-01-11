#include <U8g2lib.h>
#include <Wire.h>
#include <math.h>

const int potenciometro = A0;
int contador = 0;

// OLED SSD1306 128x64 por I2C
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0);

void setup() {
  pinMode(potenciometro,INPUT);
  u8g2.begin();
}
void parpadeo(){
  u8g2.clearBuffer();
  u8g2.drawBox(28, 32, 24, 4);
  u8g2.drawBox(76, 32, 24, 4);
  u8g2.sendBuffer();
  delay(120);
}

void espirales(){
  u8g2.clearBuffer();
  float b = 1;
  for(float theta=0; theta<7 * PI; theta+=0.05){
    float r = b * theta;

    float x = (r * cos(theta))+40;
    float y = (r * sin(theta))+32;

    float w = (r * cos(theta))+88;
    float z = (r * sin(theta))+32;

    u8g2.drawPixel(x, y);
    u8g2.drawPixel(w, z);
    u8g2.sendBuffer();
  }
  delay(2000);
}

void hipnosis1(){
  u8g2.clearBuffer();
  for(int radio=0; radio<18; radio = radio+4){
    u8g2.drawCircle(40, 32, radio);
    u8g2.drawCircle(88, 32, radio);
  }
  u8g2.sendBuffer();
  delay(100);
}
void hipnosis2(){
  u8g2.clearBuffer();
  for(int radio=0; radio<18; radio = radio+3){
    u8g2.drawCircle(40, 32, radio);
    u8g2.drawCircle(88, 32, radio);
  }
  u8g2.sendBuffer();
  delay(100);
}

void mareo(){
  hipnosis1();
  hipnosis2();
}

void malito(){
  u8g2.clearBuffer();
  u8g2.drawCircle(40, 32, 7);
  u8g2.drawCircle(88, 32, 17);
  u8g2.drawDisc(40, 32,2);
  u8g2.drawDisc(88, 32,8);
  u8g2.sendBuffer();
  delay(100);
}

void derecha(){
  u8g2.clearBuffer();
  u8g2.drawCircle(60, 32, 12);
  u8g2.drawCircle(108, 32, 12);
  u8g2.drawDisc(60, 32,8);
  u8g2.drawDisc(108, 32,8);
  u8g2.sendBuffer();
  delay(2000);
}

void izquierda(){
  u8g2.clearBuffer();
  u8g2.drawCircle(20, 32, 12);
  u8g2.drawCircle(68, 32, 12);
  u8g2.drawDisc(20, 32,8);
  u8g2.drawDisc(68, 32,8);
  u8g2.sendBuffer();
  delay(2000);
}

void movimiento_ojos(){
  derecha();
  parpadeo();
  izquierda();
}

void ojos_normales(){
  u8g2.clearBuffer();
  u8g2.drawCircle(40, 32, 12);
  u8g2.drawCircle(88, 32, 12);
  u8g2.drawDisc(40, 32,8);
  u8g2.drawDisc(88, 32,8);
  u8g2.sendBuffer();
  delay(2000);
}

void loop(){
  contador++;
  int valor = analogRead(potenciometro);

  if (valor >= 341 && valor <= 682) {
    ojos_normales();
    if(contador == 3){
      parpadeo();
      movimiento_ojos();
      contador = 0;
    }
  }
  else if ((valor >= 200 && valor < 341) || (valor > 682 && valor <= 850)) {
    malito();
    if(contador==3){
      parpadeo();
      contador = 0;
    }
  }
  else { // valor < 341
    mareo();
    contador = 0;
  }
}



