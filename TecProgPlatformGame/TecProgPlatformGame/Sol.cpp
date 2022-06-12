#include "Sol.h"
#include "Jogo.h"

#define CAMINHO_INIMIGO_C "./recurssos/Sol/Sol.png"

namespace Entidades
{
	namespace Personagens
	{
		Sol::Sol(Gerenciadores::Gerenciador_Grafico* ger, CoordF pos) :
			Inimigo(Id::SOL, ger, pos, CoordF(50.f, 50.f)),
			trajeto(3 * tamanho.getX() + rand() % (int)tamanho.getX()),
			distPercorrida(100.f)
		{
			inicializarCorpo(CAMINHO_INIMIGO_C, posicao, tamanho);

			velocidade.setX(50.f + rand() % 76);

			if (rand() % 2)
			{
				direcao = 1;
			}
			else
			{
				direcao = -1;
			}
		}

		Sol::~Sol()
		{
		}

		void Sol::colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar)
		{
			Id ind = pEntidade->getId();

			if (reposicionar)
			{
				reposicionarColisao(pEntidade->getPosicao(), pEntidade->getTamanho(), direcao_colisao);
			}

			if ((ind == Id::JOGADOR1 || ind == Id::JOGADOR2) && direcao_colisao == COLISAO_CIMA)
			{
				estaVivo = false;
			}
		}

		void Sol::executar()
		{
			mover();
		}

		void Sol::mover()
		{
			// Movimento no eixo X
			if (distPercorrida < trajeto)
			{
				proximaPosicao.atualizarX(direcao * velocidade.getX() * Jogo::getDt());
				distPercorrida += fabs(proximaPosicao.getX() - posicao.getX());
			}
			else
			{
				distPercorrida = 0.f;
				direcao *= -1;
			}

			// Movimento no eixo Y
			velocidade.setY(0.f);
			if (estaNoAr)
			{
				velocidade.atualizarY(GRAVIDADE);
			}
			// Aplicar força
			velocidade.atualizarY(-GRAVIDADE);
			estaNoAr = true;
			proximaPosicao.atualizarY(velocidade.getY() * Jogo::getDt());
		}
	}
}

