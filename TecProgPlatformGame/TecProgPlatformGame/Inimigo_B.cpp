#include "Inimigo_B.h"

Inimigo_B::Inimigo_B(int vidas, CoordF pos, CoordF tam, ID ind) :
Inimigo(vidas, pos, tam, ind),
pJogador(NULL),
cooldown(15)
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

void Inimigo_B::setJogador(Jogador* pJogador)
{
}

void Inimigo_B::colisao(int direcao_colisao, ID ind)
{
}

void Inimigo_B::executar(float dt)
{
}
