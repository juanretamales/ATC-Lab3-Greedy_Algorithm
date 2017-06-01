/* 
 * File:   funciones.h
 * Author: Juan Retamales
 * Licence: Atribución-NoComercial-SinDerivadas - CC BY-NC-ND 
 *
 * Created on 20 de abril de 2017, 16:19
 */

#ifndef FUNCIONES_H
    #define FUNCIONES_H
    /*
    * dinero  - revuelve el dinero total de la matriz de cantidad dinero y valor dinero
    *
    *Entrada: Matriz de dinero, largo de la matriz
    *Salida: Numero int con el valor del dinero total de la matriz.
    */
    int dinero(int entrada[][2],int largo);
    /*
    * leer  - pide por consola un numero, lo valida transformandolo y devuelve su valor
    *
    *Entrada: Texto char[] a mostrar para pedir el mensaje
    *Salida: Numero int del valor leido si es valido o 0 de lo contrario.
    */
    int leer(char e[]);
    
#endif /* FUNCIONES_H */

