#ifndef UNIVERSIDAD_H_INCLUDED
#define UNIVERSIDAD_H_INCLUDED

struct EstructuraUniversidad{
    char nombre[30];
    char direccion[30];
    int contacto;
    Departamento vectorDepartamentos[4];
    int cantDepartamentos;
};

typedef struct EstructuraUniversidad * Universidad;

//CONSTRUCTOR
Universidad crearUniversidad (char nombreU[30], char direccionU[30], int contacto);

//DESTRUCTOR
void destructorUniversidad(Universidad u);

//GETTERS
char * getNombreUniversidad(Universidad u);
char * getDireccionUniversidad(Universidad u);
int getContactoUniversidad(Universidad u);

//SETTERS
void setNombreUniversidad(Universidad u, char nuevoNombre[30]);
void setDireccionUniversidad(Universidad u, char nuevaDireccion[30]);
void setContactoUniversidad(Universidad u, int nuevoContacto);

//MOSTRAR UNIVERSIDAD
void mostrarUniversidad(Universidad u);

//AGREGAMOS DEPARTAMENTOS A LA UNIVERSIDAD
void agregarDepartamentosAUniversidad(Universidad u, Departamento d);

#endif // UNIVERSIDAD_H_INCLUDED
