#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED



#endif // FUNCIONES_H_INCLUDED
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[]);



/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[]);



/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[]);


/**
 * \brief Limpia el stdin, similar a fflush
 * \param -
 * \return -
 *
 */
void clean_stdin(void);



/**
 * \brief Solicita un string
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargar� el texto ingresado
 * \return -
 *
 */
void validarLetras(char mensajeOk[],char mensajeError[], char input[]);




/**
 * \brief Verifica si el valor recibido es num�rico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es n�merico y 0 si no lo es
 *
 */
int esNumerico(char str[]);



/**
 * \brief Solicita un texto num�rico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo n�meros
 */
int getStringNumeros(char mensaje[],char input[]);




/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El n�mero ingresado por el usuario
 *
 */
int validarEntero(char mensajeOk[],char mensajeError[], int min, int max);





/**
 * \brief Verifica si el valor recibido es num�rico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es n�merico y 0 si no lo es
 *
 */
int esNumericoFlotante(char str[]);



/**
 * \brief Solicita un texto num�rico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar� el texto ingresado
 * \return 1 si el texto contiene solo n�meros
 */
int getStringNumerosFlotantes(char mensaje[],char input[]);




/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El n�mero ingresado por el usuario
 *
 */
float validarEnteroFlotante(char mensajeOk[],char mensajeError[], int min, int max);


/** \brief solicita un numero entero y lo valida
 \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El n�mero ingresado por el usuario
 */

int validarOpcion(char mensajeOk[],char mensajeError[], int min, int max);
