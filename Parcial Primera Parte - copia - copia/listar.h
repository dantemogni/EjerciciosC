/** \brief Menu que permite interactuar con los arrays para listarlos de diferentes formas
 *
 * \param eEquipos[] llama al array de tipo eEquipos
 * \param eJugadores[] llama al array de tipo eJugadores
 * \param eReferi[] llama al array de tipo eReferi
 * \param ePartido[] llama al array de tipo ePartido
 * \param int cantidad (tamaño total del array)
 * \return void vacio
 *
 */
void subMenuListar(eEquipos[], eJugadores[], eReferi[], ePartido[], int);

/** \brief Muestra los jugadores existentes y en que equipo juegan
 *
 * \param eEquipos[] llama al array de tipo eEquipos
 * \param eJugadores[] llama al array de tipo eJugadores
 * \param int cantidad (tamaño total del array)
 * \return void vacio
 *
 */
void listarJugadoresPorEquipo(eEquipos[], eJugadores[], int);

/** \brief Informa el referi que participó en la mayor cantidad de partidos
 *
 * \param eReferi[]  llama al array de tipo eReferi
 * \param ePartido[]  llama al array de tipo ePartido
 * \param int cantidad (tamaño total del array)
 * \return void no retorna ningun valor
 *
 */
void informarReferi(eReferi[], ePartido[], int);

/** \brief Al ingresar un nombre, se muestran los jugadores con ese mismo nombre y en que equipo juegan
 *
 * \param eJugadores[] llama al array de tipo eJugadores
 * \param eEquipos[] llama al array de tipo eEquipos
 * \param int cantidad (tamaño total del array)
 * \return void
 *
 */
void ingresarNombre(eJugadores[], eEquipos[], int);

/** \brief Algoritmo que muestra el equipo con el nombre más largo de todos
 *
 * \param eEquipos[] llama al array de tipo eEquipos
 * \param int cantidad (tamaño total del array)
 * \return void no retorna nada
 *
 */
void equipoLargo(eEquipos[],int);

/** \brief Al ingresar una fecha de un partido, se muestran los equipos que participaron y el referi
 *
 * \param ePartido[] llama al array de tipo ePartido
 * \param eEquipos[] llama al array de tipo eEquipos
 * \param eReferi[] llama al array de tipo eReferi
 * \param int cantidad (tamaño total del array)
 * \return void no retorna nada
 *
 */
void ingresarFecha(ePartido[], eEquipos[], eReferi[], int);
