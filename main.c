#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 30

//ESTRUCTURAS
typedef struct
{
    int matricula;
    char nombre[DIM];
    char genero; //m, f, o
} StAlumno;

//PROTOTIPADO
void mostrarTPN6();
void menuTPN6();
int generarArrayAlumnos(StAlumno [], int );
StAlumno generarAlumnoEnArray(StAlumno [], int );
int generarMatriculaEnArray(StAlumno [], int );
int generarNombre(char [], int );
char generarGenero();
//Ejercicio 1
int cargarArrayAlumnos(StAlumno []);
StAlumno cargarAlumno();
int comprobarGenero(char genero);
//Ejercicio 2
void mostrarArrayAlumnos(StAlumno [], int );
void mostrarAlumnoEnArray(StAlumno [], int , int );
//Ejercicio 3
void ejercicioNro3(StAlumno [], int );
void mostrarAlumnoXMatricula(StAlumno [], int , int );
//Ejercicio 4
void ordenarAlumnosXMatricula(StAlumno [], int );
int posicionMenorMatricula(StAlumno [], int , int );
int intercambiarAlumnosXMatricula(StAlumno [], int , int , int );
//Ejercicio 5
void ejercicioNro5(StAlumno [], int );
void mostrarAlumnosXGenero(StAlumno [], int , char );
char cargarGenero();
void intercambiarAlumno(StAlumno [], int , int , int );
//Ejercicio 6
int insertarAlumnoEnOrden(StAlumno [], int );
void intercambiarAlumnosEnArray(StAlumno [], int , int , int );
int insertarAlumnoEnArray(StAlumno [], int , int , StAlumno );
void mostrarAlumno(StAlumno );
//Ejercicio 7
void ordenarAlumnosXNombre(StAlumno [], int );
//Ejercicio 8
void ejercicioNro8(StAlumno [], int );
int contarAlumnosXGenero(StAlumno [], int , char );

//MAIN
int main()
{
    //LLAMADOS A FUNCION
    menuTPN6();

    printf("\n\nSaliendo del programa...\n");
    return 0;
}

//FUNCIONES
void mostrarTPN6()
{
    printf("\n\nTrabajo Practico Nro 6: Estructuras de Datos.");
    printf("\n\nSea la Estructura:");
    printf("\n| typedef struct {");
    printf("\n|     int matricula;");
    printf("\n|     char nombre[30];");
    printf("\n|     char genero;"); //m, f, o
    printf("\n| } stAlumno;");
    printf("\n\n1. Hacer una funcion que cargue un arreglo de alumnos, hasta que el usuario lo decida.");
    printf("\n\n2. Hacer una funcion que muestre un arreglo de alumnos por pantalla. Modularizar.");
    printf("\n\n3. Hacer una funcion que muestre por pantalla los datos de un alumno, conociendo su matricula. Modularizar.");
    printf("\n\n4. Hacer una funcion que ordene el arreglo de alumnos por medio del metodo de seleccion. El criterio de ordenacion es el numero de matricula.");
    printf("\n\n5. Hacer una funcion que muestre por pantalla los datos de los estudiantes de un genero determinado (se envia por parametro). Modularizar.");
    printf("\n\n6. Hacer una funcion que inserte en un arreglo ordenado por matricula un nuevo dato,conservando el orden.");
    printf("\n\n7. Hacer una funcion que ordene el arreglo de alumnos por medio del metodo de insercion. Elcriterio de ordenacion es el nombre.");
    printf("\n\n8. Hacer una funcion que cuente y retorne la cantidad de estudiantes de un genero determinado (se envia por parametro) que tiene un arreglo de alumnos.");
    printf("\n\n9. Hacer una funcion principal que pruebe el funcionamiento de todos los incisos anteriores, conun menu de opciones para poder ejecutar todas las funciones");
    printf("\nrequeridas. Tengan presente la correcta declaracion y el ambito de variables.\n");
}

//MENU
void menuTPN6()
{
    //DECLARACIONES
    srand(time(NULL));
    int i = 0, nroEjercicio = 0, validosAlumnos;
    char continuar = 's';

    StAlumno alumnos[DIM];

    //LLAMADOS A FUNCION
    while( continuar == 's' )
    {
        mostrarTPN6();
        printf("\nIngrese el numero de Ejercicio que desea ejecutar (0 para salir): ");
        fflush(stdin);
        scanf("%i", &nroEjercicio);
        switch( nroEjercicio )
        {
        case 1: //Ejercicio 1
            /** Desactivado / Se Genera Automaticamente
            validosAlumnos = cargarArrayAlumnos(alumnos);
            printf("\nvalidos: %i", validosAlumnos); //debug
            */
            validosAlumnos = generarArrayAlumnos(alumnos, 12);
            printf("\n\nGenerando %i alumnos...\n", validosAlumnos);
            break;
        case 2: //Ejercicio 2
            mostrarArrayAlumnos(alumnos, validosAlumnos);
            break;
        case 3: //Ejercicio 3
            ejercicioNro3(alumnos, validosAlumnos);
            break;
        case 4: //Ejercicio 4
            ordenarAlumnosXMatricula(alumnos, validosAlumnos);
            printf("\n\nOrdenando alumnos por numero de matricula...\n");
            break;
        case 5: //Ejercicio 5
            ejercicioNro5(alumnos, validosAlumnos);
            break;
        case 6: //Ejercicio 6
            printf("\nInsertando Alumno dentro de Alumnos...");
            validosAlumnos = insertarAlumnoEnOrden(alumnos, validosAlumnos);
            break;
        case 7: //Ejercicio 7
            printf("\nOrdenando alumnos por nombre...");
            ordenarAlumnosXNombre(alumnos, validosAlumnos);
            break;
        case 8: //Ejercicio 8
            ejercicioNro8(alumnos, validosAlumnos);
            break;
        case 9: //Ejercicio 9
            break;
        case 0:
            continuar = -1;
            break;
        default:
            printf("\n\nEl numero de ejercicio ingresado no es correcto, por favor ingresar un numero entre el 1 y el 9 inclusive.");
            continue;
        }
        if( continuar != -1 )
        {
            printf("\n\nDesea ejecutar otro ejercicio? s/n: ");
            fflush(stdin);
            scanf("%c", &continuar);
        }
    }
}

//Auxiliares
int generarArrayAlumnos(StAlumno alumnos[], int validos)
{
    int i = 0;
    while( i < validos && i < DIM )
    {
        alumnos[i] = generarAlumnoEnArray(alumnos, validos);
        i++;
    }
    return validos;
}

StAlumno generarAlumnoEnArray(StAlumno alumnos[], int validos)
{
    StAlumno alumnoNuevo;
    char nombre[DIM];
    int validosNombre = 0; //puede ser útil
    alumnoNuevo.matricula = generarMatriculaEnArray(alumnos, validos);
    validosNombre = generarNombre(nombre, 20);
    strcpy(alumnoNuevo.nombre, nombre);
    alumnoNuevo.genero = generarGenero();
    return alumnoNuevo;
}

int generarMatriculaEnArray(StAlumno alumnos[], int validos)
{
    int i = 0;
    int matricula = rand()%100;
    while( i < validos && i < DIM )
    {
        if( matricula == alumnos[i].matricula)
        {
            matricula = rand()%100;
            i = -1;
        }
        i++;
    }
    return matricula;
}

int generarNombre(char nombre[], int validos)
{
    int i = 0;
    while( i < validos-1 && i < DIM )
    {
        nombre[i] = rand()%25+97;
        i++;
    }
    nombre[i] = '\0';
    i++;
    validos = i;
    return validos;
}

char generarGenero() //nice name
{
    char genero;
    int rand3 = rand()%3;
    if( rand3 == 0 ) genero = 'm';
    else if( rand3 == 1 ) genero = 'f';
    else if( rand3 == 2 ) genero = 'o';
    return genero;
}

//Ejercicio 1
int cargarArrayAlumnos(StAlumno alumnos[])
{
    int i = 0, validos;
    char continuar = 's';
    while( continuar == 's' && i < DIM )
    {
        alumnos[i] = cargarAlumno();
        printf("\nDesea ingresar otro alumno? s/n: ");
        fflush(stdin);
        scanf("%c", &continuar);
        i++;
    }
    validos = i;
    return validos;
}

StAlumno cargarAlumno()
{
    StAlumno alumnoNuevo;
    int generoComprobado = 0;
    char genero;
    printf("\nIngrese el numero de matricula: ");
    fflush(stdin);
    scanf("%i", &alumnoNuevo.matricula);
    printf("\nIngrese el nombre: ");
    fflush(stdin);
    gets(alumnoNuevo.nombre);
    do
    {
        printf("\nIngrese el genero 'm', 'f' u 'o': ");
        fflush(stdin);
        scanf("%c", &genero);
        generoComprobado = comprobarGenero(genero);
        if( generoComprobado == 0)
        {
            printf("\nEl genero ingresado no es valido, por favor ingresar 'm', 'f' u 'o'.");
        }
    }
    while( generoComprobado == 0 );
    alumnoNuevo.genero = genero;
    return alumnoNuevo;
}

int comprobarGenero(char genero)
{
    int valido = 0;
    switch( genero )
    {
    case 'm':
    case 'M':
    case 'f':
    case 'F':
    case 'o':
    case 'O':
        valido = 1;
        break;
    }
    return valido;
}

//Ejercicio 2
void mostrarArrayAlumnos(StAlumno alumnos[], int validosAlumnos)
{
    int indexAlumno = 0;
    while( indexAlumno < validosAlumnos )
    {
        mostrarAlumnoEnArray(alumnos, validosAlumnos, indexAlumno);
        indexAlumno++;
    }
}

void mostrarAlumnoEnArray(StAlumno alumnos[], int validosAlumnos, int indexAlumno)
{
    if( indexAlumno >= 0 && indexAlumno < validosAlumnos && validosAlumnos < DIM)
    {
        printf("\n---------------------------");
        printf("\nAlumno nro: %i", indexAlumno + 1);
        printf("\nMatricula: %i", alumnos[indexAlumno].matricula);
        printf("\nNombre: %s", alumnos[indexAlumno].nombre);
        printf("\nGenero: %c", alumnos[indexAlumno].genero);
    }
    else
    {
        printf("\n\nEl alumno no se encontro en la lista.\n");
    }
}

//Ejercicio 3
void ejercicioNro3(StAlumno alumnos[], int validosAlumnos)
{
    int matricula;
    printf("\n\nIngresar el numero de matricula que desea buscar: ");
    fflush(stdin);
    scanf("%i", &matricula);
    mostrarAlumnoXMatricula(alumnos, validosAlumnos, matricula);
}

void mostrarAlumnoXMatricula(StAlumno alumnos[], int validosAlumnos, int matriculaAlumno)
{
    int i = 0, indexEncontrado;
    char encontrado = 'n';
    while( i < validosAlumnos && encontrado == 'n' )
    {
        if( matriculaAlumno == alumnos[i].matricula )
        {
            indexEncontrado = i;
            encontrado = 's';
        }
        i++;
    }
    if( encontrado == 's' )
    {
        mostrarAlumnoEnArray(alumnos, validosAlumnos, indexEncontrado);
    }
    else
    {
         printf("\nNo se encontro el alumno matricula: %i", matriculaAlumno);
    }
}

//Ejercicio 4
void ordenarAlumnosXMatricula(StAlumno alumnos[], int validosAlumnos)
{
    int i = 0;
    int posicionMenor = 0;
    while( i < validosAlumnos && i < DIM )
    {
        posicionMenor = posicionMenorMatricula(alumnos, validosAlumnos, i);
        intercambiarAlumnosXMatricula(alumnos, validosAlumnos, i, posicionMenor);
        i++;
    }
}

int posicionMenorMatricula(StAlumno alumnos[], int validosAlumnos, int posicionInicial)
{
    int i = posicionInicial + 1;
    int posicionMenor = posicionInicial;
    while( i < validosAlumnos && i < DIM )
    {
        if( alumnos[i].matricula < alumnos[posicionMenor].matricula )
        {
            posicionMenor = i;
        }
        i++;
    }
    return posicionMenor;
}

int intercambiarAlumnosXMatricula(StAlumno alumnos[], int validosAlumnos, int matriculaAlumno1, int matriculaAlumno2)
{
    int valido = 0;
    if( matriculaAlumno1 < DIM && matriculaAlumno1 < validosAlumnos && matriculaAlumno1 >= 0 && matriculaAlumno2 < DIM && matriculaAlumno2 < validosAlumnos && matriculaAlumno2 >= 0 )
    {
        StAlumno alumnoAux;
        alumnoAux.matricula = alumnos[matriculaAlumno1].matricula;
        alumnoAux.genero = alumnos[matriculaAlumno1].genero;
        strcpy(alumnoAux.nombre, alumnos[matriculaAlumno1].nombre);
        alumnos[matriculaAlumno1].matricula = alumnos[matriculaAlumno2].matricula;
        alumnos[matriculaAlumno1].genero = alumnos[matriculaAlumno2].genero;
        strcpy(alumnos[matriculaAlumno1].nombre, alumnos[matriculaAlumno2].nombre);
        alumnos[matriculaAlumno2].matricula = alumnoAux.matricula;
        alumnos[matriculaAlumno2].genero = alumnoAux.genero;
        strcpy(alumnos[matriculaAlumno2].nombre, alumnoAux.nombre);
        valido = 1;
    }
    return valido;
}

//Ejercicio 5
void ejercicioNro5(StAlumno alumnos[], int validosAlumnos)
{
    char genero = cargarGenero();
    mostrarAlumnosXGenero(alumnos, validosAlumnos, genero);
}

void mostrarAlumnosXGenero(StAlumno alumnos[], int validosAlumnos, char genero)
{
    int i = 0;
    while( i < validosAlumnos && i < DIM)
    {
        if( genero == alumnos[i].genero )
        {
            mostrarAlumnoEnArray(alumnos, validosAlumnos, i);
        }
        i++;
    }
}

char cargarGenero()
{
    int generoComprobado;
    char genero;
    do
    {
        printf("\nIngrese el genero 'm', 'f' u 'o': ");
        fflush(stdin);
        scanf("%c", &genero);
        generoComprobado = comprobarGenero(genero);
        if( generoComprobado == 0)
        {
            printf("\nEl genero ingresado no es valido, por favor ingresar 'm', 'f' u 'o'.");
        }
    }
    while( generoComprobado == 0 );
    return genero;
}

//Ejercicio 6
int insertarAlumnoEnOrden(StAlumno alumnos[], int validosAlumnos)
{
    int i = validosAlumnos - 1;
    //StAlumno alumnoNuevo = cargarAlumno(); //cargado
    StAlumno alumnoNuevo = generarAlumnoEnArray(alumnos, validosAlumnos); //generado

    while( i >= 0 && alumnoNuevo.matricula < alumnos[i].matricula )
    {
        intercambiarAlumnosEnArray(alumnos, validosAlumnos, i, i+1);
        i--;
    }
    validosAlumnos = insertarAlumnoEnArray(alumnos, validosAlumnos, i+1, alumnoNuevo);
    return validosAlumnos;
}

void intercambiarAlumnosEnArray(StAlumno alumnos[], int validosAlumnos, int indexAlumno1, int indexAlumno2)
{
    StAlumno alumnoAux;

    alumnoAux.matricula = alumnos[indexAlumno1].matricula;
    alumnoAux.genero = alumnos[indexAlumno1].genero;
    strcpy(alumnoAux.nombre, alumnos[indexAlumno1].nombre);

    alumnos[indexAlumno1].matricula = alumnos[indexAlumno2].matricula;
    alumnos[indexAlumno1].genero = alumnos[indexAlumno2].genero;
    strcpy(alumnos[indexAlumno1].nombre, alumnos[indexAlumno2].nombre);

    alumnos[indexAlumno2].matricula = alumnoAux.matricula;
    alumnos[indexAlumno2].genero = alumnoAux.genero;
    strcpy(alumnos[indexAlumno2].nombre, alumnoAux.nombre);
}

int insertarAlumnoEnArray(StAlumno alumnos[], int validosAlumnos, int indexAlumno, StAlumno alumnoAInsertar)
{
    alumnos[indexAlumno].matricula = alumnoAInsertar.matricula;
    alumnos[indexAlumno].genero = alumnoAInsertar.genero;
    strcpy(alumnos[indexAlumno].nombre, alumnoAInsertar.nombre);
    return validosAlumnos + 1;
}

void mostrarAlumno(StAlumno alumno)
{
    printf("\n---------------------------");
    printf("\nMatricula: %i", alumno.matricula);
    printf("\nNombre: %s", alumno.nombre);
    printf("\nGenero: %c", alumno.genero);
}

//Ejercicio 7
void ordenarAlumnosXNombre(StAlumno alumnos[], int validosAlumnos)
{
    int i, j;
    StAlumno alumnoAInsertar;
    while( i < validosAlumnos && i < DIM )
    {
        alumnoAInsertar.matricula = alumnos[i].matricula;
        alumnoAInsertar.genero = alumnos[i].genero;
        strcpy(alumnoAInsertar.nombre, alumnos[i].nombre);
        j = i - 1;
        while( j >= 0 && strcmp(alumnos[j].nombre, alumnoAInsertar.nombre) > 0 )
        {
            intercambiarAlumnosEnArray(alumnos, validosAlumnos, j+1, j);
            j--;
        }
        insertarAlumnoEnArray(alumnos, validosAlumnos, j+1, alumnoAInsertar);
        i++;
    }
}

//Ejercicio 8
void ejercicioNro8(StAlumno alumnos[], int validosAlumnos)
{
    char genero;
    int generoComprobado = 0;
    do
    {
        printf("\nIngrese el genero que desea contar 'm', 'f' u 'o': ");
        fflush(stdin);
        scanf("%c", &genero);
        generoComprobado = comprobarGenero(genero);
        if( generoComprobado == 0)
        {
            printf("\nEl genero ingresado no es valido, por favor ingresar 'm', 'f' u 'o'.");
        }
    }
    while( generoComprobado == 0 );
    printf("\nContando alumnos...");
    printf("\nHay %i alumnos del genero %c.", contarAlumnosXGenero(alumnos, validosAlumnos, genero), genero);
}

int contarAlumnosXGenero(StAlumno alumnos[], int validosAlumnos, char genero)
{
    int i = 0, cantidadGenero = 0;
    while( i < validosAlumnos && i < DIM )
    {
        if( alumnos[i].genero == genero )
        {
            cantidadGenero++;
        }
        i++;
    }
    return cantidadGenero;
}

//Ejercicio 9 implementado

//Olmos Fernando, UTN2023

