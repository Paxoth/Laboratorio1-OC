/*
UNIVERSIDAD DE SANTIAGO DE CHILE
Facultad de Ingeniería
Departamento de Ingeniería Informática
Ingeniería Civil Informática
Organización de Computadores - Laboratorio 1
Autores:
	Nicole Macarena Henríquez Sepúlveda
	Maximiliano Felipe Andrés Pérez Ródríguez
Profesores:
	Nicolás Andrés Hidalgo Castillo
	Erika Rosas Olivos
Ayudante:
	Felipe Ignacio Garay Pérez
*/

//LIBRERIAS
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <getopt.h>


/*************************MAIN*************************/
int main (int argc, char **argv)
{
	int nflag=0;
	int iflag=0;
	char* ivalue =NULL;
	char* nvalue =NULL;

	/******************INICIO FUNCION GETOPT******************/
	int c;
	while ((c = getopt (argc, argv, "i:n:")) != -1)
		switch (c){
			case 'i':
				iflag = 1;
				ivalue=optarg;
				break;

			case 'n':
				nflag = 1;
				nvalue=optarg;
				break;

			case '?':
				if (optopt == 'n'||optopt == 'i')
					fprintf (stderr, "La opcion -%c requiere argumento (numero).\n", optopt);
				else if (isprint (optopt))
					fprintf (stderr, "-%c es una opción desconocida.\n", optopt);
				else
					fprintf (stderr,"Caracter de opción desconocida `\\x%x'.\n",optopt);
				return 1;	

			default:
				abort ();
				
		}
	/******************FIN FUNCION GETOPT******************/
	/******************************************************/
	/***************VALIDACIÓN DE ARGUMENTOS***************/
	if(iflag==1&&ivalue[0]=='-'&&nflag==0)
	{
		printf("ERROR: faltan argumentos de las opciones\n");
		abort();
	}
	if(nflag==1&&nvalue[0]=='-'&&iflag==0)
	{
		printf("ERROR: faltan argumentos de las opciones\n");
		abort();
	}

	printf ("nflag = %d, nvalue = %s\niflag = %d, ivalue = %s\n", nflag,nvalue,iflag,ivalue);
	/************FIN DE VALIDACIÓN DE ARGUMENTOS***********/
	/******************************************************/

	n = atoi(nvalue);
	i = atoi(ivalue);
	

	return 0;
}
