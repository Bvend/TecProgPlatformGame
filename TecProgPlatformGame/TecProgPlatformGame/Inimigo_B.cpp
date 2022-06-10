#include "Inimigo_B.h"
#include "Jogo.h"

#define CAMINHO_INIMIGO_B "./recurssos/Inimigo_B/Inimigo_B.png"

Inimigo_B::Inimigo_B(Gerenciador_Grafico* ger, CoordF pos, ListaEntidades* pLE, Obst_A* pPt):
Inimigo(Id::INIMIGO_B, ger, pos, CoordF(50.f, 50.f), 1),
pJogador(NULL),
pListaEntidades(pLE),
pPlataforma(pPt),
velMov(50.f)
{
	intervaloRecarga = 2.f;

	inicializarCorpo(CAMINHO_INIMIGO_B, posicao, tamanho);

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

	if (ind != Id::PROJETIL && reposicionar)
	{
		reposicionarColisao(pEntidade->getPosicao(), pEntidade->getTamanho(), direcao_colisao);
	}

	if (ind == Id::JOGADOR && direcao_colisao == COLISAO_CIMA)
	{
		num_vidas -= 1;
	}
	else  if (antingiuTodaRecarga())
	{
		reiniciarTempoRecarregando();
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
	atualizarTempoRecarregando();

	if (atingiuMetadeRecarga())
	{
		mover();

		if (antingiuTodaRecarga())
		{
			atacar();
		}
	}
}

void Inimigo_B::mover()
{
	if (pJogador && pPlataforma)
	{
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

void Inimigo_B::atacar()
{
	Projetil* pProjetil = new Projetil(getGerenciadorGrafico(), CoordF(getCentroX(), getCentroY()), direcaoProjetil());
	pListaEntidades->adicionarEntidade(pProjetil);
	reiniciarTempoRecarregando();
}
