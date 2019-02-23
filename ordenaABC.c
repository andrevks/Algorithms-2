#include <stdio.h>


void main(){
	int a,b,c,aux;
	printf("\n SEJA BEM VINDO/WELCOME !!"); 
	//ler os numeros desordenados
	printf("\n Digite três números: a b c: ");
	printf("\n Digite A: ");
	scanf("%d", &a);
	
	printf("\n Digite B: ");
	scanf("%d",&b);
	
	printf("\n Digite C: ");
	scanf("%d", &c);		
	
	//imprimir números antes
	printf("\n Números inseridos: %d %d %d:\n ",a,b,c);

	//Ordenação
	if(a>b || a>c){
	  //se A for maior entra no if   		
	   if(b>c){
	     aux = a;
	     a = c;
             c = aux;

	  }else{

	     aux = a;
	     a = b;
	     b = aux;
	  }
       }
	//senão comparamos somente os dois restantes	
	if(b>c){

	aux = b;
	b = c;
 	c = aux;
	}
	
	//imprimir os números de forma crescente
	printf("\n Os números em forma crescente: %d %d %d \n\n",a,b,c);
}

								

