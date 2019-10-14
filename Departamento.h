#ifndef DEPARTAMENTO_H_INCLUDED
#define DEPARTAMENTO_H_INCLUDED

struct EstructuraDepartamento{
    char nombreDepartamento[45];
    char descripcion[70];
    Carreras vectorCarreras[2];
    int cantCarreras;
};

typedef struct EstructuraDepartamento * Departamento;

//CONSTRUCTOR
Departamento crearDepartamento(char nombreD[45],char descripcionD[70]);

//DESTRUCTOR
void destructorDepartamento(Departamento d);

//GETTER
char * getNombreDepartamento(Departamento d);

char * getDescripcion(Departamento d);

//SETTER
void setNombreDepartamento(Departamento d, char nuevoNombreD[45]);

void setDescripcion (Departamento d,char nuevaDescripcion [70]);

//MOSTRAR CARRERA
void mostrarDepartamento(Departamento d);

//AGREGAMOS CARRERA A DEPARTAMENTO
void agregarCarreraADpto(Departamento d, Carreras c);

#endif // DEPARTAMENTO_H_INCLUDED
