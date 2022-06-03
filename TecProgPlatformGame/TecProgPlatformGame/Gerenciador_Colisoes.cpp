#include "Gerenciador_Colisoes.h"
#include "Elemento.h"

Gerenciador_Colisoes::Gerenciador_Colisoes(ListaEntidades* LE) //ListaEntidades* ListaMoveis, ListaEntidades* ListaFixas):
//EntidadesMoveis(ListaMoveis),
//EntidadesFixas(ListaFixas)
{
	Entidades = LE;
}

Gerenciador_Colisoes::~Gerenciador_Colisoes()
{
	Entidades = NULL;
	//EntidadesMoveis = NULL;
	//EntidadesFixas = NULL;
}

/* Função para gerenciar as colisoes entre entidades.
   Até o momento gerencia apenas colisões entre entidades sem distinção entre fixas e móveis
   SÓ FUNCIONA PARA UMA ENTIDADE MOVEL (A ÚLTIMA DA LISTA) E VÁRIAS ENTIDADES FIXAS*/
void Gerenciador_Colisoes::checarColisoes()
{
	int i, j;

	Elemento<Entidade>* pElEntidade1;
	Elemento<Entidade>* pElEntidade2;

	Entidade* pEntidade1;
	Entidade* pEntidade2;

	CoordF distCentro;
	CoordF somaTam;

	int qtdEntidades = Entidades->getLength();

	bool estaNoChao = false;

	//if (numEntMoveis == 0)
	//{
		//return;
	//}

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

				/* Essa Implementação da colisão é melhor mas ainda não funciona
				distCentro = pEntidade1->getProximaPosicao() - pEntidade2->getProximaPosicao();
				distCentro.calculaAbs();

				somaTam = pEntidade1->getTamanho() / 2.f + pEntidade2->getTamanho() / 2.f;
				
				if (distCentro.getX() < somaTam.getX() && distCentro.getY() < somaTam.getY())
				{
					//std::cout << "INTERSECCAO x: " << somaTam.getX() - distCentro.getX() << " y: " << somaTam.getY() - distCentro.getY() << std::endl;
					pEntidade2->colisao(pEntidade1, somaTam - distCentro);
				}
				*/
				
				sf::FloatRect ent2Bounds = (pEntidade2->getBody())->getGlobalBounds();
				sf::FloatRect ent1Bounds = (pEntidade1->getBody())->getGlobalBounds();
				ent1Bounds.left = (pEntidade1->getProximaPosicao()).getX();
				ent1Bounds.top = (pEntidade1->getProximaPosicao()).getY();
				if (ent2Bounds.intersects(ent1Bounds))
				{
					//std::cout << "INTERSECCAO x: " << somaTam.getX() - distCentro.getX() << " y: " << somaTam.getY() - distCentro.getY() << std::endl;
					pEntidade1->colisao(pEntidade2, somaTam - distCentro, &estaNoChao);
					pEntidade1->colisao(pEntidade1, somaTam - distCentro, &estaNoChao);
				}
				if (fabs(pEntidade1->getBaixo() - pEntidade2->getCima()) < 0.5f
					&& (pEntidade1->getDireita() >= pEntidade2->getEsquerda()
					&& pEntidade1->getEsquerda() <= pEntidade2->getDireita()))
				{
					estaNoChao = true;
				}
			}
			pElEntidade2 = pElEntidade2->getPprox();
		}

		if (estaNoChao)
		{
			pEntidade1->setEstaNoAr(false);
		}
		else
		{
			pEntidade1->setEstaNoAr(true);
		}
		
		estaNoChao = false;

		pElEntidade1 = pElEntidade1->getPprox();
	}
}
