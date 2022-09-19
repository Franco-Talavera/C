#include<stdio.h>
#include<conio.h>
#include<math.h>
#define PI 3.14159265
main()
{ 
	float m1=5,m2=0,g=10,Vo1,Vo2,F1,F2=0,phi1=15,phi2=0,a=0,a2,t,t2,Phirad,Fx1,Fx2,Fy1,Fy2,Fc,Fc2,Froz,P1,P2,Px,mue,Py,N;
	Phirad= PI/180;
	
	Fy1=cos(phi1*Phirad)*F1;
	Fx1=sin(phi1*Phirad)*F1;
	
	Fy2=cos(phi2*Phirad)*F2;
	Fx2=sin(phi2*Phirad)*F2;
	
	//P1=m1*g;	P2=m2*g;
	//F1=(m1+m2)*a+P1+P2;
	//Fc=m2*a+P2;
	//a=(F1-P1-Fc)/(m1);
	
	Px=sin(phi1*Phirad)*m1*g;
	Py=cos(phi1*Phirad)*m1*g;
	Fc=F1-Px;
	Froz=Px;
	Fc2=Px;
	
	/*F=ma; 		Fx1-Fc-Px=0  Fc-Fc2-Px=0    Fc2-Px=0  Px=sin(phi1*Phirad)*m1*g;		Fc2=Px		Fc-2*Px=0 ==> Fc=2*sin(phi1*Phirad)*m1*g		Fx1-3*sin(phi1*Phirad)*m1*g=0
					Fy1
	
	F-m2*a-Froz*2=m1*(a)
	F-Froz*2=a*(m1+m2)
	a=F-Froz*2/(m1+m2);
  	*/
  	N= Py;
	//Froz = mue * N ;
	
	
	/* 	
	a=Fx1/m1;   
	a2=Fx2/m2;
	V=Vo+a*t; 
	t=-Vo1/a;	
	t2=-Vo2/a2;  */
	printf("Froz=%d \n",Froz);
	printf("El t es: %.2f \n El a es: %.2f \n El a2 es: %.2f \n El t2 es: %.2f \n El F1 es: %.2f \n El F2 es: %.2f \n El Vo1 es: %.2f \n El Fc es: %.2f \n El Fc2 es: %.2f \n",t,a,a2,t2,F1,F2,Vo1,Fc,Fc2);
	//---------------------------------------------------------------------------
	
	
	
	
	
	getch();
}
