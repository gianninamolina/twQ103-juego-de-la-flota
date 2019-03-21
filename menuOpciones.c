#include<stdio.h>
int main()
{
	char opcion;
	
	do{
		printf("HUNDIR LA FLOTA \n");
		printf("A - Reglas de la flota \n");
		printf("B - Jugar a la flota \n");
		printf("C - Salir del programa \n");
		scanf("%c",&opcion);
		fflush(stdin);
		system("cls");
		switch(opcion)
		{
			case'a':
			case'A':
			printf("El  juego  consiste  en  hundir  la  flota  del contrincante(el programa).\n Para  ello,  debe  colocar  su propia flota de forma estratégica y encontrar y hundir con los disparos la flota contraria\n");
			printf("Cada jugador  debe  colocar  en uno  de  los cuadros los  barcos \n");
			printf("Cada jugador pone de un turno de disparo que se irá alternando.\n Para hacerlo dirá las coordenadas.  Por  ejemplo “B3”, significa que su disparo corresponde a la casilla que se encuentra en esa coordenada. ");
			break;
			case'b':
			case'B':
			printf("Juguemos a la flota\n");
			break;
			case'c':
			case'C':
			printf("Ha salido del programa \n");
			break;
		}
	}
	while(opcion!='c'&& opcion!='C');
	return 0;
}
