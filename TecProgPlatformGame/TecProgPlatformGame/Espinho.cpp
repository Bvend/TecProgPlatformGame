#include "Espinho.h"
#include "Jogo.h"

#define CAMINHO_ESPINHO "./recurssos/Espinho/Espinho.png"

namespace Entidades
{
	namespace Obstaculos
	{
		Espinho::Espinho(Gerenciadores::Gerenciador_Grafico* ger, CoordF pos):
			Obstaculo(Id::ESPINHO, ger, pos, CoordF(60, 30))
		{
			inicializarCorpo(CAMINHO_ESPINHO, posicao, tamanho);
		}

		Espinho::~Espinho()
		{
		}

		void Espinho::colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar)
		{
			if (reposicionar && direcao_colisao != COLISAO_DIREITA && direcao_colisao != COLISAO_ESQUERDA)
			{
				reposicionarColisao(pEntidade->getPosicao(), pEntidade->getTamanho(), direcao_colisao);
			}
		}

		void Espinho::executar()
		{
			mover();
		}

		void Espinho::mover()
		{
			if (estaNoAr)
			{
				deslocamentoY += GRAVIDADE * Jogo::getDt();
				proximaPosicao.atualizarY(deslocamentoY);
			}
		}
	}
}

