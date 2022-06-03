#include "ListaEntidades.h"

ListaEntidades::ListaEntidades():
LE(new Lista<Entidade>())
{
}

ListaEntidades::~ListaEntidades()
{
	limpar();
	delete LE;
}

int ListaEntidades::getLength()
{
	return LE->getLen();
}

void ListaEntidades::adicionarEntidade(Entidade* E)
{
	if (E == NULL)
	{
		cout << "Erro ao adicionar entidade" << endl;
		return;
	}

	LE->push(E);
}

Entidade* ListaEntidades::operator[](int i)
{
	return (LE->getItem(i));
}

Elemento<Entidade>* ListaEntidades::getElemento(int posicao)
{
	return (LE->getElemento(posicao));
}

void ListaEntidades::limpar()
{
	LE->esvaziar();
}
