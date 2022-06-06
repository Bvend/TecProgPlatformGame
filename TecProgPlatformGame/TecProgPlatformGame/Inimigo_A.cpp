#include "Inimigo_A.h"

#define VELMOV 150.f

Inimigo_A::Inimigo_A(int vidas, CoordF pos, CoordF tam, ID ind):
Inimigo(vidas, pos, tam, ind),
pJogador(NULL),
trajeto(2 * tamanho.getX() + rand() % (int)tamanho.getX()),
distPercorrida(0),
cooldown(15)
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
	cout << direcao << endl;
}

Inimigo_A::~Inimigo_A()
{
	pJogador = NULL;
}

void Inimigo_A::setJogador(Jogador* pJogador)
{
	this->pJogador = pJogador;
}

void Inimigo_A::executar(float dt)
{
	proximaPosicao = posicao;

	if (cooldown > 0)
	{
		cooldown--;
		return;
	}

	if (estaNoAr)
	{
		deslocamentoY += GRAVIDADE * dt;
		proximaPosicao.atualizarY(deslocamentoY);
	}
	else
	{
		if (distPercorrida < trajeto)
		{
			proximaPosicao.atualizarX(direcao * VELMOV * dt);
			distPercorrida += fabs(proximaPosicao.getX() - posicao.getX());
		}
		else
		{
			distPercorrida = 0;
			direcao *= -1;
		}
	}
}

/* Essa fun��o fica vazia por enquanto */
void Inimigo_A::colisao(int direcao_colisao, ID ind)
{
	cooldown = 20;

	if (direcao_colisao == COLISAO_CIMA)
	{
		if (ind == jogador)
		{
			num_vidas -= 5;
		}
	}
	else
	{
		direcao *= -1;
	}
}
