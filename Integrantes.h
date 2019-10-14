#ifndef INTEGRANTES_H_INCLUDED
#define INTEGRANTES_H_INCLUDED

struct EstructuraIntegrantes{
    char nombre[20];
    char apellido[20];
    int dni;
    int docOAlum;
    int codigoMateria;
};

typedef struct EstructuraIntegrantes * Integrantes;

//CONSTRUCTORES
Integrantes crearIntegrantes (char nombreA[20],char apellidoA[20],int dniA,int docOAluma,int codigoMateria);
Integrantes crearIntegrantesPorTeclado();
void destructorIntegrantes (Integrantes integran);

//GETTERS
char *getNombreInt(Integrantes integran);
char *getApellidoInt(Integrantes integran);
int getDniInt(Integrantes integran);
int getDocOAlumInt(Integrantes integran);
int getCodigoMateria(Integrantes integran);

//SETTERS
void setNombreInt(Integrantes integran,char nuevoNombre[20]);
void setApellidoInt (Integrantes integran,char nuevoApellido[20]);
void setDniInt(Integrantes integran,int nuevoDni);
void setDocOAlumnoInt (Integrantes integran,int nuevoDocOAlum);


//MOSTRAR DATOS
void mostrarIntegrantes(Integrantes integran);

#endif // INTEGRANTES_H_INCLUDED
