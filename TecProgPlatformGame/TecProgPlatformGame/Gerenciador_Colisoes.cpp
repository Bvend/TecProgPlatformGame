#include "Gerenciador_Colisoes.h"

namespace Gerenciadores
{
	Gerenciador_Colisoes::Gerenciador_Colisoes(Listas::ListaEntidades* LE) :
		pListaEntidades(LE)
	{
	}

	Gerenciador_Colisoes::~Gerenciador_Colisoes()
	{
		pListaEntidades = NULL;
	}

	void Gerenciador_Colisoes::setListaEntidades(Listas::ListaEntidades* LE)
	{
		pListaEntidades = LE;
	}

	/* Função para gerenciar as colisoes entre entidades.
	   Até o momento gerencia apenas colisões entre entidades
	   sem distinção entre fixas e móveis */
	void Gerenciador_Colisoes::checarColisoes()
	{
		int i, j;

		Listas::Lista<Entidades::Entidade>::Elemento<Entidades::Entidade>* pElEntidade1 = NULL;
		Listas::Lista<Entidades::Entidade>::Elemento<Entidades::Entidade>* pElEntidade2 = NULL;

		Entidades::Entidade* pEntidade1 = NULL;
		Entidades::Entidade* pEntidade2 = NULL;

		Entidades::Personagens::Personagem* pPersonagem = NULL;

		int qtdEntidades = pListaEntidades->getLength();

		bool estaNoChao = false;

		pElEntidade1 = pListaEntidades->getElemento(0);

		for (i = 0; i < qtdEntidades; i++)
		{
			pElEntidade2 = pListaEntidades->getElemento(0);
			pEntidade1 = pElEntidade1->getItem();

			for (j = 0; j < qtdEntidades; j++)
			{
				if (i != j)
				{
					pEntidade2 = pElEntidade2->getItem();

					sf::FloatRect ent1Bounds = (pEntidade1->getForma())->getGlobalBounds();
					ent1Bounds.left = (pEntidade1->getProximaPosicao()).getX();
					ent1Bounds.top = (pEntidade1->getProximaPosicao()).getY();

					sf::FloatRect ent2Bounds = (pEntidade2->getForma())->getGlobalBounds();

					if (ent2Bounds.intersects(ent1Bounds))
					{
						int direcao_colisao = pEntidade1->detectarColisao(pEntidade2->getPosicao(), pEntidade2->getTamanho());
						pEntidade1->colisao(direcao_colisao, pEntidade2, true);
						pEntidade2->colisao(direcao_colisao * -1, pEntidade1, false);
					}

					if (fabs(pEntidade1->getBaixo() - pEntidade2->getCima()) < 0.2f
						&& (pEntidade1->getDireita() >= pEntidade2->getEsquerda()
							&& pEntidade1->getEsquerda() <= pEntidade2->getDireita()))
					{
						estaNoChao = true;
					}
				}
				pElEntidade2 = pElEntidade2->getPprox();
			}

			/* Checa se um personagem esta caindo */
			if (pPersonagem = dynamic_cast<Entidades::Personagens::Personagem*>(pEntidade1))
			{
				if (estaNoChao)
				{
					pPersonagem->setEstaNoAr(false);
					pPersonagem->setDeslocamentoY(0.f);
				}
				else
				{
					pPersonagem->setEstaNoAr(true);
				}
			}

			estaNoChao = false;

			pElEntidade1 = pElEntidade1->getPprox();
		}
	}
}
