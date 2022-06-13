#include "Polen.h"
#include "Jogo.h"

#define CAMINHO_POLEN "./recurssos/Polen/Polen.png"

namespace Entidades
{
	Polen::Polen(Gerenciadores::Gerenciador_Grafico* ger, CoordF pos, int dir):
		Entidade(Id::POLEN, ger, pos, CoordF(15.f, 15.f)),
		velMov(190.f),
		direcao(dir)
	{
		inicializarCorpo(CAMINHO_POLEN, posicao, tamanho);
		deslocamentoY = -2.f * velMov * Jogo::getDt();
	}

	Polen::~Polen()
	{
	}

	void Polen::colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar)
	{
		Id ind = pEntidade->getId();
		if (ind == Id::FLORCHEFE)
		{
			return;
		}
		else
		{
			estaVivo = false;
		}
	}

	void Polen::executar()
	{
		mover();
	}

	void Polen::mover()
	{
		if (deslocamentoY < 2 * velMov)
		{
			deslocamentoY += GRAVIDADE * Jogo::getDt();;
		}
		proximaPosicao.atualizarY(deslocamentoY);

		proximaPosicao.atualizarX(direcao * velMov * Jogo::getDt());
	}

	void Polen::atualizarPos()
	{
		if (proximaPosicao.getX() < 0)
		{
			estaVivo = false;
			return;
		}

		setPosicao(proximaPosicao);
	}
}


