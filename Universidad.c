#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Integrantes.h"
#include "Materia.h"
#include "Carrera.h"
#include "Departamento.h"
#include "Universidad.h"

//CREAMOS UNIVERSIDAD POR PARAMETROS
Universidad crearUniversidad(char nombreU[50], char direccionU[50], int contacto){
   Universidad u = malloc(sizeof(struct EstructuraUniversidad));
   strcpy(u->nombre, nombreU);
   strcpy(u->direccion, direccionU);
   u->contacto = contacto;
   u->cantDepartamentos = 0;
   return u;
}

//DESTRUCTOR
void destructorUniversidad(Universidad u){
    free(u);
}

//GETTERS
char *getNombreUniversidad (Universidad u){
    return u->nombre;
}

char *getDireccionUniversidad(Universidad u){
    return u->direccion;
}

int getContactoUniversidad(Universidad u){
    return u->contacto;
}

//SETTERS
void setNombreUniversidad(Universidad u, char nuevoNombre[30]){
    strcpy (u->nombre, nuevoNombre);
}

void setDireccionUniversidad (Universidad u, char nuevaDireccion[30]){
    strcpy(u->direccion, nuevaDireccion);
}

void setContactoUniversidad(Universidad u, int nuevoContacto){
    u->contacto = nuevoContacto;
}

//MOSTRAMOS UNIVERSIDAD
void mostrarUniversidad(Universidad u){
    int i;
    printf ("\n---------- UNIVERSIDAD ----------\n");
    printf ("NOMBRE: %s\nDIRECCION: %s\nCONTACTO: %d\n", u->nombre, u->direccion, u->contacto);
    for(i = 0; i < u->cantDepartamentos; i ++){
        mostrarDepartamento(u->vectorDepartamentos[i]);
    }
}

//AGREGAMOS DEPARTAMENTOS A LA UNIVERSIDAD
void agregarDepartamentosAUniversidad(Universidad u,Departamento d){
    u->vectorDepartamentos[u->cantDepartamentos] = d;
    u->cantDepartamentos = u->cantDepartamentos + 1;
}
