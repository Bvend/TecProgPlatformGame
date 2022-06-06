#include "ListaEntidades.h"

ListaEntidades::ListaEntidades():
LE(new Lista<Entidade>())
{
}

ListaEntidades::~ListaEntidades()
{
	delete LE;
}

int ListaEntidades::getLength()
{
	return LE->getTam();
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

void ListaEntidades::deletarEntidades()
{
	Entidade* pEntidade = NULL;

	while (LE->getTam())
	{
		pEntidade = LE->pop(0);
		if (pEntidade)
		{
			delete pEntidade;
		}
	}
}

void ListaEntidades::deletarEntidade(Entidade* pEntidade)
{
	Entidade* tmp = NULL;
	tmp = LE->pop(pEntidade);
	if (pEntidade)
	{
		delete pEntidade;
	}
}
