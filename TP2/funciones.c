
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "estructuras.h"





void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}



int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}




int getStringLetras(char mensaje[],char input[])// el nombre va a ser menos de X caracteres 10 en este caso.
{
    char aux[256];
    getString(mensaje,aux);
    if((esSoloLetras(aux))&& (strlen (aux) <50 ))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

void validarLetras(char mensajeOk[],char mensajeError[], char input[])
{

    while(1)
    {
        if (!getStringLetras(mensajeOk,input))
        {
            printf ("%s\n",mensajeError);
            continue;
        }

        clean_stdin();
        break;
    }

}







int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}



int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}



int validarEntero(char mensajeOk[],char mensajeError[], int min, int max)
{
    char auxStr[256];
    int auxInt;
    while(1)
    {
        if (!getStringNumeros(mensajeOk,auxStr))
        {
            printf ("%s\n",mensajeError);
            continue;

        }
        auxInt = atoi(auxStr);
        if(auxInt < min || auxInt > max)
        {
            printf ("El numero del debe ser mayor a %d y menor a %d\n",min,max);
            continue;

        }
        return auxInt;


    }
     //fflush(stdin);

}


int esNumericoFlotante(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}


int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


float validarEnteroFlotante(char mensajeOk[],char mensajeError[], int min, int max)
{
    char auxStr[256];
    float auxFloat;
    while(1)
    {
        if (!getStringNumerosFlotantes(mensajeOk,auxStr))
        {
            printf ("%s\n",mensajeError);
            continue;

        }
        auxFloat = atof(auxStr);
        if(auxFloat < min || auxFloat > max)
        {
            printf ("El numero del debe ser mayor a %d y menor a %d\n",min,max);
            continue;

        }
        return auxFloat;


    }
     //fflush(stdin);

}
//-----------------------------------------------------------------------------------------------------


int validarOpcion(char mensajeOk[],char mensajeError[], int min, int max){

char auxStr[256];
    int auxInt;
    while(1)
    {
        if (!getStringNumeros(mensajeOk,auxStr))
        {
            printf ("%s\n",mensajeError);
            continue;

        }
        auxInt = atoi(auxStr);
        if(auxInt < min || auxInt > max)
        {
            printf ("La opcion debe estar entre: %d y  %d\n",min,max);
            continue;

        }
        return auxInt;


    }
     //fflush(stdin);

}
