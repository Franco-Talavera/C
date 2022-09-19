#include <stdio.h>
#include<conio.h>
#include<math.h>

main()
{
	float Porcfalla;
	int Mod[50],CCSF[50],CCCF[50],Cod[50], i, k, N, c=0, auxCCCF,auxCCSF,Codigo,Cod303[50],aux,aux2,aux3,aux4,K,X,A;
	
	printf("Ingresar el numero de maquinas: "); 
	scanf("%d",&N);
	
	for (i=0 ; i<N ; i++)
	{
		printf("Ingresar el codigo de la maquina %d: ", i+1); scanf("%d",&Cod[i]);
		printf("Ingresar su modelo producido: "); scanf("%d",&Mod[i]);
		printf("Ingresar su cantidad de contenedores sin fallas: "); scanf("%d",&CCSF[i]);
		printf("Ingresar su cantidad de contenedores con fallas: "); scanf("%d",&CCCF[i]);
	}
	
	printf("\n\nDatos actualizado y ordenados segun orden de ingreso\n\n");
	for (i=0 ; i<N ; i++)
	printf("%10d%10d%10d%10d\n",Cod[i],Mod[i],CCSF[i],CCCF[i]);
	
// fin modulo 1	
	
	printf("Ingresar el codigo de la maquina a consultar(ingresando 0 se deja de consultar): "); 
	scanf("%d",&Codigo);
	
	while(Codigo!=0)
	{
		k=0;i=0;
		while(k==0 && i<N)
		{
			if(Codigo==Cod[i])
			{
				k=1;
			}
			else
			{
				i++;
			}
		}
		if(k==0)
		{
			printf("no encontrado \n");
		}
		else
		{
			printf("%d : ",Mod[i]);
			if(Mod[i]==101)
			{
				printf("Es Rectangular \n");
			}
			else
			{
				if(Mod[i]==202)
				{
					printf("Es Cuadrado \n");
				}
				else
				{
					printf("Es Redondo \n");
				}
			}
			auxCCCF=CCCF[i];
			auxCCSF=CCSF[i];
			if((auxCCCF+auxCCSF)!=0)
			{
				
				Porcfalla = (float) auxCCCF*100/( auxCCCF + auxCCSF );
				printf("El porcentaje de fallas de la maquina es %.2f %% \n",Porcfalla);
			}
			else
			{
				printf("no se fabricaron contenedores");
			}	
		}
		printf("Ingresar el codigo de la maquina a consultar(ingresando 0 se deja de consultar): "); 
		scanf("%d",&Codigo);
	}
	
	// fin modulo 2
	
	for(i=0;i<N;i++)
	{
		if(Mod[i]==303)
		{
			Cod303[c]=Cod[i];
			c++;
		}	
	}
	if(c!=0)
	{
		printf("Los codigos de las maquinas que fabrican modelos redondos son: \n");
		for(k=0;k<c;k++)
		{
			printf("%d \n",Cod303[k]);
		}
	}
	else
	{
		printf("Ninguna maquina fabrica modelos redondos \n ");
	}
	
	// fin modulo 3
	
	K=0;
	X=N;
	while(K==0)
	{
		K=1;
		X--;
		for(i=0;i<X;i++)
		{
			if(Cod[i]>Cod[i+1])
			{
				K=0;
				aux=Cod[i];
				Cod[i]=Cod[i+1];
				Cod[i+1]=aux;
				
				aux2=Mod[i];
				Mod[i]=Mod[i+1];
				Mod[i+1]=aux2;
				
				aux3=CCSF[i];
				CCSF[i]=CCSF[i+1];
				CCSF[i+1]=aux3;
				
				aux4=CCCF[i];
				CCCF[i]=CCCF[i+1];
				CCCF[i+1]=aux4;
				
			}
		}
	}
	
	printf("\n\nDatos actualizado y ordenados segun codigo de maquina de menor a mayor\n\n");
	for (i=0 ; i<N ; i++)
	printf("%10d%10d%10d%10d\n",Cod[i],Mod[i],CCSF[i],CCCF[i]);
	
	//fin modulo 4
	getch();	
}
