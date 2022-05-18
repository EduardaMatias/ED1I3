/*
Funcionario
  - prontuario: int
  - nome: string
  - salario: double
Elabore um programa que permita administrar uma lista de funcion�rios e, atrav�s de um menu, ofere�a as seguintes op��es:

   0. Sair
   1. Incluir
   2. Excluir
   3. Pesquisar
   4. Listar

   a) N�o poder�o ser cadastrados funcion�rios com mesmo prontu�rio;

	b) A pesquisa de funcion�rio dever� utilizar o atributo "Prontu�rio" como crit�rio e, quando encontrado, dever�o ser exibidos os demais atributos;

	c) A listagem dos funcion�rios dever� apresentar todos os seus atributos e, ao final, informar o total dos sal�rios.
*/

#include <iostream>
#include <string.h>

using namespace std;

class Funcionario
{

private:
	string nome;
	double salario;
	int prontuario;

public:
	Funcionario(string nome, double salario, int prontuario)
	{
		this->nome = nome;
		this->salario = salario;
		this->prontuario = prontuario;
	}

	Funcionario()
	{
		this->nome = "";
		this->salario = 0.0;
		this->prontuario = 0;
	}

	void setNome(string nome)
	{
		this->nome = nome;
	}

	void setSalario(double salario)
	{
		this->salario = salario;
	}

	void setProntuario(int prontuario)
	{
		this->prontuario = prontuario;
	}

	string getNome()
	{
		return this->nome;
	}

	double getSalario()
	{
		return this->salario;
	}

	int getProntuario()
	{
		return this->prontuario;
	}
};

struct Lista
{
	Funcionario* funcionario;
	Lista* ant;
};

Lista* init()
{
	return NULL;
}

int isEmpty(Lista* lista) //verifica se a lista est� vazia
{
	return (lista == NULL);
}

Lista* insert(Lista* lista, Funcionario* f)
{
	Lista* novo = new Lista();
	novo->funcionario = f;
	novo->ant = lista;
	return novo;
}

int count(Lista* lista)
{
	int k = 0;
	Lista* aux;
	aux = lista;
	while (aux != NULL)
	{
		++k;
		aux = aux->ant;
	}
	return k;
}

void print(Lista* lista)
{
	setlocale (LC_ALL,"");
	Lista* aux;
	aux = lista;
	while (aux != NULL)
	{
		cout << "Funcion�rio: " << aux->funcionario->getNome() << endl <<
			 "Sal�rio: " << aux->funcionario->getSalario() << endl <<
			 "Prontu�rio: " << aux->funcionario->getProntuario() << endl;
		aux = aux->ant;
	}
}

Lista* find(Lista* lista, int prontuario)
{
	Lista* aux;
	aux = lista;
	while (aux != NULL && aux->funcionario->getProntuario() != prontuario)
	{
		aux = aux->ant;
	}
	return aux;
}

Lista* remove(Lista* lista, int prontuario)
{
	Lista *aux;

	Lista *anterior = NULL;

	aux = lista;
	while (aux != NULL && aux->funcionario->getProntuario() != prontuario)
	{
		anterior = aux;
		aux = aux->ant;
	}

	if (aux == NULL)
	{
		return lista;
	}

	if (anterior == NULL)
	{
		lista = aux->ant;
	}
	else
	{
		anterior->ant = aux->ant;
	}
	free(aux);
	return lista;
}

int main(int argc, char** argv)
{

	setlocale (LC_ALL,"");
	
	int escolha;
	string nome;
	double salario;
	int prontuario;
	bool loop = true;
	Funcionario *f;
	Lista* minhaLista;
	minhaLista = init();
	double totalSalario = 0;
	while(loop == true)
	{

		cout << "\nEscolha uma op��o \n0. Sair\n1. Incluir\n2. Excluir\n3. Pesquisar\n4. Listar\n\nSua escolha: ";
		cin >> escolha;

		if(escolha == 0)
		{
			cout << "Finalizando...." << endl;
			loop = false;
		}

		else if(escolha == 1)
		{
			int i = 0;
			cout << endl;
			cout << "Cadastro " << i + 1 << endl;
			cout << "Digite seu nome: ";
			cin >> nome;
			cout << endl;
			cout << "Digite seu sal�rio: ";
			cin >> salario;
			cout << endl;
			cout << "Digite seu prontu�rio: ";
			cin >> prontuario;
			cout << endl;
			
			Lista* busca = find(minhaLista, prontuario);
			if (busca == NULL)
			{
				totalSalario = totalSalario + salario;
				f = new Funcionario(nome, salario, prontuario);
				minhaLista = insert(minhaLista, f);
			}
			else
			{
				cout << "Prontu�rio j� digitado!" << endl;
			}		
		}

		else if (escolha == 2)
		{
			cout << "Digite o prontu�rio que deseja remover: ";
			cin >> prontuario;
			if(f->getProntuario() != prontuario){
				cout << "Esse usuario n�o existe!" << endl;
			} else {
				totalSalario = totalSalario - f->getSalario();
				minhaLista = remove(minhaLista, prontuario);
			}
			
		}

		else if (escolha == 3)
		{
			cout << "Digite o prontu�rio que deseja pesquisar: ";
			cin >> prontuario;
			Lista* buscado = find(minhaLista, prontuario);
			if (buscado == NULL)
			{
				cout << "N�o encontrado" << endl;
			}
			else
			{
				cout << "\n-------------------------\n";
				cout << "Funcion�rio: " << buscado->funcionario->getNome() << endl <<
					 "Sal�rio: " << buscado->funcionario->getSalario() << endl <<
					 "Prontu�rio: " << buscado->funcionario->getProntuario() << endl;
					 cout << "-------------------------\n";
			}
		}

		else if (escolha == 4)
		{
			cout << "\n-------------------------\n";
			print(minhaLista);
			cout << "Total sal�rio: " << totalSalario << endl;
			cout << "-------------------------\n";

		}

		else
		{
			cout << "Valor inv�lido" << endl;
		}

	}

	return 0;
}
