#include <iostream>
#include <time.h>
#include <locale.h> 
using namespace std;

struct No {
	float dado;
	No *prox;
};

struct Fila {
	No *ini;
	No *fim; 
};

Fila* init() {
	Fila *f = new Fila;
	f->ini = NULL;
	f->fim = NULL;
	return f;
}

int isEmpty(Fila *f) {
	return (f->ini == NULL);
}

int count(Fila *f) {
	int qtde = 0;
	No *no;
	no = f->ini;
	while (no != NULL) {
		qtde++;
		no = no->prox;
	}
	return qtde;
}

void print(Fila *f) {
	No *no;
	no = f->ini;
	cout << "-------------" << endl;
	while (no != NULL) {
		cout << no->dado << endl;
		no = no->prox;
	}
	cout << "-------------" << endl;
}

void enqueue(Fila *f, float v) {
	No *no = new No;
	no->dado = v;
	no->prox = NULL;
	if (isEmpty(f)) {
		f->ini = no;
	}
	else {
		f->fim->prox = no;
	}
	f->fim = no;
}

float dequeue(Fila *f) {
	float ret;
	if (isEmpty(f)) {
		ret = -1;
	}
	else {
		No *no = f->ini;
		ret = no->dado;
		f->ini = no->prox;
		if (f->ini == NULL) {
			f->fim = NULL;
		}
		free(no);
	}
	return ret;
}

void freeFila(Fila *f) {
	No *no = f->ini;
	while (no != NULL) {
		No *temp = no->prox;
		free(no);
		no = temp;
	}
	free(f);
}

int main(int argc, char** argv)
{
	setlocale (LC_ALL,"");
	int opcao;
	float i = 1; 
	
	Fila *senhasGeradas;
	senhasGeradas = init();
	
	Fila *senhasAtendidas;
	senhasAtendidas = init();
	
	do {
    cout<<endl;
	cout << "Fila de espera: " << endl;
	print(senhasGeradas);
		cout << "0. Sair \n1. Gerar senha \n2. Realizar atendimento\nDigite a opção escolhida: ";
		cin >> opcao;
		switch (opcao) {
			case 0:
				cout << endl;
				break;
			case 1:
				cout << "Opção escolhida: Gerar senha." << endl;
				enqueue(senhasGeradas, i);
				i++;
				break;
			case 2:
				cout << "Opção escolhida: Realizar atendimento." << endl;
				if(isEmpty(senhasGeradas) == false){
					enqueue(senhasAtendidas, dequeue(senhasGeradas));
				}
				break;
			default:
				cout << "Opção inexistente" << endl;
		}
	} while(opcao != 0 || count(senhasGeradas)!=0);	
	
	cout << "Quantidade de senhas atendidas: " << count(senhasAtendidas) << endl;	 
	freeFila(senhasGeradas);
	freeFila(senhasAtendidas);
	
	return 0;
}