/*
1. Crear el archivo alumnos.csv que va a contener la informacion de 10 alumnos (nombre, edad, legajo, sexo), los cuales deben ser creados de
   manera dinamica y almacenados en un arraylist
2. Listar los alumnos del arraylist ordenados por edad -

MARIANO MADOU - DIVISION 1C - TURNO TARDE
*/

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    ArrayList* alumnos=al_newArrayList();
    ArrayList* alumnosMayores=al_newArrayList();

    int opcion, salir=0;
    parseCargaDeDatos(alumnos,"data.csv");
    do
    {
        opcion = generic_menu();
        switch(opcion)
        {
        case 1:
            main_mostrarLista(alumnos);
            finFuncion();
            break;

            case 2:
            al_sort(alumnos,tramite_ordenarEdad,0);
            main_mostrarLista(alumnos);
            finFuncion();
            break;

        case 3:
            alumnosMayores=al_filter(alumnos,funcionFiltrar);
            main_mostrarLista(alumnosMayores);
            parseGuardarDatos(alumnosMayores,"out.csv");
            finFuncion();
            break;
        case 4:

        case 0:
            printf("-END-\n");
            salir = 1;
            break;
        default:
            printf("\nOpcion invalida. Intente otra vez.\n");
            system("pause");
            system("cls");
            break;
        }
    }
    while(salir==0);
    return 0;
}
