#include <stdlib.h>
#include <stdio.h>

typedef struct box Box;
struct box
{
	char conteudo;
	Box *proximo;
} *inicio, *novo, *temp1, *temp2;
