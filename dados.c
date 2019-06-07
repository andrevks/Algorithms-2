
/*Aluno: André Geraldo,Engenharia da computação. Professor Ruy de Oliveira.
O algoritmo tem como objetivo criar um arquivo textp, com os campos, nome,
sexo, cor dos olhos,altura e peso. E a tarefa é separar esse arquivo em dois 
binários,um para o sexo masculino e outro para o feminino*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//definição de constante
#define TAM 100

//declaração registro/struct
typedef struct{
	char nome[30];
	char sexo[2];
	char olhos[2];
	float altura;
	float peso;

}DADO;

//declaração de subrotinas
void cadastrar();
void ler();
void separar();

//declaração de variáveis globais
int lido = 0,tam=0,opc,i;
DADO dado;
DADO dados[TAM];//vetor de registro 

//criação de ponteiro para os arquivos
FILE *arqTexto,*arq2,*arq3;


void main()
{

	

	//declaração de variáveis
	int opc;

	//começo do menu

	do{
		//aprensentação das opções
		printf("\n===============================\n");
		printf("\n    MENU - PESQUISA IBGE       \n");
		printf("\n===============================\n");
		printf("\n ALGORITMO PARA COLETA DE DADOS\n");
		printf("\nESCOLHA A OPÇÃO QUE DESEJAR:   \n");
		printf("\n1:CADASTRAR INDIVÍDUO\n");
		printf("\n2:LER PESSOAS CADASTRADAS\n");
		printf("\n3:SEPARAR DADOS EM DOIS ARQUIVOS,PARA O SEXO FEMININO E MASCULINO\n");
		printf("\n4:SAIR\n");
		printf("\nDIGITE>>");
			scanf(" %d",&opc); //leitura da opcao

			//uso do switch para chamar subrotinas
			switch(opc){
				case 1:
					system("clear");
					cadastrar();
					break;
				case 2:
					system("clear");
					ler();
					break;
				case 3:
					system("clear");
					separar();
					break;
				case 4:
					system("clear");
					printf("\n===============================\n");		
					printf("\nTENHA UM BOM DIA!!\n");
					printf("\n===============================\n");
					break;
				default:
					printf("\n================================\n");		
					printf("\nPOR FAVOR, DIGITE UM VALOR VÁLIDO\n");
					printf("\n================================\n");
			}


	}while( opc != 4);
}
//caso 1
void cadastrar(){
	//declaração de variáveis
	char nome[30],sexo[2],olhos[2],altura[4],peso[4];

	//abertura do arquivo
	arqTexto = fopen("dados.txt","a");

	//teste da abertura
	if(arqTexto == NULL){
		printf("\nHá um erro na abertura do arquivo\n");
	}else{
		//leitura de valores
		printf("\n================================\n");
		printf("\n            CADASTRO 			  \n");
		printf("\nDIGITE: NOME| SEXO(M/F)| COR DOS OLHOS| ALTURA| PESO|, RESPECTIVAMENTE\n");
			scanf(" %s %s %s %s %s",nome,sexo,olhos,altura,peso);

			//então, é feita a escrita no arquivo do que foi "coletado"
			//a linha será escrita com o delimitador ";"	
			fprintf(arqTexto,"%s;%s;%s;%s;%s;\n",nome,sexo,olhos,altura,peso);

			//fechamento do arquivo
			fclose(arqTexto);
	}
}

//caso 2
void ler(){
	//definição de variáveis 
	char linha[100],*str;//ponteiro que receberá a linha do arq;
	const char d[2] = ";";//caracter usado para separação dos campos, neste caso ";"
	i = 0;

	//abertura do arquivo
	arqTexto = fopen("dados.txt","r");

	//teste da abertura do arquivo
	if(arqTexto == NULL){

		printf("\n\n Erro! Problema ao tentar abrir o arquivo");

	}else{

		lido=1;//quando for lido pelo menos uma vez recebe 1
		printf("\n=======================LIDOS OS SEQUINTES INDIVÍDUOS========================\n");
		printf("\n%s %30s %10s %10s %10s\n","NOME"," SEXO(M/F)","COR DOS OLHOS(A,B,C,D)"," ALTURA(M)","PESO(KG)" );
		do{

			str = fgets(linha,100,arqTexto); //lê um linha começando da primeira

			//para entender melhor o funcionamento do fgets:

			/*	linha = onde os dados da linha do arquivo serão armazenados
				50= o tamanho limite de bytes ou será buscado até o \n
				arqTexto = o apontador do arquivo

				fgets = irá abrir o arq apontado por arqTextp, percorrerá toda a linha do primeiro
				caracter até \n ou até o limite "100" e atribuirá a string do arquivo para a string "linha".

				o valor retornado armazenado em str é uma string,então quando chegarmos ao final
				do arquivo o valor "NULL" é retornado*/

			if(str != NULL){//então buscamos até NULL ou ""

				/*usamos o strok que recebe a string e transfoma o primeiro 
				elemento até o deliminitador ";" e coloca um "\0" no lugar,
				após a primeira passagem da string, quando passamos "NULL" 
				como paramêtro, ele continua a pegar o restante dos elementos
				da linha */

				strcpy(dados[i].nome, strtok(str,d));//pega o primeiro elemento da linha e passa dps da conversão para o vetor
				strcpy(dados[i].sexo, strtok(NULL,d));//segundo elemento
				strcpy(dados[i].olhos, strtok(NULL,d));
				dados[i].altura = atof(strtok(NULL,d));
				dados[i].peso = atof(strtok(NULL,d));
				
				//impressão dos dados que foram para o registro
				printf("\n%s %25s %10s %17.2f %11.2f\n",dados[i].nome,dados[i].sexo,
							dados[i].olhos,dados[i].altura,dados[i].peso );

				i++;

			}


		}while(str != NULL);//repete até o final do arquivo

			fclose(arqTexto);//fechamento do arquivo

			tam = i-1;
				//aviso
			printf("\n LEITURA BEM SUCEDIDA!\n");

	}


}

//caso 3
void separar(){
	//declaração de variáveis
	i =0;


	//testa se foi lido
	if(lido == 0){
		printf("\nPRIMEIRO LEIA O ARQUIVO\n");

	}else{
		//abertura de 2 arquivos do tipo binário
		//cujo ponteiros foram declarados de maneira global
			arq2 = fopen("masculino","wb");	
			arq3 = fopen("feminino","wb");

			//teste de abertura
			if(arq2 == NULL || arq3 == NULL){
				printf("\nHá UM PROBLEMA NA ABERTURA DO ARQUIVO\n");
			}else{
					do{
						if(!strcmp(dados[i].sexo,"M")){

							//escreve o registro com o sexo masculino no novo arquivo
							fwrite(&dados[i],sizeof(DADO),1,arq2);
						}
						if(!strcmp(dados[i].sexo,"F")){

							//escreve o registro com o sexo masculino no novo arquivo;
							fwrite(&dados[i],sizeof(DADO),1,arq3);
						}


							i++;
					}while(i<=tam);

						//fechamento dos arquivos
						fclose(arq2);
						fclose(arq3); 	

						//essa parte não foi pensada no algoritmo, entretanto,isso é uma perfumaria
						//apenas achei interessante mostrar diretamente os dados do arquivo

						//abertura dos arquivos em modo leitura
						arq2 = fopen("masculino","r");	
						arq3 = fopen("feminino","r");

					
					//impressão do arquivo Masculino e Feminino
					printf("\n========================EXIBIÇÃO DOS ARQUIVOS BINÁRIOS======================\n");
					printf("\nMASCULINO:\n");
					printf("\n%s %30s %10s %10s %10s\n","NOME"," SEXO(M/F)","COR DOS OLHOS"," ALTURA","PESO" );
					
						while(!feof(arq2)){
							fread(&dado,sizeof(DADO),1,arq2);//pegando dados em linha do arquivo

							if(feof(arq2))break;
							//imprimindo para o usuário
							printf("\n%s %25s %10s %17.2f %11.2f\n",dado.nome,dado.sexo,dado.olhos,dado.altura,dado.peso);
						}

					printf("\n================================================");	

					//impressão do feminino
					printf("\nFEMININO:\n");
					printf("%s %30s %10s %10s %10s\n","NOME"," SEXO(M/F)","COR DOS OLHOS"," ALTURA","PESO" );

						while(!feof(arq3)){

							fread(&dado,sizeof(DADO),1,arq3);//pegando dados em linha do arquivo

							if(feof(arq3))break;
							//imprimindo para o usuário
							printf("\n%s %25s %10s %17.2f %11.2f\n",dado.nome,dado.sexo,dado.olhos,dado.altura,dado.peso);
						}

					printf("\n================================================\n");
					//fechamento dos arquivos
							fclose(arq2);
							fclose(arq3);

		    }	
	}
}
