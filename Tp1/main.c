#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int salir=0;
    int opcion=0;
    int opcionMenuResultados=0;
    int flagA =0,flagB =0,flagC =0;
    float numA,numB;
    float sumarAB;
    float restarAB;
    float dividirAB;
    float multiplicarAB;
    float FactA;
    float FactB;
    system("cls");

    printf("Bienvenido\n\n");

    while(seguir=='s')
    {

        if(flagA ==0)
        {
            printf("1- Ingresar 1er operando (A = X)\n");
        }
        else
        {
            printf("1- Ingresar 1er operando (A= %.2f)\n", numA);
        }
        if(flagB ==0)
        {
            printf("2- Ingresar 2do operando (B = Y)\n");
        }
        else
        {
            printf("2- Ingresar 2do operando (B=%.2f)\n", numB);
        }
        printf("3- Calcular todas las operaciones\n");
        printf("4- Informar resultados\n");
        printf("5- Salir");

        printf("\nElija opcion 1 o 2  para comenzar a operar...\n\n\n\n\n");

        scanf("%d",&opcion);


        switch(opcion)
        {
        case 1:
            numA = numeroA();
            flagA =1;
            break;

        case 2:
            numB =numeroB();
            flagB =1;
            break;

        case 3:
            if (flagA ==0 || flagB==0)
            {
                printf("Primero deben estar cargados los numeros (A Y B) \nelige opcion 1 u opcion 2 para comenzar las operaciones...\n");
            }
            else
            {
                printf("Calculando operaciones... \n\n");
                sumarAB= suma(numA,numB);
                restarAB=resta(numA,numB);
                dividirAB=division(numA,numB);
                multiplicarAB=multiplicacion(numA,numB);
                FactA=factorial(numA);
                FactB=factorial(numB);

                //system("pause");
            }
            flagC=1;
            break;



        case 4:

            if (flagA ==0 || flagB==0|| flagC==0)
            {
                printf("Primero deben estar cargados los numeros (A Y B) y haberlos calculado. \nelige opcion 1 u opcion 2 para comenzar las operaciones...\n");
            }

            else
            {
                do
                {
                    printf("Selecione opcion a mostrar: \n\n");

                    printf("1)- El resultado de A+B  \n");
                    printf("2)- El resultado de A-B \n");
                    printf("3)- El resultado de  A/B \n");
                    printf("4)- El resultado de A*B \n");
                    printf("5)- El factorial de A!  y el factorial de B! \n");
                    printf("6)-Salir\n");

                    printf("\n\nIndique opcion: ");

                    scanf("%d",&opcionMenuResultados);

                    switch(opcionMenuResultados)
                    {
                    case 1:
                        printf("la suma es: %.2f\n",sumarAB);
                        break;
                    case 2:
                        printf("La resta es: %.2f\n",restarAB);
                        break;
                    case 3:
                        if(numB==0)
                        {
                            printf("No se puede dividir por cero\n");
                        }
                        else
                        {
                            printf("La division es: %.2f\n",dividirAB);
                        }
                        break;
                    case 4:
                        printf("La multiplicacion es: %.2f\n",multiplicarAB);
                        break;
                    case 5:
                        printf("El factorial de A es: %.2f\n",FactA);
                        printf("El factorial de B es: %.2f\n",FactB);
                        break;
                    case 6:
                        salir=1;
                        break;
                    default:
                        printf("\nOpcion Incorrecta\n\n");
                        system("pause");

                    }


                }
                while(salir!=1);
            }

            break;
        case 5:
            seguir='n';
            break;
        }
        system("pause");
        system("cls");

    }

    printf("\n\nGracias ,vuelvas pronto\n");

    return 0;
}
