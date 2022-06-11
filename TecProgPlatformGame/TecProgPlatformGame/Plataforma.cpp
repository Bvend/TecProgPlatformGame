#include "Plataforma.h"
#include "Jogo.h"

#define CAMINHO_PLATAFORMA "./recurssos/Plataforma/Plataforma.png"

namespace Entidades
{
	namespace Obstaculos
	{
		Plataforma::Plataforma(Gerenciadores::Gerenciador_Grafico* ger, CoordF pos, CoordF tam) :
			Obstaculo(Id::PAREDE, ger, pos, tam),
			aceleracaoSustentacao(- GRAVIDADE)
		{
			inicializarCorpo(CAMINHO_PLATAFORMA, posicao, tamanho);
		}

		Plataforma::~Plataforma()
		{
		}

		/* Parede é fixa, portanto em colisao se mantém no mesmo local*/
		void Plataforma::colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar)
		{
			if (reposicionar)
			{
				reposicionarColisao(pEntidade->getPosicao(), pEntidade->getTamanho(), direcao_colisao);
			}
		}

		void Plataforma::executar()
		{
			mover();
		}

		void Plataforma::mover()
		{
			deslocamentoY += GRAVIDADE * Jogo::getDt() + aceleracaoSustentacao * Jogo::getDt();
			proximaPosicao.atualizarY(deslocamentoY);
		}
	}
}


