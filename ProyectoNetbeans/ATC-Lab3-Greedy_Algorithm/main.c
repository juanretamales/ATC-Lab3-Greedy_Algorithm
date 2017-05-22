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
    int entrada[12];
    int largo = 0;
    
    printf("Iniciando...ok \n");
    int a,b,c,d,e,f,g,h,i,j,k,l;
    
    int x;
    int y=0;
    
    printf("Entrada.in...");
    
    /* Preparandose para leer el archivo entrada.in */
    FILE *archivo;

    archivo = fopen("entrada.in","r");
    fclose(archivo);
    
    archivo = fopen("entrada.in","w+");
    fputs("20 20000", archivo);
    rewind(archivo);
    if (archivo == NULL)
    {
        printf("\nError de apertura del archivo. \n\n");
    }
    else
    {
/*
        while((caracter = fgetc(archivo)) != EOF)
*/
        while( !feof( archivo ))
        {
            int cantidad, moneda;
            
           // fscanf( archivo, "Cadena:[%d]",  cadena);
            /* Revisando si la cadena tiene dos o mas items separados por espacio (solo se usaran los dos primeros) y los guarda en variables */
            if(fscanf( archivo, "%d %d",  cantidad, moneda)==2)
            {
                printf("\n Cantidad:[%d] Moneda:[%d]",cantidad,moneda);
                /* Lee el archivo entrada.in pero en formato UTF8 sin BOM */
                /* Verificamos que cantidad y moneda solo sean numericos */
                if(isdigit(cantidad)!=0 && isdigit(moneda)!=0)
                {
                    printf("\n Ambos son numericos");
    /*              
                    if(largo>0)
                    {
                        y=0;
                        for ( x = 0; x < largo; x++ )
                        {
                            if(entrada[x]==(((int)caracter)-48))
                            {
                                y=1;
                            }
                        }
                    }
                    if(y==0)
                    {
                        entrada[largo]=((int)caracter)-48;
                        largo++;
                    }
    */
                }
                else
                {
                    if(isdigit(cantidad)==0)
                    {
                        printf("\n - Descartando combinaciones con letras encontrada en cantidad: [%d] -",cantidad);
                    }
                    if(isdigit(moneda)==0)
                    {
                        printf("\n - Descartando combinaciones con letras encontrada en moneda: [%d] -",moneda);
                    }
                }
            }
            else
            {
                printf("\n ERROR: alguna linea de entrada.in no tiene espacios entre cantidad moneda y valor moneda");
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
        int salida = 0;
        printf("ok \n");
        printf("Formando las  combinaciones posibles y guardandolo en salida.out...");
        /* -Creo el archivo salida.out sin contenido, y lo reemplaza de ser existente.  */
        FILE *fp;
        fp = fopen ( "salida.out", "w" );
        fclose(fp);
        printf("Terminando ejecucion, continuacion no implementada.");
        /* -Creo la combinacion*/
/*
        for ( a = 0; a < largo; a++ )
        {
            for ( b = 0; b < largo; b++ )
            {
                for ( c = 0; c < largo; c++ )
                {
                    int temp[] = {entrada[a], entrada[b], entrada[c]};
                    if(validadorIgualesConsecutivos(temp,3)==0)
                    {
                        for ( d = 0; d < largo; d++ )
                        {
                            int temp2[] = {entrada[a], entrada[b], entrada[c], entrada[d]};
                            if(validadorIgualesConsecutivos(temp2,4)==0 && validadorConsecutivos(temp2,4)==0)
                            {
                                for ( e = 0; e < largo; e++ )
                                {
                                    int temp3[] = {entrada[a], entrada[b], entrada[c], entrada[d], entrada[e]};
                                    if(validadorIgualesConsecutivos(temp3,5)==0 && validadorConsecutivos(temp3,5)==0)
                                    {
                                        for ( f = 0; f < largo; f++ )
                                        {
                                            int temp4[] = {entrada[a], entrada[b], entrada[c], entrada[d], entrada[e], entrada[f]};
                                            if(validadorIgualesConsecutivos(entrada,6)==0 && validadorConsecutivos(temp4,6)==0)
                                            {
                                                for ( g = 0; g < largo; g++ )
                                                {
                                                    int temp5[] = {entrada[a], entrada[b], entrada[c], entrada[d], entrada[e], entrada[f], entrada[g]};
                                                    if(validadorIgualesConsecutivos(temp5,7)==0 && validadorConsecutivos(temp5,7)==0)
                                                    {
                                                        for ( h = 0; h < largo; h++ )
                                                        {
                                                            int temp6[] = {entrada[a], entrada[b], entrada[c], entrada[d], entrada[e], entrada[f], entrada[g], entrada[h]};
                                                            if(validadorIgualesConsecutivos(temp6,8)==0 && validadorConsecutivos(temp6,8)==0)
                                                            {
                                                                for ( i = 0; i < largo; i++ )
                                                                {
                                                                    int temp7[] = {entrada[a], entrada[b], entrada[c], entrada[d], entrada[e], entrada[f], entrada[g], entrada[h], entrada[i]};
                                                                    if(validadorIgualesConsecutivos(temp7,9)==0 && validadorConsecutivos(temp7,9)==0)
                                                                    {
                                                                        for ( j = 0; j < largo; j++ )
                                                                        {
                                                                            int temp8[] = {entrada[a], entrada[b], entrada[c], entrada[d], entrada[e], entrada[f], entrada[g], entrada[h], entrada[i], entrada[j]};
                                                                            if(validadorIgualesConsecutivos(temp8,10)==0 && validadorConsecutivos(temp8,10)==0)
                                                                            {
                                                                                for ( k = 0; k < largo; k++ )
                                                                                {
                                                                                    int temp9[] = {entrada[a], entrada[b], entrada[c], entrada[d], entrada[e], entrada[f], entrada[g], entrada[h], entrada[i], entrada[j], entrada[k]};
                                                                                    if(validadorIgualesConsecutivos(temp9,11)==0 && validadorConsecutivos(temp9,11)==0)
                                                                                    {
                                                                                        for ( l = 0; l < largo; l++ )
                                                                                        {
                                                                                            int temp10[] = {entrada[a], entrada[b], entrada[c], entrada[d], entrada[e], entrada[f], entrada[g], entrada[h], entrada[i], entrada[j], entrada[k], entrada[l]};
                                                                                            if(validadorIgualesConsecutivos(temp10,12)==0 && validadorImparImpar(entrada[a],entrada[l])==0 && validadorConsecutivos(temp10,12)==0)
                                                                                            {
                                                                                                fp = fopen ( "salida.out", "a" );
                                                                                                fprintf(fp, "%d%d%d%d%d%d%d%d%d%d%d%d \n", entrada[a], entrada[b], entrada[c], entrada[d], entrada[e], entrada[f], entrada[g], entrada[h], entrada[i], entrada[j], entrada[k], entrada[l]);
                                                                                                fclose ( fp );
                                                                                                salida++;
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }

                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } 
        printf("ok \n");
        if(salida==0)
        {
            printf("No hubieron combinaciones validas para salida.out, revisa los numeros ingresados y asegurate de que minimo tengas 1 numero par. \n");
        }
        else
        {
            printf("\n Se lograron crear %d combinaciones validas.", salida);
        }
*/
    }
    else
    {
        printf("Se necesitan como minimo 2 digitos en el archivo entrada.in de los cuales como minimo 1 tiene que ser par. \n");
    }
    printf("Tiempo transcurrido: %f segundos", ((double)clock() - start) / CLOCKS_PER_SEC);
 
    return (EXIT_SUCCESS); 
}
