#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() 
{
    setlocale(LC_ALL, "Portuguese");
    
    char continuar[3]; // Variável para verificar se o usuário deseja continuar
    
    do {
        // Criação das variáveis para armazenar informações do usuário
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

        printf("\nUsuário cadastrado com sucesso!\n");
        
        printf("\nDeseja adicionar mais um usuário? (Sim/Não): ");
        scanf("%s", continuar);

    } while (strcmp(continuar, "Sim") == 0 || strcmp(continuar, "sim") == 0);
    
    // Após sair do loop, o usuário pode voltar ao menu principal ou realizar outra ação
}

int consulta() 
{
    setlocale(LC_ALL, "Portuguese");
    
    char continuar[3]; // Variável para verificar se o usuário deseja continuar
    
    do {
        char cpf[40];
        char conteudo[200];
        
        printf("Digite o CPF a ser consultado: ");
        scanf("%s", cpf);
        
        FILE *file;
        file = fopen(cpf, "r");
        
        if (file == NULL) 
		{
            printf("CPF não cadastrado!\n");
        }
        
        while (fgets(conteudo, 200, file) != NULL) 
		{
            printf("\nEssas são as informações do usuário: ");
            printf("%s", conteudo);
            printf("\n\n");
        }
        
        fclose(file);
        
        printf("Deseja consultar outro CPF? (Sim/Não): ");
        scanf("%s", continuar);

    } while (strcmp(continuar, "Sim") == 0 || strcmp(continuar, "sim") == 0);
    
}

int deletar() 
{
    char continuar[3]; // Variável para verificar se o usuário deseja continuar
    
    do {
        char cpf[40];
        
        printf("Digite o CPF a ser DELETADO: ");
        scanf("%s", cpf);
        
        FILE *file;
        file = fopen(cpf, "r");
        
        if (file == NULL) 
		{
            printf("\nCPF não cadastrado!\n\n");
        }
        
        remove(cpf);
        
        fclose(file);
        
        if (file != NULL) 
		{
            printf("\nUsuário deletado com sucesso!\n\n");
        }
        
        printf("Deseja deletar outro CPF? (Sim/Não): ");
        scanf("%s", continuar);

    } while (strcmp(continuar, "Sim") == 0 || strcmp(continuar, "sim") == 0);
}

int main() 
{
    int opcao = 0; // Definindo as variáveis
    int x = 1;

    for (x = 1; x == 1;) 
	{

        system("cls"); // Responsável por limpar a tela

        setlocale(LC_ALL, "Portuguese"); // Definindo a Linguagem

        printf("### Cartório da EBAC ###\n\n\n"); // Início do menu
        printf("Escolha a opção desejada do menu:\n\n\n");
        printf("\t1- Registrar Usuário\n");
        printf("\t2- Consultar Usuário\n");
        printf("\t3- Deletar Usuário\n");
        printf("\t4- Sair do Programa\n\n\n"); // Opção para sair do programa
        printf("Opção: "); // Final do Menu

        scanf("%d", &opcao); // Armazenando a escolha do usuário

        system("cls"); // Limpar a tela após a seleção da opção

        switch (opcao) 
		{ // Início da seleção do menu
            case 1:
                registro(); // Chamada de funções
                break;

            case 2:
                consulta();
                break;

            case 3:
                deletar();
                break;

            case 4: // Opção para sair do programa
                printf("Programa encerrado. Dados salvos com sucesso!\n\n");
                return 0;

            default:
                printf("Esta opção não está disponível.\n\n");
                system("pause");
                break;

        } // Fim da seleção
    }
}
