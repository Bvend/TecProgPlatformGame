#include "ListaEntidades.h"

namespace Listas
{
	ListaEntidades::ListaEntidades() :
	LE(new Lista<Entidades::Entidade>())
	{
	}

	ListaEntidades::~ListaEntidades()
	{
		deletarEntidades();
		delete LE;
	}

	int ListaEntidades::getTamanho()
	{
		return LE->getTam();
	}

	void ListaEntidades::adicionarEntidade(Entidades::Entidade* E)
	{
		if (E == NULL)
		{
			std::cout << "Erro ao adicionar entidade" << std::endl;
			return;
		}

		LE->push(E);
	}

	Entidades::Entidade* ListaEntidades::operator[](int i)
	{
		return (LE->getItem(i));
	}

	Lista<Entidades::Entidade>::Elemento<Entidades::Entidade>* ListaEntidades::getElemento(int posicao)
	{
		return (LE->getElemento(posicao));
	}

	void ListaEntidades::deletarEntidades()
	{
		LE->esvaziar();
	}

	void ListaEntidades::removerEntidadeSemDeletar(Entidades::Entidade* pEntidade)
	{
		LE->popSemRetorno(pEntidade);
	}

	void ListaEntidades::deletarEntidade(Entidades::Entidade* pEntidade)
	{
		Entidades::Entidade* tmp = NULL;
		tmp = LE->pop(pEntidade);
		if (pEntidade)
		{
			delete pEntidade;
		}
	}
}
