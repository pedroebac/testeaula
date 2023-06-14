#include <stdio.h> //BarraBarra significa comentário: biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço de memória
#include <locale.h> //Biblioteca de alocações de textos por região
#include <string.h> //Biblioteca das strings


	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");	
}

int consultar() //Função de Consultar
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
		printf("Não foi possível localizar o CPF");
	}
	
	while(fgets(conteudo, 200, file) != NULL);
	{
		printf("\nEssas são as informações do usuário: \n\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file);
	system("pause");
}
	
int deletar() //Função de Deletar
{
	setlocale(LC_ALL, "Portuguese");
	char cpf [40];
	
	printf("Por favor, digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file==NULL);
	{
		printf("O usuário não consta no nosso banco de dados!\n");
		system("pause");
	}	
}
	
int main() //PRINCIPAL
{
	int opcao=0; //Definindo as variáveis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	setlocale(LC_ALL, "Portuguese");
	printf("### Cartório da Escola ###\n\n");
	printf("Login de administrador!\n\nPor favor, digite sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
		{
		for(laco=1;laco=1;)
			{
			system("cls"); //Limpar a tela
		
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
			printf("### Cartório da Escola ###\n\n"); //Início do menu
			printf("Escolha a opção desejada do menu:\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do sistema\n\n"); 
			printf("Qual é a opção desejada? ");//Fim do menu
			scanf("%d", &opcao); //Armazenamento de informações do usuário
			system("cls"); //Limpar a tela
	
				switch(opcao) //Início da seleção do menu
				{
				case 1:
				registrar(); //Chamada da função "registrar"
				break;
		
				case 2:
				consultar(); //Chamada da função "consultar"
				break;
		
				case 3:
				deletar(); //Chamada da função "deletar"
				break;	
		
				case 4:
				printf("Obrigado por utilizar o sistema!");
				return 0;
				break;
		
				default: //Quando for diferente dos números estabelecidos
				printf("Essa opção não está disponível!\n");
				system("pause");
				break; 
				//Fim da seleção das opções
				}
			}
		}
	else
	printf("Senha incorreta!");		
}

