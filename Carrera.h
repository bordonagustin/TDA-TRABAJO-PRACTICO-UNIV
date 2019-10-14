#ifndef CARRERA_H_INCLUDED
#define CARRERA_H_INCLUDED

struct EstructuraCarrera{
    char nombreCarrera[45];
    char nombreTitulo [50];
    Materia vectorMaterias[5];
    int cantMaterias;
};

typedef struct EstructuraCarrera * Carreras;

//CONSTRUCTOR
Carreras crearCarrera(char nombreC[50], char nombreT[50]);

//DESTRUCTOR
void destructorCarrera(Carreras c);

//GETTERS
char * getNombreCarr(Carreras c);
char * getNombreTitCarr(Carreras c);

//SETTERS
void setNombreCarr(Carreras c, char nuevoNombre[45]);
void SstNombreTitCarr(Carreras c, char nuevoNombreTit[50]);

//MOSTRAR CARRERA
void mostrarCarrera(Carreras c);

//AGREGAMOS MATERIAS A LA CARRERA
void agregarMateriaACarrera(Carreras c, Materia m);

#endif // CARRERA_H_INCLUDED
