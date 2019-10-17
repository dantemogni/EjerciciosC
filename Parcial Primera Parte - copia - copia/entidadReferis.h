/** \brief estructura para la entidad de Referis
 *
 * \param int codigo autoincremental de los referis
 * \param char apellido del referi
 * \param char nombre del referi
 * \param sexo sexo (f/m) del referi
 * \param mail del referi
 * \param eFecha datos de tipo eFecha correspondientes a la fecha de nacimiento del referi
 *
 */
typedef struct
{
    int codigoReferi;
    char apellidoReferi[31];
    char nombreReferi[31];
    char sexo;
    char mail[31];
    eFecha fechaNacimiento;
} eReferi;

/** \brief Sub menú que permite interactuar con la entidad Referis
 *
 * \param eReferi[] array de tipo eReferis
 * \param int cantidad (tamaño total del array)
 * \return void no retorna nada
 *
 */
void subMenuReferis(eReferi[], int);

/** \brief Permite el alta de los referis
 *
 * \param eReferi[] array de tipo eReferi
 * \param int cantidad (tamaño total del array)
 * \return void no retorna nada
 *
 */
void cargaReferis(eReferi[], int);

/** \brief Muestra los datos ingresados de cada referi
 *
 * \param eReferi[] array de tipo eReferi
 * \param int cantidad (tamaño total del array)
 * \return void no retorna nada
 *
 */
void mostrarReferis(eReferi[], int);

