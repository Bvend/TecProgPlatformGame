#include "Inimigo.h"

namespace Entidades
{
	namespace Personagens
	{
		Inimigo::Inimigo(Id ind, Gerenciadores::Gerenciador_Grafico* ger, CoordF pos, CoordF tam, int vid) :
			Personagem(ind, ger, pos, tam, vid)
		{
		}

		Inimigo::~Inimigo()
		{
		}
	}
}


