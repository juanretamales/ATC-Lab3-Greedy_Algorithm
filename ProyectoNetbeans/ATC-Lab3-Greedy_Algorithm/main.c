/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Juan Retamales
 * Licence: Atribución-NoComercial-SinDerivadas - CC BY-NC-ND 
 *
 * Created on 15 de abril de 2017, 20:45
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "funciones.h"

int main(int argc, char** argv) 
{
    
    clock_t start = clock();
    int entrada[12][2];
    int largo = 0;
    int cantidad, moneda;
    
    
    
    printf("Iniciando...ok \n");
    
    printf("Entrada.in...");
    
    FILE *archivo;
    archivo = fopen("entrada.in","r");
    
    if (archivo == NULL)
    {
        printf("\nError de apertura del archivo. \n\n");
    }
    else
    {
        //for(int i=0;i<)
        while(fscanf( archivo, "%d %d",  &cantidad, &moneda) != EOF)
        {
            printf("\n Cantidad:[%d] Moneda:[%d]",cantidad,moneda);
            /* Lee el archivo entrada.in pero en formato UTF8 sin BOM */
            /* Verificamos que cantidad y moneda solo sean numericos */
            
            if(cantidad>0 && moneda>0)
            {
                printf("\n Ambos son numericos");
                if(entrada[largo][1]<entrada[largo-1][1])
                {
                    entrada[largo][0] = cantidad;
                    entrada[largo][1] = moneda;
                    largo++;
                }
                else
                {
                    printf("\n el valor moneda de entrada.in debe ir de manera decendente, forzando cierre.");
                    return (EXIT_FAILURE); 
                }
            }
            else
            {
                if(cantidad==0)
                {
                    printf("\n - El valor: [%d] se descartara debido a que contiene letras",cantidad);
                }
                if(moneda==0)
                {
                    printf("\n - El valor: [%d] se descartara debido a que contiene letras",moneda);
                }
            }
            if (feof(archivo))
            {
                printf("\n Fin de la lectura");
                break;
            }
        }
    }
    fclose(archivo);
    
    /* Solo creara combinaciones si encontramos alguna entrada, de lo contrario desplegara un mensaje */
    if(largo>1)
    {
        int pago;
        int entrega;
        int vuelto;
        int actual;
        while(pago==0 || entrega==0)
        {
            for(int i=0;actual!=0 || entrada[i];i++)
            {
                int operacion[12][2];
                printf("(Introduce cero para terminar)");
                printf("Total a pagar: ");
                scanf("%d", &pago);
                printf("(Introduce cero para terminar)");
                printf("Cliente entrega: ");
                scanf("%d", &entrega);
                vuelto=pago-entrega;
                actual=vuelto;/*Dinero actual que falta para hacer el vuelto, no se trabaja con vuelto por que se vuelve a utilizar.*/
                if(actual>0)
                {
                    int temp=0;
                    /* Reviso si dar vuelto de esa moneda es posible */
                    temp=actual/entrada[i,2];
                    if(temp>1)
                    {
                        /*reviso si tengo suficientes de esas monedas para dar vuelto */
                        if(entrada[i,1]>=temp)
                        {
                            /*Agrego a operacion para despues quitar a caja el total si finaliza exitosamente.*/
                            operacion[i,2]=entrada[i,2];
                            operacion[i,1]=entrada[i,2]-(actual/entrada[i,2]);
                            /*Actualizo el vuelto a dar.*/
                            actual= actual-(operacion[i,1]*operacion[i,2]);
                            l--;
                        }
                    }
                }
                else
                {
                    if(vuelto<0)
                    {
                        printf("El cliente no entrego suficiente dinero");
                    }
                    if(vuelto=0)
                    {
                        printf("El cliente pago justo, no tiene vuelto.");
                    }
                }
            }
        }
    }
    else
    {
        printf("Se necesitan como minimo 2 digitos en el archivo entrada.in de los cuales como minimo 1 tiene que ser par. \n");
    }
    printf("Tiempo transcurrido: %f segundos", ((double)clock() - start) / CLOCKS_PER_SEC);
 
    return (EXIT_SUCCESS); 
}
