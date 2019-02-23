#include <stdio.h>
#include <math.h>

void main(){
     //declaração de variáveis
     int a,b,c;
     float D;
		
	
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");		
	printf("\n SEJA BEM VINDO/WELCOME");
	printf("\n CALCULE A DIAGONAL DO PARALELEPIPEDO!");
        printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");

 	printf("\n Digite a Aresta1, Aresta2 e Altura: ");
	//leia valores
	printf("\n Digite Aresta 1: ");
	scanf("%d",&a);

	printf("\n Digite Aresta 2: ");
	scanf("%d",&b);
	
	printf("\n Digite Altura: ");
	scanf("%d", &c);

	//imprimir valores 
	printf("\n Valores digitados=> A1:%d, A2:%d, Altura:%d ",a,b,c);

	//diagonal principal
	D = sqrt(a*a+ b*b + c*c);
	
	//imprima diagonal
	printf("\n O valor da diagonal do paralelepípedo: %.2f \n",D);


} 
	
	

