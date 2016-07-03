#include <stdlib.h>
#include <stdio.h>

typedef struct box Box;
struct box
{
	char conteudo;
	Box *proximo;
} *inicio, *novo, *temp1, *temp2;

Box *criabox(char letra)
{
	novo = malloc(sizeof(Box));
	novo->proximo=0;
	novo->conteudo=letra;
	return novo;
}

Box *insere_inicio(Box *inicio, char letra)
{
	novo = criabox(letra);
	novo->proximo=inicio;
	return novo;
}

void insere_final(Box *inicio, char letra)
{
	temp1=inicio;
	while(temp1->proximo !=0)
		temp1 = temp1->proximo;
	temp1->proximo = criabox(letra);
}

void insere_entre(Box* inicio, char letra, char priletra)
{
	temp1=inicio;
	while(temp1->proximo !=0)
	{
		if(temp1->conteudo==priletra)
		{
			novo = criabox(letra);
			novo->proximo = temp1->proximo;
			temp1->proximo = novo;
			return;
		}
		temp1 = temp1->proximo;
	}
}

void exclue_ultimo(Box *inicio)
{
	temp1 = inicio;
	while(temp1->proximo && temp1->proximo->proximo !=0)
		temp1=temp1->proximo;
	free(temp1->proximo);
	temp1->proximo=0;
}

Box *exclue_primeiro(Box *inicio)
{
	temp1=inicio;
	inicio=inicio->proximo;
	free(temp1);
	return inicio;
}

Box *exclue_valor(Box *inicio, char letra)
{
	if(inicio->conteudo==letra)
		return exclue_primeiro(inicio);
	temp1=inicio;
	temp2=temp1->proximo;
	while(temp2->proximo !=0)
	{
		if(temp2->conteudo==letra)
		{
			temp1->proximo = temp2->proximo;
			free(temp2);
		}
		temp1=temp2;
		temp2=temp1->proximo;
	}
	return inicio;
}

int main()
{
	printf(" _________________________________________ \n");
	printf("| IFCE - Engenharia de Telecomunicações   |\n");
	printf("| Estrutura de Dados - Prof. Ernani       |\n");
	printf("| Aluna: Brena Kesia                      |\n");
	printf("|_________________________________________|\n");


	inicio = criabox('A');
	inicio = insere_inicio(inicio, 'B');
	insere_final(inicio, 'C');
	insere_final(inicio, 'D');
	insere_entre(inicio, 'E', 'A');
	insere_final(inicio, 'F');
	inicio = insere_inicio(inicio, 'G');
	exclue_ultimo(inicio);
	inicio = exclue_primeiro(inicio);
	insere_entre(inicio, 'H', 'A');
	inicio = exclue_valor(inicio, 'A');
	insere_entre(inicio, 'I', 'E');
	insere_final(inicio, 'J');
	insere_entre(inicio, 'K', 'B');
	exclue_valor(inicio, 'D');
	exclue_valor(inicio, 'K');
	exclue_valor(inicio, 'I');
	exclue_valor(inicio, 'B');
	insere_final(inicio, 'L');

	temp1=inicio;

	printf("A lista final e:\n");
	while(temp1->proximo!=0)
	{
		printf("%4c", temp1->conteudo);
		temp1=temp1->proximo;
	}
	printf("%4c", temp1->conteudo);

	return 0;
}
