#include <stdio.h> // Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // Biblioteca de aloca��o em espa�o de mem�ria
#include <locale.h> // Biblioteca de aloca��o de texto por regi�o
#include <string.h>// Biblioteca respons�vel por cuidar das stings

int registro() //fun��o por cadastrar os usu�rios do sistema
{
	//inicio cria��o de vari�veis/string
	 setlocale (LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char arquivo [40]; // in�cio da cria��o de vari�veis
	char cpf [40];
	char nome [40];
	char sobrenome [50];
	char cargo [50];  //final da cria��o de vari�veis
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf);//Respons�vel por copiar os valores das strings
	
	FILE *file; //FILE = chamando a fun��o *file= arquivo - cria o arquivo no banco de dados
	file = fopen(arquivo,"w");//w = write novo arquivo = file= fopen =cria o arquivo
	fprintf(file, "\nCPF:  "); //salva o nome do dado cadastrado
	fprintf(file,cpf); //salvo o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nNome: ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome); //salvo o valor da vari�vel
	fclose(file); // fecha o arquivo	
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nSobrenome: ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	fflush(stdin);
	scanf("%[^\n]s", sobrenome);
	
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nCargo:  ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	fflush(stdin);
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fprintf (file, "\n\n");
	fclose(file);
	
	printf("\nRegistro salvo com sucesso!\n\n");  
    system("pause"); 
	system("cls");	
}

int consulta()
{
	setlocale (LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
		
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
		
	FILE *file;
	file = fopen(cpf, "r");
		
	if(file == NULL)
	{
		printf ("\n N�o foi poss�vel localizar o arquivo informado\n");
	}
		printf ("\n Essas s�o as informa��es do usu�rio: \n" );
		while (fgets (conteudo, 200, file) != NULL)
	{ 	
		printf ("%s", conteudo);
	} 
	fclose(file);
	system ("pause");
	system ("cls");
}

int deletar()
{
	setlocale (LC_ALL, "Portuguese");
	
	char cpf[40];  
    char confirmacao;  
    
    printf("Digite o CPF do usu�rio que voc� deseja deletar: ", cpf);  
    scanf("%s", cpf);  
    
    printf("\nVoc� tem certeza que deseja deletar o registro com CPF %s? (s/n): ", cpf);  
    scanf(" %c", &confirmacao); // O espa�o antes de %c � para ignorar qualquer espa�o em branco  
    
    if (confirmacao == 's' || confirmacao == 'S')
	{  
        if (remove(cpf) == 0) 
		{  
            printf("\nO registro foi deletado com sucesso!\n");  
            printf("\n");
        }
        
		else
		{  
		 	FILE *file;
			file = fopen(cpf, "r");
            printf("\nO usu�rio informado n�o se encontra em nosso banco de dados!\n"); 
			printf("\n"); 
        	fclose(file);
		}   
    }
    
	 	else 
	 	{	  
        printf("\nOpera��o cancelada.\n");  
    	printf("\n");
		}  
    
    	system("pause");
		system("cls");
}

int main ()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	char senhadigitada[10] = "a";
	int comparacao;
	
	printf(" ### Cart�rio da Ebac ### \n\n");
	while(1)//inicio do loop de valida��o da senha
	{
		printf("Login de administrador!\n\nDigite a sua senha: ");
		scanf("%s", senhadigitada); //armazena a senha na variavel 'senhadigitada'
		
		comparacao = strcmp(senhadigitada, "admin");//compara a variavel 'senha digitada' com a senha que o usu�rio inseriu
		if (comparacao ==0)//se acertar a senha o loop encerra e da sequencia no c�digo
		{
			printf("\nAcesso Permitido!\n\n");
			system("pause");
			break;// encerra o loop da senha
		
		}
		else//se n�o acerta e ele retornar um valor diferente de 0 o loop continua at� acertar a senha
		{	
			printf("\nSenha incorreta!\n\nTente novamente!\n\n");
			system("pause");//pausa o sistema
			system("cls");
		}
}
		system("cls");
		while(1)//loop do menu
		{
		
        	setlocale (LC_ALL, "Portuguese"); //Definindo a linguagem
	
        	printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
	    	printf(" Escolha a op��o desejada do menu\n\n");
	    	printf("\t1 - Registrar Nomes\n");
	    	printf("\t2 - Consultar Nomes\n");
	   		printf("\t3 - Deletar Nomes\n");
	    	printf("\t4 - Sair do Sistema\n\n");
	   		printf("Op��o:");//Fim do menu
	
			scanf("%d", &opcao); // Armazenando a escolha do usu�rio
	
			system("cls"); // resons�vel por limpar a tela 
	
	
		switch(opcao)//in�cio da sele��o do menu
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
	    
			case 4:
	   		printf("\n\nObrigado por utilizar o sistema de registro da EBAC! \n");
	    	return 0;
	    	break;
	    
	    
	    	default:
	    	printf("\tEssa op��o n�o est� dispon�vel!\n");
			system("pause"); //Fim da sele��o
			break;
			}
    	}
    return 0;	
	
					
		
}
