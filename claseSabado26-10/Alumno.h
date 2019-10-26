typedef struct
{
    int id;
    char nombre[50];
    char apellido[50];
    float nota;
} eAlumno;

eAlumno* new_Alumno(); // esto es un constructor que crea espacio en memoria
eAlumno* new_Alumno_Parametros(int, char*, char*, float);

int getId(eAlumno*);
void setId(eAlumno*, int);

