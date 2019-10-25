#ifndef entidad_H_INCLUDED
#define entidad_H_INCLUDED
typedef struct
{
    int idUnico;
    char dominio[20];
    int anio;
    char tipo;
}Entidad;

#endif // entidad_H_INCLUDED

/**
 * \brief Solicita espacio en memoria para crear una estructura de employee
 * \return Espacio de memoria para tipo de dato employee
 */
Entidad* entidad_new();

/**
 * \brief Parsea y asigna los datos por parametro a Entidad
 * \param char* idStr, id unico de employee
 * \param char* nombreStr, nombre de employee
 * \param char* horasTrabajadasStr, cantidad de horas trabajadas employee
 * \param char* sueldo, sueldo de employee
 * \return Employee* puntero de estructura cargada con datos
 */
Entidad* entidad_newParametros(char* idStr,char* dominioStr,char* anioStr,char* tipoStr);

/**
 * \brief Borra en espacio de memoria reservado
 * \param Employee*, this
 */
void entidad_delete(Entidad* this);

/**
 * \brief setea id unico para employee*
 * \param Employee*, this
 * \return int, -1 error / 0 ok
 * \param int id
 */
int entidad_setId(Entidad* this,int id);

/**
 * \brief get id unico de employee*
 * \param Employee*, this
 * \param int id auxiliar
 * \return int, -1 error / 0 ok
 */
int entidad_getId(Entidad* this,int* id);

/**
 * \brief setea un nombre para employee*
 * \param Employee*, this
 * \param char* nombre que se cargara en employee*
 * \return int, -1 error / 0 ok
 */
int entidad_setDominio(Entidad* this,char* dominio);

/**
 * \brief get get nombre de employee*
 * \param Employee*, this
 * \param char* nombre, auxiliar
 * \return int, -1 error / 0 ok
 */
int entidad_getDominio(Entidad* this,char* dominio);
int entidad_setTipo(Entidad* this);

