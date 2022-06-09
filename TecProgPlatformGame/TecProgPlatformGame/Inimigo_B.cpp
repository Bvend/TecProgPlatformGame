#include "Inimigo_B.h"
#include "Jogo.h"

#define CAMINHO_INIMIGO_B "./recurssos/Inimigo_B/Inimigo_B.png"

Inimigo_B::Inimigo_B(Gerenciador_Grafico* ger, CoordF pos, ListaEntidades* pLE, Obst_A* pPt):
Inimigo(Id::INIMIGO_B, pos, CoordF(100.f, 100.f), 1),
pJogador(NULL),
cooldown(0),
pListaEntidades(pLE),
pPlataforma(pPt),
velMov(100.f)
{
	corpo.inicializar(CAMINHO_INIMIGO_B, posicao, tamanho, ger);

	if (rand() % 2)
	{
		direcao = 1;
	}
	else
	{
		direcao = -1;
	}
}

Inimigo_B::~Inimigo_B()
{
	pJogador = NULL;
}

void Inimigo_B::setJogador(Jogador* pJ)
{
	pJogador = pJ;
}

void Inimigo_B::colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar)
{
	Id ind = pEntidade->getId();
	if (ind == Id::JOGADOR && direcao_colisao == COLISAO_CIMA)
	{
		num_vidas -= 1;
	}
	else  if (!cooldown)
	{
		cooldown = 1.f;
	}

	if (ind != Id::PROJETIL && reposicionar)
	{
		reposicionarColisao(pEntidade->getPosicao(), pEntidade->getTamanho(), direcao_colisao);
	}
}

int Inimigo_B::direcaoProjetil()
{
	if (pJogador->getCentroX() > getCentroX())
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

void Inimigo_B::executar()
{
	if (cooldown > 0)
	{
		cooldown -= Jogo::getDt();
		if (cooldown > 0.5f)
		{
			//return;
		}
	}
	else
	{
		cooldown = 0;
	}

	mover();
	
	if (cooldown <= 0)
	{
		Projetil* pProjetil = new Projetil(corpo.getGerenciadorGrafico(), CoordF(getCentroX(), getCentroY()), direcaoProjetil());
		pListaEntidades->adicionarEntidade(pProjetil);
		cooldown = 1;
	}
}

void Inimigo_B::mover()
{
	if (pJogador && pPlataforma)
	{
		/*
		if (pJogador->getDireita() + 150.f < pPlataforma->getEsquerda()
			&& getEsquerda() >= pPlataforma->getEsquerda())
		{
			proximaPosicao.atualizarX(-velMov * Jogo::getDt());
		}
		else if (pJogador->getEsquerda() - 150.f > pPlataforma->getDireita()
			&& getDireita() <= pPlataforma->getDireita())
		{
			proximaPosicao.atualizarX(velMov * Jogo::getDt());
		}
		else if (pJogador->getDireita() < posicao.getX()
			&& getDireita() <= pPlataforma->getDireita())
		{
			proximaPosicao.atualizarX(+velMov * Jogo::getDt());
		}
		else if (pJogador->getEsquerda() > getDireita()
			&& getEsquerda() >= pPlataforma->getEsquerda())
		{
			proximaPosicao.atualizarX(velMov * Jogo::getDt());

		}
		*/
		if (pJogador->getDireita() < getEsquerda()
			&& getDireita() <= pPlataforma->getDireita())
		{
			proximaPosicao.atualizarX(velMov * Jogo::getDt());
		}
		else if (pJogador->getEsquerda() > getDireita()
			&& getEsquerda() >= pPlataforma->getEsquerda())
		{
			proximaPosicao.atualizarX(-velMov * Jogo::getDt());
		}

	}
}
