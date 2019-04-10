#include<stdio.h>
#include<string.h>
#define MAX 30
typedef struct
{
	char nombre[50];
	char nick[50];
	char nick2[50];
	char email[50];
}registro;

int main()
{
	FILE *puntero;
	//definimos variables
	registro jugador;
	int a,b,i,tam,x;
	char linea[1024];
	char *frase1;
char *frase2;
char *frase3;
	char respuesta;
	printf("REGISTRO DE JUGADORES \n");
	printf("¿Te has registrado antes? S/N \n");
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
		gets(jugador.nombre);
		fflush(stdin);
		printf("Nick del jugador\a \n");
		gets(jugador.nick);
		fflush(stdin);
		do{
			printf("Email del jugador\a \n");
			gets(jugador.email);
			tam=strlen(jugador.email); //Para calcular la longitud del email
			a=0; //es falso
			b=0; //es falso
				for(i=0;i<tam;i++)
			{
					if(jugador.email[i]=='@')
					a=1; //es verdadera
					else if(jugador.email[i]=='.')
					b=1; //es verdadera
			}
		}while(a==0||b==0); //si es falsa te lo vuelve a preguntar
		//GUARDAMOS EN EL FICHERO
		//fwrite(&jugador,sizeof(registro),1,puntero);
		fprintf(puntero,"%s\t%s\t%s\t\n",jugador.nombre,jugador.nick,jugador.email);
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
	}
		
	printf("Introduce el nick registrado\n");
	scanf("%s", jugador.nick2 );
	printf("NICKS EN EL FITXER\n");
	
	
			for (i=0; i<MAX; i++)
		{
		  fgets(linea, 1024, puntero);
		  //puts(linea);
		  frase1 = strtok(linea, "\t");
		  frase2 = strtok(NULL, "\t");
		  frase3 = strtok(NULL, "\t");
			if( strcmp(jugador.nick2, frase2) == 0 )
			{
				x=0;
			//printf("el nick esta registrado !!\n");
			//printf("%s\t%s\t%s\n", frase1, frase2, frase3);
			} else {
				x=1;
			// printf("el nick NO esta registrado\n");
			}
	
		}

	if(x==0)
	printf("el nick esta registrado");
	else if(x==1)
	printf("no");
	


		/*puntero=fopen("registro.txt","r");
		while(feof(pf)==0) //leemos el fichero que no sabemos donde acaba
		{
			
		}*/
return 0;
}
