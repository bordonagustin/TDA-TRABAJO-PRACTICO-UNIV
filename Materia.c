#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Integrantes.h"
#include "Materia.h"

Materia crearMateria(int codigom, char nombrem[30]){
    Materia m = malloc(sizeof(struct EstructuraMateria));
    m->codigo = codigom;
    strcpy(m->nombre, nombrem);
    m->integrantesCargados = 0; //INICIALMENTE CUANDO SE CREA LA MATERIA HAY 0 ALUMNOS


    FILE * archivoIntegrante;
    archivoIntegrante = fopen("integrantes.txt", "r");

    while(!feof(archivoIntegrante)){
        char auxIntegrante[100]=" ";
        fgets(auxIntegrante, 100, archivoIntegrante);
        Integrantes Int=leerIntegrante(auxIntegrante, '+', Integrantes i);
        if (getCodigoMateria(Int)==m-->codigom){
            m->vectorIntegran[m->integrantesCargados]=Int;
            m->integrantesCargados=m->integrantesCargados+1;
        }
    }

    return m;
}

//DESTRUCTOR
void destructorMateria(Materia m){
    free(m);
}

//GETTERS
int getCodigoMat(Materia m){
    return m->codigo;
}

char * getNombreMat(Materia m){
    return m->nombre;
}

int getIntegrantesCargados(Materia m){
    return m->IntegrantesCargados;
};

Integrantes * getvectorIntegran(Materia m){
    return m->IntegrantesCargados;
};




//SETTERS
void setCodigoMat(Materia m, int nuevoCod){
    m->codigo = nuevoCod;
}

void setNombreMat(Materia m, char nuevoNombre[30]){
    strcpy(m->nombre, nuevoNombre);
}

void setintegrantesCargados(Materia m, int integrantesCargados){
    m->integrantesCargados = integrantesCargados;
}


//MOSTRAR LA MATERIA
void mostrarMateria(Materia m){
    int i;
    printf("\n---------- MATERIA ----------\n");
    printf("CODIGO: %d\nNOMBRE: %s\n", m->codigo, m->nombre);

    if (m->integrantesCargados>0){
       printf("los integrantes cargados son:\n");

        for(i = 0; i < m->integrantesCargados; i ++){
            mostrarIntegrantes(m->vectorIntegran[i]);
        }
    }
    printf("\n\n-------------------------------------\n\n");

}

//AGREGA PERSONAS EN CUALQUIER MOMENTO
/*void agregarPersonaAMateria(Materia m, Integrantes integran){
    m->vectorIntegran[m->cantIntegrantes] = integran;
    m->cantIntegrantes = (m->cantIntegrantes) + 1;
}*/
