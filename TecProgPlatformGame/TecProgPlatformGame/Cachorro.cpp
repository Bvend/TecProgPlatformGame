#include "Cachorro.h"
#include "Jogo.h"

#define CAMINHO_CACHORRO "./recurssos/Cachorro/Cachorro.png"

namespace Entidades
{
	namespace Personagens
	{
		Cachorro::Cachorro(Gerenciadores::Gerenciador_Grafico* ger, CoordF pos) :
			Inimigo(Id::CACHORRO, ger, pos, CoordF(30.f, 30.f)),
			trajeto(2 * tamanho.getX() + rand() % (int)tamanho.getX()),
			distPercorrida(trajeto / 2.f)
		{
			inicializarCorpo(CAMINHO_CACHORRO, posicao, tamanho);

			velocidade.setX(50.f + rand() % 26);

			// Atribui aleatoriamente direcao incial de movimento
			if (rand() % 2)
			{
				direcao = 1;
			}
			else
			{
				direcao = -1;
			}
		}

		Cachorro::~Cachorro()
		{
		}

		/* Essa função fica vazia por enquanto */
		void Cachorro::colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar)
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
			else  if (antingiuTodaRecarga())
			{
				direcao *= -1;
				distPercorrida = 0;
				reiniciarTempoRecarregando();
			}
		}

		void Cachorro::executar()
		{
			atualizarTempoRecarregando();

			if (atingiuMetadeRecarga())
			{
				mover();
			}
		}

		void Cachorro::mover()
		{
			proximaPosicao = posicao;

			if (estaNoAr)
			{
				velocidade.atualizarY(GRAVIDADE);
				proximaPosicao.atualizarY(velocidade.getY() * Jogo::getDt());
			}
			else if (distPercorrida < trajeto)
			{
				proximaPosicao.atualizarX(direcao * velocidade.getX() * Jogo::getDt());
				distPercorrida += fabs(proximaPosicao.getX() - posicao.getX());
			}
			else
			{
				distPercorrida = 0;
				direcao *= -1;
			}
		}
	}
}



