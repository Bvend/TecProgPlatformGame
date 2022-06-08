#include "Inimigo_B.h"
#include "Jogo.h"

Inimigo_B::Inimigo_B(Id ind, Gerenciador_Grafico* ger, CoordF pos, CoordF tam, int vid, ListaEntidades* pLE, Obst_A* pPt):
Inimigo(ind, ger, pos, tam, vid),
pJogador(NULL),
cooldown(0),
pListaEntidades(pLE),
pPlataforma(pPt),
velMov(100.f)
{
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
		cooldown = 10.f;
	}

	if (reposicionar)
	{
		reposicionarColisao(pEntidade->getPosicao(), pEntidade->getTamanho(), direcao_colisao);
	}
}

void Inimigo_B::executar()
{
	proximaPosicao = posicao;

	if (cooldown > 0)
	{
		cooldown -= Jogo::getDt();
		if (cooldown > 5)
		{
			return;
		}
	}

	if (pJogador && pPlataforma)
	{
		if (pJogador->getDireita() < getEsquerda()
			&& getEsquerda() >= pPlataforma->getEsquerda())
		{
			proximaPosicao.atualizarX(-velMov * Jogo::getDt());
		}
		else if (pJogador->getEsquerda() > getDireita()
			&& getDireita() <= pPlataforma->getDireita())
		{
			proximaPosicao.atualizarX(velMov * Jogo::getDt());
		}
	}
	
	if (cooldown < 0)
	{
		Projetil* pProjetil = new Projetil();
		pListaEntidades->adicionarEntidade(pProjetil);
		cooldown = 10;
	}
}
