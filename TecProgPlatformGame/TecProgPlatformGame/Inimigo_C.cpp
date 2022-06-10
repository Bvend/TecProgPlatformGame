#include "Inimigo_C.h"
#include "Jogo.h"

#define CAMINHO_INIMIGO_C "./recurssos/Inimigo_C/Inimigo_C.png"

namespace Entidades
{
	namespace Personagens
	{
		Inimigo_C::Inimigo_C(Gerenciadores::Gerenciador_Grafico* ger, CoordF pos) :
			Inimigo(Id::INIMIGO_C, ger, pos, CoordF(40.f, 40.f), 1),
			trajeto(500.f),
			distPercorrida(0),
			velMov(150.f),
			direcao(1)
		{
			inicializarCorpo(CAMINHO_INIMIGO_C, posicao, tamanho);
		}

		Inimigo_C::~Inimigo_C()
		{
		}

		void Inimigo_C::colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar)
		{
			Id ind = pEntidade->getId();

			if (reposicionar)
			{
				reposicionarColisao(pEntidade->getPosicao(), pEntidade->getTamanho(), direcao_colisao);
			}

			if (ind == Id::JOGADOR && direcao_colisao == COLISAO_CIMA)
			{
				num_vidas -= 1;
				estaVivo = false;
			}
		}

		void Inimigo_C::executar()
		{
			mover();
		}

		void Inimigo_C::mover()
		{
			if (distPercorrida < trajeto)
			{
				proximaPosicao.atualizarY(direcao * velMov * Jogo::getDt());
				distPercorrida += fabs(proximaPosicao.getY() - posicao.getY());
			}
			else
			{
				distPercorrida = 0;
				direcao *= -1;
			}
		}
	}
}

