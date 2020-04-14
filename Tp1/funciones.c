#include <stdio.h>

float numeroA()
{
    float num;
    printf("ingrese numero para 1er operando (A): ");
    scanf("%f",&num);
    return num;
}
//--------------------------------------------------------------------------------------------------------------------------------------
float numeroB()
{
    float num;
    printf("ingrese numero para 2do operando (B):");
    scanf("%f",&num);
    return num;
}
//---------------------------------------------------------------------------------------------------------------------------------
float suma(float a,float b)
{
   /* float resultado;
    resultado=a+b;
    return resultado;*/
    return a+b;
}

float resta(float a, float b)
{
    float resultado;
    resultado=a-b;
    return resultado;
}

float division(float a, float b)
{
    float resultado;
    resultado= a/b;
    return resultado;
}

float multiplicacion(float a, float b)
{
    float resultado;
    resultado=a*b;
    return resultado;
}

float factorial(float a)
{

    float fact = 1;
    for (int i = a; i > 1; i--)
    {
        fact = fact * i;
    }
    return fact;

}

