#include "mbed.h"

#define ZERO 0b0000000
#define n0 0b0111111
#define n1 0b0000110
#define n2 0b1011011
#define n3 0b1001111
#define n4 0b1100110
#define n5 0b1101101
#define n6 0b1111101
#define n7 0b0100111
#define n8 0b1111111
#define n9 0b1101111


void show(int n, int ms);

Serial pc(USBTX, USBRX);
DigitalOut led(dp18);
BusOut segments(dp2/*A-11*/,dp13/*B-7*/,dp11/*C-4*/,dp10/*D-2*/,dp9/*E-1*/,dp6/*F-10*/,dp4/*G-5*//*DP-3*/);
int number[11] = {n0,n1,n2,n3,n4,n5,n6,n7,n8,n9,ZERO};


// 1桁だけ光らせるプログラム
int main() {
  led = 1;
  segments = ~number[10]
  while(1) {
    for(int i = 0; i < 10; i++) {
      show(i,400);
    }
  }
}

void show(int n, int ms/*何ms表示するか*/){
    if(n>=0 && n<10000){
      segments = ~number[n];
      wait_ms(400);
        }
    }
}
