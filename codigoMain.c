//
//  main.c
//  Efinal
//
//  Created by Miguel Angel Butron Lopez & Itai Nallely Barrera Santiago on 5/21/19.
//  Copyright © 2019 Miguel Angel Butron Lopez. All rights reserved.
//

//Programa simulador
#include <stdio.h>  //biblioteca para gets, scanf y printf
#include <stdlib.h> //biblioteca para rand
#include <locale.h> //biblioteca para palabras en espaÒol
#include <unistd.h> //biblioteca para compilar en Unix 
#include <time.h>   //biblioteca para el tiempo
// 1 es la primoridad mas alta y 10 la mas baja
struct datos{
    int nproceso;
    int prioridad;
                      //estructura que contiene dos caracteristicas prioridad y n˙mero del proceso    
}cola[10],buff;      // lista de elementos que contienen dos campos y variable susada para ordenar 


//Definici€n de variables globales
#define MAX 15    //Capacidad de la cola
int queue[MAX];   //Cola implementada como arreglo
int front = 0;     //Inicio de la cola
int rear = 1;     //Fin de la cola
//DefiniciÛn de las funciones 
void insertPrio(int data); //insertar en prioridad
void desplegar (void); //Despliega cola
void crear (void);     //Crea una cola priorizada


int main(){
    setlocale(LC_ALL, "");   //instrucciones para palabras en espaÒol
    srand(time(NULL));      //GeneraciÛn de n˙meros aleatorios 
    crear();                //llama a la funciÛn crear 
    desplegar();           //llama a la funciÛn desplegar
    
    int prio =  1;
    float times = 0;
    int ciclo, bucle;
    for( ciclo = 0; ciclo<2; ciclo++){
        for( bucle = 0; bucle<9; bucle++){
            printf("\n\nProceso %d esta ejecutando con prioridad %d\n",cola[front].nproceso,cola[front].prioridad);
            times=1+rand()%((15+1)-1); //define el tiempo
            printf("Procesando %.4f segundos\n",times/1000); //imprime el tiempo
            sleep(times); //da tiempo de espera para imprimir lo siguiente 
            printf("Proceso %d perdio control del CPU\n",cola[front].nproceso);
            if ((prio=rand()%(9))<1){    //Valores de prioridad mayores que 1 y menores que 10 
                prio=rand()%(9);
            }
            else{
                prio=rand()%(9);    
            }
            printf("Nueva prioridad: %d",prio); //asiganaciÛn de la nueva prioridad
            
            insertPrio(prio);
            
        }
        desplegar(); //muestra los datos aleatorios 
    }
    return 0;
}

void desplegar(void){       //muestra el proceso seguido de la prioridad
    int i;
    printf("\n\nProcesos en cola: \n");
    for(i = 0; i < rear-1; i++){
        printf("\n\nNumero: %d || Prioridad: %d",cola[i].nproceso,cola[i].prioridad);
    }
}


void insertPrio(int prio) {     //inserta en base a prioridad con bubble sort
    int indi=0,cursor;
    cola[indi].prioridad=prio;      //Asigna la nueva prioridad
    /* Algorítmo Bubble sort */
    for(indi=0;indi<rear+1;indi++){
        for(cursor=indi+1;cursor<rear;cursor++){
            if(cola[indi].prioridad> cola[cursor].prioridad){
                buff = cola[indi];          //Buff es la variable auxiliar al algorítmo
                cola[indi] = cola[cursor];
                cola[cursor] = buff;
            }
        }
    }
}

void crear(void) {//Crea los procesos por primera vez
    int i, j;
    for( i=0; i<10; i++){
        //printf("\ni = %i", i);
        cola[i].nproceso = (i+1)*1000; //Procesos del 1000 - 10000
        j = i + 1;
        cola[i].prioridad = j;
        rear++;
    }
}
