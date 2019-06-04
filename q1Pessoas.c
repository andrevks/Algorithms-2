/*Aluno:André Geraldo, Eng. da Computação. Professor Dr Ruy de oliveira. Algoritmo com uso de arquivo csv, em cada linha conterá 
os campos: nome,dia aniversário e meses. O objetivo é mostrar durante o ano todo quem são os aniversariantes de cada mês, exibindo
o nome e o dia, faça um teste com um conjunto de 15 pessoas*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//declaração registro/struct
typedef struct{
	char nome[30];
	int dia;
	int mes;

}pessoa;



//declaração de subrotinas
void cadastrar();
void listar();
void mostrarMes();
void mes();


//declaração de variáveis globais
int lido = 0,tam=0,i=0;
pessoa pessoas[15];//vetor de registro

//ponteiro global para arquivo
FILE *arq;


void main(){

	int opc;

	//começo do menu e leitura da opção
	do{
		printf("====================================================\n");
		printf("\n    		  MENU -  RIHAPPY  \n");
		printf("\n===================================================\n");
		printf("\n ALGORITMO PARA CADASTRO DE ANIVERSARIANTES \n");
		printf("\n 1: CADASTRAR PESSOAS\n");
		printf("\n 2: LISTAR PESSOAS \n");
		printf("\n 3: LISTAR ANIVERSARIANTES DO ANO PELOS MESES \n");
		printf("\n 4: SAIR \n");
		printf("\n DIGITE>>>>>");
		  scanf(" %d",&opc);


		switch(opc){
			case 1:
			   cadastrar();
			   break;
			case 2:
			   listar();
			   break;
			case 3:
			   mostrarMes();
			   break;
			case 4:
		       printf("\nTENHA UM BOM DIA\n");
			   break;
			default:
			   printf("\nDIGITE UM VALOR VÁLIDO\n");
			   break;

		}
	}while(opc != 4);//só termina quando for 4



}
//caso 1
void cadastrar(){
	system("clear");
	//declaração de variáveis
	char nome[30],dia[3],mes[3];

	//abertura arquivo
	arq = fopen("aniversariantes.txt","a");

	//teste da abertura do arquivo
		if(arq == NULL){
			printf("\nHÁ UM PROBLEMA NA ABERTURA DO ARQUIVO\n");
		}else{


			printf("=============================================================================\n");
			printf("\n                    CADASTRO DE ANIVERSARIANTES      \n");
			printf("\n| NOME | DIA | MES |\n");
			printf("\nDIGITE(RESPECTIVAMENTE)>>>>>>");
				scanf("%s %s %s",nome,dia,mes);
				//foi lido e agora é impresso no arquivo

				fprintf(arq,"%s;%s;%s;\n",nome,dia,mes);
				//o delimitador usado é o ";"

				//fechamento do arquivo
				fclose(arq);

		}

}

//caso 2
void listar(){
	system("clear");
	//declaração de variáveis
	char linha[100],*str,d[2] = ";";
	i=0;
	//abertura do arquivo
	arq = fopen("aniversariantes.txt","r");

		//teste da abertura do arquivo
		if(arq == NULL){
			printf("\nHÁ UM PROBLEMA NA ABERTURA DO ARQUIVO\n");
		}else{
				lido =1;//garante que foi lido
				
				//apresentação, dados serão coletados para um registro e impressos na tela 
				printf("===================================PESSOAS CADASTRADAS====================================\n");
				printf("%s %10s %9s\n","NOME", "DIA", "MES");

				while(!feof(arq)){
					//str aponta para o inicio da linha
					//a linha do arquivo é mandada para a string "linha"
					str = fgets(linha,100,arq);

					if(str != NULL && linha !="\n" && linha !="\0"){
						//o strtok recebe o ponteiro que aponta para a atual linha, e pega a informação até ";"
						//d é o delimitador e a primeira chamada pega o primeiro item do arq

						strcpy(pessoas[i].nome, strtok(str,d));
						pessoas[i].dia = atoi(strtok(NULL,d));//quando passamos os null, continuamos na mesma linha
						pessoas[i].mes = atoi(strtok(NULL,d));//até o último
						
						

						//impressão dos dados na tela
						printf("\n%s %9d %9d \n",pessoas[i].nome,pessoas[i].dia,pessoas[i].mes);

						i++;
					}
				}

				//fechamento do arquivo
				fclose(arq);
				tam = i-1;
		}
}

//caso 3

void mostrarMes(){
	system("clear");
	//declaração de variáveis
	char tipo[30];
	int imp=0;
	i = 0;

	//só será permitida a exibição dos meses após ter sido listado e passado para o registro

	//teste de leitura
	if(lido == 0){
		printf("\nPRIMEIRO LEIA O ARQUIVO\n");
	}else{

			printf("===================================ANIVERSARIANTES DO ANO====================================\n");
			while(i<=12){

				mes(i);

				i++;
			}

			
			//fechamento do arquivo
			fclose(arq);
	}
}


void mes(int mes){
	//declaração de variáveis
	int cont=0,imp=0;

	

	//comparação para saber os meses
	while(cont<=tam){

		if(pessoas[cont].mes == mes){
			if(imp == 0){
				printf("\n----------MES:%d----------\n",mes);
				printf("\n%s %9s \n","NOME", "DIA");
				imp=1;
			}
			printf("\n%s %8d\n",pessoas[cont].nome,pessoas[cont].dia);

		}

			cont++;
	}
}


