#include <stdio.h> // Biblioteca de comunicação com o usuário
#include <stdlib.h> // Biblioteca de alocação em espaço de memória
#include <locale.h> // Biblioteca de alocação de texto por região
#include <string.h>// Biblioteca responsável por cuidar das stings

int registro() //função por cadastrar os usuários do sistema
{
	//inicio criação de variáveis/string
	 setlocale (LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char arquivo [40]; // início da criação de variáveis
	char cpf [40];
	char nome [40];
	char sobrenome [50];
	char cargo [50];  //final da criação de variáveis
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf);//Responsável por copiar os valores das strings
	
	FILE *file; //FILE = chamando a função *file= arquivo - cria o arquivo no banco de dados
	file = fopen(arquivo,"w");//w = write novo arquivo = file= fopen =cria o arquivo
	fprintf(file, "\nCPF:  "); //salva o nome do dado cadastrado
	fprintf(file,cpf); //salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nNome: ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome); //salvo o valor da variável
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
		printf ("\n Não foi possível localizar o arquivo informado\n");
	}
		printf ("\n Essas são as informações do usuário: \n" );
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
    
    printf("Digite o CPF do usuário que você deseja deletar: ", cpf);  
    scanf("%s", cpf);  
    
    printf("\nVocê tem certeza que deseja deletar o registro com CPF %s? (s/n): ", cpf);  
    scanf(" %c", &confirmacao); // O espaço antes de %c é para ignorar qualquer espaço em branco  
    
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
            printf("\nO usuário informado não se encontra em nosso banco de dados!\n"); 
			printf("\n"); 
        	fclose(file);
		}   
    }
    
	 	else 
	 	{	  
        printf("\nOperação cancelada.\n");  
    	printf("\n");
		}  
    
    	system("pause");
		system("cls");
}

int main ()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	char senhadigitada[10] = "a";
	int comparacao;
	
	printf(" ### Cartório da Ebac ### \n\n");
	while(1)//inicio do loop de validação da senha
	{
		printf("Login de administrador!\n\nDigite a sua senha: ");
		scanf("%s", senhadigitada); //armazena a senha na variavel 'senhadigitada'
		
		comparacao = strcmp(senhadigitada, "admin");//compara a variavel 'senha digitada' com a senha que o usuário inseriu
		if (comparacao ==0)//se acertar a senha o loop encerra e da sequencia no código
		{
			printf("\nAcesso Permitido!\n\n");
			system("pause");
			break;// encerra o loop da senha
		
		}
		else//se não acerta e ele retornar um valor diferente de 0 o loop continua até acertar a senha
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
	
        	printf("### Cartório da EBAC ###\n\n"); //Início do menu
	    	printf(" Escolha a opção desejada do menu\n\n");
	    	printf("\t1 - Registrar Nomes\n");
	    	printf("\t2 - Consultar Nomes\n");
	   		printf("\t3 - Deletar Nomes\n");
	    	printf("\t4 - Sair do Sistema\n\n");
	   		printf("Opção:");//Fim do menu
	
			scanf("%d", &opcao); // Armazenando a escolha do usuário
	
			system("cls"); // resonsável por limpar a tela 
	
	
		switch(opcao)//início da seleção do menu
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
	    
			case 4:
	   		printf("\n\nObrigado por utilizar o sistema de registro da EBAC! \n");
	    	return 0;
	    	break;
	    
	    
	    	default:
	    	printf("\tEssa opção não está disponível!\n");
			system("pause"); //Fim da seleção
			break;
			}
    	}
    return 0;	
	
					
		
}
