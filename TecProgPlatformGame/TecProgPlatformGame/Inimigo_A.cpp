#include "Inimigo_A.h"

#define VELMOV 300.f

Inimigo_A::Inimigo_A(int vidas, CoordF pos, CoordF tam, ID ind):
Inimigo(vidas, pos, tam, ind),
pJogador(NULL),
trajeto(2 * tamanho.getX() + rand() % (int)tamanho.getX()),
distPercorrida(0)
{
	//body.setFillColor(sf::Color::Magenta);

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

	if (estaNoAr)
	{
		deslocamentoY += GRAVIDADE * dt;
		proximaPosicao.atualizarY(deslocamentoY);
	}

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

/* Essa função fica vazia por enquanto */
void Inimigo_A::colisao(Entidade* Entidade2)
{
	/*
	if (interseccao.getX() < interseccao.getY())
	{
		if (Entidade2->getID() == inimigo_A)
		{
			num_vidas--;
			cout << num_vidas << endl;
			if (num_vidas <= 0)
			{
				body.setFillColor(sf::Color::Yellow);
			}
		}
	}
	*/

	reposicionarColisao(Entidade2->getPosicao(), Entidade2->getTamanho());
}

void Inimigo_A::setTexture(Texture* texture)
{
	body.setTexture(texture);
}

