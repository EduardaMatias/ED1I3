#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <iomanip>
using namespace std;

#define LIN 15
#define COL 40

void mostra_mapa(char **x)
{

	cout << endl << "========= MAPA DE OCUPAÇÃO =========" << endl
		 << endl;
	for (int i = 0; i < LIN; ++i)
	{
		/*cout << "Fileira " << i + 1 << " ";*/
		for (int j = 0; j < COL; ++j)
		{
			cout << setw(1) << x[i][j] << "|";
		}
		cout << endl;
	}
}

int main(int argc, char **argv)
{
	setlocale(LC_ALL, "");

	int i;
	int j;
	int k;

	char **lugar;

	lugar = (char **)malloc(LIN * sizeof(int));

	for (i = 0; i < LIN; ++i)
	{
		lugar[i] = (char *)malloc(COL * sizeof(int));
	}

	k = 0;
	for (i = 0; i < LIN; ++i)
	{
		for (j = 0; j < COL; ++j)
		{
			lugar[i][j] = '.';
		}
	}

	/*menu*/
	int menu, ocupados = 0;
	double totalBilheteria = 0;
	bool loop = true;

	do
	{
		cout << endl
			 << "========= MENU BILHETERIA =========" << endl
			 << endl;
		cout << "0. Finalizar" << endl
			 << "1. Reservar poltrona" << endl
			 << "2. Mapa de ocupação" << endl
			 << "3. Faturamento" << endl
			 << "Digite a opção escolhida: ";
		cin >> menu;

		switch (menu)
		{
		case 0:
			cout << "Programa finalizado." << endl;
			loop = false;
			break;

		case 1:
			mostra_mapa(lugar);
			cout << endl << "Informe a fileira desejada (0 a 14): ";
			cin >> i;
			if (i >= 15 || i < 0)
			{
				cout << "Opção invalída." << endl
					 << "Fechando programa..." << endl;
				return 0;
			}

			cout << endl << "Informe a coluna desejada (0 a 39): ";
			cin >> j;

			if (j >= 40 || j < 0)
			{
				cout << "Opção invalída." << endl
					 << "Fechando programa..." << endl;
				return 0;
			}

			cout << endl << "Fileira escolhida: " << i << endl;
			cout << endl << "Coluna escolhida: " << j << endl;

			if (lugar[i][j] == '.')
			{
				cout << endl << "Lugar reservado!" << endl;
				lugar[i][j] = '#';
				ocupados++;

				if (i >= 0 && i <= 4)
				{
					totalBilheteria = totalBilheteria + 50;
				}

				else if (i >= 6 && i <= 9)
				{
					totalBilheteria = totalBilheteria + 30;
				}

				else if (i >= 10 && i <= 14)
				{
					totalBilheteria = totalBilheteria + 15;
				}
			}

			else
			{
				cout << endl << "Esse lugar já está reservado, tente novamente." << endl;
				return 0;
			}

			break;

		case 2:
			mostra_mapa(lugar);
			break;

		case 3:
			cout << endl << "Quantidade de lugares ocupados: " << ocupados << endl;
			cout << endl << "Valor da bilheteria: " << totalBilheteria << endl;
			break;

		default:
			cout << endl << "Opção invalida." << endl
				 << endl << "Fechando programa..." << endl;
			loop = false;
			return 0;
			break;
		}
	} while (loop == true);

	return 0;
}
