#include "Projetil.h"
#include "Jogo.h"

#define CAMINHO_PROJETIL "./recurssos/Projetil/Projetil.png"

Projetil::Projetil(Gerenciador_Grafico* ger, CoordF pos, int dir):
Personagem(Id::PROJETIL, ger, pos, CoordF(20.f, 20.f), 2),
velMov(400.f),
direcao(dir)
{
	inicializarCorpo(CAMINHO_PROJETIL, posicao, tamanho);
	deslocamentoY = -velMov * Jogo::getDt();
}

Projetil::~Projetil()
{
}

void Projetil::colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar)
{
	Id ind = pEntidade->getId();
	if (ind == Id::INIMIGO_B)
	{
		return;
	}
	else
	{
		num_vidas = 0;
	}
}

void Projetil::executar()
{
	mover();
}

void Projetil::mover()
{
	if (estaNoAr)
	{
		if (deslocamentoY < 2 * velMov)
		{
			deslocamentoY += GRAVIDADE * Jogo::getDt();;
		}
		proximaPosicao.atualizarY(deslocamentoY);
	}

	proximaPosicao.atualizarX(direcao * velMov * Jogo::getDt());
}

void Projetil::atualizarPos()
{
	if (proximaPosicao.getX() < 0)
	{
		num_vidas = 0;
		return;
	}

	setPosicao(proximaPosicao);
}
