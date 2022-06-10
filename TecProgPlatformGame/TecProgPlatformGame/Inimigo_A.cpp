#include "Inimigo_A.h"
#include "Jogo.h"

#define CAMINHO_GOOBER "./recurssos/Goober/Goober.png"

Inimigo_A::Inimigo_A(Gerenciador_Grafico* ger, CoordF pos):
Inimigo(Id::INIMIGO_A, ger, pos, CoordF(40.f, 60.f), 1),
pJogador(NULL),
trajeto(2 * tamanho.getX() + rand() % (int)tamanho.getX()),
distPercorrida(0),
velMov(50.f + rand() % 26)
{
	inicializarCorpo(CAMINHO_GOOBER, posicao, tamanho);

	// Atribui aleatoriamente direcao incial de movimento
	if (rand() % 2)
	{
		direcao = 1;
	}
	else
	{
		direcao = -1;
	}
}

Inimigo_A::~Inimigo_A()
{
	pJogador = NULL;
}

void Inimigo_A::setJogador(Jogador* pJogador)
{
	this->pJogador = pJogador;
}

/* Essa função fica vazia por enquanto */
void Inimigo_A::colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar)
{
	Id ind = pEntidade->getId();

	if (reposicionar)
	{
		reposicionarColisao(pEntidade->getPosicao(), pEntidade->getTamanho(), direcao_colisao);
	}

	if (ind == Id::JOGADOR && direcao_colisao == COLISAO_CIMA)
	{
		num_vidas -= 1;
	}
	else  if (antingiuTodaRecarga())
	{
		direcao *= -1;
		distPercorrida = 0;
		reiniciarTempoRecarregando();
	}
}

void Inimigo_A::executar()
{
	atualizarTempoRecarregando();

	if (atingiuMetadeRecarga())
	{
		mover();
	}
}

void Inimigo_A::mover()
{
	proximaPosicao = posicao;

	if (estaNoAr)
	{
		deslocamentoY += GRAVIDADE * Jogo::getDt();
		proximaPosicao.atualizarY(deslocamentoY);
	}
	else if (distPercorrida < trajeto)
	{
		proximaPosicao.atualizarX(direcao * velMov * Jogo::getDt());
		distPercorrida += fabs(proximaPosicao.getX() - posicao.getX());
	}
	else
	{
		distPercorrida = 0;
		direcao *= -1;
	}
}

