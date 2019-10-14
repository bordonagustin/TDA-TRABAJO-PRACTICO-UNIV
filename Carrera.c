#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Integrantes.h"
#include "Materia.h"
#include "Carrera.h"

//CREAR CONSTRUCTOR
Carreras crearCarrera(char nombreC[50], char nombreT[50]){
    Carreras c = malloc(sizeof(struct EstructuraCarrera));
    strcpy(c->nombreCarrera, nombreC);
    strcpy(c->nombreTitulo, nombreT);
    c->cantMaterias = 0;
    return c;
}

//DESTRUCTOR
void destructorCarrera(Carreras c){
    free(c);
}

//GETTERS
char * getNombreCarr(Carreras c){
    return c->nombreCarrera;
}

char * getNombreTitCarr(Carreras c){
    return c->nombreTitulo;
}

//SETTERS
void setNombreCarr (Carreras c, char nuevoNombre[45]){
    strcpy(c->nombreCarrera, nuevoNombre);
}

void setNombreTitCarr(Carreras c, char nuevoNombreTit[50]){
    strcpy(c->nombreTitulo, nuevoNombreTit);
}

//MOSTRAR CARRERA
void mostrarCarrera(Carreras c){
    printf("\n---------- CARRERA ----------\n");
    printf("NOMBRE: %s\nTITULO: %s\n",c->nombreCarrera, c->nombreTitulo);
    int i;
    for(i = 0; i < c->cantMaterias; i ++){
        mostrarMateria(c->vectorMaterias[i]);
    }
}

//AGREGAMOS LA MATERIA A LA CARRERA
void agregarMateriaACarrera(Carreras c, Materia m){
    c->vectorMaterias[c->cantMaterias] = m;
    c->cantMaterias = c->cantMaterias + 1;
}
