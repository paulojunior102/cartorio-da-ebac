#include <stdio.h> //biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das strings

int registro() // fun��o responsavel por cadastrar os usuarios
{
	// inicio da cria��o de vari�veis/strings
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
	//final da cria��o de variaveis
		
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
	
	//inicio da cria��o de variaveis
     char cpf[40];
     char conteudo[100];
    // fim da cria��o de variaveis
     printf("\n\t> Informe o CPF a ser consultado:"); // consultar os dados do usuario
     scanf("%s",cpf);
     printf("_______________________________________________________________________________________________________________________\n");
     
     FILE *file;
     file = fopen(cpf,"r");
     
     if(file == NULL)
     {
     	printf("Usuario n�o localizado,tente novamante\n"); 
	 }
	 
	 while(fgets(conteudo,200, file) != NULL)
	 {
	 	printf("\n\t> Essas s�o as informa��es do usu�rio:");
	 	printf("%s",conteudo);
	 	printf("\n\n");
	 }
	 system("pause");
}

int deletar()
{
	//inicio da cria��o de variaveis
	char cpf[40];
	// fim da cria��o de variaveis
	
	printf("\n\t>Informe o CPF a ser deletado:\n"); // identificar os dados do usu�rio
	scanf("%S", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Usu�rio n�o localizado, tente outro!\n");
		system("pause");
	}
}




int main()
{
	int opcao=0; // definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
	
	  setlocale(LC_ALL, "portuguese_brazil"); // definido linguagem
	
	    printf("\n\t\t\t\ <---===== Cart�rio da Escola Brit�nica de Artes Criativas e Tecnologia(EBAC) =====--->\n\n");
	    printf("\t\t\t\t\t\t <=== SEJA BEM VINDO ===>\n\n");
    	printf("------------------------------------------------------------------------------------------------------------------------\n\n");
    	printf("\t|| Ol�, escolha a op��o desejada :\n\n");
	    printf("\t(1) - Registrar nomes :\n\n");
     	printf("\t(2) - Consultar nomes :\n\n ");
    	printf("\t(3) - Deletar nomes :\n\n ");
	
    	scanf("%d" , &opcao); // armazenando a escolha do usu�rio
	
    	system("cls"); // responsavel por "linpar" a tela
    	
    	switch(opcao) // inicio da sele��o
    	{
    		case 1:
    		registro(); // chamada de fun��es 
		    break;
		    
		    case 2:
		    consultar();
		    break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o est� disponivel!.Tente novamente!\n");
	    	system("pause");
			break; // fim da sele��o 	
		}
    	
    	
	
   }
	
}
