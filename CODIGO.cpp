#include <stdio.h>
#include<conio.h>
#include<math.h>

#define PI 3.14159265

main()
{	/* codigo de grupo 3 rodrigo franco */
	//fabrica de contenedores, produccion mensual, "x" maquinas de su linea de produccion , 1 MES X MAQUINAS Y NUMERO DE CONTENEDORES
	//cada maquina produce muchos contenedores pero solo de un modelo
	// CID : codigo de identificacion de la maquina.  MCP: modelo de contenedor que produce.  L101,A101,P101,L202,P202,D303,P303 : DIMENSIONES DE CADA MODELO DE CONTENEDOR.
	// CCPMSF : CANTIDAD DE CONTENEDORES QUE PRODUJO POR MES SIN FALLAS.  CCPMCF : CANTIDAD DE CONTENEDORES QUE PRODUJO POR MES CON FALLAS.
	// CMTPM : CANTIDAD DE MAQUINAS TOTALES POR MES.  VOL101 : VOLUMEN DEL C RECTANGULAR. VOL202 : VOLUMEN DEL C CUBICO. VOL303 : VOLUMEN DEL C CILINDRICO.
	// ACUPORC : acumulador de porcentajes de fallas
	int CID,MCP,Min,C5=0,C5A15=0,C15=0,bandera=0,MODMIN;
	float L101,A101,P101,L202,P202,D303,P303,VOL101,VOL202,VOL303,CCPMCF,CCPMSF,CMTPM=0,ACUPORC=0,PORCCF=0,PORCMIN;
	printf("Ingrese el codigo de identificacion de la maquina\n(0 para dejar de ingresar maquinas):");
	scanf("%d",&CID);
	while(CID!=0)
	{
		CMTPM++;
		printf("Ingrese el modelo de contenedor que produce esta maquina: \nSi el contenedor es rectangular, ingrese el numero 101\n");
		printf("Si el contenedor es cubico, ingrese el numero 202\nSi el contenedor es cilindrico, ingrese el numero 303 \n");
		scanf("%d",&MCP);
		if(MCP==101)
		{
			printf("Ingrese el largo del contenedor rectangular ");
			scanf("%f",&L101);
			printf("Ingrese el ancho del contenedor rectangular ");
			scanf("%f",&A101);
			printf("Ingrese la profundidad del contenedor rectangular ");
			scanf("%f",&P101);
			printf("Ingrese la cantidad de contenedores fallados ");
			scanf("%f",&CCPMCF);
			printf("Ingrese la cantidad de contenedores sanos ");
			scanf("%f",&CCPMSF);
			VOL101 = L101 * A101 * P101;
			printf("\nEl volumen de este contenedor es %.2f\nEl modelo es rectangular\n",VOL101);
			printf("El codico de identificacion de la maquina que lo produjo es %d \n",CID);
		}
		else 
		{
			if(MCP==202)
			{
			printf("Ingrese el lado del contenedor cubico ");
			scanf("%f",&L202);
			printf("Ingrese la profundidad del contenedor cubico: ");
			scanf("%f",&P202);
			printf("Ingrese la cantidad de contenedores fallados ");
			scanf("%f",&CCPMCF);
			printf("Ingrese la cantidad de contenedores sanos ");
			scanf("%f",&CCPMSF);
			VOL202 = L202 * L202 * P202;
			printf("El volumen de este contenedor es %.2f\nEl modelo es cubico\n",VOL202);
			printf("El codico de identificacion de la maquina que lo produjo es %d \n",CID);
			}
			else
			{
			printf("Ingrese el diametro del contenedor cilindrico: ");
			scanf("%f",&D303);
			printf("Ingrese la profundidad del contenedor cilindrico:");
			scanf("%f",&P303);
			printf("Ingrese la cantidad de contenedores fallados ");
			scanf("%f",&CCPMCF);
			printf("Ingrese la cantidad de contenedores sanos ");
			scanf("%f",&CCPMSF);
			VOL303 = PI * D303 * D303 * P303 / 4;
			printf("El volumen de este contenedor es %.2f\nEl modelo es cilindrico\n",VOL303);
			printf("El codico de identificacion de la maquina que lo produjo es %d \n",CID);
			}	
		}
		
		PORCCF=(float)CCPMCF*100/(CCPMCF+CCPMSF);
		if(PORCCF<5)
		{
			C5++;
		}
		else
		{
			if(PORCCF>=5 && PORCCF<=15)
			{
				C5A15++;
			}
			else
			{
				C15++;
			}
		}
		ACUPORC+=PORCCF;
		printf("El porcentaje de contenedores con fallas es %.2f %% \n\n",PORCCF);
		if (bandera==0)
		{
			Min=CID;
			bandera=1;
			PORCMIN=PORCCF;
			MODMIN=MCP;
		}
		else
		{
			if(CID<Min)
			{
				Min=CID;
				PORCMIN=PORCCF;
				MODMIN=MCP;
			}
		}
		printf("Ingrese el codigo de identificacion de la maquina\n(0 para dejar de ingresar maquinas):");
		scanf("%d",&CID);
	}
	if(bandera!=0)
	{
		printf("\nEl codigo de identificacion de la maquina mas antigua es %d\nSu porcentaje de fallas es: %.2f %%\nSu modelo es: %d\n",Min,PORCMIN,MODMIN);
		printf("\nMaquinas con fallas menores al 5 %% : %d \n",C5);
		printf("\nMaquinas con fallas mayores al 5 %% y menores al 15 %%: %d \n",C5A15);
		printf("\nMaquinas con fallas mayores al 15 %% : %d \n",C15);
		printf("\nEl porcentaje de fallas promedio es %.2f %% \n",ACUPORC/CMTPM);
	}
	else
	{
		printf("No se ingresaron datos");
	}
	getch();
}
