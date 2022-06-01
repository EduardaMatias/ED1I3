#include <iostream>
#include <string.h>
#include <math.h> 
using namespace std;

#define MAX 30

struct Pilha
{
	int qtde;
	float numero[MAX];
};

Pilha* init()
{
	Pilha *p = new Pilha;
	p->qtde = 0;
	return p;
};

int push(Pilha *p, float n)
{
	int podeEmpilhar = (p->qtde < MAX);
	if(podeEmpilhar)
	{
		p->numero[p->qtde++] = n;
	}
	return podeEmpilhar;
};

int isEmpty(Pilha *p)
{
	return (p->qtde == 0);
}

void print(Pilha *p)
{
	for(int i = p->qtde - 1; i >= 0; --i)
	{
		int podeDesempilhar = (p->qtde > 0);
	float ret;
	if (podeDesempilhar)
	{
		ret = p->numero[p->qtde - 1];
		p->qtde--;
	}
	else
	{
		ret = NULL;
	}
	cout << ret<<endl;
	}
	cout << "----------" << endl;
}

int main(int argc, char** argv)
{
	setlocale (LC_ALL, "");
	Pilha *pilhaPar;
	pilhaPar = init();
	Pilha *pilhaImpar;
	pilhaImpar = init();
	float n[30];
	int i = 0;
	
	while(i < MAX)
	{
		cout << "Digite o " << (i + 1) << "° número: " << endl;
		cin >> n[i];
		if(n[i] > n[i - 1])
		{
			if(fmod(n[i],2) == 0)
			{
				push(pilhaPar, n[i]);
			
			}
			else{
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
	
	cout << "Impar: " << endl;
	print(pilhaImpar);
	return 0;
}
