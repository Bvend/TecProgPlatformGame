#pragma once
#include "Inimigo.h"
#include <time.h>

namespace Entidades
{
	namespace Personagens
	{
		class Cachorro : public Inimigo
		{
		private:
			float trajeto;
			float distPercorrida;

		public:
			Cachorro(Gerenciadores::Gerenciador_Grafico* ger = NULL, CoordF pos = CoordF(0.0f, 0.0f));
			~Cachorro();

			void colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar);

			void executar();

			void mover();
		};
	}
}



