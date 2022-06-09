#include "Projetil.h"
#include "Jogo.h"

#define CAMINHO_PROJETIL "./recurssos/Projetil/Projetil.png"

Projetil::Projetil(Gerenciador_Grafico* ger, CoordF pos, int dir):
Personagem(Id::PROJETIL, pos, CoordF(20.f, 20.f), 1),
velMov(400.f),
direcao(dir)
{
	corpo.inicializar(CAMINHO_PROJETIL, posicao, tamanho, ger);
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

	num_vidas--;

	if (ind == Id::MOLA || ind == Id::PAREDE || ind == Id::ESPINHO && reposicionar)
	{
		reposicionarColisao(pEntidade->getPosicao(), pEntidade->getTamanho(), direcao_colisao);
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
