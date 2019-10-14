#ifndef MATERIA_H_INCLUDED
#define MATERIA_H_INCLUDED

struct EstructuraMateria{
    char nombre[30];
    int codigo;
    Integrantes vectorIntegran[100];
    int integrantesCargados;
};

typedef struct EstructuraMateria * Materia;

//CONSTRUCTOR
Materia crearMateria(int codigom, char nombrem[30]);

//DESTRUCTOR
void destructorMateria(Materia m);

//AGREGAR INTEGRANTES EN CUALQUIER MOMENTO

//GETTERS
int getCodigoMat(Materia m);
char * getNombreMat(Materia m);
int getIntegrantesCargados(Materia m);
Integrantes * getvectorIntegran(Materia m); //CARGAR VECTOR

//SETTERS
void setCodigoMat(Materia m, int nuevoCod);
void setNombreMat(Materia m, char nuevoNombre[30]);
void setintegrantesCargados(Materia m, int integrantesCargados);

//MOSTRAR MATERIA
void mostrarMateria(Materia m);

//AGREGAMOS INTEGRANTES A LA MATERIA
void agregarPersonaAMateria(Materia m, Integrantes integran);

#endif // MATERIA_H_INCLUDED
