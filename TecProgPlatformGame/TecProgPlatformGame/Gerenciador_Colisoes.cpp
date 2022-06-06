#include "Gerenciador_Colisoes.h"

Gerenciador_Colisoes::Gerenciador_Colisoes(ListaEntidades* LE):
pListaEntidades(LE)
{
}

/*
Gerenciador_Colisoes::Gerenciador_Colisoes(Lista<Personagem>* ListaObst, Lista<Obstaculo>* ListaPers):
ListaObstaculos(ListaObst),
ListaPersonagens(ListaPers)
{
}
*/

Gerenciador_Colisoes::~Gerenciador_Colisoes()
{
	pListaEntidades = NULL;
	//ListaObstaculos = NULL;
	//ListaPersonagens = NULL;
}

void Gerenciador_Colisoes::setListaEntidades(ListaEntidades* LE)
{
	pListaEntidades = LE;
}

/* Função para gerenciar as colisoes entre entidades.
   Até o momento gerencia apenas colisões entre entidades
   sem distinção entre fixas e móveis */
void Gerenciador_Colisoes::checarColisoes()
{
	int i, j;

	Elemento<Entidade>* pElEntidade1 = NULL;
	Elemento<Entidade>* pElEntidade2 = NULL;

	Entidade* pEntidade1 = NULL;
	Entidade* pEntidade2 = NULL;

	Entidade_Movel* pEntidade_Movel = NULL;

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
				
				sf::FloatRect ent1Bounds = (pEntidade1->getBody())->getGlobalBounds();
				ent1Bounds.left = (pEntidade1->getProximaPosicao()).getX();
				ent1Bounds.top = (pEntidade1->getProximaPosicao()).getY();

				sf::FloatRect ent2Bounds = (pEntidade2->getBody())->getGlobalBounds();

				if (ent2Bounds.intersects(ent1Bounds))
				{
					int p = pEntidade2->detectarColisao(pEntidade1->getPosicao(), pEntidade1->getTamanho());
					cout << p << endl;
					pEntidade1->colisao(pEntidade2);
				}

				// Talvez melhorar isso
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
		if (pEntidade_Movel = dynamic_cast<Entidade_Movel*>(pEntidade1))
		{
			if (estaNoChao)
			{
				pEntidade_Movel->setEstaNoAr(false);
				pEntidade_Movel->setDeslocamentoY(0.f);
			}
			else
			{
				pEntidade_Movel->setEstaNoAr(true);
			}
		}
			
		estaNoChao = false;

		pElEntidade1 = pElEntidade1->getPprox();
	}
}

/*
void Gerenciador_Colisoes::checarColisoes()
{
	int i, j;

	Elemento<Personagem>* pElPersonagem1 = NULL;
	Elemento<Personagem>* pElPersonagem2 = NULL;
	Elemento<Obstaculo>* pElObstaculo1 = NULL;

	Personagem* pPersonagem1 = NULL;
	Personagem* pPersonagem2 = NULL;
	Obstaculo* pObstaculo1 = NULL;

	CoordF distCentro;
	CoordF somaTam;

	int qtdPersonagens = ListaPersonagens->getLen();
	int qtdObstaculos = ListaObstaculos->getLen();


}
*/
