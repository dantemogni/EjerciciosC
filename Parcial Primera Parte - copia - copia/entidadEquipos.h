/** \brief Estructura de la entidad equipos
 *
 * \param int almacena el codigo autoincremental de los equipos
 * \param char almacena el nombre de los equipos
 * \param char alamcena la localidad de los equipos
 *
 */
typedef struct
{
    int codigoEquipo;
    char nombre[51];
    char localidad[33];
} eEquipos;

/** \brief Muestra el menu correspondiente a los equipos
 *
 * \param eEquipos[] declara un array de tipo eEquipo
 * \param int corresponde a la cantidad total del array
 * \return void no devuelve nada
 *
 */
void subMenuEquipo(eEquipos[], int);

/** \brief Aqui se cargan los datos del equipo
 *
 * \param eEquipos[] array de tipo eEquipo
 * \param int cantidad total del array
 * \return void no devuelve nada
 *
 */
void cargaEquipos(eEquipos[], int);

/** \brief Funcion que muestra por printf() los datos ingresados
 *
 * \param eEquipos[] array de tipo eEquipo
 * \param int cantidad
 * \return void no devuelve nada
 *
 */
void mostrarEquipos(eEquipos[], int);

/** \brief Ordena alfabeticamente los nombres de los equipos y todos sus datos
 *
 * \param eEquipos[] array de tipo eEquipos
 * \param int cantidad total
 * \return void no retorna nada
 *
 */
void listarAlfabeticamenteEquipos(eEquipos[], int);

/** \brief Permite modificar datos del equipo, ya sea el nombre o la localidad
 *
 * \param eEquipos[] array de tipo eEquipos
 * \param int cantidad
 * \return void no retorna nada
 *
 */
void modificarEquipo(eEquipos[], int);


/** \brief a partir de un valor dado, encunetra una coindicencia dentro del array equipos
 *
 * \param eEquipos[] array de tipo eEquipos
 * \param int cantidad
 * \param int valor que se le va a pasar a la funcion, donde va a buscar la coindicencia
 * \return int devuelve el subindice i si halla una coicidencia, -1 si no
 *
 */
int encontrarEquipo(eEquipos[], int, int);

/** \brief permite eliminar un equipo a través de una baja lógica
 *
 * \param eEquipos[] array de eEquipos
 * \param int cantidad
 * \return void no retorna nada
 *
 */
void eliminarEquipo(eEquipos[], int);
