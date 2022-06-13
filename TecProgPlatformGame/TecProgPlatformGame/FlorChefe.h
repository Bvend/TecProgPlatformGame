#pragma once
#include "Inimigo.h"
#include "Plataforma.h"
#include "Polen.h"
#include "ListaEntidades.h"
#include <time.h>

namespace Entidades
{
	namespace Personagens
	{
		class FlorChefe : public Inimigo
		{
		private:
			Jogador* pJogador1;
			Jogador* pJogador2;
			Listas::ListaEntidades* pListaEntidades;
			Obstaculos::Plataforma* pPlataforma;

		public:
			FlorChefe(Gerenciadores::Gerenciador_Grafico* ger = NULL, CoordF pos = CoordF(0.0f, 0.0f), Listas::ListaEntidades* pLE = NULL, Obstaculos::Plataforma* pPt = NULL);
			~FlorChefe();

			void setJogador1(Jogador* pJ1);
			void setJogador2(Jogador* pJ2);

			void colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar);

			Entidades::Personagens::Jogador* getJogadorMaisProximo();

			int direcaoProjetil(Entidades::Personagens::Jogador* pJogador);

			void executar();

			void mover();

			void atacar();
		};
	}
}



