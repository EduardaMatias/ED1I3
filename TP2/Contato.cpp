#include <iostream>
#include <string.h>
#include <locale.h>
using namespace std;

class Data
{
private:
	int dia;
	int mes;
	int ano;

public:
	Data(int dia, int mes, int ano)
	{
		this->dia = dia;
		this->mes = mes;
		this->ano = ano;
	}

	Data()
	{
		this->dia = 28;
		this->mes = 9;
		this->ano = 1962;
	}

	void setDia(int dia)
	{
		this->dia = dia;
	}

	void setMes(int mes)
	{
		this->mes = mes;
	}

	void setAno(int ano)
	{
		this->ano = ano;
	}

	int getDia()
	{
		return this->dia;
	}

	int getMes()
	{
		return this->mes;
	}

	int getAno()
	{
		return this->ano;
	}

	string getData()
	{
		return to_string(this->dia) + "/" +
			   to_string(this->mes) + "/" +
			   to_string(this->ano);
	}

	Data* dia_seguinte()
	{
		Data *ds;
		int diasNoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

		ds = new Data(this->dia, this->mes, this->ano);

		if (ds->ano % 4 == 0)
		{
			diasNoMes[1]++;
		}

		ds->dia++;
		if (ds->dia > diasNoMes[ds->mes - 1])
		{
			ds->dia = 1;
			ds->mes++;
			if(ds->mes > 12)
			{
				ds->mes = 1;
				ds->ano++;
			}
		}

		return ds;
	}

};

class Contato
{
private:
	string email;
	string nome;
	string telefone;
	Data* dtnasc;


public:
	Contato(string email, string nome, string telefone, Data* dtnasc)
	{
		this->email = email;
		this->nome = nome;
		this->telefone = telefone;
		this->dtnasc = dtnasc;
	}

	Contato()
	{
		this->email = "email@email.com";
		this->nome = "nome";
		this->telefone = "(00)000000000";
		this->dtnasc = new Data();
	}

	void setEmail(string email)
	{
		this->email = email;
	}

	void setNome(string nome)
	{
		this->nome = nome;
	}

	void setTelefone(string telefone)
	{
		this->telefone = telefone;
	}

	void setDtnasc(Data* data)
	{
		this->dtnasc = data;
	}

	string getEmail(string email)
	{
		return this-> email;
	}

	string getNome(string nome)
	{
		return this-> nome;
	}

	string getTelefone(string telefone)
	{
		return this-> telefone;
	}

	int getIdade(int idade)
	{
		return this-> calcIdade();
	}

	Data* getDtnasc(Data* data)
	{
		return this-> dtnasc;
	}


	string getContato()
	{
		return "Email: " + this->email + "\n" +
			   "Nome: " + this->nome + "\n" +
			   "Telefone: " + this->telefone + "\n" +
			   "Data de Nascimento: " + this->dtnasc->getData() + "\n" +
			   "Idade: " + to_string(this->calcIdade());
	}

	int calcIdade()
	{
		return 2022 - this->dtnasc->getAno();
	}

};

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	Contato *contatos[5];

	string email;
	string nome;
	string telefone;
	int dia;
	int mes;
	int ano;

	for(int i = 0; i < 5; i++)
	{
		cout << "Digite o nome do " + to_string(i + 1) + "° contato: ";
		cin >> nome;
		cout << "Digite o email do " + to_string(i + 1) + "° contato: ";
		cin >> email;
		cout << "Digite o telefone do " + to_string(i + 1) + "° contato: ";
		cin >> telefone;
		cout << "Digite o dia de nascimento do " + to_string(i + 1) + "° contato: ";
		cin >> dia;

		if(dia > 0 && dia < 31)
		{
			cout << "Digite o mês de nascimento do " + to_string(i + 1) + "° contato: ";
			cin >> mes;

			if(mes > 0 && mes < 12)
			{
				cout << "Digite o ano de nascimento do " + to_string(i + 1) + "° contato: ";
				cin >> ano;

				if(ano > 1822 && ano <= 2022)
				{
					cout << "================================================" << endl;
				}
				else
				{
					cout << "Você digitou um valor inválido!" << endl << "...........Fechando o programa";
					return 0;
				}
			}
			else
			{
				cout << "Você digitou um valor inválido!" << endl << "...........Fechando o programa";
				return 0;
			}

		}
		else
		{
			cout << "Você digitou um valor inválido!" << endl << "...........Fechando o programa";
			return 0;
		}
		
		Data *dataNascimento = new Data(dia, mes, ano);

		Contato *contato = new Contato(nome, email, telefone, dataNascimento);
		cout << contato->getContato() << endl;
		cout << "================================================" << endl;
	}
	return 0;
}
