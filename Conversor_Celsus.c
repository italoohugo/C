//
// Created by hugo- on 13/08/2018.
//
#include <stdio.h>

float converteCF (float);
float converteFC (float);

int main (void)
{
    float c;
    float f;
    printf("Informe TEMP em Celsius: ");
    scanf("%f",&c);
    f = converteCF(c);
    printf("Temperatura em Fahrenheit: %.1f",f);
    return 0;
}

float converteCF(float t){
    return  t *1.8 + 32;
}

float  converteFC(float t){
    return  (5.0/9.0)*(t+32.0);
}
