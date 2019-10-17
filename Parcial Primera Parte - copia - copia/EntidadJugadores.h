/** \brief estructura para la entidad Jugadores
 *
 * \param int codigo autoincremental de los jugadores
 * \param char apellido de los jugadores
 * \param char nombre de los jugadores
 * \param int codigo del equipo al cual pertenecen (debe existir)
 * \param char sexo de los jugadores (f/m)
 * \param eFecha dato de tipo eFecha que corresponde a la fecha de nacimiento de los jugadores
 *
 */
typedef struct
{
    int codigoJugador;
    char apellidoJugador[31];
    char nombreJugador[31];
    int codigoEquipo;
    char sexo;
    eFecha fechaNacimiento;
} eJugadores;

/** \brief Muestra el menu para interactuar con la entidad Jugadores
 *
 * \param eJugadores[] array de tipo eJugadores
 * \param int cantidad (tamaño) total del array
 * \return void
 *
 */
void subMenuJugadores(eJugadores[], int);

/** \brief Permite la alta de los jugadores
 *
 * \param eJugadores[] array de tipo eJugadores
 * \param int  cantidad (tamaño) total del array
 * \return void
 *
 */
void cargaJugadores(eJugadores[], int);

/** \brief Funcion que muestra por printf() los datos de los Jugadores
 *
 * \param eJugadores[] array de tipo eJugadores
 * \param int cantidad (tamaño) total del array
 * \return void
 *
 */
void mostrarJugadores(eJugadores[], int);

/** \brief Ordena alfabeticamente por nombre y apellido a los jugadores del array
 *
 * \param eJugadores[] array de tipo eJugadores
 * \param int cantidad (tamaño) total del array
 * \return void
 *
 */
void listarAlfabeticamenteJugadores(eJugadores[], int);

/** \brief  a partir de un valor dado, encunetra una coindicencia dentro del array jugadores
 *
 * \param eJugadores[] array de tipo eJugadores
 * \param int cantidad
 * \param int valor por el cual se busca el dato
 * \return int devuelve el subindice i en caso de encontrar una coincidencia, caso contrario devuelve -1
 *
 */
int encontrarJugadores(eJugadores[], int, int);

/** \brief Permite eliminar un jugador, con una baja lógica
 *
 * \param eJugadores[] array de tipo eJugadores
 * \param int cantidad (tamaño) del array
 * \return void no retorna nada
 *
 */
void eliminarJugadores(eJugadores[], int);
