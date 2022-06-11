#include "Projetil.h"
#include "Jogo.h"

#define CAMINHO_PROJETIL "./recurssos/Projetil/Polen.png"

namespace Entidades
{
	Projetil::Projetil(Gerenciadores::Gerenciador_Grafico* ger, CoordF pos, int dir):
		Entidade(Id::PROJETIL, ger, pos, CoordF(15.f, 15.f)),
		velMov(190.f),
		direcao(dir)
	{
		inicializarCorpo(CAMINHO_PROJETIL, posicao, tamanho);
		deslocamentoY = -2.f * velMov * Jogo::getDt();
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
			estaVivo = false;
		}
	}

	void Projetil::executar()
	{
		mover();
	}

	void Projetil::mover()
	{
		if (deslocamentoY < 2 * velMov)
		{
			deslocamentoY += GRAVIDADE * Jogo::getDt();;
		}
		proximaPosicao.atualizarY(deslocamentoY);

		proximaPosicao.atualizarX(direcao * velMov * Jogo::getDt());
	}

	void Projetil::atualizarPos()
	{
		if (proximaPosicao.getX() < 0)
		{
			estaVivo = false;
			return;
		}

		setPosicao(proximaPosicao);
	}
}


