/*
UNIVERSIDAD DE SANTIAGO DE CHILE
Facultad de Ingeniería
Departamento de Ingeniería Informática
Ingeniería Civil Informática
Organización de Computadores - Laboratorio 1
Autores:
	Nicole Macarena Henriquez Sepúlveda
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

//Constantes
#define F0 1 		/*1/1*/
#define F1 0.333333333 	/*1/3*/
#define F2 0.2		/*1/5*/
#define F3 0.142857143	/*1/7*/
#define F4 0.111111111	/*1/9*/
#define F5 0.090909091	/*1/11*/
#define F6 0.076923077	/*1/13*/
#define F7 0.066666667	/*1/15*/	
#define F8 0.058823529	/*1/17*/
#define F9 0.052631579	/*1/19*/
#define F10 0.047619048	/*1/21*/
#define F11 0.043478261	/*1/23*/

/************************TAYLOR************************/
/*Parametros.
	numero: valor que se calculará el logaritmo natural Ln(n)
	iteracion: cantidad de veces que se iterará el proceso
/******************************************************/

float ln(int numero)
{
	int i;
	float resultado;
	float a = (numero-1);
	float b = (numero+1);
	float c = a/b;
	float c2 = c*c;
	float c3 = c2*c;
	float c4 = c2*c2;
	float c5 = c3*c2;
	resultado = 2*(
		F0 *c + 	
		F1 *c3 + 
		F2 *c5 + 
		F3 *c5*c2 + 
		F4 *c5*c4 + 
		F5 *c5*c5*c +  
		F6 *c5*c5*c3 + 
		F7 *c5*c5*c5 + 
		F8 *c5*c5*c5*c2+  
		F9 *c5*c5*c5*c4+  
		F10*c5*c5*c5*c5*c+  
		F11*c5*c5*c5*c5*c3);
	return resultado; 
}

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

	int n,i,iteraciones;
	float final;
	n = atoi(nvalue);
	i = atoi(ivalue);
	for (iteraciones = 0;iteraciones <i;iteraciones++)
	{
		final = ln(n);
	}
	printf("ln(%i) = %f\n",n,final);


	return 0;
}
