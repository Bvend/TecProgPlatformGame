#include "FlorChefe.h"
#include "Jogo.h"

#define CAMINHO_INIMIGO_B "./recurssos/FlorChefe/FlorChefe.png"

namespace Entidades
{
	namespace Personagens
	{
		FlorChefe::FlorChefe(Gerenciadores::Gerenciador_Grafico* ger, CoordF pos, Listas::ListaEntidades* pLE, Obstaculos::Plataforma* pPt) :
			Inimigo(Id::FLORCHEFE, ger, pos, CoordF(60.f, 60.f)),
			pListaEntidades(pLE),
			pPlataforma(pPt),
			pJogador1(NULL),
			pJogador2(NULL)
		{
			intervaloRecarga = 10.f;

			inicializarCorpo(CAMINHO_INIMIGO_B, posicao, tamanho);

			velocidade.setX(50.f);

			if (rand() % 2)
			{
				direcao = 1;
			}
			else
			{
				direcao = -1;
			}
		}

		FlorChefe::~FlorChefe()
		{
			pJogador1 = NULL;
			pJogador2 = NULL;
		}

		void FlorChefe::setJogador1(Jogador* pJ1)
		{
			pJogador1 = pJ1;
		}

		void FlorChefe::setJogador2(Jogador* pJ2)
		{
			pJogador2 = pJ2;
		}

		void FlorChefe::colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar)
		{
			Id ind = pEntidade->getId();

			if (ind != Id::POLEN && reposicionar)
			{
				reposicionarColisao(pEntidade->getPosicao(), pEntidade->getTamanho(), direcao_colisao);
			}

			if ((ind == Id::JOGADOR1 || ind == Id::JOGADOR2) && direcao_colisao == COLISAO_CIMA)
			{
				estaVivo = false;
			}
			else  if (antingiuTodaRecarga())
			{
				reiniciarTempoRecarregando();
			}
		}

		Entidades::Personagens::Jogador* FlorChefe::getJogadorMaisProximo()
		{
			if (pJogador1 == NULL && pJogador2 == NULL)
			{
				return NULL;
			}
			else if (pJogador1 == NULL)
			{
				return pJogador2;
			}
			else if (pJogador2 == NULL)
			{
				return pJogador1;
			}
			else if (fabs(pJogador1->getCentroX() - getCentroX()) < fabs(pJogador2->getCentroX() - getCentroX()))
			{
				return pJogador1;
			}
			else
			{
				return pJogador2;
			}
		}

		int FlorChefe::direcaoProjetil(Entidades::Personagens::Jogador* pJogador)
		{
			if (pJogador->getCentroX() > getCentroX())
			{
				return 1;
			}
			else
			{
				return -1;
			}
		}

		void FlorChefe::executar()
		{
			atualizarTempoRecarregando();

			mover();

			if ((antingiuTodaRecarga()) && (fabs(getJogadorMaisProximo()->getCentroX() - pPlataforma->getCentroX()) < 300.f))
			{
				atacar();
			}
		}

		void FlorChefe::mover()
		{
			Entidades::Personagens::Jogador* pJogador = getJogadorMaisProximo();

			if (pJogador && pPlataforma)
			{
				if (pJogador->getDireita() < getEsquerda()
					&& getDireita() <= pPlataforma->getDireita())
				{
					proximaPosicao.atualizarX(velocidade.getX() * Jogo::getDt());
				}
				else if (pJogador->getEsquerda() > getDireita()
					&& getEsquerda() >= pPlataforma->getEsquerda())
				{
					proximaPosicao.atualizarX(-velocidade.getX() * Jogo::getDt());
				}
			}

			if (estaNoAr)
			{
				velocidade.atualizarY(GRAVIDADE);
				proximaPosicao.atualizarY(velocidade.getY() * Jogo::getDt());
			}
		}

		void FlorChefe::atacar()
		{
			Polen* pPolen = new Polen(getGerenciadorGrafico(), CoordF(getCentroX(), getCentroY()), direcaoProjetil(getJogadorMaisProximo()));
			pListaEntidades->adicionarEntidade(pPolen);
			reiniciarTempoRecarregando();
		}
	}
}

