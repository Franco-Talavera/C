#include<stdio.h>
#include<conio.h>
#include<math.h>
#define PI 3.14159265
main()
{ 
	float  R=3.2,R2,f=600,T,T2,g=9.8,ac,ac2,V,w,w2,fs,Vo,at,t,t2, Wsegundero= 2*PI/60 , Wminutero=2*PI/3600, Whorero=2*PI/43200, phi0=0, phis,phim,phih,phih2;
	//----------------- pasar de rpm a rps
	fs=f/60;  /* fs= 1/T; */
	//-----------------
	T=1/fs;  /* T=sqrt((R*4*PI*PI)/ac);   * T=2*PI/w;  */   
	w=2*PI/T; /* w= V/R;  */	
	V=w*R;  /* V= Vo+at*t; *     w2=V/R2; T2=2*PI/w2; */
	ac=R*w*w/g; /*  ac= V*V/R;  * ac2= R2*w2*w2; */ 
	//----------------------------
	//fs=sqrt(ac/(R*4*PI*PI));	f= fs*60;
	//	printf("f= %.2f \n",f);
	//------------------------------------
		printf("El periodo es %.2f \n la velocidad angular es %.2f \n la velocidad tangencial es %.2f \n la aceleracion centripeta es %.2fg \n la vel angular 2 es %.2f \n la aceler centrip 2 es %.2f \n  T2 es %.2f \n",T,w,V,ac,w2,ac2,T2);
	//--------------------------------------------
	//phi=phi0+w*t; 	phis=phi0+Wsegundero*t;   phim=phi0+Wminutero*t;   phih=phi0+Whorero*t;
	t=PI/(2*(Wminutero-Whorero));	
	t2=PI/((Wminutero-Whorero));
	phih=phi0+Whorero*t;
	phih2=phi0+Whorero*t2;
	//	printf("el t y t2 son %.2f y %.2f y el phih y phih2 son %.2f y %.2f ",t,t2,phih,phih2);
	//---------------------------------------------
	getch();
	
	



}
