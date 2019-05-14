#include <stdio.h>
#include <stdlib.h>
#include <locale.h>// esto es para las tildes
#include <time.h>
#include <conio.h>//La funcion getche() lee caracter a caracter y muestra por pantalla el caracter leido.
#include <string.h>
	typedef struct
{
char nombre[50], pregunta[50], experiencia[10] , ganar[10];
int matricula, edad;
}
ficha;
// esta funcion la voy a usar en la flota pero os la dejo aqui para el stop
void wait(int seconds) // Funcion que empieza a contar el tiempo desde que el programa se enciende
{
    clock_t endwait;
    endwait = clock() + seconds * CLOCKS_PER_SEC;
    while( clock() < endwait )
    {}
}
//__________________________________________________________________________________________________________
// DEFINO FUNCIONES DE LA FLOTA
void imprimir();
void ataques();
//_________________________________________________________________________________________________________
// VARIABLES DE LA FLOTA QUE VOY A USAR EN TODO
int i, j, k, jugador[6][10], programa[6][10], opcion1, opcion2, puntajeprograma=0,puntajejugador=0;
time_t start,end;
double dif, tiempototal=0;
//_________________________________________________________________________________________________________
int main()
{
setlocale(LC_CTYPE,"Spanish");// esto tambien es para poner las tildes
   char r;
int c;
//VARIABLES DE LA FLOTA
 int  auxiliar, destruidosprograma=0, destruidosjugador=0;

	printf("MINIJUEGOS\n\n");
	printf("NOTA: CUALQUIERA DE LOS JUEGOS PUEDE PEDIRLE AL USUARIO UN REGISTRO PREVIO.\n\n\n");
	printf("AHORCADO\t\t\tHUNDIR LA FLOTA\t\t\tSTOP\n\n\n");

	fflush(stdin);// CHICAS ESTO ES PARA RESETEAR EL TECLADO Y QUE NO SE ME GUARDE EL ENTER EN EL SIGUIENTE SCANF
	system("cls"); // Limpia la pantalla

			printf("Usted ha elegido HUNDIR LA FLOTA\n");
			printf("Bienvenido a hundir la flota, pulse 'R' si quiere saber las reglas del juego\n");
			scanf("%c",&r);
			if(r=='R')
			{
			 printf("El  juego  consiste  en  hundir  la  flota  del contrincante(el programa).\n Para  ello,  debe  colocar  su propia flota de forma estratégica y encontrar y hundir con los disparos la flota contraria\n");
			 printf("Cada jugador  debe  colocar  en uno  de  los cuadros los  barcos \n");
			 printf("Cada jugador pone de un turno de disparo que se irá alternando.\n Para hacerlo dirá las coordenadas.  Por  ejemplo “B3”, significa que su disparo corresponde a la casilla que se encuentra en esa coordenada. ");
		    } 
		    printf("\n\n\n\t\tPulse 1 para jugar\n\n\n\t\tPulse 2 para salir");
		    scanf("%i", &c);
		    fflush(stdin);
		        switch(c)
                  { 
                     case 1:
                     {
                     	ataques(); // Llama a la funcion iniciar
                        printf("\n\n\n\t\t Preparado?\n\n");
                        wait(3);
                             
                          do
                          {
                             time(&start);
                             system("cls"); // Limpia la pantalla
                               
                             imprimir();
                               
                             printf(" Es tu turno! Dame la posicion que deseas atacar~\n\n");
                             printf("\tX = ");
                             	fflush(stdin);
                             scanf("%d", &opcion2);
                                 while(opcion2<1 || opcion2>9)
                                 {
                                   printf("\n    Escoje un valor valido ( 1 a 9 )\n\n\tX = ");
                                  scanf("%d", &opcion2);
                                 }
                               	fflush(stdin);
                             printf("\tY = ");
                             scanf("%d", &opcion1);
                                 while(opcion1<1 || opcion1>5)
                                 {
                                   printf("\n    Escoje un valor valido ( 1 a 5 )\n\n\tY = ");
                                   scanf("%d", &opcion1);
                                 }
                             auxiliar=programa[opcion1][opcion2];
                             programa[opcion1][opcion2]=3;
                             imprimir();
                             programa[opcion1][opcion2]=auxiliar;                          
                               
                                 if(programa[opcion1][opcion2]==1)
					               {
					                   programa[opcion1][opcion2]=2;// has destruido uno de los barcos del programa
					                   destruidosprograma=destruidosprograma+1;// sumamos un barco destruido del programa
					                   puntajejugador=puntajejugador+200;// sumamos tu puntuacion
					                   printf("\n Has acertado!!\n\n");
					               }
						         else
						            {
						               printf("\n Has fallado...\n\n");
						            }
						                               
				               system("PAUSE");
				               system("cls");
				               if(destruidosprograma==5)// si destruyes todos los barcos del oponente has ganado
				               {
				                   fflush (stdin);// vuelvo a borrar porque sino no me aparece el printf
				                   printf("\n\n\n\n\t\t\tHAZ GANADO!!");
				                   getche();
				               }                                                                
				               imprimir();
				                               
				               printf(" Turno del oponente!~\n\n");
				               wait(2);
				               jugador[i][j]=3;
				               opcion1=i;
				               opcion2=j;
				               imprimir();
				               jugador[opcion1][opcion2]=auxiliar;
				             
				               if(jugador[opcion1][opcion2]==1)
				               {
				                   printf("\n El oponente ha acertado!!\n\n");
				                   jugador[opcion1][opcion2]=2;
				                   imprimir();
				                   destruidosjugador=destruidosjugador+1;
				                   puntajeprograma=puntajeprograma+200;
				               }
				               else
				               {
				                   printf("\n El oponente ha fallado...\n\n");
				               }
				               if(destruidosjugador==5)
				               {    
							       fflush(stdin);// vuelvo a borrar porque sino no me aparece el printf                                        
				                   printf("\n\nHAS PERDIDO!!");
				                   printf("\nMÁS SUERTE LA PRÓXIMA VEZ\n");
				                   
				               }
				               system("PAUSE");
				               time(&end);
                             }
                         while(destruidosprograma<5 || destruidosjugador<5);       	
                    break;
                     }
                     case 2:
                     	return 0;
                    break;
		           }
		           return 0;
		           
	}

	

//______________________________________________________________________________________________________________________
//FUNCIONES DE LA FLOTA
void imprimir() // Funcion que imprime el tablero de juego
{  
    printf("Tiempo transcurrido= %.1f segundos\n\n", tiempototal);
     
    for(i=1;i<=5;i++) // Imprime tablero del programa
    {
        printf("\n\t");
        for(j=1;j<=9;j++)
        {
            if(programa[i][j]==3)// donde ha disparado 
            {
                printf("  #");
            }
            else
            {
                if(programa[i][j]==2) // barco destruido
                {
                    printf("  X");
                }
                else
                {
                    printf("  -");// pintar el espacio vacio
                }
            }                                    
        }
        if(i==3)
        {
            printf("\tTablero del programa"); 
        }
        else
         {
            if(i==1)
            {
                printf("\t\t\tPuntos del programa: %d", puntajeprograma);
            }
        }
       
    }
     
    printf("\n\n\n\n");
     
    for(i=1;i<=5;i++) // Imprime el tablero del jugador
    {
        printf("\n\t");
        for(j=1;j<=9;j++)
        {
            if(jugador[i][j]==3)// donde has disparado
            {
                printf("  #");
            }
            else
            {
                if(jugador[i][j]==2) //barco destruido 
                {
                    printf("  X");
                }
                else
                {
                    if(jugador[i][j]==1)
                    {
                        printf("  O");// imprime tu barco
                    }
                    else
                    {
                        printf("  -");// pinta el espacio vacio
                    }
                }
            }                                    
        }
        if(i==3)
        {
            printf("\tTablero del jugador");
        }
        else
        {
            if(i==1)
            {
                printf("\t\t\tPuntos del jugador: %d", puntajejugador);
            }
        }
    }
 
    printf("\n\n");  
}

void ataques() 
{
         
    for(i=1;i<=5;i++) 
    {
        for(j=1;j<=9;j++)
        {
            jugador[i][j]=0;
            programa[i][j]=0;
        }
    }
     
    printf("\n\nIntroduzca las coordenadas de sus barcos\n\n");
     
    srand(time(NULL));// inicia el generador de números aleatorios
    for(k=1;k<=5;k++) // Distribuye los barcos
    {
        imprimir();
                       
        i=1+rand()%5; //da las coordenadas del programa de manera aleatoria
        j=1+rand()%9;
        while(programa[i][j]==1)
        {
            i=1+rand()%5; j=1+rand()%9;
        }
        programa[i][j]=1; //las coordenadas tendran un barco del oponente
                       
        printf("\n\tX%d = ", k);
        scanf("%d", &opcion2);
        while(opcion2<1 || opcion2>9) //le vuelvo a pedir la coordenada x porque se ha salido del tablero
        {
            printf("Escoja un valor valido ( 1 a 9 )\n\n\tX%d = ", k);
            scanf("%d", &opcion2);
        }
                         
        printf("\n\tY%d = ", k);
        scanf("%d", &opcion1);
        while(opcion1<1 || opcion1>5)//le vuelvo a pedir la coordenada y porque se ha salido del tablero
        {
            printf("\nEscoja un valor valido( 1 a 5 )\n\n\tY%d = ", k);
            scanf("%d", &opcion1);
        }
                         
        if(jugador[opcion1][opcion2]==1)
        {
        	fflush(stdin);// vuelvo a borrar porque sino no me aparece el printf
            printf("\n Ya hay un barco en esa posicion\n");
            getchar();
            k=k-1;//para que vuelva a pedirme el valor repetido
        }
        jugador[opcion1][opcion2]=1;
                       
        system("cls");//borro la pantalla
    }
}
 
