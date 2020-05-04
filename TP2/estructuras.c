#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funciones.h"
#include "estructuras.h"

void hardcodearEmployess(Employee arrayEmployers[])
{
    Employee list[]=
    {
        {10,"beto","casela",25000.5,1,1},
        {11,"yesica","paez",35000.5,2,1},
        {12,"mirko","sanchez",45000.5,1,1},
        {13,"mica","casela",55000.5,2,1},
        {14,"coco","sily",65000.5,3,1},
    };
    for(int i=0; i<5; i++)
    {
        arrayEmployers[i]=list[i];
    }

}

void hardcodearSector(Sector arraySector[])
{
    Sector list[]=
    {
        {1,"Sistemas"},
        {2,"Base de datos"},
        {3,"Desarrollo"},
    };

    for(int i=0; i<3; i++)
    {
        arraySector[i]=list[i];
    }

}





void initEmployees(Employee arrayEmployers[],int cantEmp, int value)
{

    int i;
    for(i=0; i <cantEmp; i++)
    {
        arrayEmployers[i].isEmpty = value;
    }
}



int encontrarLugarLibre(Employee arrayEmployers[],int cantEmp)
{
    int i;
    for(i=0; i <cantEmp; i++)
    {
        if(arrayEmployers[i].isEmpty == 0)
        {
            return i;
        }
    }
    return -1;
}


int altaEmployee(Employee arrayEmployers[],int cantEmp,Sector arraySector[],int cantSector, int lastId)
{
    Employee nuevoEmpleado;
    int indiceLugarLibre;

    indiceLugarLibre=encontrarLugarLibre(arrayEmployers,cantEmp);
    if(indiceLugarLibre == -1)
    {
        printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n\n");


    }
    else
    {

        printf("\nALTA\n");

        nuevoEmpleado.id=lastId;


        validarLetras("Ingrese el nombre: ","el nombre debe ser en letras",nuevoEmpleado.name);
        validarLetras("Ingrese el apellido: ","el apellido debe ser en letras",nuevoEmpleado.lastName);
        nuevoEmpleado.salary=validarEnteroFlotante("Ingrese el sueldo: ","El sueldo debe ser numerico: ",0.00,99999);

        printf("\nSECTORES:\n\n");

        for(int i=0; i< cantSector; i++)
        {
            printf("%d- %s\n", arraySector[i].idSector, arraySector[i].nameSector );
        }

        nuevoEmpleado.sector=validarEntero("Ingrese sector: ","El sector debe ser numerico: ",1,3);
        nuevoEmpleado.isEmpty=1;
        arrayEmployers[indiceLugarLibre]=nuevoEmpleado;


    }
    return indiceLugarLibre;
}






int removeEmployee(Employee arrayEmployers[],int cantEmp, int id)
{
    int encontrarIndice;
    char confirma;

    encontrarIndice=findEmployeeById(arrayEmployers,cantEmp,id);
    if(encontrarIndice == -1)
    {
        printf("\n\nNO SE ENCUENTRA ESE CODIGO\n");

    }
    else
    {
        printf("\nConfirma baja?: ");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma == 's')
        {
            arrayEmployers[encontrarIndice].isEmpty = 0;
            printf("\nSe ha realizado la baja\n\n");
        }
        else
        {
            printf("\nSe ha cancelado la baja\n\n");
        }
    }
    return encontrarIndice;

}





void  addEmployee(Employee arrayEmployers[],int indiceLugarLibre, int idAux,char nameAux[],char lastNameAux[],float salaryAux, int sectorAux)
{

    arrayEmployers[indiceLugarLibre].id=idAux;
    strcpy(arrayEmployers[indiceLugarLibre].name,nameAux);
    strcpy(arrayEmployers[indiceLugarLibre].lastName,lastNameAux);
    arrayEmployers[indiceLugarLibre].salary=salaryAux;
    arrayEmployers[indiceLugarLibre].sector=sectorAux;
    arrayEmployers[indiceLugarLibre].isEmpty=1;


}

void addSector(Sector arraySector[],int indiceLugarLibre,int idAux,char nameAux[])
{
    arraySector[indiceLugarLibre].idSector=idAux;
    strcpy(arraySector[indiceLugarLibre].nameSector,nameAux);
}




int findEmployeeById(Employee arrayEmployers[],int cantEmp,int idAux)
{

    int i;
    for(i=0; i <cantEmp; i++)
    {
        if(arrayEmployers[i].id == idAux && arrayEmployers[i].isEmpty == 1)
        {
            return i;
        }
    }
    return -1;
}

void mostrarEmployee(Employee emp,Sector arraySector[],int cantSector)
{
    int indice;
    for(int i=0; i< cantSector; i++)
    {
        if((emp.sector == arraySector[i].idSector ) )
        {
            indice = i;
            break;
        }
    }
    printf("\n%d  %10s   %10s   %10.2f   %12s\n\n",emp.id,emp.name,emp.lastName,emp.salary,arraySector[indice].nameSector);
}

void mostrarEmployers(Employee arrayEmployers[], int cantEmp,Sector arraySector[],int cantSector)
{
    int cont=0;
    int i;

     printf("****Listado de empleados*****\n\n");
    printf("Id       Nombre     Apellido    Sueldo      Sector\n");
    for(i=0; i < cantEmp; i++)
    {
        if(arrayEmployers[i].isEmpty != 0)//=1
        {
            mostrarEmployee(arrayEmployers[i],arraySector,cantSector);
            cont++;
        }
    }
    if(cont==0)
    {
        printf("No hay empleados para mostrar\n\n");
    }


}

void modificarEmployee(Employee arrayEmployers[],int cantEmp,Sector arraySector[],int cantSector)
{
    int idAux;
    int encontrarIndice;
    int opcionModificacion;
    int sectorAux;
    float salarioAux;
    char nombreAux[20];
    char apellidoAux[20];
    char confirma;

    idAux=validarEntero("Ingrese id de empleado a modificar: ", "El id debe ser numerico: ",0,9999);
    encontrarIndice=findEmployeeById(arrayEmployers,cantEmp,idAux);
    if(encontrarIndice==-1)
    {
        printf("No se encuentra ese codigo!\n");

    }

    else
    {
        while(opcionModificacion!=5)
        {
            opcionModificacion=validarOpcion("\nIngrese opcion:\n1-Nombre  \n2-Apellido  \n3-Salario  \n4-Sector  \n5-Salir\n","Opcion debe ser numerico: ",1,5);
            switch(opcionModificacion)
            {
            case 1:
                validarLetras("Ingrese nuevo nombre: ","Nuevo nombre debe ser en letras",nombreAux);
                printf("\nConfirma modificacion?: ");
                fflush(stdin);
                scanf("%c", &confirma);

                if(confirma == 's')
                {
                    strcpy(arrayEmployers[encontrarIndice].name,nombreAux);
                    printf("\nSe ha realizado la modificacion\n\n");
                }
                else
                {
                    printf("\nSe ha cancelado la modificacion\n\n");
                }
                //strcpy(arrayEmployers[encontrarIndice].name,nombreAux);
                opcionModificacion=5;
                break;
            case 2:
                validarLetras("Ingrese nuevo apellido: ","Nuevo apellido debe ser en letras",apellidoAux);
                printf("\nConfirma modificacion?: ");
                fflush(stdin);
                scanf("%c", &confirma);

                if(confirma == 's'||'S')
                {
                    strcpy(arrayEmployers[encontrarIndice].lastName,apellidoAux);
                    printf("\nSe ha realizado la modificacion\n\n");
                }
                else
                {
                    printf("\nSe ha cancelado la modificacion\n\n");
                }
                //strcpy(arrayEmployers[encontrarIndice].name,nombreAux);
                opcionModificacion=5;
                break;

            case 3:
                salarioAux=validarEnteroFlotante("Ingrese nuevo sueldo: ","Sueldo en numeros: ",0.00,99999.99);
                printf("\nConfirma modificacion?: ");
                fflush(stdin);
                scanf("%c", &confirma);

                if(confirma == 's'||'S')
                {
                    arrayEmployers[encontrarIndice].salary=salarioAux;
                    printf("\nSe ha realizado la modificacion\n\n");
                }
                else
                {
                    printf("\nSe ha cancelado la modificacion\n\n");
                }
                //strcpy(arrayEmployers[encontrarIndice].name,nombreAux);
                opcionModificacion=5;

                break;
            case 4:
                printf("\nSECTORES:\n\n");

                for(int i=0; i< cantSector; i++)
                {
                    printf("%d- %s\n", arraySector[i].idSector, arraySector[i].nameSector );
                }
                sectorAux=validarEntero("Ingrese id del nuevo sector: ","Id debe ser numerico: ",1,3);
                printf("\nConfirma modificacion?: ");
                fflush(stdin);
                scanf("%c", &confirma);

                if(confirma == 's'||'S')
                {
                    arrayEmployers[encontrarIndice].sector=sectorAux;
                    printf("\nSe ha realizado la modificacion\n\n");
                }
                else
                {
                    printf("\nSe ha cancelado la modificacion\n\n");
                }
                //strcpy(arrayEmployers[encontrarIndice].name,nombreAux);
                opcionModificacion=5;
                break;
            }//fin swith
        }//fin while
    }//fin else

}//fin funcion



void listaApellidoSector(Employee arrayEmployers[],int cantEmp,Sector arraySector[],int cantSector)
{

    Employee empAux;
    int i,j;

    for(i=0; i < cantEmp - 1; i++)
    {
        if(arrayEmployers[i].isEmpty == 0)
        {
            continue;
        }
        for(j=i+1; j < cantEmp; j++)
        {
            if(arrayEmployers[j].isEmpty == 0)
            {
                continue;
            }
            if(strcmp(arrayEmployers[j].lastName,arrayEmployers[i].lastName) < 0)
            {
                empAux = arrayEmployers[j];
                arrayEmployers[j] = arrayEmployers[i];
                arrayEmployers[i] = empAux;
            }
            else if(strcmp(arrayEmployers[j].lastName,arrayEmployers[i].lastName) == 0)
            {
                if(strcmp(arraySector[j].nameSector,arraySector[i].nameSector) > 0)
                {
                    empAux = arrayEmployers[j];
                    arrayEmployers[j] = arrayEmployers[i];
                    arrayEmployers[i] = empAux;
                }
            }
        }
    }
}//fin funcion





void salariosPromedios(Employee arrayEmployers[],int cantEmp)
{

    printf("\n\nTotal y Promedio de los Importes y cuantos empleados superan el importe promedio: \n\n");

//------------Total importes--------------------------------
    float totalImporte = 0;

    for(int i=0; i< cantEmp; i++)
    {

        if(arrayEmployers[i].isEmpty == 1)
        {
            totalImporte += arrayEmployers[i].salary;
        }
    }


//--------------------------------------------------------------------
//----------Promedio Importes-----------------------------------------
    int i;
    float precioTotal = 0;
    int productosActivos = 0;

    for(i=0; i < cantEmp; i++)
    {
        if(arrayEmployers[i].isEmpty == 1)
        {
            precioTotal = precioTotal + arrayEmployers[i].salary;
            productosActivos++;
        }
    }
//--------------------------------------------------------------------
//-----------Superan Precio Promedio----------------------------------
    int J;
    float precioTotalProm = 0;
    int productosActivosProm = 0;
    int total= 0;

    for(J=0; J < cantEmp; J++)
    {
        if(arrayEmployers[J].isEmpty == 1)
        {
            precioTotalProm = precioTotalProm + arrayEmployers[J].salary;
            productosActivosProm++;
        }
    }
    for(int J=0; J< cantEmp; J++)
    {

        if((arrayEmployers[J].isEmpty == 1)&&(arrayEmployers[J].salary>precioTotalProm / (float)productosActivosProm)) // cero es que esta dado de alta.
        {
            total += arrayEmployers[J].isEmpty;

        }
    }

    // system("cls");
//----------------------------------------------------------------------------------------------------------------



    printf("\nEl total de importe es $ %.2f\n\n", totalImporte);
    printf("\nEl promedio de importe es $ %.2f\n\n",precioTotal / (float)productosActivos);
    printf("\nEl total de importes mayores al promedio  es  %d\n\n", total);

}//fin funcion
