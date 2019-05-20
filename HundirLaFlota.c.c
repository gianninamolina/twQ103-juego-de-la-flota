// Definimos Constantes:
	#define tamTab	10		// Tablero
	//Marcas en el tablero
	#define	tocado	'X'	
	#define hundido	'#'
	#define agua 	'~'
	#define fin 	'*'
	#define vacio 	' '
	//Numero de barcos de cada tamaño
	#define BARPEQ  2
	#define BARMED  2
	#define BARGRA  1
	//Longitud de cada barco
	#define LONGBARPEQ 2
	#define LONGBARMED 3
	#define LONGBARGRA 4
// Librerias:
	#include <stdio.h>

	#include <stdlib.h>// Librerías requeridas para el calculo de números aleatorios.
	#include <time.h>
	#include <string.h>
	#include<locale.h> //Para las tildes
// Librería propias que contiene todas las funciones necesarias para que el programa funcione
	#include "ImprimeBarcos.h"
	#include "ImprimeBombas.h"
//Defino estructura
typedef struct
{
	char nombre[50];
	char nick[50];
	char nick2[50];
	char email[50];
}registro;

int main()
{
	setlocale(LC_CTYPE,"Spanish"); //Para las tildes
	FILE *puntero;
	registro usuario;
	int a,b,tam,x,z;
	char respuesta;
	int c;
	
	srand((unsigned int)time(NULL));//Se genera un conjunto de números aleatorios
	
	// Se crean dos tableros de tres dimensiones, en el primer nivel se guardan los barcos de cada jugador, y en el segundo las bombas que tocaron barco o agua del contrario:
	char tabJug[tamTab][tamTab][2];
	char tabMaq[tamTab][tamTab][2];

	// Se inicializan las variables, algunas de ellas reciben el valor de las Constantes de la cabecera:
	int  barPeq = BARPEQ, longBarPeq = LONGBARPEQ;
	int  barMed = BARMED, longBarMed = LONGBARMED;
	int  barGra = BARGRA, longBarGra = LONGBARGRA;
	int  barcos = barPeq + barMed + barGra;
	int trozosBarco = (barPeq*longBarPeq)+(barMed*longBarMed)+(barGra*longBarGra);
	char tipoBar;
	int i;
	int leTocaA = rand()%2; // Variable con valor generado aleatoriamente cuyos valores seran: 0=jugador, 1=maquina. E indicaran de quien es el turno.
//FICHERO
//________________

	printf("REGISTRO DE JUGADORES \n");
	printf("?Te has registrado antes? S/N \n");
	scanf("%c",&respuesta);
	if(respuesta=='N'|| respuesta=='n')
	{
		puntero=fopen("registro.txt","a"); //para que me guarde todos los jugadores sin que se borren
		if(puntero==NULL)
		{
			printf("No se puede abrir el fichero \n");
			return -1;
		}
		fflush(stdin);
		printf("Nombre del jugador\a \n");
		gets(usuario.nombre);
		fflush(stdin);
		printf("Nick del jugador\a \n");
		gets(usuario.nick);
		fflush(stdin);
		do{
			printf("Email del jugador\a \n");
			gets(usuario.email);
			tam=strlen(usuario.email); //Para calcular la longitud del email
			a=0; //es falso
			b=0; //es falso
				for(z=0;z<tam;z++)
			{
					if(usuario.email[z]=='@')
					a=1; //es verdadera
					else if(usuario.email[z]=='.')
					b=1; //es verdadera
			}
		}while(a==0||b==0); //si es falsa te lo vuelve a preguntar
		
		//Guardamos en el fichero
		fprintf(puntero,"%s\t%s\t%s\t\n",usuario.nombre,usuario.nick,usuario.email);
		fclose(puntero);
	}
	else if(respuesta=='S'||respuesta=='s')
	{
		puntero=fopen("registro.txt","r"); 
		if(puntero==NULL)
		{
			printf("No se puede abrir el fichero \n");
			return -1;
		}
	printf("Introduce el nick registrado\n");
	scanf("%s", usuario.nick2 );
	x=0; //es falsa
	fscanf(puntero,"%s",usuario.nick); //Lee en el fichero el primer nick que hemos registrado
	if(strcmp(usuario.nick,usuario.nick2)==1) //compara las dos cadenas
	{
		x=1;//es verdadera
		printf("El nick esta registrado \n");
	}
	else
	printf("No estas registrado, sal y registrate \n"); //x=0 es falsa
	}
	
//INICIO DEL CODIGO HUNDIR LA FLOTA

do{
	printf("\n\n\n\t\tPulse 1 para leer las reglas del juego \n\n\n\t\tPulse 2 para jugar\n\n\n\t\t Pulse 3 para salir \n\n\n\t\t");
	scanf("%i", &c);
	fflush(stdin); //Limpia el scanf
	system("cls");//limpia la pantalla
	switch(c)
	{
		case 1:
			{
				printf("El  juego  consiste  en  hundir  la  flota  del contrincante(el programa).\n Para  ello,  debe  colocar  su propia flota de forma estrategica y encontrar y hundir con los disparos la flota contraria\n\n");
				printf("Dispones de 5 barcos para colocar: 2 pequeños, 2 medianos y 1 grande \n\n");
				printf("Cada jugador  debe  colocar  sus barcos mediante un numero y una letra \n\n");
				printf("El turno se ira alternando, y en pantalla se mostrará ambas pantallas \n\n");
				printf("BUENA SUERTE \n");
				break;
			}
		case 2:
			{
				// Se rellenan todos los componentes de las cuatro matrices con 'vacio':
				rellTablero( tabJug, tabMaq );
				// La Maquina coloca todos sus barcos:
				for( i=0; i < barcos; i++ )
				{
					// Se van eligiendo los barcos de mayor a menor medida:
					if( barGra != 0 )
					{
						tipoBar = 'g';
						impBarco( tabJug, tabMaq, longBarGra, i, 1 ); // El ultimo parámetro, el 1, indica que la introducción de barcos es por parte de la maquina y por consiguiente que tablero deberá de usar.
						barGra--;
					}
					else if( barMed != 0 )
					{
						tipoBar = 'm';
						impBarco( tabJug, tabMaq, longBarMed, i, 1 );
						barMed--;
					}
					else if( barPeq != 0 )
					{
						tipoBar = 'p';
						impBarco( tabJug, tabMaq, longBarPeq, i, 1 );
						barPeq--;
					};
				};

				//Se resetean los barcos con los valores de las Constantes para que el jugador pueda colocar sus barcos ahora:
				barPeq = BARPEQ; barMed = BARMED; barGra = BARGRA;

				// El jugador introduce todos sus barcos:
				for( i=0; i < barcos; i++ )
				{
					// Se imprime el tablero:
					impTablero(tabJug);

					// Se solicita el barco a colocar:
					printf( "Dispone de %i barcos: %i pequeños, %i medianos y %i grandes.\n", barPeq+barMed+barGra, barPeq, barMed, barGra );
					printf( "Indique el barco que quiere colocar: p / m / g\n" );
					do
					{
						scanf( "%c", &tipoBar );
					} while( tipoBar != 'p' && tipoBar != 'm' && tipoBar != 'g' );

					// Si hay disponibles barcos de ese tamaño, se envían a la función que los imprime:
					if( tipoBar == 'p' && barPeq != 0 )
					{
						impBarco( tabJug, tabMaq, longBarPeq, i, 0); // El ultimo parámetro, el 0, indica que la introducción de barcos es por parte del jugador y por consiguiente que tablero deberá de usar.
						barPeq--;
					}
					else if( tipoBar == 'm' && barMed != 0 )
					{
						impBarco( tabJug, tabMaq, longBarMed, i, 0);
						barMed--;
					}
					else if( tipoBar == 'g' && barGra != 0 )
					{
						impBarco( tabJug, tabMaq, longBarGra, i, 0);
						barGra--;
					}
					else
					{
						printf( "No dispone de mas barcos de ese tamanio, elija otro.\n" );
						i--; //Dado que hemos elegido un tamaño de barco que no estaba disponible, para que no dejemos de introducir ninguno se resta 1 al bucle.
					};
				};

				system("clear");
				// Cuando alguno de los jugadores tenga todos los barcos hunidos se termina el juego:
				do
				{
					impBomba( tabJug, tabMaq, trozosBarco, &leTocaA );
				} while( cuenTrozHund(tabJug) != trozosBarco   &&   cuenTrozHund(tabMaq) != trozosBarco );

				printf( "\n\n" );
				impTabJudYTamBomJug( tabJug, tabMaq );
				// Quien tenga mas trozos hundidos pierde:
				if( cuenTrozHund(tabJug) < cuenTrozHund(tabMaq) )	printf( "\n   Ganaste!\n\n" );
				else												printf( "\n   Gano la maquina\n\n" );
				
				break;
			}
		case 3:
			{
				printf("Ha salido del programa correctamente \n");
				break;
			}
	}
	
}while(c!=3);

	
return 0;
};
