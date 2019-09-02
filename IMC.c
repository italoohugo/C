#include <stdio.h>

int main(void) {

    float massa, altura, imc;

    printf("Informe seu peso (Kg): ");

    scanf("%f", &massa);

    printf("Informe sua altura (cm): ");

    scanf("%f", &altura);

    imc = massa / (altura * altura);

    printf("IMC: %.1f\n", imc);

    return 0;

}
