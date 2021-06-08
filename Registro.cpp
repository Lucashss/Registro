#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

/*
À partir da estrutura "Funcionario" descrita abaixo:

Funcionario
  - prontuario: int
  - nome: string
  - salario: double
Elabore um programa que permita administrar uma lista de funcionários e, através de um menu, ofereça as seguintes opções:

   0. Sair
   1. Incluir
   2. Excluir
   3. Pesquisar
   4. Listar
OBSERVAÇÕES:

a) Não poderão ser cadastrados funcionários com mesmo prontuário;

b) A pesquisa de funcionário deverá utilizar o atributo "Prontuário" como critério e, quando encontrado, deverão ser exibidos os demais atributos;

c) A listagem dos funcionários deverá apresentar todos os seus atributos e, ao final, informar o total dos salários.*/

struct Funcionario
{
	int pront;
	double sal;
	string  nome;
	struct Funcionario *prox;
};

Funcionario* init()
{
	return NULL;
}

void lista(Funcionario* lista)
{
	Funcionario* aux;
	aux = lista;
	int totalFunc = 0;

	while(aux != NULL)
	{
		totalFunc++;
		cout << "Nome: " << aux->nome << " - Prontuario: " << aux->pront << " - Salario: " << aux->sal << endl;
		cout << endl;
		aux = aux->prox;
	}

	cout << "Total de funcionarios: " << totalFunc << endl;
}

Funcionario* excluir(Funcionario* lista, int i)
{
	Funcionario *aux;
	Funcionario *ant = NULL;
	aux = lista;


	while(aux != NULL && aux->pront != i)
	{
		ant = aux;
		aux = aux->prox;
	}

	if(aux == NULL)
	{
		return lista;
	}
	if(ant == NULL)
	{
		lista = lista->prox;
	}
	else
	{
		ant->prox = aux->prox;
	}
	return lista;
}

Funcionario* pesquisar(Funcionario* lista, int pront)
{
	Funcionario* aux;
	aux = lista;

	while (aux != NULL && aux->pront != pront)
	{
		aux = aux->prox;
	}
	return aux;
}

Funcionario* incluir(Funcionario* lista, int pront, double sal, string nome)
{

	Funcionario *procurado = pesquisar(lista, pront);

	if(procurado != NULL)
	{
		cout << "Funcionario com o mesmo prontuario ja cadastrado." << endl;
		return lista;
	}

	Funcionario* novo = new Funcionario();
	novo->pront = pront;
	novo->sal = sal;
	novo->nome = nome;
	novo->prox = lista;

	return novo;
}

void menu()
{
	bool menu = true;
	int op = 0;
	Funcionario *listaFunc;
	listaFunc = init();

	while (menu)
	{
		string nome = "";
		double sal = 0;
		double total;
		int pront = 0;
		cout << "==============================" << endl;
		cout << "            Menu             |" << endl;
		cout << "==============================" << endl;
		cout << "\nSelecione uma opcao:" << endl;
		cout << "\n1.Cadastrar funcionario" << endl;
		cout << "2.Excluir funcionario" << endl;
		cout << "3.Pesquisar funcionario" << endl;
		cout << "4.Listar funcionarios" << endl;
		cout << "0.SAIR" << endl;
		cout << "==============================" << endl;
		cin >> op;
		cout << endl;
		system("cls");

		switch(op)
		{
		case 0:
			menu = false;
			break;
		case 1:
			for(int i = 0; i < 1; i++)
			{
				cout << "Digite o nome do Funcionario:" << endl;
				cin >> nome;
				cout << "Digite o salario do Funcionario:" << endl;
				cin >> sal;
				cout << "Digite o prontuario do Funcionario" << endl;
				cin >> pront;

				total = total + sal;
				listaFunc = incluir(listaFunc, pront, sal, nome);
			}


			break;
		case 2:
			cout << "Digite o prontuario do Funcionario" << endl;
			cin >> pront;

			listaFunc = excluir(listaFunc, pront);
			break;
		case 3:
		{
			cout << "Digite o prontuario do Funcionario" << endl;
			cin >> pront;

			Funcionario *procurado = pesquisar(listaFunc, pront);
			if(procurado != NULL)
			{
				cout << "Nome: " << procurado->nome << " - Prontuario: " << procurado->pront << " - Salario: " << procurado->sal << endl;

			}
			else
			{
				cout << "Funcionario nao localizado." << endl;
			}
			break;
		}
		case 4:
			lista(listaFunc);
			cout << "Valor total dos salarios dos funcionarios: " << total << endl;
			break;
		}
	}
}

int main(int argc, char** argv)
{

	menu();
	return 0;
}
