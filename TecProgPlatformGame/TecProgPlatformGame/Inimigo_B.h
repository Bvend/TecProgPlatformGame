#pragma once
#include "Inimigo.h"
#include "Plataforma.h"
#include "Projetil.h"
#include "ListaEntidades.h"
#include <time.h>

namespace Entidades
{
	namespace Personagens
	{
		class Inimigo_B : public Inimigo
		{
		private:
			int direcao;
			float velMov;
			Jogador* pJogador;
			Listas::ListaEntidades* pListaEntidades;
			Obstaculos::Plataforma* pPlataforma;

		public:
			Inimigo_B(Gerenciadores::Gerenciador_Grafico* ger = NULL, CoordF pos = CoordF(0.0f, 0.0f), Listas::ListaEntidades* pLE = NULL, Obstaculos::Plataforma* pPt = NULL);
			~Inimigo_B();

			void setJogador(Jogador* pJ);

			void colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar);

			int direcaoProjetil();

			void executar();

			void mover();

			void atacar();
		};
	}
}



