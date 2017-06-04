/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.c
 * Author: Juan Retamales
 * Licence: Atribución-NoComercial-SinDerivadas - CC BY-NC-ND 
 *
 * Created on 15 de abril de 2017, 20:45
 */
//Definición de las inclusiones
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//Se agrega el .h
#include "funciones.h"

/*
 * dinero  - revuelve el dinero total de la matriz de cantidad dinero y valor dinero
 *
 *Entrada: Matriz de dinero, largo de la matriz
 *Salida: Numero int con el valor del dinero total de la matriz.
 */
int dinero(int entrada[][2],int largo)
{
    int d=0;
    for(int i=0;i<largo;i++)
    {
        d=d+(entrada[i][0]*entrada[i][1]);
        //printf("\n Dinero al momento %d ",d);
    }
    return d;
}
/*
 * leer  - pide por consola un numero, lo valida transformandolo y devuelve su valor
 *
 *Entrada: Texto char[] a mostrar para pedir el mensaje
 *Salida: Numero int del valor leido si es valido o 0 de lo contrario.
 */
int leer(char str[])
{
    char e[12];
    printf("%s",str);
    scanf("%s", e);
    if(atoi(e)>0)
    {
        return atoi(e);
    }
    else if(atoi(e)==0)
    {
        return 0;
    }
    else
    {
        printf("\n Error al introducir el pago");
        return 0;
    }
}