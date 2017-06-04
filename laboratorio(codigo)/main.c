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
    int i=0;
            
    clock_t start = clock();
    int entrada[12][2]={{0, 20000},{0, 10000},{0, 5000},{0, 2000},{0, 1000},{0, 500},{0, 100},{0, 50},{0, 10},{0, 5},{0, 1}};
    int largo = 11;
    int cantidad, moneda;
    int cantPagos = 0;
    
    int inicial=0;
    
    
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
        char m[12] ="" ;
        char c[12] ="" ;
        while(fscanf( archivo, "%s %s",  c, m) != EOF)
        {
            /*Revisa si es transformable y si son mayores a cero*/
            if(atoi(m)>=0 && atoi(c)>=0)
            {
                moneda=atoi(m);
                cantidad=atoi(c);
                if(largo>0)
                {
                    for(i=0;i<largo;i++)
                    {
                        if(moneda==entrada[i][1])
                        {
                            entrada[i][0] = cantidad;
                            //printf("\n Agregando %d  de %d ",cantidad,entrada[i][1]);
                            inicial++;
                        }
                        if(i==largo)
                        {
                            printf("\n el valor moneda de entrada.in debe ir de manera decendente, forzando cierre.");
                            return (EXIT_FAILURE); 
                        }
                    }
                }
                else
                {
                    entrada[largo][0] = cantidad;
                    entrada[largo][1] = moneda;
                    largo++;
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
    
    /*Creo salida.out (si ya existe es reemplazado) e introdusco el registro */
    FILE *fp;
    fp = fopen ( "salida.out", "w" );
    fprintf(fp, "Inicial: %d \n", dinero(entrada,largo));
    fclose(fp);
    /* Solo creara combinaciones si encontramos alguna entrada, de lo contrario desplegara un mensaje */
    
    //printf("\n Largo > 0");

    int pago=-1;
    int entrega=-2;
    int vuelto;
    int actual;
    while(pago!=0 || entrega!=0)
    {
        int operacion[12][2]={{0, 20000},{0, 10000},{0, 5000},{0, 2000},{0, 1000},{0, 500},{0, 100},{0, 50},{0, 10},{0, 5},{0, 1}};
        printf("\n(Introduce cero para terminar)");
        pago=leer("\nTotal a pagar: ");
        if(pago!=0)
        {
            printf("\n(Introduce cero para terminar)");
            entrega=leer("\nCliente entrega: ");
        }
        else
        {
            entrega=0;
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
                        operacion[i][0] = 0 - temp;
                        temp=operacion[i][0]*operacion[i][1];
                        /*Actualizo el vuelto a dar.*/
                        actual= actual + temp;
                        //printf("\n Agregando a operacion %d  de %d para llegar a %d",operacion[i][0],entrada[i][1],temp);
                    }
                }
                else
                {
                    operacion[i][0] = 0;
                }
            }
            //printf("\n actual: [%d]",actual);
            if(actual==0)
            {
                printf("\n Vuelto: %d",vuelto);
                /*Asigno vuelto a actual para agregar el pago a caja*/
                actual=entrega;
                /*Agrego a operacion el dinero recibido*/
                for(int i=0;i<largo;i++)
                {
                    //printf("\n - Pago: %d",pago);
                    /* Reviso si dar vuelto de esa moneda es posible */
                    temp = actual / entrada[i][1];
                    //printf("\n - Intentando %d billetes de %d",temp,entrada[i][1]);

                    if(temp>0)
                    {

                        //printf("\n - - Actual [%d]",actual);

                        /*Agrego a operacion para despues agregar a caja el total */
                        operacion[i][0] = operacion[i][0]+temp;
                        /*Actualizo el vuelto a dar.*/
                        actual= actual-(temp*operacion[i][1]);
                        if(actual==0)
                        {
                            break;
                        }
                    }
                }
                //printf("\n - - Actual [%d]",actual);
                /*Muestro el mejor vuelto*/
                for(int i=0;i<largo;i++)
                {
                    if(operacion[i][0]<0)
                    {
                        /*Realizo efectivo la resta del dinero por el vuelto y la suma por el pago al dinero actual (caja)*/
                        if(operacion[i][1]>999)
                        {
                            if(operacion[i][0]>1)
                            {
                                printf("\n %d billetes de %d ",abs(operacion[i][0]),operacion[i][1]);
                            }
                            else
                            {
                                printf("\n %d billete de %d ",abs(operacion[i][0]),operacion[i][1]);
                            }
                        }
                        else
                        {
                            if(operacion[i][0]>1)
                            {
                                printf("\n %d monedas de %d ",abs(operacion[i][0]),operacion[i][1]);
                            }
                            else
                            {
                                printf("\n %d moneda de %d ",abs(operacion[i][0]),operacion[i][1]);
                            }
                        }
                    }
                    /*Realiza los cambios en el arreglo*/
                    if(operacion[i][0]!=0)
                    {
                         entrada[i][0]= entrada[i][0] + operacion[i][0];
                    }
                }
                cantPagos++;
                fp = fopen ( "salida.out", "a" );
                int din = dinero(entrada,largo);
                fprintf(fp, "Pago %d: %d \n", cantPagos, din);
                //printf("\n Pago %d: %d \n", cantPagos, din);
                fclose(fp);
            }
            else
            {
                printf("\n No puede generar un vuelto con el saldo disponible, cerrando aplicacion, falto [%d]}",actual);
                break;
            }
        }
        else
        {
            if(pago!=0 && entrega!=0)
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
    printf("\n Finalizando aplicacion");
    printf("\n Tiempo transcurrido: %f segundos", ((double)clock() - start) / CLOCKS_PER_SEC);
 
    return (EXIT_SUCCESS); 
}
