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
#include <stdlib.h>
#include <stdio.h>
//Se agrega el .h
#include "funciones.h"
/*
 * validadorIgualesConsecutivos  - verifica que no existan 3 numeros iguales consecutivos
 *
 *Entrada: arreglo de 12 numeros de formato int y el largo de dicho arreglo.
 *Salida: Numero int 1 si existen 3 numeros iguales consecutivos o 0 de lo contrario.
 */
int validadorIgualesConsecutivos(int c[], int tamanio)
{
    for(int m=0; m<(tamanio-2); m++)
    {
        if(c[m]==c[m+1] && c[m+1]==c[m+2])
        {
            return 1;
        }
    }
    return 0;
}
/*
 * validadorImparImpar - verifica que si el primer numero es impar, no termine en impar
 *
 *Entrada: 2 numeros de formato int.
 *Salida: Numero int 1 si ambos son impar o 0 de lo contrario.
 */
int validadorImparImpar(int c1, int c12)
{
    if(c1%2==1 && c12%2==1)
    {
        return 1;
    }
    return 0;
}

/*
 * validadorConsecutivos - verifica que no tenga mas de 3 numeros consecutivos
 *
 *Entrada: arreglo de 12 numeros de formato int y el largo de dicho arreglo.
 *Salida: Numero int 1 si existen 4 numeros consecutivos o 0 de lo contrario.
 */
int validadorConsecutivos(int c[], int tamanio)
{
    for(int m=0; m<(tamanio-3); m++)
    {
        if((c[m]+4)<10)
        {
            if((c[m]+1)==(c[m+1]) && (c[m]+2)==(c[m+2]) && (c[m]+3)==(c[m+3]) && (c[m]+4)==(c[m+4]))
            {
                return 1;
            }
        }
    }
    return 0;
}