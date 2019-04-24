#include<stdio.h>
#include<string.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 30
typedef struct
{
	char nombre[50];
	char nick[50];
	char nick2[50];
	char email[50];
}registro;

//____________
// DEFINO FUNCIONES DE LA FLOTA
void imprimir();
void ataques();
//_____________

int main()
{
	FILE *puntero;
	//definimos variables
//________________

	registro usuario;
	int a,b,tam,x;
	char linea[1024];
	char *frase1;
	char *frase2;
	char *frase3;
	char respuesta;
	
	//VARIABLES DE LA FLOTA
int auxiliar_main, destruidosprograma_main=0, destruidosjugador_main=0;
int z,c, jugador_main[6][10], programa_main[6][10], opcion1_main, opcion2_main, puntajeprograma_main=0,puntajejugador_main=0;
time_t start,end;
//________________

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
		//GUARDAMOS EN EL FICHERO
		//fwrite(&jugador,sizeof(registro),1,puntero);
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
	printf("NICKS EN EL FICHERO\n");
			for (z=0; z<MAX; z++)
		{
		  fgets(linea, 1024, puntero);
		  //puts(linea);
		  frase1 = strtok(linea, "\t");
		  frase2 = strtok(linea, "\t"); //he cambiado NULL por linea
		  frase3 = strtok(NULL, "\t");
		  
			if( strcmp(usuario.nick2, frase2) == 1 )
				x=1; //es veradera
			 else 
				x=0; //es falsa
		}

	if(x==1)
	printf("el nick esta registrado");
	else
	printf("no");
	}
//________________
//INICIO DEL CODIGO HUNDIR LA FLOTA    
	 //_____________
		    printf("\n\n\n\t\tPulse 1 para jugar\n\n\n\t\tPulse 2 para salir");
		    scanf("%i", &c);
		    fflush(stdin);
		        switch(c)
         {
         	case 1:
                     {
                     	ataques(); // Llama a la funcion iniciar
                        printf("\n\n\n\t\t Preparado?\n\n");
                             
                          do
                          {
                             time(&start);
                             system("cls"); // Limpia la pantalla
                               
                             imprimir();
                               
                             printf(" Es tu turno! Dame la posicion que deseas atacar~\n\n");
                             printf("\tX = ");
                             scanf("%d", &opcion2_main);
                                 while(opcion2_main<1 || opcion2_main>9)
                                 {
                                   printf("\n    Escoje un valor valido ( 1 a 9 )\n\n\tX = ");
                                  scanf("%d", &opcion2_main);
                                 }
                               
                             printf("\tY = ");
                             scanf("%d", &opcion1_main);
                                 while(opcion1_main<1 || opcion1_main>5)
                                 {
                                   printf("\n    Escoje un valor valido ( 1 a 5 )\n\n\tY = ");
                                   scanf("%d", &opcion1_main);
                                 }
                             auxiliar_main=programa_main[opcion1_main][opcion2_main];
                             programa_main[opcion1_main][opcion2_main]=3;
                             imprimir();
                             programa_main[opcion1_main][opcion2_main]=auxiliar_main;                          
                               
                                 if(programa_main[opcion1_main][opcion2_main]==1)
					               {
					                   programa_main[opcion1_main][opcion2_main]=2;// has destruido uno de los barcos del programa
					                   destruidosprograma_main=destruidosprograma_main+1;// sumamos un barco destruido del programa
					                   puntajejugador_main=puntajejugador_main+200;// sumamos tu puntuacion
					                   printf("\n Has acertado!!\n\n");
					               }
						         else
						            {
						               printf("\n Has fallado...\n\n");
						            }
						                               
				               system("PAUSE");
				               system("cls");
				               if(destruidosprograma_main==5)// si destruyes todos los barcos del oponente has ganado
				               {
				                   fflush (stdin);// vuelvo a borrar porque sino no me aparece el printf
				                   printf("\n\n\n\n\t\t\tHAS GANADO!!");
				                   getche();
				               }                                                                
				               imprimir();
				                               
				               printf(" Turno del oponente!\n\n");
				               
				               auxiliar_main=jugador_main[opcion1_main][opcion2_main];
                               jugador_main[opcion1_main][opcion2_main]=3;
				               imprimir();
				               jugador_main[opcion1_main][opcion2_main]=auxiliar_main;
				             
				               if(jugador_main[opcion1_main][opcion2_main]==1)
				               {
				                   printf("\n El oponente ha acertado!!\n\n");
				                   jugador_main[opcion1_main][opcion2_main]=2;
				                   destruidosjugador_main=destruidosjugador_main+1;
				                   puntajeprograma_main=puntajeprograma_main+200;
				               }
				               else
				               {
				                   printf("\n El oponente ha fallado...\n\n");
				               }
				               if(destruidosjugador_main==5)
				               {    
							       fflush(stdin);// vuelvo a borrar porque sino no me aparece el printf                                        
				                   printf("\n\nHAS PERDIDO!!");
				                   printf("\nMÁS SUERTE LA PRÓXIMA VEZ\n");
				                   
				               }
				               system("PAUSE");
				               time(&end);
                             }
                         while(destruidosprograma_main<5 || destruidosjugador_main<5);       	
                    break;
                     }
             case 2:
             	return 0;
            break;
		           }
return 0;
}
//______________
//FUNCIONES DE LA FLOTA
void imprimir() // Funcion que imprime el tablero de juego
{  
int i,j, programa[6][10],puntajeprograma=0,puntajejugador=0,jugador[6][10];
double tiempototal=0;
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
     int t,m,k,jugador_ataques[6][10],opcion1_ataques, opcion2_ataques, programa_ataques[6][10];    
    for(t=1;t<=5;t++) 
    {
        for(m=1;m<=9;m++)
        {
            jugador_ataques[t][m]=0;
            programa_ataques[t][m]=0;
        }
    }
     
    printf("\n\nIntroduzca las coordenadas de sus barcos\n\n");
     
    srand(time(NULL));// inicia el generador de números aleatorios
    for(k=1;k<=5;k++) // Distribuye los barcos
    {
        imprimir();
                       
        t=1+rand()%5; //da las coordenadas del programa de manera aleatoria
        m=1+rand()%9;
        while(programa_ataques[t][m]==1)
        {
            t=1+rand()%5; m=1+rand()%9;
        }
        programa_ataques[t][m]=1; //las coordenadas tendran un barco del oponente
                       
        printf("\n\tX%d = ", k);
        scanf("%d", &opcion2_ataques);
        while(opcion2_ataques<1 || opcion2_ataques>9) //le vuelvo a pedir la coordenada x porque se ha salido del tablero
        {
            printf("Escoja un valor valido ( 1 a 9 )\n\n\tX%d = ", k);
            scanf("%d", &opcion2_ataques);
        }
                         
        printf("\n\tY%d = ", k);
        scanf("%d", &opcion1_ataques);
        while(opcion1_ataques<1 || opcion1_ataques>5)//le vuelvo a pedir la coordenada y porque se ha salido del tablero
        {
            printf("\nEscoja un valor valido( 1 a 5 )\n\n\tY%d = ", k);
            scanf("%d", &opcion1_ataques);
        }
                         
        if(jugador_ataques[opcion1_ataques][opcion2_ataques]==1)
        {
        	fflush(stdin);// vuelvo a borrar porque sino no me aparece el printf
            printf("\n Ya hay un barco en esa posicion\n");
            getchar();
            k=k-1;//para que vuelva a pedirme el valor repetido
        }
        jugador_ataques[opcion1_ataques][opcion2_ataques]=1;
                       
        system("cls");//borro la pantalla
                                                         
    }  
}

