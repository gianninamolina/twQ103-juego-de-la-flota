#include<stdio.h>
#include<string.h>
//definimos las estructuras
typedef struct
{
	char nombre[50];
	char apellidos[100];
	int dni[8];
	char dniLetra;
	char sexo; //M mujer, H hombre
	int edad;
	char fuma;//S, fumador, N no fumador
}registro;
typedef struct
{
	char dia[50];
	float hora;
	int libre; //1-libre 0-ocupado
}departamento;
//PROTOTIPOS DE FUNCIONES
int menu(void);
int main()
{
	registro usuario;
	departamento cita[100];
	FILE *pf1,*pf2,*pf3,*pf4,*FICHA;
	int op,i,datos=0,especialista,orden;
	float hora;
	char dia[50],menstruacion;
	do{
		op=0;
		op=menu(); //llamamos a la funcion menu
	switch(op)
		{
			case 1:
				{ 
					FICHA=fopen("informacion.txt","a");
					if(FICHA==NULL)
					{
						printf("No se puede abrir el fichero \n");
						return -1;
					}
					fflush(stdin); //para limpiar el scanf
					printf("Nombre del usuario \n");
					gets(usuario.nombre);
					fflush(stdin);//para limpiar el scanf
					printf("Apellidos del usuario \n");
					gets(usuario.apellidos);
					printf("Dni (8 digitos) \n");
					for(i=0;i<8;i++)
					{
						scanf("%i",&usuario.dni[i]);
					}
					fflush(stdin);
					printf("Letra del dni \n");
					scanf("%c",&usuario.dniLetra);
					printf("Sexo: M si es mujer / H si es hombre\n");
					fflush(stdin);
					scanf("%c",&usuario.sexo);
					printf("Edad:\n");
					fflush(stdin);
					scanf("%i",&usuario.edad);
					printf("Fumador: S si es si / N si es no\n");
					fflush(stdin);
					scanf("%c",&usuario.fuma);
					fprintf(FICHA,"%s \t %s \t %i%c\t %c \t %i \t %c \n",usuario.nombre,usuario.apellidos,usuario.dni,usuario.dniLetra,usuario.sexo,usuario.edad,usuario.fuma);
					fclose(FICHA);
					//system("cls"); //para limpiar la pantalla
					printf("Escriba el numero correspondiente del especialista con quien quiere concretar su cita: \n\n");
					printf("\t- 1/ Traumatologia \t\n\n");
					printf("\t- 2/ Dermatologia \t\n\n");
					printf("\t- 3/ Ginecologia \t\n\n");
					printf("\t- 4/ Cardiologia \t\n\n");
					scanf("%i",&especialista);
					switch(especialista)
					{
						case 1:
							{
								pf1=fopen("trauma.txt","r"); //leer el fichero
								if(pf1==NULL)
								{
									printf("No se puede abrir el fichero \n");
									return -1;
								}
								//leer columna traumatologo
								while(fscanf(pf1,"%s %f %i",cita[datos].dia,&cita[datos].hora,&cita[datos].libre)!=EOF)
								{
									datos++;
								}
								for(i=0;i<datos;i++)
								{
									printf("\t %s %.2f \n\n",cita[i].dia,cita[i].hora); //mostramos las citas
								}
								 //cerramos el fichero1
								fflush(stdin);
								printf("Que dia quieres y a que hora \n");
								scanf("%s %f",dia,&hora);
								i=0;
								orden=0;
								for(i=0;i<datos;i++)
								{
									
									if(orden==0)//comparamos las dos cadenas para ver si se cumplen
									{
										if(hora==cita[i].hora)
										{
											
											if(cita[i].libre!=0)
											{
												printf("Recuerde su cita el dia %s a las %.2f \n",cita[i].dia,cita[i].hora);
												cita[i].libre=0; //la cita esta ocupada
											}
											else
											{
												printf("La cita esta ocupada, elige otra\n");
												scanf("%s %f",dia,&hora);
											}
										}
									}
								}
								fclose(pf1);
								/*if(orden!=0)
								{
									printf("No hay fechas disponibles \n");
									printf("Escribe una de las que estan puestas \n");
									scanf("%s %f",dia,&hora);
									
								}*/
								pf1=fopen("trauma.txt","w"); //escribimos en el fichero
								if(pf1==NULL)
								{
									printf("No se puede abrir el fichero \n");
									return -1;
								}
								i=0;
								for(i=0;i<datos;i++)//escribimos en el fichero todos los datos incluidas las citas ocupadas
								{
									fprintf(pf1,"%s \t",cita[i].dia);
									fprintf(pf1,"%.2f \t",cita[i].hora);
									fprintf(pf1,"%i \n",cita[i].libre);
								}
								datos=0;
								fclose(pf1);

								break;
							}
						case 2:
							{
								//leer columna dermatologo
								pf2=fopen("derma.txt","r"); //leer el fichero
								if(pf2==NULL)
								{
									printf("No se puede abrir el fichero \n");
									return -1;
								}
								//leer columna traumatologo
								while(fscanf(pf2,"%s %f %i",cita[datos].dia,&cita[datos].hora,&cita[datos].libre)!=EOF)
								{
									datos++;
								}
								for(i=0;i<datos;i++)
								{
									printf("\t %s %.2f \n\n",cita[i].dia,cita[i].hora); //mostramos las citas
								}
								fclose(pf2); //cerramos el fichero1
								fflush(stdin);
								printf("Que dia quieres y a que hora \n");
								scanf("%s %f",dia,&hora);
								i=0;
								orden=0;
								for(i=0;i<datos;i++)
								{
									orden=strcmp(dia,cita[i].dia);
									if(orden==0)//comparamos las dos cadenas para ver si se cumplen
									{
										if(hora==cita[i].hora)
										{
											
											if(cita[i].libre!=0)
											{
												printf("Recuerde su cita el dia %s a las %.2f \n",cita[i].dia,cita[i].hora);
												cita[i].libre=0; //la cita esta ocupada
											}
											else
											{
												printf("La cita esta ocupada, elige otra\n");
												scanf("%s %f",dia,&hora);
											}
										}
									}
								}
								pf2=fopen("derma.txt","w"); //escribimos en el fichero
								if(pf2==NULL)
								{
									printf("No se puede abrir el fichero \n");
									return -1;
								}
								i=0;
								for(i=0;i<datos;i++)//escribimos en el fichero todos los datos incluidas las citas ocupadas
								{
									fprintf(pf2,"%s \t",cita[i].dia);
									fprintf(pf2,"%.2f \t",cita[i].hora);
									fprintf(pf2,"%i \n",cita[i].libre);
								}
								datos=0;
								fclose(pf2);

								break;
							}
						case 3:
							{
								//leer columna ginecologo
								pf3=fopen("gine.txt","r"); //leer el fichero
								if(pf3==NULL)
								{
									printf("No se puede abrir el fichero \n");
									return -1;
								}
								if (usuario.sexo=='M')
								{
									fflush(stdin);
									printf(" Su consulta se debe a un retraso en su mentruacion?: S si es si / N si es no\n");
									scanf("%c",&menstruacion);
									if (menstruacion=='S')
									{
										printf("Nota para el doctor/a: TEST DE EMBARAZO");
									}		
								}
								while(fscanf(pf3,"%s %f %i",cita[datos].dia,&cita[datos].hora,&cita[datos].libre)!=EOF)
								{
									datos++;
								}
								for(i=0;i<datos;i++)
								{
									printf("\t %s %.2f \n\n",cita[i].dia,cita[i].hora); //mostramos las citas
								}
								fclose(pf3); //cerramos el fichero1
								fflush(stdin);
								printf("Que dia quieres y a que hora \n");
								scanf("%s %f",dia,&hora);
								i=0;
								orden=0;
								for(i=0;i<datos;i++)
								{
									orden=strcmp(dia,cita[i].dia);
									if(orden==0)//comparamos las dos cadenas para ver si se cumplen
									{
										if(hora==cita[i].hora)
										{
											
											if(cita[i].libre!=0)
											{
												printf("Recuerde su cita el dia %s a las %.2f \n",cita[i].dia,cita[i].hora);
												cita[i].libre=0; //la cita esta ocupada
											}
											else
											{
												printf("La cita esta ocupada, elige otra\n");
												scanf("%s %f",dia,&hora);
											}
										}
									}
								}
								pf3=fopen("gine.txt","w"); //escribimos en el fichero
								if(pf3==NULL)
								{
									printf("No se puede abrir el fichero \n");
									return -1;
								}
								i=0;
								for(i=0;i<datos;i++)//escribimos en el fichero todos los datos incluidas las citas ocupadas
								{
									fprintf(pf3,"%s \t",cita[i].dia);
									fprintf(pf3,"%.2f \t",cita[i].hora);
									fprintf(pf3,"%i \n",cita[i].libre);
								}
								datos=0;
								fclose(pf3);
								break;
							}
						case 4:
							{
								//leer columna cardiologia
								pf4=fopen("cardio.txt","r"); //leer el fichero
								if(pf4==NULL)
								{
									printf("No se puede abrir el fichero \n");
									return -1;
								}
								//leer columna traumatologo
								while(fscanf(pf4,"%s %f %i",cita[datos].dia,&cita[datos].hora,&cita[datos].libre)!=EOF)
								{
									datos++;
								}
								for(i=0;i<datos;i++)
								{
									printf("\t %s %.2f \n\n",cita[i].dia,cita[i].hora); //mostramos las citas
								}
								fclose(pf4); //cerramos el fichero1
								fflush(stdin);
								printf("Que dia quieres y a que hora \n");
								scanf("%s %f",dia,&hora);
								i=0;
								orden=0;
								for(i=0;i<datos;i++)
								{
									orden=strcmp(dia,cita[i].dia);
									if(orden==0)//comparamos las dos cadenas para ver si se cumplen
									{
										if(hora==cita[i].hora)
										{
											
											if(cita[i].libre!=0)
											{
												printf("Recuerde su cita el dia %s a las %.2f \n",cita[i].dia,cita[i].hora);
												cita[i].libre=0; //la cita esta ocupada
											}
											else
											{
												printf("La cita esta ocupada, elige otra\n");
												scanf("%s %f",dia,&hora);
											}
										}
									}
								}
								pf4=fopen("cardio.txt","w"); //escribimos en el fichero
								if(pf4==NULL)
								{
									printf("No se puede abrir el fichero \n");
									return -1;
								}
								i=0;
								for(i=0;i<datos;i++)//escribimos en el fichero todos los datos incluidas las citas ocupadas
								{
									fprintf(pf4,"%s \t",cita[i].dia);
									fprintf(pf4,"%.2f \t",cita[i].hora);
									fprintf(pf4,"%i \n",cita[i].libre);
								}
								datos=0;
								fclose(pf4);
								break;
							}
					}
				break;
				}
			case 2:
				{
					printf("Ha salido correctamente del programa \n");
					break;
				}
		}

	}while(op!=2);
	

return 0;
}
//FUNCION DEL MENU PRINCIPAL
int menu(void)
{
	int opcion;
	printf("\t SISTEMA  INFORMATICO  PARA  PEDIR  CITAS \t\n\n");
	printf("\t\t Pulse 1 para pedir cita \n\n");
	printf("\t\t Pulse 2 para salir del sistema \n\n");
	fflush(stdin);
	scanf("%i",&opcion);
	return opcion;
}
