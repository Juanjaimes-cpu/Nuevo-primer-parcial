/*
 * BIBLIO.h
 *
 *  Created on: 6 may. 2021
 *      Author: juan__000
 */

#ifndef BIBLIO_H_
#define BIBLIO_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "utn.h"
#define LIBRE 0
#define OCUPADO 1


typedef struct {
	int dia;
	int mes;
	int anio;
	}eFecha;

typedef struct {
	int idServicio;
	char descripcion[25];
	float precio;
	}eServicio;

typedef struct {
	int id;
	char marcaBicicleta[51];
	float rodadoBicicleta;
	int idServicio;
	int isEmpty;
	eFecha fecha;
	}eTrabajo;


int MENU();

int eTrabajo_idSubida;
int eServicio_idSubida;
int eTrabajo_ObtenerID();
int eServicio_obtenerID();
int eTrabajo_Inicializar(eTrabajo[], int TAM);
int eTrabajo_ObtenerIndexLibre(eTrabajo[], int TAM);
int eTrabajo_BuscarPorID(eTrabajo[], int TAM, int ID);

eTrabajo eTrabajo_CargarDatos();
eFecha PedirFecha(char mensaje[]);

int  eTrabajo_Alta(eTrabajo Lista[], int TAM, eServicio ListaServicio[], int TSERV);
int eTrabajo_Baja(eTrabajo Lista[], int TAM, eServicio ListaServicio[], int TSERV);

void MostrarUnSoloTrabajo(eTrabajo Lista, eServicio listaServicio[], int TSERV);
void ListadoTrabajos(eTrabajo[], int TamTrabajo, eServicio[], int TamServicio);
int servicioDes(eServicio lista[], int T, int buscarCodigo, char descripcion[]);

void ordenamientoTrabajos(eTrabajo listaTrabajos[], int TAM, eServicio listaServicios[], int TSERV);

#endif /* BIBLIO_H_ */
