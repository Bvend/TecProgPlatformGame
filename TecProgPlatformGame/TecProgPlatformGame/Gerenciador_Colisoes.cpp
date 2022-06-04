#include "Gerenciador_Colisoes.h"

Gerenciador_Colisoes::Gerenciador_Colisoes(ListaEntidades* LE)
{
	Entidades = LE;
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
	Entidades = NULL;
	//ListaObstaculos = NULL;
	//ListaPersonagens = NULL;
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

	Personagem* pPersonagem = NULL;

	int qtdEntidades = Entidades->getLength();

	bool estaNoChao = false;

	pElEntidade1 = Entidades->getElemento(0);

	for (i = 0; i < qtdEntidades; i++)
	{
		pElEntidade2 = Entidades->getElemento(0);
		pEntidade1 = pElEntidade1->getItem();

		for (j = 0; j < qtdEntidades; j++)
		{
			if (i != j)
			{
				pEntidade2 = pElEntidade2->getItem();
				
				sf::FloatRect ent2Bounds = (pEntidade2->getBody())->getGlobalBounds();
				sf::FloatRect ent1Bounds = (pEntidade1->getBody())->getGlobalBounds();
				ent1Bounds.left = (pEntidade1->getProximaPosicao()).getX();
				ent1Bounds.top = (pEntidade1->getProximaPosicao()).getY();

				if (ent2Bounds.intersects(ent1Bounds))
				{
					pEntidade1->colisao(pEntidade2);
				}

				// Talvez melhorar isso
				if (fabs(pEntidade1->getBaixo() - pEntidade2->getCima()) < 0.1f
					&& (pEntidade1->getDireita() >= pEntidade2->getEsquerda()
					&& pEntidade1->getEsquerda() <= pEntidade2->getDireita()))
				{
					estaNoChao = true;
				}
			}
			pElEntidade2 = pElEntidade2->getPprox();
		}

		/* Checa se um personagem esta caindo */
		if (pPersonagem = dynamic_cast<Personagem*>(pEntidade1))
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
