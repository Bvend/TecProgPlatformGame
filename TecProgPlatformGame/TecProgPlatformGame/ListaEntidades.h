#pragma once
#include "Lista.h"
#include "Entidade.h"

namespace Listas
{
	class ListaEntidades
	{
	private:
		Lista<Entidades::Entidade>* LE;

	public:
		ListaEntidades();
		~ListaEntidades();

		int getLength();
		void adicionarEntidade(Entidades::Entidade* E);
		Entidades::Entidade* operator[](int i);
		Lista<Entidades::Entidade>::Elemento<Entidades::Entidade>* getElemento(int posicao);
		void deletarEntidades();

		void deletarEntidade(Entidades::Entidade* pEntidade);
	};
}

