#include "Inimigo_A.h"

#define VELMOV 150.f

Inimigo_A::Inimigo_A(int vidas, CoordF pos, CoordF tam, ID ind):
Inimigo(vidas, pos, tam, ind),
pJogador(NULL),
trajeto(2 * tamanho.getX() + rand() % (int)tamanho.getX()),
distPercorrida(0),
cooldown(0)
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
	proximaPosicao = posicao;

	if (cooldown > 0)
	{
		cout << cooldown << endl;
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
void Inimigo_A::colisao(Entidade* Entidade2)
{
	cooldown = 50;

	if ((posicao.getY() > Entidade2->getCima()
		&& posicao.getY() + tamanho.getY() > Entidade2->getCima() + Entidade2->getAltura()
		&& posicao.getX() < Entidade2->getDireita()
		&& getDireita() > Entidade2->getEsquerda())
		)
	{
		if (Entidade2->getID() == jogador)
		{
			num_vidas -= 5;
			if (num_vidas <= 0)
			{
				body.setFillColor(sf::Color::Yellow);
			}
		}
	}
	else
	{
		direcao *= -1;
	}

	reposicionarColisao(Entidade2->getPosicao(), Entidade2->getTamanho());
}
