#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED

typedef struct
{
    int idSector;
    char nameSector[20];
}Sector;



typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

#endif // ESTRUCTURAS_H_INCLUDED

void hardcodearEmployess(Employee arrayEmployers[]);
void hardcodearSector(Sector arraySector[]);



/** \brief inicializa los empleados de acuerdo a un valor pasado por referencia
 *
 * \param arrayEmployers array de empleados
 * \param cantEmp cantidad de empleados
 *
 */
void initEmployees(Employee arrayEmployers[],int cantEmp, int value);

/** \brief harcodea los empleados
 *
 * \param arrayEmployers es el array de empleados
 * \param indiceLugarLibre es el indice disponible a ser usado
 * \param idAux es el id del empleado
 * \param nameAux es el nombre del empleado
 * \param lastNameAux es el apellido del empleado
 * \param salary es el sueldo del empleado
 * \param sectorAux es el id del sector
 *
 */

void addEmployee(Employee arrayEmployers[],int indiceLugarLibre, int idAux,char nameAux[],char lastNameAux[],float salaryAux, int sectorAux);


/** \brief harcodea un sector
 *
 * \param arraySector es el sector a ser harcodeado
 * \param indiceLugarLibre es el indice disponible a ser usado
 * \param idAux es el id del sector
 * \param nameAux es el nombre del sector
 *
 */

void addSector(Sector arraySector[],int indiceLugarLibre,int idAux,char nameAux[]);



/** \brief encuentra a un empleado por su id
 *
 * \param arraEmployers es el array donde buscar
 * \param cantEmp es la cantidad de empleados
 * \param idAux es el id por el cual buscar
 *
 */

int findEmployeeById(Employee arrayEmployers[],int cantEmp,int idAux);


/** \brief encuentra un indice disponible en el array de empleados
 *
 * \param arrayEmployers es el array deempleados
 * \param cantEmp es la cantidad de empleados
 *
 */

int encontrarLugarLibre(Employee arrayEmployers[],int cantEmp);

/** \brief muestra los empleados
 *
 * \param arrayEmployers es el array de los empleados
 * \param cantEmp es la cantidad de emplados
 * \param arraySector es el array de los sectores
 * \param cantSector es la cantidad de sectores
 *
 */

void mostrarEmployers(Employee arrayEmployers[], int cantEmp,Sector arraySector[],int cantSector);

/** \brief muestra un empleado
 *
 * \param emp es un empleado
 * \param arraySector es el array de sectores
 * \return cantSector es la cantidad de sectores
 *
 */

void mostrarEmployee(Employee emp,Sector arraySector[],int cantSector);



/** \brief da de alta a los empleados
 *
 * \param arrayEmployers es el arrray de empleados
 * \param cantEmp es la cantidad de empleados
 * \param arraySector es el array de sectores
 * \param cantSector es la cantidad de sectores
 * \param lastId es el id con el cual va a comenzar el empleado dado de alta
 * \return devuelve el indice del empleado
 *
 */

int altaEmployee(Employee arrayEmployers[],int cantEmp,Sector arraySector[],int cantSector, int lastId);

/** \brief da de baja logica a un empleado
 *
 * \param arrayEmployers es el array de empleados
 * \param cantEmp es la cantidad de empelados
 * \param id es el id que se pide para realizar la baja
 *  \return devuelve el indice en 0
 */

int removeEmployee(Employee arrayEmployers[],int cantEmp, int id);

/** \brief modifica a un empleado determinado
 *
 * \param arrayEmployers es el array de empleados
 * \param cantEmp es la cantidad de empleados
 * \param arraySector es el array de sectores
 * \param cantSector es la cantidad de sectores
 *
 */

void modificarEmployee(Employee arrayEmployers[],int cantEmp,Sector arraySector[],int cantSector);


/** \brief ordena los empleados de acuerdo a su apellido y si son iguales, a su sector
 *
 * \param arrayEmployers es el array de empleados
 * \param cantEmp es la cantidad de empleados
 * \param arraySector es el array de sectores
 * \param cantSector es la cantidad de sectores
 *
 */

void listaApellidoSector(Employee arrayEmployers[],int cantEmp,Sector arraySector[],int cantSector);

/** \brief brinda la informacion del salario promedio en el array de empleados
 *
 * \param arrayEmployers es el array de empleados
 * \param cantEmp es la cantidad de empleados
 *
 */

void salariosPromedios(Employee arrayEmployers[],int cantEmp);
