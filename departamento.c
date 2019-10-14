#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Integrantes.h"
#include "Materia.h"
#include "Carrera.h"
#include "Departamento.h"

//CONSTRUCTOR
Departamento crearDepartamento(char nombreD[45],char descripcionD[70]){
    Departamento d = malloc(sizeof(struct EstructuraDepartamento));
    strcpy(d->nombreDepartamento, nombreD);
    strcpy (d->descripcion,descripcionD);
    d->cantCarreras = 0;
    return d;
}

//DESTRUCTOR
void destructorDepartamento(Departamento d){
    free(d);
}

//GETTERS
char * getNombreDepartamento(Departamento d){
    return d->nombreDepartamento;
}

char * getDescripcion(Departamento d){
   return d->descripcion;
}

//SETTERS
void setNombreDepartamento(Departamento d, char nuevoNombreDepartamento[50]){
    strcpy(d->nombreDepartamento, nuevoNombreDepartamento);
}

void setDescripcion(Departamento d,char NuevaDescripcion[70]){
    strcpy(d->descripcion,NuevaDescripcion);
}

//MOSTRAR DEPARTAMENTO
void mostrarDepartamento(Departamento d){
    int i;
    printf ("\n---------- DEPARTAMENTO ----------\n");
    printf("NOMBRE: %s\nDESCRICION: %s\n", d->nombreDepartamento,d->descripcion);
    for(i = 0; i < d->cantCarreras; i ++){
        mostrarCarrera(d->vectorCarreras[i]);
    }
}

//AGREGAMOS CARRERAS A LOS DEPARTAMENTOS
void agregarCarreraADpto(Departamento d, Carreras c){
    d->vectorCarreras[d->cantCarreras] = c;
    d->cantCarreras = d->cantCarreras + 1;
}
