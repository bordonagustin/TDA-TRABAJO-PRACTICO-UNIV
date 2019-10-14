#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"
#include "Integrantes.h"
#include "Materia.h"
#include "Carrera.h"
#include "Departamento.h"
#include "Universidad.h"
// es es un comentario en el main
// este otro cambio en el main
void presentacion();
int menu();
int subMenuAlta();
int subMenuMostrar();
int subMenuEliminar();
int subMenuModificar();
int subMenuBuscar();
int subMenuOrdenar();
int subMenuGuardar();
void salir();

int buscarIntegrantePorDni(Materia m, int dni);
int buscarMateriaPorNombre(Carreras c, char nombreMateria[30]);
void ordenarIntegrantesPorDni(Materia m);
void ordenarIntegrantesPorNombre(Materia m);

////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
//VARIABLES GLOBALES
int cantInt = 0; //VARIABLE GLOBAL ---> TAMAÑO DEL VECTOR DE INTEGRANTES, BUSCAR ALTERNATIVA
int cantMat = 0;//VARIABLE GLOBAL ---> TAMAÑO DEL VECTOR DE MATERIAS

Carreras vectorMateria[10];

//PYF VECTOR INTEGRANTES
void cargarVectorDeIntegrantes(Integrantes vectorIntegrantes[10]); //CARGA EL VECTOR DE INTEGRANTES
Integrantes leerIntegrante(char variableIntegrante[], char delimitador, Integrantes i); //RETORNA UN INTEGRANTE
void mostrarVectorDeIntegrantes(Integrantes vectorIntegrantes[10]); //MUESTRA EL VECTOR DE INTEGRANTES

//PYF VECTOR MATERIAS(MODIFICAR EL TAMAÑO DE VectorMateria SI SE QUIERE EXPANDIR EL TXT)
void cargarVectorDeMaterias(Materia vectorMateria[10]); //CARGA EL VECTOR DE MATERIAS
Materia leerMaterias(char variableMateria[], char delimitador, Materia m); //RETORNA UNA MATERIA
void mostrarVectorDeMaterias(Materia vectorMateria[10]); //MUESTRA EL VECTOR DE MATERIA

Integrantes leerIntegrante(char variableIntegrante[], char delimitador, Integrantes i);



int main ()
{


// MATERIAS
     cargarVectorDeMaterias(vectorMateria); //CARGA EL VECTOR DE INTEGRANTES
     mostrarVectorDeMaterias(vectorMateria); //MUESTRA EL VECTOR DE INTEGRANTES

    ////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////

    /*Integrantes i1;
    Materia m1;
    Carreras c1;
    Departamento d1;
    Universidad u;*/

    int opcion = -9;
    int opcionSubAlta;
    int opcionSubMostrar;
    int opcionSubEliminar;
    int opcionSubModificar;
    int opcionSubBuscar;
    int opcionSubOrdenar;
    int opcionSubGuardar;

    presentacion();

    while(opcion != 0){

        opcionSubAlta = -8;
        opcionSubMostrar = -7;
        opcionSubEliminar = -6;
        opcionSubModificar = -5;
        opcionSubBuscar = -4;
        opcionSubOrdenar = -3;
        //opcionSubGuardar = -2;

        opcion = menu();

        /*switch(opcion){
            case 1: while(opcionSubAlta != 0){

                        opcionSubAlta = subMenuAlta();

                        switch(opcionSubAlta){

                            case 1: i1 = crearIntegrantes("Gonzalo", "Ajuria", 12345, 1);
                            break;
                            case 2: m1 = crearMateria(1806, "Programacion");
                                    agregarPersonaAMateria(m1, i1);
                            break;
                            case 3: c1 = crearCarrera("Sistemas", "Lic. en Sistemas");
                                    agregarMateriaACarrera(c1, m1);
                            break;
                            case 4: d1 = crearDepartamento("Desarrollo Productivo y Tecnologico");
                                    agregarCarreraADpto(d1, c1);
                            break;
                            case 5: u = crearUniversidad("UNLa", "29 de Septiembre 3901", 1826);
                                    agregarDepartamentosAUniversidad(u, d1);
                            break;
                            case 0: system("CLS");
                            break;
                            default: printf("Error, opcion invalida\n");
                        }
                    }
            break;
            case 2: while(opcionSubMostrar != 0){

                        opcionSubMostrar = subMenuMostrar();

                        switch(opcionSubMostrar){
                            case 1: mostrarIntegrantes(i1);
                            break;
                            case 2: mostrarMateria(m1);
                            break;
                            case 3: mostrarCarrera(c1);
                            break;
                            case 4: mostrarDepartamento(d1);
                            break;
                            case 5: mostrarUniversidad(u);
                            break;
                            case 0: system("CLS");
                            break;
                            default: printf("Error, opcion invalida\n");
                        }
                    }
            break;
            case 3: while(opcionSubEliminar != 0){

                        opcionSubEliminar = subMenuEliminar();

                        switch(opcionSubEliminar){
                            case 1: free(i1);
                            break;
                            case 2: free(m1);
                            break;
                            case 3: free(c1);
                            break;
                            case 4: free(d1);
                            break;
                            case 5: free(u);
                            break;
                            case 0: system("CLS");
                            break;
                            default: printf("Error, opcion invalida\n");
                        }
                    }
            break;
            case 4: while(opcionSubModificar != 0){

                        opcionSubModificar = subMenuModificar();

                        switch(opcionSubModificar){
                            case 1: setNombreInt(i1, "Martin");
                                    setApellidoInt(i1, "Fernandez");
                                    setDniInt(i1, 14725);
                                    setDocOAlumnoInt(i1, 0);
                            break;
                            case 2: setCodigoMat(m1, 1703);
                                    setNombreMat(m1, "Tecnologia de la imagen");
                            break;
                            case 3: setNombreCarr(c1, "Audiovision");
                                    setNombreTitCarr(c1, "Lic. en Audiovision");
                            break;
                            case 4: setNombreDepartamento(d1, "Humanidades y Artes");
                            break;
                            case 5: setNombreUniversidad(u, "Universidad Nacional de Lanus");
                                    setDireccionUniversidad(u, "19 de Agosto 2900");
                                    setContactoUniversidad(u, 1725);
                            break;
                            case 0: system("CLS");
                            default: printf("Error, opcion invalida\n");
                        }
                    }
            break;
            case 5: while(opcionSubBuscar != 0){

                        opcionSubBuscar = subMenuBuscar();

                        switch(opcionSubBuscar){
                            case 1: if(buscarIntegrantePorDni(m1, 12345) != -1){
                                        printf("Se encontro\n");
                                    }else{
                                        printf("No se encontro\n");
                                    }
                            break;
                            case 2: if(buscarMateriaPorNombre(c1, "Arquitectura de Computadoras") != -1){
                                        printf("Se encontro");
                                    }else{
                                        printf("No se encontro\n");
                                    }

                           break;
                           default: printf("Error, opcion invalida\n");
                           case 0: system("CLS");
                           break;
                        }
                    }
            case 6: while(opcionSubOrdenar != 0){

                        opcionSubOrdenar = subMenuOrdenar();

                        switch(opcionSubOrdenar){
                            case 1: ordenarIntegrantesPorDni(m1);
                            break;
                            default: printf("Error, opcion invalida\n");
                            case 0: system("CLS");
                            break;
                        }
                    }
            break;
            case 0: salir();
            break;
            default: printf("Error, opcion invalida\n");
        }
    }*/
    return 0;
}


void presentacion(){
    printf("---------- Trabajo Practico TDA ----------\n\n");
    system("pause");
    system("CLS");
}

int menu(){
    int opcion;
    printf("\nPor favor ingrese una opcion:\n");
    printf("1- ALTA\n"); //para mí hay que llamar a la funcion de listas "INSERTARFIN" y al terminar hacer un GRABADO en archivo txt con "a" o "w" según convenga
    printf("2- MOSTRAR\n"); // procedimientos de cada procedimiento que està acà abajo en el MAIN por ahora (hasta ahora solo de vectorIntegrantes para la materia
    printf("3- ELIMINAR\n");//IDEM ALTA: hay que llamar a la funcion de listas, en este caso "REMOVER"
                            //y al terminar hacer un GRABADO en archivo txt con "a" o "w" según convenga
    printf("4- MODIFICAR\n"); // SETTS de cada TDA
                            //y al terminar hacer un GRABADO en archivo txt con "a" o "w" según convenga
    printf("5- BUSCAR\n"); //procedimientos q estan aca abajo en el main
    printf("6- ORDENAR\n");//procedimientos q estan aca abajo en el main
    //printf("7- GUARDAR\n");
    printf("0- SALIR\n\n");
    scanf("%d", &opcion);
    return opcion;
}
//adasd

int subMenuAlta(){
    int opcionSubAlta;
    printf("\nPor favor ingrese una opcion:\n");
    printf("1- ALTA DE ALUMNO O DOCENTE\n");
    printf("2- ALTA DE MATERIA\n");
    printf("3- ALTA DE CARRERA\n");
    printf("4- ALTA DE DEPARTAMENTO\n");
    printf("5- ALTA DE UNIVERSIDAD\n");
    printf("0- VOLVER A MENU PRINCIPAL\n\n");
    scanf("%d", &opcionSubAlta);
    return opcionSubAlta;
}

int subMenuMostrar(){
    int opcionSubMostrar;
    printf("\nPor favor ingrese una opcion:\n");
    printf("1- MOSTRAR ALUMNO O DOCENTE\n");
    printf("2- MOSTRAR MATERIA\n");
    printf("3- MOSTRAR CARRERA\n");
    printf("4- MOSTRAR DEPARTAMENTO\n");
    printf("5- MOSTRAR UNIVERSIDAD\n");
    printf("0- VOLVER A MENU PRINCIPAL\n\n");
    scanf("%d", &opcionSubMostrar);
    return opcionSubMostrar;
}


int subMenuEliminar(){
    int opcionSubEliminar;
    printf("\nPor favor ingrese una opcion:\n");
    printf("1- ELIMINAR ALUMNO O DOCENTE\n");
    printf("2- ELIMINAR MATERIA\n");
    printf("3- ELIMINAR DEPARTAMENTO\n");
    printf("4- ELIMINAR CARRERA\n");
    printf("5- ELIMINAR UNIVERSIDAD\n");
    printf("0- VOLVER A MENU PRINCIPAL\n\n");
    scanf("%d", &opcionSubEliminar);
    return opcionSubEliminar;
}

int subMenuModificar(){
    int opcionSubModificar;
    printf("\nPor favor ingrese una opcion:\n");
    printf("1- MODIFICAR ALUMNO O DOCENTE\n");
    printf("2- MODIFICAR MATERIA\n");
    printf("3- MODIFICAR DEPARTAMENTO\n");
    printf("4- MODIFICAR CARRERA\n");
    printf("5- MODIFICAR UNIVERSIDAD\n");
    printf("0- VOLVER A MENU PRINCIPAL\n\n");
    scanf("%d", &opcionSubModificar);
    return opcionSubModificar;
}

int subMenuBuscar(){
    int opcionSubBuscar;
    printf("\nPor favor ingrese una opcion:\n");
    printf("1- BUSCAR ALUMNO O DOCENTE\n");
    printf("2- BUSCAR MATERIA\n");
    //printf("3- BUSCAR DEPARTAMENTO\n");
    //printf("4- BUSCAR CARRERA\n");
    //printf("5- BUSCAR UNIVERSIDAD\n");
    printf("0- VOLVER A MENU PRINCIPAL\n\n");
    scanf("%d", &opcionSubBuscar);
    return opcionSubBuscar;
}

int subMenuOrdenar(){
    int opcionSubOrdenar;
    printf("\nPor favor ingrese una opcion:\n");
    printf("1- ORDENAR ALUMNO O DOCENTE\n");
    //printf("2- ORDENAR MATERIA\n");
    //printf("3- ORDENAR DEPARTAMENTO\n");
    //printf("4- ORDENAR CARRERA\n");
    //printf("5- ORDENAR UNIVERSIDAD\n");
    printf("0- VOLVER A MENU PRINCIPAL\n\n");
    scanf("%d", &opcionSubOrdenar);
    return opcionSubOrdenar;
}

/*int subMenuGuardar(){
    int opcionSubGuardar;
    printf("\nPor favor ingrese una opcion:\n");
    printf("1- GUARDAR ALUMNO O DOCENTE\n");
    printf("2- GUARDAR MATERIA\n");
    printf("3- GUARDAR DEPARTAMENTO\n");
    printf("4- GUARDAR CARRERA\n");
    printf("5- GUARDAR UNIVERSIDAD\n");
    printf("0- VOLVER A MENU PRINCIPAL\n\n");
    scanf("%d", &opcionSubGuardar);
    return opcionSubGuardar;*/
}

void salir(){
    printf("Gracias por usar nuestro programa\n");
    system("pause");
    system("CLS");
}

int buscarIntegrantePorDni(Materia m, int dni){
    int resultado = -1;
    int j;
    for(j = 0; j < m->cantIntegrantes; j ++){
        if(m->vectorIntegran[j]->dni == dni){
            resultado = j;
            j = m->cantIntegrantes;
        }
    }
    return resultado;
}

int buscarMateriaPorNombre(Carreras c, char nombreMateria[30]){ //RETORNA LA POSICION SI LA ENCUENTRA, -1 SI NO LA ENCUENTRA
    int resultado = -1;
    int i;
    for(i = 0; i < c->cantMaterias; i ++){
        if(strcmp(c->vectorMaterias[i]->nombre, nombreMateria) == 0){
            resultado = i;
            i = c->cantMaterias; //DEJA DE BUSCAR SI ENCUENTRA LA MATERIA
        }
    }
    return resultado;
}

void ordenarIntegrantesPorDni(Materia m){
    Integrantes aux; //EL AUXILIAR ES EL TIPO DE DATO
    int j, k;
    for(j = 0; j < m->cantIntegrantes; j ++){
        for(k = 0; k < m->cantIntegrantes - 1; k ++){
            if(m->vectorIntegran[k]->dni >= m->vectorIntegran[k+1]->dni){
                    aux = m->vectorIntegran[k];
                    m->vectorIntegran[k] = m->vectorIntegran[k+1];
                    m->vectorIntegran[k+1] = aux;
            }
        }
    }
}

void ordenarIntegrantesPorNombre(Materia m){
    Integrantes aux; //EL AUXILIAR ES EL TIPO DE DATO
    int j, k;
    for(j = 0; j < m->cantIntegrantes; j ++){
        for(k = 0; k < m->cantIntegrantes - 1; k ++){
            if(strcmp(m->vectorIntegran[k]->nombre, m->vectorIntegran[k+1]->nombre) == 1){
                aux = m->vectorIntegran[k];
                m->vectorIntegran[k] = m->vectorIntegran[k+1];
                m->vectorIntegran[k+1] = aux;
            }
        }
    }
}

////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

void cargarVectorDeIntegrantes(Integrantes vectorIntegrantes[10]){
    FILE * archivoIntegrante;
    int i = 0;
    archivoIntegrante = fopen("integrantes.txt", "r");
    while(!feof(archivoIntegrante)){
        char lectura[100];
        fgets(lectura, 100, archivoIntegrante);
        if(!feof(archivoIntegrante)){
            printf("%s\n", lectura);
            Integrantes in;
            vectorIntegrantes[i] = leerIntegrante(lectura, '+', in);
            i ++;
        }
    }
    fclose(archivoIntegrante);
    cantInt = i; //VARIABLE GLOBAL ---> TAMAÑO DEL VECTOR DE INTEGRANTES, BUSCAR ALTERNATIVA
}

Integrantes leerIntegrante(char variableIntegrante[], char delimitador, Integrantes i){
    int ubicacionPrimerDelimitador = 0;
    int ubicacionSegundoDelimitador = 0;
    int ubicacionTercerDelimitador = 0;

    char auxNombre[100] = " ";
    char auxApellido[100] = " ";
    char auxDni[100] = " ";
    char auxDocenteOAlumno[100] = " ";

    int j = 0;

    for(j = 0; j < 100; j ++){
        if(variableIntegrante[j] == delimitador){
            ubicacionPrimerDelimitador = j; //HALLO EL PRIMER DELIMITADOR
            j = 100;
        }
    }

    for(j = ubicacionPrimerDelimitador+1; j < 100; j ++){
        if(variableIntegrante[j] == delimitador){
            ubicacionSegundoDelimitador = j; //HALLO EL SEGUNDO DELIMITADOR
            j = 100;
        }
    }

    for(j = ubicacionSegundoDelimitador+1; j < 100; j ++){
        if(variableIntegrante[j] == delimitador){
            ubicacionTercerDelimitador = j; //HALLO EL TERCER DELIMITADOR
            j = 100;
        }
    }

    for(j = 0; j < ubicacionPrimerDelimitador; j ++){
        auxNombre[j] = variableIntegrante[j]; //GUARDO CARACTER A CARACTER EL NOMBRE
    }

    for(j = ubicacionPrimerDelimitador+1; j < ubicacionSegundoDelimitador; j ++){
        auxApellido[j-ubicacionPrimerDelimitador-1] = variableIntegrante[j]; //GUARDO CARACTER A CARACTER EL APELLIDO
    }

    for(j = ubicacionSegundoDelimitador+1; j < ubicacionTercerDelimitador; j ++){
        auxDni[j-ubicacionSegundoDelimitador-1] = variableIntegrante[j]; //GUARDO CARACTER A CARACTER EL DNI
    }

    for(j = ubicacionTercerDelimitador+1; j < 100; j ++){
        auxDocenteOAlumno[j-ubicacionTercerDelimitador-1] = variableIntegrante[j]; //GUARDO DOCENTE O ALUMNO
    }

    i = crearIntegrantes(auxNombre, auxApellido, atoi(auxDni), atoi(auxDocenteOAlumno)); //CREO UN INTEGRANTE

    return i; //LO RETORNO
}

void mostrarVectorDeIntegrantes(Integrantes vectorIntegrantes[10]){
   for(int i = 0; i < cantInt; i ++){
        mostrarIntegrantes(vectorIntegrantes[i]); //MUESTRO EL VECTOR DE INTEGRANTES
    }
}


//////////////////////////////////////////////////////////ARCHIVOS CON MATERIA

void cargarVectorDeMaterias(Materia vectorMateria [10]){

int i=0;
FILE *archivoMateria;
archivoMateria=fopen("materias.txt","r");

while (!feof(archivoMateria)){
    char lectura[30];
    fgets(lectura,30,archivoMateria);
     if(!feof(archivoMateria)){
            printf("%s\n", lectura);
            Materia mat;
            vectorMateria[i] = leerMaterias(lectura,'+',mat);
            i ++;
        }
}
fclose(archivoMateria);
cantMat=i;

}

Materia leerMaterias(char variableMateria[],char delimitador,Materia m){

int ubicacionPrimerDelimitador = 0;

char auxNombre[100]=" ";
char auxCodigo[100]=" ";

int i=0;

for (i=0;i<100;i++){
if (variableMateria[i]==delimitador){
    ubicacionPrimerDelimitador=i;
     i=100;
}//CIERRO IF PARA ENCONTRAR EL DELIMITADOR
}//CIERRO FOR

for (i=0;i<ubicacionPrimerDelimitador;i++){
    auxNombre[i]=variableMateria[i];
}

for (i=ubicacionPrimerDelimitador+1;i<100;i++){
    auxCodigo[i-ubicacionPrimerDelimitador-1]=variableMateria[i];
}

m=crearMateria(atoi(auxCodigo),auxNombre);

return m;

}
mostrarVectorDeMaterias(Materia vectorMateria[10]){
int i;

for(i=0;i<cantMat;i++){
    mostrarMateria(vectorMateria[i]);
}

}

//////////////////////////////////////ARCHIVOS CON CARRERAS

/*void cargarVectorDeCarrera(Carreras vectorCarreras[10]){

FILE * archivoCarreras = fopen("Carreras.txt","r");

int i=0;
printf ("\n");
while (!feof(archivoCarreras)){
    char lectura[100];
    fgets(lectura,100,archivoCarreras);
    if(!feof(archivoCarreras)){
            printf("%s\n", lectura);
        Carreras car;
        vectorCarreras[i]=leerCarrera(lectura,'+',car);
            i++;
    }
}

fclose(archivoCarreras);
cantCarreras=i;

}


Carreras leerCarrera(char variableCarrera[],char delimitador,Carreras c){

int ubicacionPrimerDelimitador = 0;

char auxNombrec[100]=" ";
char auxNombret[100]=" ";

int i=0;
for (i=0;i<100;i++){
if (variableCarrera[i]==delimitador){
    ubicacionPrimerDelimitador=i;
    i=100;
}
}

for (i=0;i<ubicacionPrimerDelimitador;i++){
    auxNombrec[i]=variableCarrera[i];
    }
for (i=ubicacionPrimerDelimitador+1;i<100;i++){
    auxNombret[i-ubicacionPrimerDelimitador-1]=variableCarrera[i];
}

c = crearCarrera(auxNombrec,auxNombret);

return c;
}


void mostrarVectorDeCarreras(Carreras vectorCarreras[]){
int i;
for (i=0;i<cantCarreras;i++){
    mostrarCarrera(vectorCarreras[i]);
}

}


//////////////////////////////ARCHIVOS CON DEPARTAMENTOS
void cargarVectorDeDepartamentos(Departamento vectorDepartamento[4]){

FILE * archivoDepartamento = fopen("departamentos.txt","r");

int i=0;
printf ("\n");

while (!feof(archivoDepartamento)){
    char lectura[100];
     fgets(lectura,100,archivoDepartamento);
    if(!feof(archivoDepartamento)){
            printf("%s\n", lectura);
        Departamento dep;
        vectorDepartamento[i]=leerDepartamento(lectura,'+',dep);
        i++;
        }
}

fclose(archivoDepartamento);
cantDep=i-2;//REVISAR ESTO

}


Departamento leerDepartamento(char variableDepartamento [],char delimitador,Departamento d){

int ubicacionPrimerLimitador = 0;
char auxNombre [100]=" ";
char auxDescripcion [100]=" ";

int i=0;

for (i=0;i<100;i++){
    if (variableDepartamento[i]==delimitador){
        ubicacionPrimerLimitador=i;
        i=100;
    }
}

for (i=0;i<ubicacionPrimerLimitador;i++){
   auxNombre[i]=variableDepartamento[i];
}

for (i=ubicacionPrimerLimitador+1;i<100;i++){
    auxDescripcion[i-ubicacionPrimerLimitador-1]=variableDepartamento[i];
}

 d=crearDepartamento(auxNombre,auxDescripcion);

return d;
}

void mostrarVectorDeDepartamentos(Departamento vectorDepartamento[4]){


int i;

for (i=0;i<cantDep;i++){
    mostrarDepartamento(vectorDepartamento[i]);
}


}


void cargarUniversidad(Universidad u){

FILE * archivoUniversidad = fopen("universidad.txt","r");
int i=0;

while (!feof(archivoUniversidad)){
    char lectura[150];
    fgets(lectura,150,archivoUniversidad);
    if(!feof(archivoUniversidad)){
        Universidad unla;
        u=leerUniversidad(lectura,'+',unla);
            i++;
    }
}
fclose(archivoUniversidad);


}


Universidad leerUniversidad(char variableUniversidad[],char delimitador,Universidad un){


int ubicacionPrimerDelimitador = 0;
int ubicacionSegundoDelimitador = 0;
int ubicacionTercerDelimitador = 0;

char auxNombre[100]=" ";
char auxDireccion[100]=" ";
char auxContacto[100]=" ";

 int i;
 for (i=0;i<200;i++){
    if (variableUniversidad[i]==delimitador){
        ubicacionPrimerDelimitador=i;//HALLO EL PRIMER DELIMITADOR
        i=200;
    }
 }

 for(i = ubicacionPrimerDelimitador+1; i < 200; i++){
        if(variableUniversidad[i] == delimitador){
            ubicacionSegundoDelimitador = i; //HALLO EL SEGUNDO DELIMITADOR
            i = 200;
        }
    }

    for(i = ubicacionSegundoDelimitador+1; i < 200; i ++){
        if(variableUniversidad[i] == delimitador){
            ubicacionTercerDelimitador = i; //HALLO EL TERCER DELIMITADOR
            i = 200;
        }
    }
int j;
    for(j = 0; j < ubicacionPrimerDelimitador; j ++){
        auxNombre[j] = variableUniversidad[j]; //GUARDO CARACTER A CARACTER EL NOMBRE
    }

    for(j = ubicacionPrimerDelimitador+1; j < ubicacionSegundoDelimitador; j ++){
        auxDireccion[j-ubicacionPrimerDelimitador-1] = variableUniversidad[j]; //GUARDO CARACTER A CARACTER EL APELLIDO
    }

    for(j = ubicacionSegundoDelimitador+1; j < 150; j ++){
        auxContacto[j-ubicacionSegundoDelimitador-1] = variableUniversidad[j]; //GUARDO CARACTER A CARACTER EL DNI
    }


    //PUEDE ESTAR ACA EL ERROR
    un = crearUniversidad(auxNombre,auxDireccion,atoi(auxContacto));

    //prueba de que los parametros estan bien
     printf ("%s %s %s",auxNombre,auxDireccion,auxContacto);

    return un;

}

void mostrarUniversidadArchivos(Universidad u){//O PUEDE ESTAR EN ESTA FUNCION EL ERROR

 mostrarUniversidad(u);*/


}








