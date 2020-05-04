
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funciones.h"
#include "estructuras.h"

#define CANT 10
#define SECT 3

int main()
{
    Employee arrayEmployers[CANT];
    Sector arraySector[SECT];

    int lastId=15;
    int opcion = 0;
    int flag=0;
    int informe;
    int pedirId;



    initEmployees(arrayEmployers,CANT,0);
    hardcodearEmployess(arrayEmployers);
    hardcodearSector(arraySector);




    while(opcion!=5)
    {
        opcion=validarOpcion("\n\n----------------MENU-------------\n1 - ALTA \n2 - MODIFICAR \n3 - BAJA\n4 - INFORMAR\n5 - SALIR\n\n\n","Opcion incorrecta",1,5);
        switch(opcion)
        {
        case 1:
            if(altaEmployee(arrayEmployers,CANT,arraySector,SECT,lastId))
            {
                lastId++;
            }
            flag=1;
            system("pause");
            break;

        case 2:
            if(flag==0)
            {
                printf("Primero debe darse de alta a algun empleado");
            }
            else
            {
                modificarEmployee(arrayEmployers,CANT,arraySector,SECT);
            }

            break;

        case 3:
            if(flag==0)
            {
                printf("Primero debe darse de alta a algun empleado\n");
            }
            else
            {
                mostrarEmployers(arrayEmployers,CANT,arraySector,SECT);
                pedirId=validarEntero("Ingrese Id de empleado a eliminar: ","El Id debe ser numerico",0,9999);
                removeEmployee(arrayEmployers,CANT,pedirId);
            }

            system("pause");
            break;
        case 4:
            if(flag==0)
            {
                printf("Primero debe darse de alta a algun empleado");
            }
            else
            {
                mostrarEmployers(arrayEmployers,CANT,arraySector,SECT);
                printf("Informes: \n");
                informe=validarEntero("Elija opcion: \n1. Listado de los empleados ordenados alfabeticamente por Apellido y Sector.\n2. Total y promedio de los salarios, y cuantos empleados superan el salario promedio.\n","Opcion incorrecta",1,2);

                if (informe==1)
                {
                    listaApellidoSector(arrayEmployers,CANT,arraySector,SECT);
                    mostrarEmployers(arrayEmployers,CANT,arraySector,SECT);
                }
                else
                {
                    salariosPromedios(arrayEmployers,CANT);
                }
            }
            break;
        }//fin swith
    }//fin while
    return 0;
}
