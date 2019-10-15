typedef struct
{
    int codigoPartido;
    int codigoVisitante;
    int codigoLocal;
    int codigoReferi;
    eFecha fechaPartido;
} ePartido;


void subMenuPartidos(ePartido[], int);
void cargaPartidos(ePartido[], int);
void mostrarPartidos(ePartido[], int);
void listarFechaPartidos(ePartido[], int);

