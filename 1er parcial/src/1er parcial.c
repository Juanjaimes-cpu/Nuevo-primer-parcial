/*
 ============================================================================
 Name        : 1er.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "utn.h"
#include "BIBLIO.h"

#define T 3
#define TSERV 4

int main(void) {

	setbuf(stdout, NULL);

	int opcion;
	int BanderaDeControl;
	int retorno;
	retorno = 0;
	BanderaDeControl = 0;

	eTrabajo trabajos[T];
	eServicio servicios[TSERV];

	eTrabajo_Inicializar(trabajos, T);

	do{
			MENU();
			printf("Elija una opcion: ");
			scanf("%d", &opcion);

			switch(opcion)
			{
			case 1:
				//ALTA
			retorno =  eTrabajo_Alta(trabajos, T, servicios, TSERV);
			 if(retorno != -1)
			 {
			 printf("\n\nEmpleado ingresado con exito!!!\n\n");
			// eEmployee_MostrarUno(empleados[retorno]);
			 }else{
			 printf("\n\nNo hay mas lugar en la lista!!\n\n");
			 }
			 BanderaDeControl = 1;
			 system("pause");
			break;
			case 2:

			break;
			case 3:
				//baja
				if(BanderaDeControl == 0){
				printf("\nError, debe ingresar primero a la opcion 1 para poder continuar... Gracias\n");
				}else{
				if(eTrabajo_Baja(trabajos, T, servicios, TSERV)) {
				puts("\n * BAJA DE Empleado EXITOSA");
				}
				system("pause");
					}
				break;
			break;
			case 4:
			//listado
				if(BanderaDeControl == 0){
				printf("\nError, debe ingresar primero a la opcion 1 para poder continuar... Gracias\n");
				}else{
			    ordenamientoTrabajos(trabajos, T, servicios, TSERV);
				ListadoTrabajos(trabajos, T, servicios, TSERV);
				}
				system("pause");
				break;
			case 5:

				break;

			default:
			printf("Opcion invalida! La opcion [%d] no existe\n", opcion);
			printf("\n");
								}

	}while(opcion!=6);


	return 0;


	return EXIT_SUCCESS;

	}
