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
     * validadorIgualesConsecutivos  - verifica que no existan 3 numeros iguales consecutivos
     *
     *Entrada: arreglo de 12 numeros de formato int y el largo de dicho arreglo.
     *Salida: Numero int 1 si existen 3 numeros iguales consecutivos o 0 de lo contrario.
     */
    int validadorIgualesConsecutivos(int c[], int tamanio);
    /*
     * validadorImparImpar - verifica que si el primer numero es impar, no termine en impar
     *
     *Entrada: 2 numeros de formato int.
     *Salida: Numero int 1 si ambos son impar o 0 de lo contrario.
     */
    int validadorImparImpar(int c1, int c12);
    /*
     * validadorConsecutivos - verifica que no tenga mas de 3 numeros consecutivos
     *
     *Entrada: arreglo de 12 numeros de formato int y el largo de dicho arreglo.
     *Salida: Numero int 1 si existen 4 numeros consecutivos o 0 de lo contrario.
     */
    int validadorConsecutivos(int c[], int tamanio);
#endif /* FUNCIONES_H */

