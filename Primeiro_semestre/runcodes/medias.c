#include <math.h>
#include <stdio.h>

int main()
{
    float a,b,c,media_ar,media_ge,media_har;
    scanf("%f%f%f",&a, &b, &c);
    media_ar = (a+b+c)/3;
    media_ge = pow(a*b*c,1.0000000/3);
    media_har = 3/(pow(a,-1)+pow(b,-1)+pow(c,-1));
    printf("Media aritimetica: %.4f\nMedia harmonica: %.4f\nMedia geometrica: %.4f\n", media_ar, media_har, media_ge);

    return 0;
}
