#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "ArrayList.h"
#include "funciones.h"

//PARSEOS

int parseCargaDeDatos(ArrayList* lista,char filename[])
{
    FILE* fp;
    eAlumno* s;
    int id=0;
    int estado, edad, legajo;
    char nombre[40];
    char sexo[40];
    fp = fopen(filename,"r");
    if(fp!=NULL&&lista!=NULL)
    {
        do
        {
            s=emp_newStruct();
            fscanf(fp,"%d,%d,%d,%d,%[^,],%[^\n]\n",&id,&estado,&legajo,&edad,sexo,nombre);
            emp_setId(s,&id);
            emp_setEstado(s,estado);
            emp_setLegajo(s,legajo);
            emp_setNombre(s,nombre);
            emp_setSexo(s,sexo);
            emp_setEdad(s,edad);
            lista->add(lista,s);
        }
        while(!feof(fp));
        printf("\n");
    }
    else
    {
        printf("\n");
    }
    fclose(fp);

    return id;
}

void parseGuardarDatos(ArrayList* lista,char filename[])
{
    eAlumno* s;
    FILE* fp;
    int i;
    if(lista!=NULL)
    {
        fp=fopen(filename,"w");
        if(fp!=NULL)
        {
            for(i=0; i<lista->len(lista); i++)
            {
                s=(eAlumno*) lista->get(lista,i);
                fprintf(fp,"%d,%d,%d,%d,%s,%s\n",emp_getId(s),emp_getEstado(s),emp_getLegajo(s),emp_getEdad(s),emp_getSexo(s),emp_getNombre(s));
            }
        }
        fclose(fp);
    }
    else
    {
        printf("No se pudo generar un archivo.");
    }
            fclose(fp);

}

// FUNCIONES MUESTREO

void emp_mostrarUno (eAlumno* s)
{
    if(s!=NULL)
    {
        printf("\nID\t| Nombre\t| Sexo");
        printf("\n%d\t| %s\t| %s",emp_getId(s),emp_getNombre(s),emp_getSexo(s));
    }
}

void main_mostrarLista(ArrayList* lista)
{
    int i, len;
    eAlumno* g;
    if(lista!=NULL)
    {
        len=lista->len(lista);
        printf("\nID\t| Esta.\t| Leg.\t| Edad\t| Sexo\t| Nombre\n");
        for(i=0; i<len; i++)
        {
            g=lista->get(lista,i);
            if(emp_getEstado(g)!=0)
            {
                printf("\n%d\t| %d\t| %d\t| %d\t| %s\t| %s",emp_getId(g),emp_getEstado(g),emp_getLegajo(g) ,emp_getEdad(g),emp_getSexo(g),emp_getNombre(g));
            }
        }
        printf("\n");
    }
}

// FUNCION DE FILTRO EMPLEADO
int funcionFiltrar(void* alumno)
{
    int retorno=0;
    eAlumno* e;
    e = (eAlumno*)alumno;
    if(alumno!=NULL)
    {
        if(emp_getEdad(e)>30)
        {
                retorno=1;
        }
        else
        {
            retorno=0;
        }
    }
    return retorno;
}

// FULL FUNCIONES ARRAYLIST

eAlumno* emp_newStruct()
{
    eAlumno* aux;

    aux=(eAlumno*)malloc(sizeof(eAlumno));

    return aux;
}

//MASCARA PROGRAMA

void emp_newNombre(eAlumno* s)
{
    char aux[40];
    if(s!=NULL)
    {
        while(!string_getLetras("\nIngrese el nombre: ",aux))
        {
            printf("ATENCION! El nombre solo puede contener letras.");
        }
        strlwr(aux);
        *(aux+0)=toupper(*aux+0);
        strcpy(s->nombre,aux);
    }
}

int emp_newSexo(eAlumno* s)
{
    int opcion;
    if(s!=NULL)
    {
        printf("\nCual es el sexo del nuevo alumno?\n\n1.Mujer\n2.Hombre\n");
        opcion=entero_get("opcion");
        switch(opcion)
        {
        case 1:
            strcpy(s->sexo,"Mujer");
            break;
        case 2:
            strcpy(s->sexo,"Hombre");
            break;
        }
    }
    return opcion;
}

void emp_newEdad(eAlumno* s)
{
    int aux;
    if(s!=NULL)
    {
        do
        {
            aux=entero_get("edad");
        }
        while(!entero_validaRango(aux,"edad",18,99));
        s->edad=aux;
    }

}

// APLICACIONES DE SET

void emp_setId(eAlumno* s,int* id)
{
    if(s!=NULL)
    {
        s->idAlumno=*id;
    }
}

void emp_setEstado(eAlumno* s,int st)
{
    if(s!=NULL)
    {
        s->estado=st;
    }
}

void emp_setNombre(eAlumno* s, char* nombre)
{
    if(s!=NULL)
    {
        strcpy(s->nombre,nombre);
    }
}

void emp_setEdad (eAlumno* s, int edad)
{
    if(s!=NULL)
    {
        s->edad=edad;
    }
}

void emp_setLegajo (eAlumno* s, int legajo)
{
    if(s!=NULL)
    {
        s->legajo=legajo;
    }
}

void emp_setSexo(eAlumno* s, char* sexo)
{
    if(s!=NULL)
    {
        strcpy(s->sexo,sexo);
    }
}

// APLICACIONES GET

int emp_getId(eAlumno* s)
{
    int id;
    if(s!=NULL)
    {
        id=s->idAlumno;
    }
    return id;
}

int emp_getEstado(eAlumno* s)
{
    int st;
    if(s!=NULL)
    {
        st=s->estado;
    }
    return st;
}

char* emp_getSexo(eAlumno* s)
{
    char* str;
    if(s!=NULL)
    {
        str=s->sexo;
    }
    return str;
}

char* emp_getNombre (eAlumno* s)
{
    char* str=NULL;
    if(s!=NULL)
    {
        str=s->nombre;
    }
    return str;
}

int emp_getEdad(eAlumno* s)
{
    int edad;
    if(s!=NULL)
    {
        edad=s->edad;
    }
    return edad;
}

int emp_getLegajo(eAlumno* s)
{
    int legajo;
    if(s!=NULL)
    {
        legajo=s->legajo;
    }
    return legajo;
}

// FUNCIONES GENERICAS

int generic_menu (void)
{
    fflush(stdin);
    printf("---------------------\n");
    printf("----- ESCUELITA -----\n");
    printf("---------------------\n\n");
    printf("1. Listar Alumnos\n");
    printf("2. Listar Alumnos ordenados por edad\n");
    printf("3. Filtrar por alumnos mayor de 30 anios\n");

    printf("\n0. Salir\n");

    int opcion = entero_get("Opcion");

    return opcion;
}

void finFuncion (void)
{
    printf("\n");
    system("pause");
    system("cls");
}

int generic_confirmar(void)
{
    char respuesta;
    int flag = 0;
    do
    {
        if(flag)
        {
            printf("\nRespuesta incorrecta, ingrese s por SI o n por NO: ");
        }
        respuesta = getche();
        respuesta = tolower(respuesta);
        flag = 1;
    }
    while(respuesta!='s'&&respuesta!='n');
    if(respuesta=='s')
        return 1;
    else
        printf("\nAccion cancelada.");
    return 0;
}

void generic_alta(ArrayList* lista, int* id)
{
    eAlumno* s;
    //int sex;
    system("cls");

    printf("--- ALTA DE EMPLEADO ---\n");
    s=emp_newStruct();
    emp_newNombre(s);
    emp_newEdad(s);
    emp_newSexo(s);
    emp_setId(s,id);
    emp_setEstado(s,1);

    printf("\nConfirma dar de alta alumno? s/n: ");
    if(generic_confirmar())
    {
        lista->add(lista,s);
        parseGuardarDatos(lista,"data.csv");
    }
    finFuncion();
}

// VALIDAR STRINGS
int string_isNull (char value)
{
    if(value=='\0' || value ==' ')
    {
        return 1;
    }
    return 0;
}

int string_esNumerico(char array[])
{
    int i=0;

    if(string_isNull(array[0]))
    {
        return 0;
    }
    else
    {
        while(array[i] != '\0')
        {
            if((!isdigit(array[i])))
            {
                return 0;
            }
            i++;
        }
    }
    return 1;
}

int string_esSoloLetras(char array[])
{
    int i=0;
    if(string_isNull(array[0]))
    {
        return 0;
    }
    else
    {
        while(array[i] != '\0')
        {
            if( (!isspace(array[i])) && (!isalpha(array[i])) )
            {
                return 0;
            }
            i++;
        }
    }
    return 1;
}

int string_validaRango(char str[], int min, int max)
{
    int aux;
    aux = atoi(str);
    if(aux>=min&&aux<=max)
        return 1;
    else
    {
        printf("Error, el numero ingresado esta fuera de rango. MIN: %d MAX: %d",min,max);
        return 0;
    }
}

// VALIDACION GET (STRINGS)
void string_get(char mensaje[],char input[])
{
    fflush(stdin);
    printf("%s",mensaje);
    gets(input);
}

int string_getNumerico(char mensaje[],char input[])
{
    char aux[256];
    string_get(mensaje,aux);
    if(string_esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int string_getLetras(char mensaje[],char input[])
{
    char aux[256];
    string_get(mensaje,aux);
    if(string_esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

// VALIDACION DE ENTEROS
int entero_get(char mensaje[])
{
    char auxDato[20];
    int dato;
    printf("\nIngrese %s:",mensaje);
    while(!string_getNumerico(" ",auxDato))
    {
        printf("ATENCION, *%s* solo puede estar compuesto por numeros. \nReingrese %s:",mensaje,mensaje);
    }
    dato = atoi(auxDato);

    return dato;
}

int entero_validaRango(int dato, char mensaje[], int min, int max)
{
    if(dato >= min && dato <= max)
        return 1;
    else
    {
        printf("El rango *%s* debe estar entre %d y %d.\n",mensaje,min,max);
        return 0;
    }
}

int tramite_ordenarEdad(void* alumno1, void* alumno2)
{
    int returnAux;
    eAlumno* alumnoUno = (eAlumno*) alumno1;
    eAlumno* alumnoDos = (eAlumno*) alumno2;
        if(alumnoUno->edad > alumnoDos->edad)
        {
            returnAux =1;
        }
            else if( alumnoUno->edad < alumnoDos->edad)
            {
                returnAux =-1;
            }
                else
                {
                    returnAux = 0;
                }
    return returnAux;
}

