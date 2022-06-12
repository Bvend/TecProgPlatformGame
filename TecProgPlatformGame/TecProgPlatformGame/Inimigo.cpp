#include "Inimigo.h"

namespace Entidades
{
	namespace Personagens
	{
		Inimigo::Inimigo(Id ind, Gerenciadores::Gerenciador_Grafico* ger, CoordF pos, CoordF tam):
			Personagem(ind, ger, pos, tam),
			direcao(-1)
		{
		}

		Inimigo::~Inimigo()
		{
		}
	}
}


