#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsável por cadastrar os usuários
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
	//inicio criaçõo de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criaçõo de variáveis/string

	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa ESCREVER
	fprintf(file,cpf); //salva o valor da variável
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
		printf("CPF não cadastrado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
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
		printf("\nCPF não cadastrado!\n\n");
		system("pause");
	}
	
	remove(cpf);
	
	if(file != NULL)
	{
		
		printf("\nUsuário deletado com sucesso!\n\n");
		system("pause");
 	}
	
}

int main()
{
	int opcao=0; //Definindo as variáveis
	int x=1;
	
	for (x=1;x=1;)
	{
	
		system("cls"); //responsável por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
		printf("### Cartório da EBAC ###\n\n\n"); //Inicio do menu
		printf("Escolha a opção desejada do menu:\n\n\n");
		printf("\t1- Registrar Aluno\n");
		printf("\t2- Consultar Aluno\n");
		printf("\t3- Deletar Aluno\n\n\n"); 
		printf("Opção: ");//Final do Menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usuário
	
		system("cls"); //Limpar a tela após a seleção da opção
		
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2: 
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Esta opção não está disponível.\n\n");
			system("pause");
			break;
			
		} //fim da seleção
	}
}
