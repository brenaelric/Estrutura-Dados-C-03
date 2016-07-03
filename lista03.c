#include <stdlib.h>
#include <stdio.h>

typedef struct box Box;
struct box
{
	char conteudo;
	Box *proximo;
}*inicio, *novo, *temp1, *temp2;

Box *criabox(char letra)
{
	novo = malloc(sizeof(Box));
	novo->proximo = 0;
	novo->conteudo = letra;
	return novo;
}

Box *insere_inicio(Box *inicio, char letra)
{
	novo = criabox(letra);
	novo->proximo = inicio;
	return novo;
}

void insere_final(Box *inicio, char letra)
{
	temp1 = inicio;
	while (temp1->proximo != 0)
		temp1 = temp1->proximo;
	temp1->proximo = criabox(letra);
}

void insere_entre(Box* inicio, char letra, char priletra)
{
	temp1 = inicio;
	while (temp1->proximo != 0)
	{
		if (temp1->conteudo == priletra)
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
	while (temp1->proximo && temp1->proximo->proximo != 0)
		temp1 = temp1->proximo;
	free(temp1->proximo);
	temp1->proximo = 0;
}

Box *exclue_primeiro(Box *inicio)
{
	temp1 = inicio;
	inicio = inicio->proximo;
	free(temp1);
	return inicio;
}

Box *exclue_valor(Box *inicio, char letra)
{
'	if (inicio->conteudo == letra)
		return exclue_primeiro(inicio);
	temp1 = inicio;
	temp2 = temp1->proximo;
	while (temp2->proximo != 0)
	{
		if (temp2->conteudo == letra)
		{
			temp1->proximo = temp2->proximo;
			free(temp2);
			break;
		}
		temp1 = temp2;
		temp2 = temp1->proximo;
	}
	return inicio;
}

void imprime_lista(Box*inicio)
{
	temp1 = inicio;

	printf("A lista final e:\n");
	while (temp1->proximo != 0)
	{
		printf("%4c", temp1->conteudo);
		temp1 = temp1->proximo;
	}
	printf("%4c\n", temp1->conteudo);
}

int main()
{
	printf(" _________________________________________ \n");
	printf("| IFCE - Engenharia de Telecomunica��es   |\n");
	printf("| Estrutura de Dados - Prof. Ernani       |\n");
	printf("| Aluna: Brena Kesia                      |\n");
	printf("|_________________________________________|\n");

	inicio = criabox('A');
	imprime_lista(inicio);
	inicio = insere_inicio(inicio, 'B');
	imprime_lista(inicio);
	insere_final(inicio, 'C');
	imprime_lista(inicio);
	insere_final(inicio, 'D');
	imprime_lista(inicio);
	insere_entre(inicio, 'E', 'A');
	imprime_lista(inicio);
	insere_final(inicio, 'F');
	imprime_lista(inicio);
	inicio = insere_inicio(inicio, 'G');
	imprime_lista(inicio);
	exclue_ultimo(inicio);
	imprime_lista(inicio);
	inicio = exclue_primeiro(inicio);
	imprime_lista(inicio);
	insere_entre(inicio, 'H', 'A');
	imprime_lista(inicio);
	inicio = exclue_valor(inicio, 'A');
	imprime_lista(inicio);
	insere_entre(inicio, 'I', 'E');
	imprime_lista(inicio);
	insere_final(inicio, 'J');
	imprime_lista(inicio);
	insere_entre(inicio, 'K', 'B');
	imprime_lista(inicio);
	inicio = exclue_valor(inicio, 'D');
	imprime_lista(inicio);
	inicio = exclue_valor(inicio, 'K');
	imprime_lista(inicio);
	inicio = exclue_valor(inicio, 'I');
	imprime_lista(inicio);
	inicio = exclue_valor(inicio, 'B');
	imprime_lista(inicio);
	insere_final(inicio, 'L');
	imprime_lista(inicio);

	return 0;
}
