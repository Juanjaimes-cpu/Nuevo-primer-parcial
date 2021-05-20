/*
 * BIBILIO.c
 *
 *  Created on: 6 may. 2021
 *      Author: juan__000
 */



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "utn.h"
#include "BIBLIO.h"



/**
 * @fn int MENU()
 * @brief
 *
 * @return
 */
int MENU(){
		printf("\n1.ALTA.\n");
		printf("3.MODIFICAR producto.\n");
		printf("2.BAJA producto.\n");
		printf("4.Listado de trabajos.\n");
		printf("5.Listado de servicios.\n");
		printf("6. Total.");
		printf("6.Salir.");
		return 0;
	}


int eTrabajo_idSubida = 0;


int eTrabajo_ObtenerID() {
	//INCREMENTA VARIABLE ESTATICA CADA VEZ QUE SE LLAMA ESTA FUNCION
	return eTrabajo_idSubida += 1;
}





int eTrabajo_Inicializar(eTrabajo Lista[], int TAM)
{
	int retorno = 0;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (Lista != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//SET ESTADO DE "LIBRE"
			Lista[i].isEmpty = LIBRE;
			retorno = 1;
		}
	}
	return retorno;
}




int eTrabajo_ObtenerIndexLibre(eTrabajo Lista[], int TAM) {
	int retorno = -1;
	int i;
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (Lista != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (Lista[i].isEmpty == LIBRE) {
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}


int eTrabajo_BuscarPorID(eTrabajo Lista[], int TAM, int ID) {
	int retorno = -1;
	int i;


	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (Lista != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (Lista[i].isEmpty == OCUPADO && Lista[i].id == ID) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}




eTrabajo eTrabajo_CargarDatos() {
	eTrabajo auxiliar;

	utn_getPalabra(auxiliar.marcaBicicleta ,sizeof(auxiliar.marcaBicicleta), "\nIngrese la marca: \n", "\nERROR: Ingrese sólo letras. \n", 5);
	utn_getNumeroFlotante(&auxiliar.rodadoBicicleta,"\nIngrese rodado: \n","\nERROR: Ingrese rodado válido.\n",1,150,5);

	utn_getNumero(&auxiliar.idServicio,"\nIngrese servicio: \n","\nERROR: Ingrese servicio válido.\n",20000,20004,5);
	auxiliar.fecha = PedirFecha("Ingrese Fecha");

	auxiliar.isEmpty = OCUPADO;
	return auxiliar;
}





eFecha PedirFecha(char mensaje[])
{
	eFecha miFecha;
	printf("%s\n",mensaje);

	utn_getNumero(&miFecha.dia,"\nIngrese DIA: \n","\nERROR: Ingrese DIA válido.\n",1,31,5);
	utn_getNumero(&miFecha.mes,"\nIngrese MES: \n","\nERROR: Ingrese MES válido.\n",1,12,5);
	utn_getNumero(&miFecha.anio,"\nIngrese AÑO: \n","\nERROR: Ingrese AÑO válido.\n",1,2021,5);

	return miFecha;
}


int  eTrabajo_Alta(eTrabajo Lista[], int TAM, eServicio ListaServicio[], int TSERV ) {
	int retorno = 0;
	eTrabajo auxTrabajo;

	//BUSCO ESPACIO EN ARRAY
	int index = eTrabajo_ObtenerIndexLibre(Lista, TAM);
	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Producto AUXILIAR
		auxTrabajo = eTrabajo_CargarDatos();
		//SETEO ID UNICO - VARIABLE AUTOINCREMENTAL
		auxTrabajo.id = eTrabajo_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxTrabajo.isEmpty = OCUPADO;

		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		Lista[index] = auxTrabajo;
		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		retorno = 1;
	}
	else
	{
		retorno = -1;
	}
	return retorno;
}


int eTrabajo_Baja(eTrabajo Lista[], int TAM, eServicio ListaServicio[], int TSERV)
{
	int idTrabajoIngresado;
	int i;
	ListadoTrabajos(Lista, TAM, ListaServicio, TSERV);
	//LISTO TODOS LOS eEmployee
	printf("Ingrese ID del empleado que desee dar de BAJA: \n");
		scanf("%d", &idTrabajoIngresado);

		for(i=0; i<TAM; i++)
		{
			if(idTrabajoIngresado == Lista[i].id)
			{
				Lista[i].isEmpty = LIBRE;
				break;
				}
				else
				{
				printf("\nEL id del producto que ingreso no existe.");
			}
		}
		return 0;
}


void MostrarUnSoloTrabajo(eTrabajo unSoloTrabajo, eServicio listaServicio[], int TSERV)
{
	char descripcion[51];
	servicioDes(listaServicio, TSERV, unSoloTrabajo.idServicio, descripcion);

	printf("\nID: %d\n	MARCA: %s\nRODADO: %f\n SERVICIO: %s\n FECHA: %d/%d/%d\n",

																									unSoloTrabajo.id,
																									unSoloTrabajo.marcaBicicleta,
																									unSoloTrabajo.rodadoBicicleta,
																									descripcion,
																									unSoloTrabajo.fecha.dia,
																									unSoloTrabajo.fecha.mes,
																									unSoloTrabajo.fecha.anio
																									);
}


void ListadoTrabajos (eTrabajo Lista[],int tam, eServicio listaServicio[], int tamServicio)
	{
	    int i;
	    for (i=0;i<tam;i++)
	    {
	        if (Lista[i].isEmpty==OCUPADO)
	        {
	        	MostrarUnSoloTrabajo(Lista[i],listaServicio,tamServicio);
	        }
	    }
	}



int servicioDes(eServicio lista[], int T, int buscadorAuxiliar, char descripcionDeServicio[])
{
	int retorno;
	int i;

	if(lista!=NULL && T>0 && descripcionDeServicio!=NULL)
	{
		for(i=0; i<T; i++)
		{
			if(lista[i].idServicio==buscadorAuxiliar)
			{
				strcpy(descripcionDeServicio,lista[i].descripcion);
				retorno=0;
			}
		}
	}
	return retorno;
}



void servicioDatos(eServicio listaServicio[])
{
    int i;
    eServicio auxiliar[4]= {
							{20000,"Limpieza",250},
							{20001,"Parche",300},
							{20002,"Centrado",400},
							{20003,"Cadena",350}
							};
    for(i=0;i<4;i++)
    listaServicio[i]=auxiliar[i];
}






void ordenamientoTrabajos(eTrabajo listaTrabajos[], int TAM, eServicio listaServicios[], int TSERV)
{
	   int i;
	   int j;
	   eTrabajo auxiliar;

	   for(i=0; i<TAM-1; i++)
	   {
		   for(j=i+1; j<TAM; j++)
		   {
	           if(listaTrabajos[i].fecha.anio < listaTrabajos[j].fecha.anio)
	           {
	               auxiliar = listaTrabajos[i];
	               listaTrabajos[i] = listaTrabajos[j];
	               listaTrabajos[j] = auxiliar;
	              if(listaTrabajos[i].fecha.anio == listaTrabajos[j].fecha.anio)
	              {
	              if(strcmp(listaTrabajos[i].marcaBicicleta, listaTrabajos[j].marcaBicicleta)>0)
	              {
				  auxiliar = listaTrabajos[i];
				  listaTrabajos[i] = listaTrabajos[j];
				  listaTrabajos[j] = auxiliar;
			  }
	              }
			   }
		   }
	   }
 }
