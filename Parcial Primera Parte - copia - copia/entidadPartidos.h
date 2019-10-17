/** \brief Estructura para la entidad Partidos
 *
 * \param int codigo autoincremental de los partidos
 * \param int codigo del equipo visitante (debe existir en la entidad Equipos)
 * \param int codigo del equipo local (debe existir en la entidad Equipos)
 * \param int codigo del referi (debe existir en la entidad Referis)
 * \param eFecha fecha del partido
 *
 */
typedef struct
{
    int codigoPartido;
    int codigoVisitante;
    int codigoLocal;
    int codigoReferi;
    eFecha fechaPartido;
} ePartido;


/** \brief Menu que permite interactuar con la entidad partidos
 *
 * \param ePartido[] array de tipo ePartidos
 * \param int cantidad total del array
 * \return void no devuelve nada
 *
 */
void subMenuPartidos(ePartido[], int);

/** \brief funcion que permite el alta de los partidos
 *
 * \param ePartido[]
 * \param int cantidad (tamaño total del array)
 * \return void
 *
 */
void cargaPartidos(ePartido[], int);

/** \brief funcion que muestra los datos asignados a cada partido
 *
 * \param ePartido[]
 * \param int cantidad (tamaño total del array)
 * \return void
 *
 */
void mostrarPartidos(ePartido[], int);

/** \brief Ordena los partidos por fecha, de menor a mayor
 *
 * \param ePartido[]
 * \param int cantidad (tamaño total del array)
 * \return void
 *
 */
void listarFechaPartidos(ePartido[], int);

