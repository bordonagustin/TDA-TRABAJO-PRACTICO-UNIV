#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Integrantes.h"

//CREAR INTEGRANTES CON PARAMETROS
Integrantes crearIntegrantes (char nombreA[20], char apellidoA[20], int dniA, int docOAluma,int codigoMateria){
    Integrantes x = malloc(sizeof(struct EstructuraIntegrantes));
    strcpy(x->nombre, nombreA);
    strcpy(x->apellido, apellidoA);
    x->dni = dniA;
    x->docOAlum = docOAluma;
    x->codigoMateria = codigoMateria;
    return x;
}

//CREAR INTEGRANTES POR TECLADO
Integrantes crearIntegrantesPorTeclado(){
    char nombreA[20];
    char apellidoA[20];
    int dniA;
    int docOAluma;
    int codigoMateria;

    printf("POR FAVOR INGRESE EL NOMBRE:\n");
    fflush(stdin);
    gets(nombreA);
    printf("POR FAVOR INGRESE EL APELLIDO:\n");
    fflush(stdin);
    gets(apellidoA);
    printf("POR FAVOR INGRESE EL DNI:\n");
    scanf("%d", &dniA);

    printf("POR FAVOR INGRESE EL CODIGO DE LA MATERIA:\n");
    scanf("%d", &codigoMateria);

    printf("POR FAVOR INGRESE 0 SI ES DOCENTE, 1 SI ES ALUMNO:\n");
    scanf("%d", &docOAluma);
    while((docOAluma != 0) && (docOAluma != 1)){ //ME ASEGURO DE QUE LA PERSONA SEA DOCENTE O ALUMNO
        printf("ERROR, INGRESE UNA OPCION VALIDA\n");
        scanf("%d", &docOAluma);
    }
    return crearIntegrantes(nombreA, apellidoA, dniA, docOAluma, codigoMateria);
}

//GETTERS
char * getNombreInt(Integrantes integran){
    return integran->nombre;
};

char * getApellidoInt(Integrantes integran){
    return integran->apellido;
};

int getDniInt(Integrantes integran){
    return integran->dni;
};

int getDocOAlumInt(Integrantes integran){
    return integran->docOAlum;
};

int getCodigoMateria(Integrantes integran){
    return integran->codigoMateria;
};

//SETS
void setNombreInt(Integrantes integran, char nuevoNombre[20]){
    strcpy(integran->nombre, nuevoNombre);
}

void setApellidoInt(Integrantes integran, char nuevoApellido[20]){
    strcpy(integran->apellido, nuevoApellido);
}

void setDniInt(Integrantes integran, int nuevoDni){
    integran->dni = nuevoDni;
}

void setDocOAlumnoInt(Integrantes integran, int nuevoDocOAlum){
    integran->docOAlum = nuevoDocOAlum;
}

//MOSTRAR INTEGRANTES
void mostrarIntegrantes(Integrantes integran){
    printf("\n---------- INTEGRANTE ----------\n");
    printf("NOMBRE: %s\nAPELLIDO: %s\nDNI: %d\nCODIGO: %d\n",integran->nombre, integran->apellido, integran->codigoMateria);
    if(integran->docOAlum == 1){
        printf("EL INTEGRANTE ES ALUMNO\n");
    }else{
       printf("EL INTEGRANTE ES DOCENTE\n");
    }
}

//DESTRUCTOR
void destructorIntegrantes(Integrantes integran){
    free(integran);
}

