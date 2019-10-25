typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct // tipo de dato tipificado.
{
    int id;
    char desc[20];
} eSector;

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    eFecha fechaIn;
    int idSector;
    int ocupado;
} eEmpleado;

/** \brief Muestra un men� que debe ser personalizado en la funci�n. Pide un int que guarda en la variable opcion.
 *
 * \param No recibe par�metros.
 * \return la variable int opcion que ingresa el usuario.
 *
 */
int menu();

/** \brief Realiza la baja l�gica de todos las estructuras eEmpleado del vector asignando 0 a la variable ocupado.
 *
 * \param eEmpleado es el vector de empleados.
 * \param tam es el tama�o del vector de empleados.
 * \return No devuelve par�metros.
 *
 */
void inicializarEmpleados(eEmpleado vec[], int tam);

/** \brief Muestra en pantalla todos los campos de una estructura eEmpleado. Invoca a la funci�n de usuario obtenerSector.
 *
 * \param eSector es el vector de sectores.
 * \param tamSectores es el tama�o del vector de sectores.
 * \param eEmpleado es el vector de empleados.
 * \param tam es el tama�o del vector de empleados.
 * \return No devuelve par�metros.
 *
 */
void mostrarEmpleado(eSector sectores[], int tamSectores, eEmpleado emp);

/** \brief Muestra en pantalla los campos de todas las estructuras eEmpleado de un vector. Valida si el vector est� vac�o. Invoca a la funci�n de usuario mostrarEmpleado.
 *
 * \param Recibe un vector de estructuras eSector, su tama�o, un vector de estructuras eEmpleado y su tama�o.
 * \return No devuelve par�metros.
 *
 */
void mostrarEmpleados(eSector sectores[], int tamSectores, eEmpleado vec[], int tam);

/** \brief Busca una posici�n vac�a en un vector de estructuras eEmpleado (campo ocupado == 0).
 *
 * \param eEmpleado es el vector de empleados.
 * \param tam es el tama�o del vector de empleados.
 * \return Devuelve el �ndice de la primera posici�n vac�a hallada. De no hallar ninguna, devuelve -1.
 *
 */
int buscarLibre(eEmpleado vec[], int tam);

/** \brief Busca una estructura eEmpleado utilizando su campo legajo.
 *
 * \param eEmpleado es el vector de empleados.
 * \param tam es el tama�o del vector de empleados.
 * \param legajo es el legajo del empleado a buscar en el vector.
 * \return Devuelve el �ndice de la primera posici�n cuya estructura posee el legajo buscado. De no hallar ninguna, devuelve -1.
 *
 */
int buscarEmpleado(eEmpleado vec[], int tam, int legajo);

/** \brief Da de alta a una estructura eEmpleado en una posici�n libre. Valida la existencia de una posici�n vac�a. Invoca a las funciones de usuario: buscarLibre, buscarEmpleado, mostrarEmpleado, getString, getCharGenre, getFloat, getDate, mostrarSectores.
 *
 * \param eSector es el vector de sectores.
 * \param tamSectores es el tama�o del vector de sectores.
 * \param eEmpleado es el vector de empleados.
 * \param tam es el tama�o del vector de empleados..
 * \return No devuelve par�metros.
 *
 */
void altaEmpleado(eSector sectores[], int tamSectores, eEmpleado vec[], int tam);

/** \brief Realiza la baja l�gica de una estructura eEmpleado determinada por su campo legajo. Valida la existencia del legajo ingresado. Invoca a las funciones de usuario: buscarEmpleado, mostrarEmpleado.
 *
 * \param eSector es el vector de sectores.
 * \param tamSectores es el tama�o del vector de sectores.
 * \param eEmpleado es el vector de empleados.
 * \param tam es el tama�o del vector de empleados.
 * \return No devuelve par�metros.
 *
 */
void bajaEmpleado(eSector sectores[], int tamSectores, eEmpleado vec[], int tam);

/** \brief Modifica el campo sueldo de una estructura eEmpleado determinada por su campo legajo. Valida la existencia del legajo ingresado. Invoca a las funciones de usuario: buscarEmpleado, mostrarEmpleado.
 *
 * \param eSector es el vector de sectores.
 * \param tamSectores es el tama�o del vector de sectores.
 * \param eEmpleado es el vector de empleados.
 * \param tam es el tama�o del vector de empleados.
 * \return No devuelve par�metros.
 *
 */
void modificarEmpleado(eSector sectores[], int tamSectores, eEmpleado vec[], int tam);

/** \brief Ordena a las estructuras del vector alfab�ticamente por su nombre.
 *
 * \param eEmpleado es el vector de empleados.
 * \param tam es el tama�o del vector de empleados.
 * \return No devuelve par�metros.
 *
 */
void ordenarEmpleadosAZ(eEmpleado vec[], int tam);

/** \brief Compara el sector de una estructura eEmpleado con el id del vector de estructuras eSector y copia su campo descripcion a un vector pasado en los par�metros.
 *
 * \param eSector es el vector de sectores.
 * \param tamSectores es el tama�o del vector de sectores.
 * \param idSectorEmp es el entero del campo sector de una estructura eEmpleado.
 * \param descMostrar es el vector al cual se debe copiar la descripci�n.
 * \return No devuelve par�metros.
 *
 */
void obtenerSector(eSector sectores[], int tamSectores, int idSectorEmp, char descMostrar[]);

/** \brief Lista las estructuras eSector existentes con un encabezado para sus campos.
 *
 * \param eSector es el vector de sectores.
 * \param tamSectores es el tama�o del vector de sectores.
 * \return No devuelve par�metros.
 *
 */
void mostrarSectores(eSector sectores[], int tamSectores);

/** \brief Lista las estructuras eEmpleado existentes agrupadas por sector con un encabezado para sus campos. Invoca a la funci�n mostrarEmpleado.
 *
 * \param eSector es el vector de sectores.
 * \param tamSectores es el tama�o del vector de sectores.
 * \param eEmpleado es el vector de empleados.
 * \param tam es el tama�o del vector de empleados.
 * \return No devuelve par�metros.
 *
 */
void mostrarSectoresConEmpleados(eSector sectores[], int tamSectores, eEmpleado vec[], int tamEmp);

/** \brief Lista la cantidad de estructuras eEmpleado existentes de cada sector.
 *
 * \param eSector es el vector de sectores.
 * \param tamSectores es el tama�o del vector de sectores.
 * \param eEmpleado es el vector de empleados.
 * \param tam es el tama�o del vector de empleados.
 * \return No devuelve par�metros.
 *
 */
void censoSectores(eSector sectores[], int tamSectores, eEmpleado vec[], int tamEmp);

/** \brief Lista las estructuras eEmpleado existentes para un sector determinado por el usuario con un encabezado para sus campos. Valida que el sector exista y tenga empleados. Invoca a la funci�n mostrarEmpleado.
 *
 * \param eSector es el vector de sectores.
 * \param tamSectores es el tama�o del vector de sectores.
 * \param eEmpleado es el vector de empleados.
 * \param tam es el tama�o del vector de empleados.
 * \return No devuelve par�metros.
 *
 */
void listarSectorSeleccionado(eSector sectores[], int tamSectores, eEmpleado vec[], int tamEmp);

void ordenarEmpleadosLegajoAZ(eEmpleado vec[], int tam);
