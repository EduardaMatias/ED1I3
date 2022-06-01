#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

#define MAX 30

struct No
{
	float dado;
	No *prox;
};

struct Pilha
{
	No *topo;
};

Pilha* init()
{
	Pilha *p = new Pilha;
	p->topo = NULL;
	return p;
}

void push(Pilha *p, float v)
{
	No *no = new No;
	no->dado = v;
	no->prox = p->topo;
	p->topo = no;
}

int isEmpty(Pilha *p)
{
	return (p->topo == NULL);
}


void print(Pilha *p) {
	No *no;
	no = p->topo;
	cout << "------" << endl;
	while (no != NULL) {
			float ret;
	int podeDesempilhar = (p->topo != NULL);
	if (podeDesempilhar)
	{
		No *no = p->topo;
		ret = no->dado;
		p->topo = p->topo->prox;
		free(no);
	}
	else
	{
		ret = NULL;
	}

		no = no->prox;
			cout<< ret <<endl;
	}
	cout << "------" << endl;
}


void freePilha(Pilha *p)
{
	No *no = p->topo;
	while (no != NULL)
	{
		No *aux = no->prox;
		free(no);
		no = aux;
	}

}

int main(int argc, char** argv)
{
	setlocale (LC_ALL, "");
	Pilha *pilhaPar;
	pilhaPar = init();
	Pilha *pilhaImpar;
	pilhaImpar = init();
	float n[MAX];
	int i = 0;

	while(i < MAX)
	{
		cout << "Digite o " << (i + 1) << "° número: " << endl;
		cin >> n[i];
		if(n[i] > n[i - 1])
		{
			if(fmod(n[i], 2) == 0)
			{
				push(pilhaPar, n[i]);

			}
			else
			{
				push(pilhaImpar, n[i]);
			}
			i++;
		}
		else
		{
			cout << "Digite um número maior que o anterior!" << endl;
		}
	}

	cout << endl << "Par: " << endl;
	print(pilhaPar);
	
	cout << endl << "Impar: " << endl;
	print(pilhaImpar);
	
	freePilha(pilhaPar);
	freePilha(pilhaImpar);
	return 0;
}
