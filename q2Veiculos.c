/*Aluno: André Geraldo, Eng. da Computação. Professor Dr Ruy de Oliveira. Algoritmo com uso de arquivo csv para cadastro 
de veiculos de uma locadora, os campos de cada linha conterão: placa,chassi,modelo,ano,combustível,cor,km,media consumo,gastos 
manutenção.o objetivo é implementar as seguintes funcionalidades: inserir dados no arquivo, listar todos os carros da locadora,
listar carros por combustível,mostrar gasto total com manutenção da frota e maior e menor média de consumo*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//declaração registro/struct
typedef struct{
	char placa[30];
	int chassi;
	char modelo[30];
	int ano;
	char comb[30];
	char cor[30];
	float km;
	float Mcons;
	float GManut;

}carro;



//declaração de subrotinas
void inserir();
void listar();
void listarComb();
void gasto();
void MaiorMenor();

//declaração de variáveis globais
int lido = 0,tam=0,i=0;
carro car[100];//vetor de registro

//ponteiro global para arquivo
FILE *arq;


void main(){

	int opc;

	//começo do menu e leitura da opção
	do{
		printf("====================================================\n");
		printf("\n    		  MENU -  RENT CARS   \n");
		printf("\n===================================================\n");
		printf("\n ALGORITMO PARA CADASTRO DE VEÍCULOS \n");
		printf("\n 1: INSERIR DADOS\n");
		printf("\n 2: LISTAR CARROS \n");
		printf("\n 3: LISTAR CARROS POR TIPO DE COMBUSTÍVEL \n");
		printf("\n 4: MOSTRAR GASTO TOTAL DA MANUTENÇÃO DA FROTA \n");
		printf("\n 5: MOSTRAR CARRO COM MAIOR E MENOR MÉDIA DE CONSUMO\n");
		printf("\n 6: SAIR \n");
		printf("\n DIGITE>>>>>");
		  scanf(" %d",&opc);


		switch(opc){
			case 1:
			   inserir();
			   break;
			case 2:
			   listar();
			   break;
			case 3:
			   listarComb();
			   break;
			case 4:
			   gasto();
			   break;
			case 5:
			   MaiorMenor();
			   break;
			case 6:
		       printf("\nTENHA UM BOM DIA\n");
			   break;
			default:
			   printf("\nDIGITE UM VALOR VÁLIDO\n");
			   break;

		}
	}while(opc != 6);//só termina quando for 6



}
//caso 1
void inserir(){
	system("clear");
	//declaração de variáveis
	char p[30],c[30],m[30],ano[5],comb[30],cor[30],km[30],Mcons[30],GManut[30];

	//abertura arquivo
	arq = fopen("veiculos.txt","a");

	//teste da abertura do arquivo
		if(arq == NULL){
			printf("\nHÁ UM PROBLEMA NA ABERTURA DO ARQUIVO\n");
		}else{


			printf("=================================================================================================\n");
			printf("\nINSERÇÃO DE DADOS\n");
			printf("\n|PLACA|CHASSI|MODELO|ANO|COMBUSTÍVEL|COR|KM|MÉDIA CONSUMO|GASTO MANUTENÇÃO|\n");
			printf("\nDIGITE(RESPECTIVAMENTE)>>>>>>");
				scanf("%s %s %s %s %s %s %s %s %s",p,c,m,ano,comb,cor,km,Mcons,GManut);
				//foi lido e agora é impresso no arquivo

				fprintf(arq,"%s;%s;%s;%s;%s;%s;%s;%s;%s;\n",p,c,m,ano,comb,cor,km,Mcons,GManut);
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
	arq = fopen("veiculos.txt","r");

		//teste da abertura do arquivo
		if(arq == NULL){
			printf("\nHÁ UM PROBLEMA NA ABERTURA DO ARQUIVO\n");
		}else{
				lido =1;//garante que foi lido
				//apresentação, dados serão coletados para um registro e impressos na tela 
				printf("===================================VEÍCULOS CADASTRADOS====================================\n");
				printf("%s %10s %10s %8s %18s %12s %12s %26s %20s\n","PLACA", "CHASSI", "MODELO", "ANO", "COMBUSTÍVEL", 
        "COR", "KM","MÉDIA CONSUMO", "GASTO MANUTENÇÃO");

				while(!feof(arq)){
					//str aponta para o inicio da linha
					//a linha do arquivo é mandada para a string "linha"
					str = fgets(linha,100,arq);

					if(str != NULL && linha !="\n" && linha !="\0"){
						//o strtok recebe o ponteiro que aponta para a atual linha, e pega a informação até ";"
						//d é o delimitador e a primeira chamada pega o primeiro item do arq

						strcpy(car[i].placa, strtok(str,d));
						car[i].chassi = atoi(strtok(NULL,d));//quando passamos os null, continuamos na mesma linha
						strcpy(car[i].modelo,strtok(NULL,d));//terceiro elemento...
						car[i].ano = atoi(strtok(NULL,d));
						strcpy(car[i].comb,strtok(NULL,d));
						strcpy(car[i].cor,strtok(NULL,d));
						car[i].km = atof(strtok(NULL,d));
						car[i].Mcons = atof(strtok(NULL,d));
						car[i].GManut = atof(strtok(NULL,d));//até o último

						//impressão dos dados na tela
						printf("\n%s %8d %10s %10d %15s %17s %15.2f %16.2f %16.2f\n",car[i].placa,car[i].chassi,car[i].modelo,car[i].ano,
            car[i].comb,car[i].cor,car[i].km,car[i].Mcons,car[i].GManut);

						i++;
					}
				}

				//fechamento do arquivo
				fclose(arq);
				tam = i-1;
		}
}

//caso 3

void listarComb(){
	system("clear");
	//declaração de variáveis
	char tipo[30];
	int imp=0;
	i = 0;

	//só será permitida a listagem por combustível após ter sido listado e passado para o registro

	//teste de leitura
	if(lido == 0){
		printf("\nPRIMEIRO LEIA O ARQUIVO\n");
	}else{

		//apresentação e leitura de variável
		printf("\n========================================\n");
		printf("\nPOR FAVOR, DIGITE O TIPO DE COMBUSTÍVEL DESEJADO\n");
			scanf(" %s",tipo);

			//busca por veículos com o mesmo combustível
			while(i<=tam){

				if(!strcmp(tipo,car[i].comb)){

					//apenas para organização, na hora da exibição
					if(imp == 0){
						printf("\n=============CARROS COM O COMBUSTÍVEL DO TIPO:%s===================\n",tipo);
						printf("%s %10s %10s %8s %18s %12s %12s %26s %20s\n","PLACA", "CHASSI", "MODELO", "ANO", "COMBUSTÍVEL",
            "COR", "KM","MÉDIA CONSUMO", "GASTO MANUTENÇÃO");
						imp = 1;
					}	

					//então imprimimos o carro
					printf("\n%s %8d %10s %10d %15s %17s %15.2f %16.2f %16.2f\n",
						car[i].placa,car[i].chassi,car[i].modelo,car[i].ano,car[i].comb,
						car[i].cor,car[i].km,car[i].Mcons,car[i].GManut);
				}

				i++;
			}

			//caso não houve nenhum veículo
			if(imp == 0) printf("\nDESCULPE, MAS NÃO FOI ENCONTRADO NENHUM VEÍCULO COM ESSE TIPO DE COMBUSTÍVEL\n");
			//fechamento do arquivo
			fclose(arq);
	}
}

//caso 4

void gasto(){
	system("clear");
	//declaração de variáveis
	float gasto=0;
	i=0;


	//só será permitida a listagem por combustível após ter sido listado e passado para o registro

	//teste de leitura
	if(lido == 0){
		printf("\nPRIMEIRO LEIA O ARQUIVO\n");
	}else{

			while(i<=tam){
				gasto +=car[i].GManut;//gasto da manutenção é acomulado
				i++;
				
			}
		
			//e assim o resultado é impresso
			printf("====================================================\n");
			printf("\n\tO GASTO TOTAL É: %.2f\n",gasto);
			printf("\n==================================================\n");

	}
}

//caso 5

void MaiorMenor(){
	system("clear");
	//declaração de variáveis
	float maior,menor;
	int pMA,pME;
	
	//só será permitida a listagem por combustível após ter sido listado e passado para o registro

	//teste de leitura
	if(lido == 0){
		printf("\nPRIMEIRO LEIA O ARQUIVO\n");
	}else{

		 maior = car[0].Mcons;//pega o primeiro para comparação
		 menor = car[0].Mcons;
		 pMA = 0;//pega a posição
		 pME = 0;
		 i=1;//para ser comparado a partir do segundo

		 while(i<=tam){

		 	//comparações são feitas
		 	if(car[i].Mcons > maior){
		 		maior = car[i].Mcons;
		 		pMA = i;
		 	}

		 	if(car[i].Mcons < menor){
		 		menor = car[i].Mcons;
		 		pME = i;
		 	}

		 	i++;


		 }

		 //exibição dos resultados
		 //maior
		 printf("============================VEÍCULO COM MAIOR MÉDIA DE CONSUMO======================================\n");
		 printf("%s %10s %10s %8s %18s %12s %12s %26s %20s\n","PLACA", "CHASSI", "MODELO", "ANO", "COMBUSTÍVEL", "COR", "KM","MÉDIA CONSUMO", "GASTO MANUTENÇÃO");
		 printf("\n%s %8d %10s %10d %15s %17s %15.2f %16.2f %16.2f\n",
		 	car[pMA].placa,car[pMA].chassi,car[pMA].modelo,car[pMA].ano,car[pMA].comb,car[pMA].cor,car[pMA].km,car[pMA].Mcons,car[pMA].GManut);
		 printf("\n--------------------------------------------------------------------------------------------------\n");

		 //menor
		 printf("\n============================VEÍCULO COM MENOR MÉDIA DE CONSUMO======================================\n");
		 printf("%s %10s %10s %8s %18s %12s %12s %26s %20s\n","PLACA", "CHASSI", "MODELO", "ANO", "COMBUSTÍVEL", "COR", "KM","MÉDIA CONSUMO", "GASTO MANUTENÇÃO");
		 printf("\n%s %8d %10s %10d %15s %17s %15.2f %16.2f %16.2f\n",
		 	car[pME].placa,car[pME].chassi,car[pME].modelo,car[pME].ano,car[pME].comb,car[pME].cor,car[pME].km,car[pME].Mcons,car[pME].GManut);
	 	


	}
}
