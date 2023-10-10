#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() 
{
    setlocale(LC_ALL, "Portuguese");
    
    char continuar[3]; // Vari�vel para verificar se o usu�rio deseja continuar
    
    do {
        // Cria��o das vari�veis para armazenar informa��es do usu�rio
        char arquivo[40];
        char cpf[40];
        char nome[40];
        char sobrenome[40];
        char cargo[40];

        printf("Digite o CPF a ser cadastrado: ");
        scanf("%s", cpf);
        strcpy(arquivo, cpf);

        FILE *file;
        file = fopen(arquivo, "w");
        fprintf(file, cpf);
        fclose(file);

        file = fopen(arquivo, "a");
        fprintf(file, ", ");
        fclose(file);

        printf("Digite o Nome a ser cadastrado: ");
        scanf("%s", nome);

        file = fopen(arquivo, "a");
        fprintf(file, nome);
        fclose(file);

        file = fopen(arquivo, "a");
        fprintf(file, ", ");
        fclose(file);

        printf("Digite o Sobrenome a ser cadastrado: ");
        scanf("%s", sobrenome);

        file = fopen(arquivo, "a");
        fprintf(file, sobrenome);
        fclose(file);

        file = fopen(arquivo, "a");
        fprintf(file, ", ");
        fclose(file);

        printf("Digite o Cargo a ser cadastrado: ");
        scanf("%s", cargo);

        file = fopen(arquivo, "a");
        fprintf(file, cargo);
        fclose(file);

        printf("\nUsu�rio cadastrado com sucesso!\n");
        
        printf("\nDeseja adicionar mais um usu�rio? (Sim/N�o): ");
        scanf("%s", continuar);

    } while (strcmp(continuar, "Sim") == 0 || strcmp(continuar, "sim") == 0);
    
    // Ap�s sair do loop, o usu�rio pode voltar ao menu principal ou realizar outra a��o
}

int consulta() 
{
    setlocale(LC_ALL, "Portuguese");
    
    char continuar[3]; // Vari�vel para verificar se o usu�rio deseja continuar
    
    do {
        char cpf[40];
        char conteudo[200];
        
        printf("Digite o CPF a ser consultado: ");
        scanf("%s", cpf);
        
        FILE *file;
        file = fopen(cpf, "r");
        
        if (file == NULL) 
		{
            printf("CPF n�o cadastrado!\n");
        }
        
        while (fgets(conteudo, 200, file) != NULL) 
		{
            printf("\nEssas s�o as informa��es do usu�rio: ");
            printf("%s", conteudo);
            printf("\n\n");
        }
        
        fclose(file);
        
        printf("Deseja consultar outro CPF? (Sim/N�o): ");
        scanf("%s", continuar);

    } while (strcmp(continuar, "Sim") == 0 || strcmp(continuar, "sim") == 0);
    
}

int deletar() 
{
    char continuar[3]; // Vari�vel para verificar se o usu�rio deseja continuar
    
    do {
        char cpf[40];
        
        printf("Digite o CPF a ser DELETADO: ");
        scanf("%s", cpf);
        
        FILE *file;
        file = fopen(cpf, "r");
        
        if (file == NULL) 
		{
            printf("\nCPF n�o cadastrado!\n\n");
        }
        
        remove(cpf);
        
        fclose(file);
        
        if (file != NULL) 
		{
            printf("\nUsu�rio deletado com sucesso!\n\n");
        }
        
        printf("Deseja deletar outro CPF? (Sim/N�o): ");
        scanf("%s", continuar);

    } while (strcmp(continuar, "Sim") == 0 || strcmp(continuar, "sim") == 0);
}

int main() 
{
    int opcao = 0; // Definindo as vari�veis
    int x = 1;

    for (x = 1; x == 1;) 
	{

        system("cls"); // Respons�vel por limpar a tela

        setlocale(LC_ALL, "Portuguese"); // Definindo a Linguagem

        printf("### Cart�rio da EBAC ###\n\n\n"); // In�cio do menu
        printf("Escolha a op��o desejada do menu:\n\n\n");
        printf("\t1- Registrar Usu�rio\n");
        printf("\t2- Consultar Usu�rio\n");
        printf("\t3- Deletar Usu�rio\n");
        printf("\t4- Sair do Programa\n\n\n"); // Op��o para sair do programa
        printf("Op��o: "); // Final do Menu

        scanf("%d", &opcao); // Armazenando a escolha do usu�rio

        system("cls"); // Limpar a tela ap�s a sele��o da op��o

        switch (opcao) 
		{ // In�cio da sele��o do menu
            case 1:
                registro(); // Chamada de fun��es
                break;

            case 2:
                consulta();
                break;

            case 3:
                deletar();
                break;

            case 4: // Op��o para sair do programa
                printf("Programa encerrado. Dados salvos com sucesso!\n\n");
                return 0;

            default:
                printf("Esta op��o n�o est� dispon�vel.\n\n");
                system("pause");
                break;

        } // Fim da sele��o
    }
}
