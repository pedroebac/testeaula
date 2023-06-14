#include <stdio.h> //BarraBarra significa coment�rio: biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //Biblioteca de aloca��es de textos por regi�o
#include <string.h> //Biblioteca das strings

int registrar() //Fun��o de registrar os usu�rios no sistema
{
	//In�cio da cria��o de vari�veis[string]
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis[string]
	
	printf("Digite o CPF a ser cadastrado:\n"); //Coleta de infomorma��es do usu�rio
	scanf("%s", cpf); // %s refere-se as strings
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //FILE � a fun��o. *file � para criar o arquivo no banco de dados
	
	file = fopen(arquivo, "w"); //"w" significa "write" - cria o arquivo
	fprintf(file,"CPF: ");
	fprintf(file,cpf); //Salvar o valor da vari�vel
	fclose(file); //Fechar o arquivo
		
	file = fopen(arquivo, "a"); //Atualizar a informa��o
	fprintf(file," NOME: " );
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:\n");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file," SOBRENOME: " );
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:\n");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file," CARGO: ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: \n");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");	
}

int consultar() //Fun��o de Consultar
{
	setlocale(LC_ALL, "Portuguese"); 
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //"r" de "Read"
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel localizar o CPF");
	}
	
	while(fgets(conteudo, 200, file) != NULL);
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file);
	system("pause");
}
	
int deletar() //Fun��o de Deletar
{
	setlocale(LC_ALL, "Portuguese");
	char cpf [40];
	
	printf("Por favor, digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file==NULL);
	{
		printf("O usu�rio n�o consta no nosso banco de dados!\n");
		system("pause");
	}	
}
	
int main() //PRINCIPAL
{
	int opcao=0; //Definindo as vari�veis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	setlocale(LC_ALL, "Portuguese");
	printf("### Cart�rio da Escola ###\n\n");
	printf("Login de administrador!\n\nPor favor, digite sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
		{
		for(laco=1;laco=1;)
			{
			system("cls"); //Limpar a tela
		
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
			printf("### Cart�rio da Escola ###\n\n"); //In�cio do menu
			printf("Escolha a op��o desejada do menu:\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do sistema\n\n"); 
			printf("Qual � a op��o desejada? ");//Fim do menu
			scanf("%d", &opcao); //Armazenamento de informa��es do usu�rio
			system("cls"); //Limpar a tela
	
				switch(opcao) //In�cio da sele��o do menu
				{
				case 1:
				registrar(); //Chamada da fun��o "registrar"
				break;
		
				case 2:
				consultar(); //Chamada da fun��o "consultar"
				break;
		
				case 3:
				deletar(); //Chamada da fun��o "deletar"
				break;	
		
				case 4:
				printf("Obrigado por utilizar o sistema!");
				return 0;
				break;
		
				default: //Quando for diferente dos n�meros estabelecidos
				printf("Essa op��o n�o est� dispon�vel!\n");
				system("pause");
				break; 
				//Fim da sele��o das op��es
				}
			}
		}
	else
	printf("Senha incorreta!");		
}

