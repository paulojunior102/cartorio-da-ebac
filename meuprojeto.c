#include <stdio.h> //biblioteca de comunicação com o usuário 
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsável por cuidar das strings

int registro() // função responsavel por cadastrar os usuarios
{
	// inicio da criação de variáveis/strings
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
	//final da criação de variaveis
		
		printf("\t\t\t\t\t|| Por favor, informe o cpf desejado: \n"); // coleta de dados
		scanf("%s" , cpf ); //%s refere-se a sting
		printf("========================================================================================================================\n\n");
		
		strcpy(arquivo, cpf); // responsavel por copiar os valores das strings
		
		FILE *file; // cria o arquivo
		file = fopen(arquivo,"w");
		fprintf(file,cpf); // salva o valor da variavel
		fclose(file); // fecha o arquivo
		
		file = fopen(arquivo, "a");
		fprintf(file,",");
		fclose(file);
		
		printf("\t\t\t\t\t|| Digite o nome a ser cadastrado:\n "); // coleta de dados
		scanf("%s",nome);
		printf("========================================================================================================================\n\n");
		
		file = fopen(arquivo, "a");
		fprintf(file,nome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file,",");
		fclose(file);
		
		printf("\t\t\t\t\t|| Digite o sobrenome a ser cadastrado:\n"); // coleta de dados
		scanf("%s",sobrenome);
		printf("========================================================================================================================\n\n");
		
		file = fopen(arquivo, "a");
		fprintf(file,sobrenome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file,",");
		fclose(file);
		
		printf("\t\t\t\t\t|| Informe o cargo a ser cadastrado:\n"); // coleta de dados
		scanf("%s",cargo);
		printf("========================================================================================================================\n\n");
		
		file = fopen(arquivo, "a");
		fprintf(file,cargo);
		fclose(file);
		
		system("pause");
	// fim da coleta de dados
}

int consultar()
{
	 setlocale(LC_ALL,"portuguese_brazil"); // disponibiliza os acentos
	
	//inicio da criação de variaveis
     char cpf[40];
     char conteudo[100];
    // fim da criação de variaveis
     printf("\n\t> Informe o CPF a ser consultado:"); // consultar os dados do usuario
     scanf("%s",cpf);
     printf("_______________________________________________________________________________________________________________________\n");
     
     FILE *file;
     file = fopen(cpf,"r");
     
     if(file == NULL)
     {
     	printf("Usuario não localizado,tente novamante\n"); 
	 }
	 
	 while(fgets(conteudo,200, file) != NULL)
	 {
	 	printf("\n\t> Essas são as informações do usuário:");
	 	printf("%s",conteudo);
	 	printf("\n\n");
	 }
	 system("pause");
}

int deletar()
{
	//inicio da criação de variaveis
	char cpf[40];
	// fim da criação de variaveis
	
	printf("\n\t>Informe o CPF a ser deletado:\n"); // identificar os dados do usuário
	scanf("%S", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Usuário não localizado, tente outro!\n");
		system("pause");
	}
}




int main()
{
	int opcao=0; // definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
	
	  setlocale(LC_ALL, "portuguese_brazil"); // definido linguagem
	
	    printf("\n\t\t\t\ <---===== Cartório da Escola Britânica de Artes Criativas e Tecnologia(EBAC) =====--->\n\n");
	    printf("\t\t\t\t\t\t <=== SEJA BEM VINDO ===>\n\n");
    	printf("------------------------------------------------------------------------------------------------------------------------\n\n");
    	printf("\t|| Olá, escolha a opção desejada :\n\n");
	    printf("\t(1) - Registrar nomes :\n\n");
     	printf("\t(2) - Consultar nomes :\n\n ");
    	printf("\t(3) - Deletar nomes :\n\n ");
	
    	scanf("%d" , &opcao); // armazenando a escolha do usuário
	
    	system("cls"); // responsavel por "linpar" a tela
    	
    	switch(opcao) // inicio da seleção
    	{
    		case 1:
    		registro(); // chamada de funções 
		    break;
		    
		    case 2:
		    consultar();
		    break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa opção não está disponivel!.Tente novamente!\n");
	    	system("pause");
			break; // fim da seleção 	
		}
    	
    	
	
   }
	
}
