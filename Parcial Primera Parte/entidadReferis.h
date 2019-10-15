typedef struct
{
    int codigoReferi;
    char apellidoReferi[31];
    char nombreReferi[31];
    char sexo;
    char mail[31];
    eFecha fechaNacimiento;
} eReferi;

void subMenuReferis(eReferi[], int);
void cargaReferis(eReferi[], int);
void mostrarReferis(eReferi[], int);

