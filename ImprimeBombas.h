// Función que imprime el tablero del jugador y el mar del enemigo:
void impTabJudYTamBomJug( char tabJug[tamTab][tamTab][2], char tabMaq[tamTab][tamTab][2] )
{
	// Recibe:	Dos matrices tridimensionales de tamaño: tamTab*tamTab*2
	// Sale:	Se imprime por pantalla el nivel 0 de tabJug que contiene los barcos, y el nivel 1 de tabMaq que contiene el mar del enemigo y las bombas lanzadas.

	char letCol[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i, j;

	// Se imprime los indicadores de columna de ambas tablas:
	for( i=0; i < tamTab; i++ )
		printf( " " );

	printf( "Tu tablero" );
	for( i=0; i < tamTab+(tamTab/3)+(tamTab/6); i++ )
		printf( " " );

	printf( "  Mar del enemigo\n    " );
	for( i=0; i < tamTab; i++ )
		printf( " %c", letCol[i] );

	printf( "         " );
	for( i=0; i < tamTab; i++ )
		printf( " %c", letCol[i] );

	printf( "\n    " );
	for( i=0; i < tamTab; i++ )
		printf( "__" );

	printf( "         " );
	for( i=0; i < tamTab; i++ )
		printf( "__" );

	printf( "\n" );


	// Se imprimen los indicadores de fila y la información de cada tabla:
	for( i=0; i < tamTab; i++ )
	{
		// Se añade un espacio de más cuando el indicador de fila es menor de 10:
		if( i<10 )	printf( " %i |", i );
		else		printf( "%i |", i );


		// Imprime el contenido de la tabla del jugador (nivel 0):
		for( j=0; j < tamTab; j++ )
		{
			if( tabJug[i][j][1] == agua )			// Si el nivel 1 marca agua, imprime agua en vez de vacio.
				printf( " %c", agua );

			else if( tabJug[i][j][1] == tocado )	// Si marca tocado, imprime tocado en vez del barco.
				printf( " %c", tocado );

			else if( tabJug[i][j][1] == hundido )	// Si marca hundido, imprime hundido en vez del barco.
				printf( " %c", hundido );

			else									// En caso contrario imprime el caracter del barco que corresponda.
				printf( " %c", tabJug[i][j][0] );
		};
		printf( "     " );
		// Ahora se imprime el tablero del enemigo que nos marca donde hemos echado las bombas (no sus barcos!) y si hemos tocado o hundido alguno.
		if( i<10 )	printf( " %i |", i );
		else		printf( "%i |", i );

		for( j=0; j < tamTab; j++ )
			printf( " %c", tabMaq[i][j][1] );

		printf( "\n" );
	};

	printf( "\n" );
};

// Función de depuración que imprime los tableros de la maquina para que el usuario pueda ver sus barcos y lo que hace:
void impTabJudYTamBomJugTest( char tabJug[tamTab][tamTab][2], char tabMaq[tamTab][tamTab][2] )
{
	// RECIBE:	dos matrices tridimensionales de tamaño: tamTab*tamTab*2
	// Sale:	Se imprime por pantalla el nivel 0 de tabMaq que contiene los barcos, y el nivel 1 de tabJug que contiene el mar del jugador y las bombas lanzadas.

	char letCol[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i, j;

	// Se imprime los indicadores de columna de ambas tablas:
	for( i=0; i < tamTab; i++ )
		printf( " " );

	printf( "   Mar tuyo" );
	for( i=0; i < tamTab+(tamTab/3)+(tamTab/6); i++ )
		printf( " " );

	printf( "    Maquina\n    " );
	for( i=0; i < tamTab; i++ )
		printf( " %c", letCol[i] );

	printf( "         " );
	for( i=0; i < tamTab; i++ )
		printf( " %c", letCol[i] );

	printf( "\n    " );
	for( i=0; i < tamTab; i++ )
		printf( "__" );

	printf( "         " );
	for( i=0; i < tamTab; i++ )
		printf( "__" );

	printf( "\n" );


	// Se imprimen los indicadores de fila y la información de cada componente:
	for( i=0; i < tamTab; i++ )
	{
		// Se añade un espacio de más cuando el indicador de fila es menor de 10:

		if( i<10 )
			printf( " %i |", i );
		else
			printf( "%i |", i );

		for( j=0; j < tamTab; j++ )
			printf( " %c", tabJug[i][j][1] );

		printf( "     " );
		if( i<10 )
			printf( " %i |", i );
		else
			printf( "%i |", i );

		for( j=0; j < tamTab; j++ )
			printf( " %c", tabMaq[i][j][0] );

		printf( "\n" );
	};

	printf( "\n" );
};


// Función que contabiliza las partes de barco hundido:
int cuenTrozHund( char tablero[tamTab][tamTab][2] )
{
	/*
	Reicbe:	Una matriz tridimensional de tamaño: tamTab*tamTab*2
	Sale:	Se contabilizan todas las partes hundidas del nivel 1 del tablero y se devuelve como entero.
	*/

	int trozos=0, i, j;

	for( i=0; i < tamTab; i++ )
		for( j=0; j < tamTab; j++ )
			if( tablero[i][j][1] == hundido )	// Contabiliza las partes de barco hundidas.
				trozos++;

	return trozos;
};


// Función que valida la coordenada de colocación de la bomba y de ser correcta desconcatena las coordenadas o en caso contrario envía y muestra un error al usuario:
int validaYSeparaFilyColBomba( char tablero[tamTab][tamTab][2], char coor[4], int *fil, int *col, int *leTocaA )
{
	/*
		Recibe:
						Una matriz tridimensional de tamaño: tamTab*tamTab*2
						Una cadena de caracteres de tamaño 4 termianada con '\0'
						Y tres referencias a parámetros enteros:
							fil y col: No contendrán un numero entero mas grande que el tamTab
							leTocaA: Es un entero booleano que contiene 0=jugador ó 1=maquina

		Sale:
						Valida si 'coor' es correcta, de serlo la desconcatena guardándola por separado en 'fil' y 'col' y se devuelve un 1=true
						Si no lo es se devuelve un 0=false, además si es el turno del jugador, se le imprime por pantalla un error para informarle del dato incorrecto.
	*/


	int correcto=1, longCoor=strlen(coor);

	// Si la longitud de la cadena es de 2, y el componente 0 es numero y el 1 es letra...
	if( longCoor == 2   &&   coor[0] >= 48 && coor[0] <= 48+tamTab-1   &&   coor[1] >= 97 && coor[1] <= 97+tamTab-1 )
	{
		// Tanto la fila como la columna se guardan como enteros, a la fila se le restan -48 y nos da un entero, a la columna se le resta -49 para que nos de el "número en ASCII" y luego -48 para que nos de el entero.
		*fil = coor[0]-48;
		*col = coor[1]-49-48;

		// Si la coordenada elegida ya ha sido usada
		if( tablero[*fil][*col][1] != vacio )
		{
			if( *leTocaA == 0 ) printf( "Ya la has puesto antes, elija otra coordenada:\n" );
			correcto = 0;
		};

	}	// Si la longitud es de 2, y el componente 0 es letra y el 1 numero...
	else if( longCoor == 2   &&   coor[1] >= 48 && coor[1] <= 48+tamTab-1   &&   coor[0] >= 97 && coor[0] <= 97+tamTab-1 )
	{
		*fil = coor[1]-48;
		*col = coor[0]-49-48;

		if( tablero[*fil][*col][1] != vacio )
		{
			if( *leTocaA == 0 ) printf( "Ya la has puesto antes, elija otra coordenada:\n" );
			correcto = 0;
		};

	}	// Si la longitud es de 3, y el componente 0y1 son números y el 2 es letra...
	else if( longCoor == 3   &&   coor[0] >= 48 && coor[0] <= 48+tamTab-1   &&   coor[1] >= 48 && coor[1] <= 48+tamTab-1   &&   coor[2] >= 97 && coor[2] <= 97+tamTab-1 )
	{
		*fil = ((coor[0]-48)*10) + (coor[1]-48);
		*col = coor[2]-49-48;

		if( tablero[*fil][*col][1] != vacio )
		{
			if( *leTocaA == 0 ) printf( "Ya la has puesto antes, elija otra coordenada:\n" );
			correcto = 0;
		};

	}	// Si la longitud es de 3, y el componente 0 es letra y el 1y2 números...
	else if( longCoor == 3   &&   coor[2] >= 48 && coor[2] <= 48+tamTab-1   &&   coor[1] >= 48 && coor[1] <= 48+tamTab-1   &&   coor[0] >= 97 && coor[0] <= 97+tamTab-1 )
	{
		*fil = ((coor[1]-48)*10) + (coor[2]-48);
		*col = coor[0]-49-48;

		if( tablero[*fil][*col][1] != vacio )
		{
			if( *leTocaA == 0 ) printf( "Ya la has puesto antes, elija otra coordenada:\n" );
			correcto = 0;
		};
	}
	else // En cualquier otra situación 'correcto' será falso:
	{
		if( leTocaA == 0 )	// Si el error lo ha generado el jugador:
		{
			impTablero(tablero);
			printf( "Coordenada incorrecta:\n *Use solo las coordenadas marcadas en el tablero\n *Un numero para marcar la fila y una letra minuscula para marcar la columna. Ejemplo: 2c o c2.\n\nIntentelo de nuevo: " );
		};
		correcto = 0;
	};

	return correcto;
};


//Funcion que comprueba si ademas de tocado el barco es tambien hundido o no:
void tocadoYHundido( char tablero[tamTab][tamTab][2], int fil, int col, int *leTocaA )
{
	/*
	Recibe:
				Una matriz tridimensional de tamaño: tamTab*tamTab*2
				Dos enteros cuyo valor no sera mayor que tamTab
				Y la referencia a un parámetro entero boolenano cuyo valores son 0=jugador, 1=maquina.

	Sale:	En caso de que todas las partes del barco hayan sido tocadas, se marca el barco como hundido y se imprime por pantalla.
	*/

	int barcTotales = BARPEQ + BARMED + BARGRA;
	char zonaAfectada = tablero[fil][col][0];
	int trozos=0, trozosTocados=0;
	int i, j;

	for( i=0; i < tamTab; i++ )
	{
		for( j=0; j < tamTab; j++ )
		{
			// Si en el nivel 0 no hay 'vacio', y lo que hay es igual a una parte de barco que se acaba de tocar, se contabiliza +1 trozo
			if( tablero[i][j][0] != vacio  &&  tablero[i][j][0] == zonaAfectada )
				trozos++;

			// Si en nivel 0 no hay 'vacio', y lo que hay es un trozo de barco, y en el nivel 1 marca tocado, se contabiliza +1 trozoTocado (cuenta las partes de barco tocadas)
			if( tablero[i][j][0] != vacio  &&  tablero[i][j][0] == zonaAfectada  &&  tablero[i][j][1] == tocado )
				trozosTocados++;
		};
	};


	// Si los trozos de barco no es 0, hay tantas partes de barco como partes de barco tocadas, entonces el barco esta hundido y se cambia todas esas marcas de tocado por hundido.
	if( trozos != 0  &&  trozos == trozosTocados )
	{

		if( *leTocaA == 0 )
			printf( "Hundiste el barco del enemigo!\n" );
		else
			printf( "El enemigo te hundido el barco\n" );

		// Se sustituyen las marcas de tocado por las de hundido:
		for( i=0; i < tamTab; i++ )
		{
			for( j=0; j < tamTab; j++ )
			{
				if( tablero[i][j][0] == zonaAfectada )
					tablero[i][j][1] = hundido;	// Se sustituye, en el nivel 1, el símbolo de tocado por el de hundido.
			};
		};
	};

};


// Función que comprueba si en las coordenadas recibidas del tablero hay un trozo de barco, de serlo lo marca como tocado.
void esTocado( char tablero[tamTab][tamTab][2], int fil, int col, int *leTocaA )
{
	/*
	Recibe:
				Una matriz tridimensional de tamaño: tamTab*tamTab*2
				Dos enteros cuyo valor no serán mayor que tamTab
				Y la referencia a un parámetro entero boolenano cuyo valores son 0=jugador, 1=maquina.

	Sale:	Según las coordenadas recibidas, se comprueba en el tablero "si hay agua o hay barco", y se informa según convenga. También se almacena el carácter 'agua' o 'tocado' en la matriz.
	*/


	// Se bombardea, si en el nivel 0 del tablero hay algo distinto de vacio, entonces sera un barco:
	if( tablero[fil][col][0] != vacio )
	{
		// Se marca el trozo de barco como tocado en el nivel 1 del tablero:
		tablero[fil][col][1] = tocado;


		// Se imprime un mensaje informativo según corresponda:
		if( *leTocaA == 0 )	printf( "Tocaste al enemigo, bombardee de nuevo!\n" );
		else				printf( "El enemigo te toco, el repite turno\n" );


		if( *leTocaA == 1 )
		{
			// Si en el siguiente disparo, hay una X encima de la X anterior, o debajo de la X anterior, se borran las diagonales que contengan 'fin' ya que la maquina sabe que el barco esta colocado en vertical.
			if( tablero[fil-1][col][1] == tocado  || tablero[fil+1][col][1] == tocado ) // arriba/abajo
			{
				// Se borran las diagonales solo si están marcadas con 'fin'
				if( tablero[fil-1][col-1][1] == fin ) tablero[fil-1][col-1][1] = vacio; // arriba izquierda
				if( tablero[fil-1][col+1][1] == fin ) tablero[fil-1][col+1][1] = vacio; // arriba derecha
				if( tablero[fil+1][col+1][1] == fin ) tablero[fil+1][col+1][1] = vacio; // abajo derecha
				if( tablero[fil+1][col-1][1] == fin ) tablero[fil+1][col-1][1] = vacio; // abajo izquierda

				// Puesto que nuestro barco esta colocado verticalmente, si el primer 'tocado' esta debajo, colocar un 'fin' encima de la posición actual como posible posición a bombardear.
				if( tablero[fil-1][col][1] == tocado  &&  tablero[fil+1][col][1] == vacio ) tablero[fil+1][col][1] = fin;

				// Si el primer tocado estaba debajo pues colocar un 'fin' debajo de la posición actual para seguir bombardeando hacia abajo:
				if( tablero[fil+1][col][1] == tocado  &&  tablero[fil-1][col][1] == vacio ) tablero[fil-1][col][1] = fin;

			}
 			  // Mismas condiciones que el if anterior pero ahora con comprobación horizontal:
			  // Si al disparar nos encontramos a la derecha o a la izquierda otra X anterior, entonces la maquina sabe que el barco esta en horizontal:
			else if( tablero[fil][col-1][1] == tocado  || tablero[fil][col+1][1] == tocado ) // laterales
			{
				// Se borran las diagonales:
				if( tablero[fil-1][col-1][1] == fin ) tablero[fil-1][col-1][1] = vacio; // arriba izquierda
				if( tablero[fil-1][col+1][1] == fin ) tablero[fil-1][col+1][1] = vacio; // arriba derecha
				if( tablero[fil+1][col+1][1] == fin ) tablero[fil+1][col+1][1] = vacio; // abajo derecha
				if( tablero[fil+1][col-1][1] == fin ) tablero[fil+1][col-1][1] = vacio; // abajo izquierda

				// Se marca una posible posición hacia la derecha:
				if( tablero[fil][col-1][1] == tocado  &&  tablero[fil][col+1][1] == vacio ) tablero[fil][col+1][1] = fin;

				// En caso contrario hacia la izquierda:
				if( tablero[fil][col+1][1] == tocado  &&  tablero[fil][col-1][1] == vacio) tablero[fil][col-1][1] = fin;

			}
			else // Si no hay una marca almacenada en ninguna de las direcciones, pues se crean las cuatro marcas posibles:
			{
				if( tablero[fil-1][col][1] == vacio ) tablero[fil-1][col][1] = fin; // Arriba
				if( tablero[fil][col+1][1] == vacio ) tablero[fil][col+1][1] = fin; // Derecha
				if( tablero[fil+1][col][1] == vacio ) tablero[fil+1][col][1] = fin; // Abajo
				if( tablero[fil][col-1][1] == vacio ) tablero[fil][col-1][1] = fin; // Izquierda
			};

		};

		// Se comprueba si además de tocar el barco también se ha hundido:
		tocadoYHundido( tablero, fil, col, &*leTocaA);

	}
	else// Si el disparo dio en 'vacio' se habrá tocado agua:
	{
		// Se marca la casilla como agua:
		tablero[fil][col][1] = agua;

		// Se imprime un mensaje informativo sobre el disparo realizado:
		if( *leTocaA == 0 )	printf( "Diste en el agua\n" );
		else				printf( "La maquina fallo\n" );

		// Si se falla el disparo se pierde el turno y se cambia la booleana que marca a quien le toca jugar:
		if( *leTocaA == 0 )	*leTocaA = 1;
		else				*leTocaA = 0;

	};

};


// Función que imprime las bombas en el mar del adversario
void impBomba( char tabJug[tamTab][tamTab][2], char tabMaq[tamTab][tamTab][2], int trozosBarco, int *leTocaA  )
{
	/*
	Recibe:
				Dos matrices tridimensionales de tamaño: tamTab*tamTab*2
				Un entero cuyo valor no sera mayor a la suma de todos los trozos de barco de todos los barcos.
				Y la referencia a un parámetro entero boolenano cuyo valores son 0=jugador, 1=maquina.

	Sale:	Se le solicitara al usuario/maquina unas coordenadas y se marcara el valor que corresponda según el resultado obtenido (mirar comentarios de las demás funciones que intervienen)
	*/

	char coor[4];
	int fil=0, col=0;
	int posBomMaq=0;
	int i, j;

	
	if( *leTocaA == 0 )// Si es el turno del jugador
	{
		printf( "\n\n" );
		impTabJudYTamBomJug( tabJug, tabMaq );
	
		printf( "Es tu turno, inserte las coordenadas de lanzamiento: " );
		do // La coordenada sera valida si esta dentro del tablero y es un hueco vacio:
		{
			scanf( "%s", coor );

		} while( validaYSeparaFilyColBomba( tabMaq, coor, &fil, &col, &*leTocaA ) != 1 );


		// Se comprueba si se ha tocado un barco:
		esTocado( tabMaq, fil, col, &*leTocaA);

	}
	else // Si es el turno de la maquina
	{

		printf( "\n\n" );
		impTabJudYTamBomJug( tabJug, tabMaq );

		// Lo primero que hace la maquina es comprobar si en el nivel 1 del tablero del jugador ha marcado alguna posible posición, de ser así las contabiliza:
		for( i=0; i < tamTab; i++ )
			for( j=0; j < tamTab; j++ )
				if( tabJug[i][j][1] == fin )
					posBomMaq++;


		// Si se contabiliza alguna posible posición marcada previamente, entonces se usa alguna de estas para bombardear:
		if( posBomMaq != 0 )
		{

			for( i=0; i < tamTab; i++ )
			{
				for( j=0; j < tamTab; j++ )
				{

					// Mientras que fil y col sean 0, y en el momento de que se encuentre un 'fin' (posible posición) marcada: concatenar las coordenadas dentro de coor.
					if( fil == 0 && col == 0   &&   tabJug[i][j][1] == fin )
					{
						fil = i;
						col = j;

						// Se guarda la coordenada
						coor[0] = fil+48;
						coor[1] = col+48+49;
						coor[2] = '\0';

						printf( "La maquina bombardeo la posicion: %s\n", coor );

						// Se borra esa marca para no usarla de nuevo y/o dejarla libre para atacar:
						tabJug[i][j][1] = vacio;
					};
				};
			};

		}
		else // Si no hay guardada ninguna posición en la que echar la bomba, se generaran nuevas coordenadas:
		{
			do // La maquina genera sus coordenadas para el lanzamiento de bombas
			{
				coor[0] = (rand()%tamTab)+48;
				coor[1] = (rand()%tamTab)+48+49;
				coor[2] = '\0';
			} while( validaYSeparaFilyColBomba(  tabJug, coor, &fil, &col, &*leTocaA ) != 1 );

			printf( "La maquina bombardeo la posicion: %s\n", coor );
		};


		// Se comprueba si se ha tocado el barco con las posiciones introducidas por el usuario/maquina:
		esTocado( tabJug, fil, col, &*leTocaA);

	};

};
