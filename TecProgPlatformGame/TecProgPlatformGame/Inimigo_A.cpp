#include "Inimigo_A.h"
#include "Jogo.h"

#define CAMINHO_GOOBER "./recurssos/Goober/Goober.png"

Inimigo_A::Inimigo_A(Gerenciador_Grafico* ger, CoordF pos):
Inimigo(Id::INIMIGO_A, pos, CoordF(80.f, 120.f), 1),
pJogador(NULL),
trajeto(2 * tamanho.getX() + rand() % (int)tamanho.getX()),
distPercorrida(0),
cooldown(0),
velMov(100.f + rand() % 51)
{
	corpo.inicializar(CAMINHO_GOOBER, posicao, tamanho, ger);

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
	if (reposicionar)
	{
		reposicionarColisao(pEntidade->getPosicao(), pEntidade->getTamanho(), direcao_colisao);
	}

	Id ind = pEntidade->getId();
	if (ind == Id::JOGADOR && direcao_colisao == COLISAO_CIMA)
	{
		num_vidas -= 1;
	}
	else  if (!cooldown)
	{
		direcao *= -1;
		distPercorrida = 0;
		cooldown = 1.f;
	}
}

void Inimigo_A::executar()
{

	if (cooldown > 0)
	{
		cooldown -= Jogo::getDt();
		if (cooldown > 0.5f)
		{
			return;
		}
	}
	else
	{
		cooldown = 0;
	}

	mover();
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

