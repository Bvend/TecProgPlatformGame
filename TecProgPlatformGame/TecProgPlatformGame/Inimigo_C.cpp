#include "Inimigo_C.h"
#include "Jogo.h"

#define CAMINHO_INIMIGO_C "./recurssos/Inimigo_C/Sol.png"

namespace Entidades
{
	namespace Personagens
	{
		Inimigo_C::Inimigo_C(Gerenciadores::Gerenciador_Grafico* ger, CoordF pos) :
			Inimigo(Id::INIMIGO_C, ger, pos, CoordF(50.f, 50.f), 1),
			trajeto(200.f),
			distPercorrida(0.f),
			velMov(100.f),
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
			// Movimento no eixo X
			if (distPercorrida < trajeto)
			{
				proximaPosicao.atualizarX(direcao * velMov * Jogo::getDt());
				distPercorrida += fabs(proximaPosicao.getX() - posicao.getX());
			}
			else
			{
				distPercorrida = 0.f;
				direcao *= -1;
			}

			// Movimento no eixo Y
			deslocamentoY = 0.f;
			if (estaNoAr)
			{
				deslocamentoY += GRAVIDADE * Jogo::getDt();
			}
			// Aplicar força
			deslocamentoY -= GRAVIDADE * Jogo::getDt();
			estaNoAr = true;
			proximaPosicao.atualizarY(deslocamentoY);
		}
	}
}

