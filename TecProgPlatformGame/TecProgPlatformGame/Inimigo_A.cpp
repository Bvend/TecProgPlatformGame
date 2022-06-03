#include "Inimigo_A.h"

#define VELMOV 300.f

Inimigo_A::Inimigo_A(int vidas, CoordF des, CoordF pos, CoordF tam, ID ind):
Inimigo(vidas, des, pos, tam, ind),
trajeto(2 * tamanho.getX() + rand() % (int)tamanho.getX()),
distPercorrida(0)
{
	body.setFillColor(sf::Color::Magenta);

	// Atribui aleatoriamente direcao, sendo
	// 1 para *** e -1 para ***
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
}

void Inimigo_A::setJogador(Jogador* pJogador)
{
	this->pJogador = pJogador;
}

void Inimigo_A::move(float dt)
{
	deslocamento.setX(0);

	if (distPercorrida < trajeto)
	{
		deslocamento.setX(direcao * VELMOV * dt);
		distPercorrida += fabs(deslocamento.getX());
	}
	else
	{
		distPercorrida = 0;
		direcao *= -1;
	}

	if (estaNoAr == true)
	{
		deslocamento.atualizarY(GRAVIDADE * dt);
		deslocamento.setX(0);
	}

	proximaPosicao = posicao + deslocamento;
}

/* Essa função fica vazia por enquanto */
void Inimigo_A::colisao(Entidade* Entidade2, CoordF interseccao, bool* estaNoChao)
{
	reposicionarColisao(Entidade2->getPosicao(), Entidade2->getTamanho(), interseccao, estaNoChao);
}
