/** \brief Valida las letras
 *
 * \param char[] pide una variable de tipo string
 * \return int devuelve 1 si es de tipo letras o 0 si no cumple con la condición
 *
 */
int validarLetras(char[]);

/** \brief Valida el mail
 *
 * \param char[] pide una variable de tipo string
 * \return int devuelve 1 si es de tipo letras o 0 si no cumple con la condición
 *
 */
int validarMail(char[]);

/** \brief valida los numeros
 *
 * \param char[] pide una variable de tipo string
 * \return int devuelve 1 si es de tipo letras o 0 si no cumple con la condición
 *
 *
 */
int validarNumero(char[]);

/** \brief Pide al usuario el ingreso de una variable int
 *
 * \param char[] pide que se muestre un mensaje
 * \return int devuelve el dato ingresado
 *
 */
int pedirInt(char[]);

/** \brief Pide al usuario el ingreso de una variable de tipo string
 *
 * \param char[] pide que se muestre un mensaje
 * \param char[] el dato string guardado
 * \return int devuelve 0 si no se pudo validar, o 1 si efectivamente el dato es solo string
 *
 */
int pedirString(char[],char[]);

/** \brief Pide numeros en forma de string porque así se puede validar de forma más sencilla, un digito a la vez
 *
 * \param char[] pide que se muestre un mensaje
 * \param char[] el dato string guardado
 * \return int devuelve 0 si no se pudo validar, o 1 si efectivamente el dato es solo numerico
 *
 */
int pedirStringNumeros(char[],char[]);

/** \brief Se encarga de validar si la opcion ingresada es la correspondiente con el menu mostrado
 *
 * \param int este es el dato ingresado por el usuario que toma el scanf()
 * \param int el valor minimo de opciones en el menu
 * \param int el valor maximo de opciones en el menu
 * \param char[] pide que se muestre un mensaje
 * \param char[]  pide el ingreso de un numero como dato string para utilizarlo en la funcion pedirStringNumeros()
 * \return int devuelve el dato ingresado
 *
 */
int validarMenu(int, int, int, char[], char []);

/** \brief Valida el string de la funcion pedirStringNumeros
 *
 * \param int dato ingresado por el usuario
 * \param char[] pide un mensaje a mostrar
 * \param char[] dato numero en forma de string
 * \return int dato ingresado por el usuario
 *
 */
int validarStringNumerico(int,char[], char[]);

/** \brief Valida el string de la funcion pedirString
 *
 * \param char[] pide el ingreso de un mensaje a mostrar por printf()
 * \param char[] el dato string a validar
 * \return void
 *
 */
void validarStringLetras(char[], char[]);

