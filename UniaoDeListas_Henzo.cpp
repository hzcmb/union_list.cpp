#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct No{
	int info;
	struct No*prox;
}Lista;

bool isEmpty(Lista *p){
	if(p == NULL){
		return true;
	}
	else
	{
		return false;
	}
}

struct No * insereFinal(Lista *p, int x){
	Lista *novo, *aux;
	novo = (Lista *) malloc(sizeof(Lista));
	novo -> info = x;
	novo -> prox = NULL;
	if(isEmpty(p))
	{
		p = novo;
	} 
	else 
	{	
		aux = p;
		while(aux -> prox != NULL)
		{
			aux = aux -> prox;
		}
		aux -> prox = novo;
	}
	return p;
}

Lista * terceiraLista(Lista *L1, Lista *L2){
	Lista * L3 = NULL;
	while(L1 != NULL)
	{
		L3 = insereFinal(L3, L1 -> info);
		L1 = L1 -> prox;
	}
	while(L2 != NULL)
	{
		L3 = insereFinal(L3, L2 -> info);
		L2 = L2 -> prox;
	}
	return L3;
}

Lista * removeInicio(Lista *p){
	Lista *aux;
	aux = p;
	if(!isEmpty(p)){
		p = p -> prox;
		free(aux);
	}
	return p;
}

void mostraLista(Lista *p){
	Lista *aux;
	if(isEmpty(p))
	{
		printf("\n Lista vazia \n");
	}
	else
	{
		aux = p;
		printf("---");
		while(aux != NULL)
		{
			printf(" %d - ", aux -> info);
			aux = aux -> prox;
		}
	}
}


Lista * esvaziarLista(Lista *p)
	{
		while(p != NULL)
		{
		 p = removeInicio(p);	
		}
		return p;

}

int main()
{
	int info1, info2, opc;
	Lista * L1 = NULL, * L2 = NULL, * L3 = NULL;
	
	do{
		printf("\n 1 - incia lista 1");
		printf("\n 2 - incia lista 2");
		printf("\n 3 - mostra lista 1");
		printf("\n 4 - mostra lista 2");
		printf("\n 5 - mostra lista 3 (juncao da lista 1 e 2)");
		printf("\n 6 - encerrar programa");
		printf("\n \n Digite opcao");
		scanf("%d", &opc);
		
		switch(opc)
		{
		case 1:
			printf("\nDigite o numero para a lista 1: ");
			scanf("%d", &info1);
			
			L1 = insereFinal(L1, info1);
			break;
		case 2:
			printf("\nDigite o numero para a lista 2: ");
			scanf("%d", &info2);
			
			L2 = insereFinal(L2, info2);
			break;
		case 3:
			system("cls");
			printf("\n----Lista 1----\n");
			mostraLista(L1);
			printf("\n---------------");
			getch();
			break;
		case 4:
			system("cls");
			printf("\n----Lista 2----\n");
			mostraLista(L2);
			printf("\n---------------");
			getch();
			break;
		case 5:
			system("cls");
			L3 = terceiraLista(L1, L2);
			printf("\n----Lista 3----\n");
			mostraLista(L3);
			printf("---------------");
			break;
		case 6:
			L3 = esvaziarLista(L3);
			system("cls");
			printf("---------------");
			mostraLista(L3);
			printf("---------------");   
	   		printf("\n programa encerrado. \n");
	   		break;
			default: printf("\n opçao Invalida!. \n");
			break;
		}
	}while(opc != 6);
	
	return 0;
}