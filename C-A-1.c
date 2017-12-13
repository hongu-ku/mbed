#include <stdio.h>
#include <math.h>

int main(void) {
  double a,b,c;
  printf("a=");
  scanf("%lf",&a);
  printf("b=");
  scanf("%lf",&b);
  printf("c=");
  scanf("%lf",&c);
  double x[3];
  // とりあえずx=-2bは解                                                        
  x[0] = -2 * b;
  // 残りは(a^2+1)x^2+bx-c=0やから                                              
  a = a*a + 1;
  c = -c;
  double d = sqrt(b*b - 4 * a * c) ;
  x[1] = (-b + d)/(2 * a);
  x[2] = (-b - d)/(2 * a);
  //2つの等値判定はしない。それは頑張れ                                         
  printf("x = %f, %f, %f\n",x[0],x[1],x[2]);
  //検算もしない.                                                               
  return 0;
}
