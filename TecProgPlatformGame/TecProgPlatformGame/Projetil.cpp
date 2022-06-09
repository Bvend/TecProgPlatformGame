#include "Projetil.h"

Projetil::Projetil(Id ind, Gerenciador_Grafico* ger, CoordF pos, CoordF tam, int vid):
Personagem(ind, ger, pos, tam, vid),
velMov(500.f),
direcao(0)
{
}

Projetil::~Projetil()
{
}

void Projetil::colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar)
{
	Id ind = pEntidade->getId();

	if (ind != Id::INIMIGO_B)
	{
		num_vidas--;
		reposicionarColisao(pEntidade->getPosicao(), pEntidade->getTamanho(), direcao_colisao);
	}
}

void Projetil::executar()
{
}
