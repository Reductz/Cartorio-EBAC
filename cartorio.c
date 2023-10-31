#include <stdio.h> //Biblioteca de comunica��o com usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria (vari�veis)
#include <locale.h> //Biblioteca de aloca��es de texto por regi�o
#include <string.h>//Biblioteca respons�vel por cuidar das strings

int registrar(){ //Fun��o respons�vel por cadastrar os usu�rios no sistema	
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s serve para armazenar na string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Abrindo o arquivo com a fun��o write, para escrever
	fprintf(file,cpf); //Salva o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abrindo o arquivo e atualizando
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause");
}

int consultar(){ //Fun��o respons�vel por consultar os usu�rios no sistema	
	
	setlocale(LC_ALL,"Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL){
		printf("Arquivo n�o localizado. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar(){ //Fun��o respons�vel por deletar os usu�rios no sistema	
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL){
		printf("O usu�rio n�o se encontra no sistema. \n");
		system("pause");
	}
	
}

int main(){
	int opcao = 0; //Definindo vari�veis
	int x = 1;
	
	for(x=1;x=1;){
		
		system("cls");	
		
		setlocale(LC_ALL,"Portuguese"); //Definindo a Linguagem
	
		printf("\t---Cart�rio da EBAC--- \n"); //In�cio do Menu
		printf("\n\tEscolha uma op��o: \n\n");
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes \n");
		printf("\t3 - Deletar nomes \n");
		printf("\n\tOp��o: "); //Fim do Menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio (leia do portugol)
	
		system("cls"); //Limpando a tela
		
		switch(opcao){ //In�cio da sele��o
			case 1:
				registrar(); //Chamando as fun��es
			break;
			
			case 2:
				consultar();
			break;
			
			case 3:
				deletar();
			break;
			
						
			
			default:
				printf("Op��o indispon�vel, escolha uma op��o v�lida. \n");
				system("pause");
			break;
		}
	}
}
