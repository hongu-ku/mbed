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
BusOut leds(dp18/*6*/,dp25/*8*/,dp26/*9*/,dp1/*12*/);
BusOut segments(dp2/*A-11*/,dp13/*B-7*/,dp11/*C-4*/,dp10/*D-2*/,dp9/*E-1*/,dp6/*F-10*/,dp4/*G-5*//*DP-3*/);

int thousand, handred, ten, one;
int number[11] = {n0,n1,n2,n3,n4,n5,n6,n7,n8,n9,ZERO};
// ダイナミック点灯のプログラム
int main() {
  segments = ~number[10]
  while(1) {
    for(int i = 0; i < 10000; i++) {
      show(i,400);
    }
  }
}


void show(int n, int ms/*何ms表示するか*/){
    if(n>=0 && n<10000){
        thousand = n / 1000;
        handred = (n-thousand*1000) / 100 ;
        ten = (n-thousand*1000-handred*100) / 10;
        one = n-thousand*1000-handred*100-ten*10;
        for(int i=0; i<ms/4; i++){
            leds=THOUSAND;
            segments = thousand == 0 ? ~number[10] : ~number[thousand];
            wait_ms(1);
            leds=HANDRED;
            segments = handred == 0 && thousand == 0 ? ~number[10] : ~number[handred];
            wait_ms(1);
            leds=TEN;
            segments = ten == 0 && handred == 0 && thousand == 0 ? ~number[10] : ~number[ten];
            wait_ms(1);
            leds=ONE;
            segments = ~number[one];
            wait_ms(1);
            }
        }
    }
