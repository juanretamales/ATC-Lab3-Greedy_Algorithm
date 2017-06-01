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
    int cantPagos = 0;
    
    
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
        char m[12] ="" ;
        char c[12] ="" ;
        while(fscanf( archivo, "%s %s",  c, m) != EOF)
        {
            //printf("\n Cantidad:[%s] Moneda:[%s] text version",c,m);
            if(atoi(m)>0 && atoi(c)>0)
            {
                moneda=atoi(m);
                cantidad=atoi(c);
                //printf("\n Cantidad:[%d] Moneda:[%d] int version",cantidad,moneda);
                if(largo>0)
                {
                    //printf("\n Largo > 0");
                    //printf("\n %d < %d",moneda,entrada[largo][1]);
                    if(moneda<entrada[largo-1][1])
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
                    entrada[largo][0] = cantidad;
                    entrada[largo][1] = moneda;
                    largo++;
                }
            }
            /* Lee el archivo entrada.in pero en formato UTF8 sin BOM */
            /* Verificamos que cantidad y moneda solo sean numericos */
            
/*
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
*/
            if (feof(archivo))
            {
                printf("\n Fin de la lectura");
                break;
            }
        }
    }
    fclose(archivo);
    
    /*Creo salida.out (si ya existe es reemplazado) e introdusco el registro */
    FILE *fp;
    fp = fopen ( "salida.out", "w" );
    fprintf(fp, "Inicial: %d \n", dinero(entrada,largo));
    fclose(fp);
    /* Solo creara combinaciones si encontramos alguna entrada, de lo contrario desplegara un mensaje */
    if(largo>0)
    {
        printf("\n Largo > 0");
        
        int pago=-1;
        int entrega=-2;
        int vuelto;
        int actual;
        char e[12] ="" ;
        while(pago!=0 || entrega!=0)
        {
            int i=0;
            int o=0;
            int operacion[12][2];
            printf("\n(Introduce cero para terminar)");
            printf("\nTotal a pagar: ");
            scanf("%s", e);
            if(atoi(e)>0)
            {
                pago=atoi(e);
            }
            else if(atoi(e)==0)
            {
                pago=0;
            }
            else
            {
                pago=0;
                printf("Error al introducir el pago");
            }
            printf("\n(Introduce cero para terminar)");
            printf("\nCliente entrega: ");
            scanf("%s", e);
            if(atoi(e)>0)
            {
                entrega=atoi(e);
            }
            else if(atoi(e)==0)
            {
                entrega=0;
            }
            else
            {
                entrega=0;
                printf("\n Error al introducir el pago");
            }
            vuelto=entrega-pago;
            if(vuelto>0)
            {
                int temp=0;
                actual=vuelto;/*Dinero actual que falta para hacer el vuelto, no se trabaja con vuelto por que se vuelve a utilizar.*/
                for(int i=0;actual!=0 && i<largo;i++)
                {
                    /* Reviso si dar vuelto de esa moneda es posible */
                    temp = actual / entrada[i][1];
                    //printf("\n - Intentando %d billetes de %d ",temp,entrada[i][1]);
                    if(temp>0)
                    {
                        /*reviso si tengo suficientes de esas monedas para dar vuelto */
                        if(entrada[i][0]>=temp)
                        {
                            /*Agrego a operacion para despues quitar a caja el total si finaliza exitosamente.*/
                            operacion[i][1] = entrada[i][1];
                            operacion[i][0] = temp;
                            /*Actualizo el vuelto a dar.*/
                            actual= actual-(operacion[i][0]*operacion[i][1]);
                        }
                    }
                    else
                    {
                        operacion[i][1] = entrada[i][1];
                        operacion[i][0] = 0;
                    }
                }
                if(actual==0)
                {
                    printf("\n Vuelto: %d",vuelto);
                    /*Muestro el mejor vuelto*/
                    for(int i=0;i<largo;i++)
                    {
                        if(operacion[i][0]>0)
                        {
                            /*Realizo efectivo la resta del dinero actual por el vuelto*/
                            entrada[i][0]= entrada[i][0] - operacion[i][0];

                            if(operacion[i][1]>999)
                            {
                                if(operacion[i][0]>1)
                                {
                                    printf("\n %d billetes de %d ",operacion[i][0],operacion[i][1]);
                                }
                                else
                                {
                                    printf("\n %d billete de %d ",operacion[i][0],operacion[i][1]);
                                }
                            }
                            else
                            {
                                if(operacion[i][0]>1)
                                {
                                    printf("\n %d monedas de %d ",operacion[i][0],operacion[i][1]);
                                }
                                else
                                {
                                    printf("\n %d moneda de %d ",operacion[i][0],operacion[i][1]);
                                }
                            }
                        }
                    }
                    cantPagos++;
                    fp = fopen ( "salida.out", "a" );
                    fprintf(fp, "Pago %d: %d \n", cantPagos, dinero(entrada,largo));
                    printf("\n Pago %d: %d \n", cantPagos, dinero(entrada,largo));
                    fclose(fp);
                }
                else
                {
                    printf("\n No puede generar un vuelto con el saldo disponible, cerrando aplicacion");
                    break;
                }
            }
            else
            {
                if(vuelto<0)
                {
                    printf("\n El cliente no entrego suficiente dinero");
                }
                if(vuelto=0)
                {
                    printf("\n El cliente pago justo, no tiene vuelto.");
                }
            }
        }
    }
    else
    {
        printf("\n Se necesitan como minimo 2 digitos en el archivo entrada.in de los cuales solo tiene %d ",largo);
    }
    printf("\n Tiempo transcurrido: %f segundos", ((double)clock() - start) / CLOCKS_PER_SEC);
 
    return (EXIT_SUCCESS); 
}
