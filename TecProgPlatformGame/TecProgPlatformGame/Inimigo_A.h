#pragma once
#include "Inimigo.h"
#include <time.h>

namespace Entidades
{
	namespace Personagens
	{
		class Inimigo_A : public Inimigo
		{
		private:
			float trajeto;
			float distPercorrida;
			int direcao;
			float velMov;

		public:
			Inimigo_A(Gerenciadores::Gerenciador_Grafico* ger = NULL, CoordF pos = CoordF(0.0f, 0.0f));
			~Inimigo_A();

			void colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar);

			void executar();

			void mover();
		};
	}
}



