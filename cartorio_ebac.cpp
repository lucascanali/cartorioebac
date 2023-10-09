#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final cria��o de vari�veis/string

	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa ESCREVER
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o Nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o Sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o Cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");	
	
	if(file == NULL)
	{
		printf("CPF n�o cadastrado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser DELETADO: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("\nCPF n�o cadastrado!\n\n");
		system("pause");
	}
	
	remove(cpf);
	
	if(file != NULL)
	{
		
		printf("\nUsu�rio deletado com sucesso!\n\n");
		system("pause");
 	}
	
}

int main()
{
	int opcao=0; //Definindo as vari�veis
	int x=1;
	
	for (x=1;x=1;)
	{
	
		system("cls"); //respons�vel por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
		printf("### Cart�rio da EBAC ###\n\n\n"); //Inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n\n");
		printf("\t1- Registrar Aluno\n");
		printf("\t2- Consultar Aluno\n");
		printf("\t3- Deletar Aluno\n\n\n"); 
		printf("Op��o: ");//Final do Menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
		system("cls"); //Limpar a tela ap�s a sele��o da op��o
		
		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2: 
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Esta op��o n�o est� dispon�vel.\n\n");
			system("pause");
			break;
			
		} //fim da sele��o
	}
}
