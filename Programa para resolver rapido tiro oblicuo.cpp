#include<stdio.h>
#include<conio.h>
#include<math.h>
#define PI 3.14159265
main()
{ 
	float V=20,Yo=0,Xo=0,Xinc,Yinc=1.8,tpisoinc,Phi=30,g=10,Vyo,Vxo,Phirad,Phiinc,X,Vy,Vx,Y,Ym,Xm,t,tm;
	float tpiso,tpiso2,Vypiso,Vypiso2,rap,rapinc,Xpiso=350,Yyo,Yyo2,tinc,tinc2,tinc3,Yn,Phiincrad=(-30)*(PI/180),Phiincgrad,Xinc2,Yinc2,Vyinc;
	//--------------------------------------------------------------- para intercambiar entre radianes y grados
	Phirad= PI/180;
	//--------------------------------------------------------------- para calcular las velocidades iniciales
	//Vxo=Xinc/tpisoinc;
	//Vyo=(Yinc+(g/2)*pow(tpisoinc,2))/tpisoinc;
	//V=sqrt(Xm*g/(cos(Phi*Phirad)*sin(Phi*Phirad))); // cuando el t es tm
	// Phi = ((1/Phirad)*asin(Xpiso*g / pow(V,2)))/2;  // CUANDO T ES TPISO
	// V= sqrt(Xpiso*g/(sin(2*Phi*Phirad)));        // cuando el T ES TPISO
	Vyo=sin(Phi*Phirad)*V;
	Vxo=cos(Phi*Phirad)*V;
		printf("La Vyo es: %.2f y la Vxo es %.2f \n",Vyo,Vxo);
	//---------------------------------------------------------------para calcular la v inicial y el angulo inicial con ciertos valores dados
	//V=sqrt(((-g/2)*pow(Xinc,2))/ (Yinc-Xinc*tan(Phi*Phirad))/pow(cos(Phi*Phirad),2));
	V=sqrt(pow(Vyo,2)+pow(Vxo,2));
	Phi=asin(Vyo/V)*(1/Phirad);
		printf("La vel inicial es: %.2f y el angulo inicial es %.2f \n",V,Phi);
	//-------------------------------------------------------- para t,v,rapidez y angulo en un tienmpo dado
	Vx=Vxo;
	Vypiso2=Vyo-g*tpisoinc;
	rapinc=sqrt(pow(Vypiso2,2)+pow(Vx,2));
	Phiinc= atan((Vypiso2/Vxo))*(1/Phirad);
		printf("La vel en Y a los %.2f seg es: %.2f y la rap es: %.2f y el angulo es %.2f \n",tpisoinc,Vypiso2,rapinc,Phiinc);
	//---------------------------------------------------------- LUGAR PARA DESARROLLAR ECUACIONES
	//Xm=400=cos(Phi*Phirad)*V*((sin(Phi*Phirad)*V)/g);   (400*g/(cos(Phi*Phirad)*V)*(sin(Phi*Phirad)*V))   400*g/(V*V*cos(Phi*Phirad)*sin(Phi*Phirad))=1   sqrt(400*g /(cos(Phi*Phirad)*sin(Phi*Phirad))=V
	//-----V=sqrt(400*g/(cos(Phi*Phirad)*sin(Phi*Phirad));
	//Ym=(Yo=0)+sin(Phi*Phirad)*V*tpisoinc-(g/2)*pow(tpisoinc,2);
	//Vx=cos(Phi*Phirad)*V;
	//Vy=0=sin(Phi*Phirad)*V-g*tpisoinc;  tpisoinc= (sin(Phi*Phirad)*V)/g;
	
	//Xpiso=500=cos(Phi*Phirad)*V*(2*sin(Phi*Phirad)*V)/g;   Xpiso*g = pow(V,2) * sin(2*Phi*Phirad)    V= sqrt(500*g/(sin(2*Phi*Phirad)))   ((1/Phirad)*asin(Xpiso*g / pow(V,2)))/2 = Phi 
	//Ypiso=0=(Yo=0)+Vyo*((2*Vyo)/g)-(g/2)*pow((2*Vyo)/g,2);
	//0= (2/g)*pow(Vyo,2)- (2/g)*pow(Vyo,2)
	//Vxpiso=Vxo;
	//tpiso=(2*Vyo)/g
	
	//	Yinc=Yo+Vyo*t-(g/2)*pow(t,2);
	
	
	
	//---------------------------------------------- ecuaciones genericas
	X=Xo+Vxo*t;
	Y=Yo+Vyo*t-(g/2)*pow(t,2);
	Vx=Vxo;
	Vy=Vyo-g*t;
	// ------------------------------------------------- para establecer Yo con un tiempo dado
	//0=Yo+Vyo*tpisoinc-(g/2)*pow(tpisoinc,2);
	//Yo=-Vyo*tpisoinc+(g/2)*pow(tpisoinc,2);
	printf("La Yo es: %.2f \n",Yo);
	//----------------------------------------------- para tiempo y posicion max y una altura segun un X dado
	tm=-Vyo/(-g);	Ym=Yo+Vyo*tm-(g/2)*pow(tm,2);	Xm=Vxo*tm;	tinc=Xinc/Vx;	Yn=Yo+Vyo*tinc-(g/2)*pow(tinc,2);
	printf("La altura a los %.2f metros es %.2f \nEl tmax es: %.2f, el X e Y max son: (%.2f,%.2f) \n",Xinc,Yn,tm,Xm,Ym);
	
	//--------------------------------------------para la posicion en R2 con un angulo dado
	tinc2=(tan(Phiincrad)*Vx-Vyo)/(-g);
	Xinc2=Vxo*tinc2;	Yinc2=Yo+Vyo*tinc2-(g/2)*pow(tinc2,2);	Phiincgrad= Phiincrad * (180/PI);
	printf("Cuando el angulo vale %.2f, la posicion en (x,y) es : (%.2f,%.2f) \n",Phiincgrad,Xinc2,Yinc2);
	//---------------------------------------------para el tiempo cuando pasa por la altura de la que partio
	Yyo= (-Vyo+sqrt(pow(Vyo,2)-4*(-g/2)*0))/(2*(-g/2)); Yyo2= (-Vyo-sqrt(pow(Vyo,2)-4*(-g/2)*0))/(2*(-g/2));
	if(Yyo>Yyo2) 
	{
		printf("El tiempo en el que pasa por la altura de la azotea es: %.2f \n",Yyo);
	}
	else 
	{
		printf("El tiempo en el que pasa por la altura de la azotea es: %.2f \n",Yyo2);
	}
	//---------------------------------------------- para datos cuando toca el piso
	tpiso= (-Vyo+sqrt(pow(Vyo,2)-4*(-g/2)*Yo))/(2*(-g/2)); tpiso2= (-Vyo-sqrt(pow(Vyo,2)-4*(-g/2)*Yo))/(2*(-g/2));
	if(tpiso>tpiso2) 
	{
		Vypiso=Vyo-g*tpiso;	rap=sqrt(pow(Vypiso,2)+pow(Vx,2));	Xpiso=Vx*tpiso;
		printf("Cuando toca el piso, el tiempo es %.2f, la vel en Y es: %.2f, la rapidez es: %.2f y la dis horizantal es: %.2f \n",tpiso,Vypiso,rap,Xpiso);
	}
	else 
	{
		Vypiso=Vyo-g*tpiso2;	rap=sqrt(pow(Vypiso,2)+pow(Vx,2));	Xpiso=Vx*tpiso2;
		printf("Cuando toca el piso, el tiempo es %.2f, la vel en Y es: %.2f, la rapidez es: %.2f, la dis horizantal es: %.2f \n",tpiso2,Vypiso,rap,Xpiso);
	}
	//-------------------------------------------------------------
	getch();
	//--------------------------------------------------- para ver valores genericos en un tiempo dado
		printf("Ingrese el tiempo: ");
	scanf("%f",&t);
	X=Xo+Vxo*t;	Y=Yo+Vyo*t-(g/2)*pow(t,2);	Vx=Vxo;	Vy=Vyo-g*t;
	printf("El X es: %.2f \nEl Y es: %.2f \nEl Vy es: %.2f \nEl Vx es: %.2f \n",X,Y,Vy,Vx);
	//---------------------------------------------------
	getch();
}

