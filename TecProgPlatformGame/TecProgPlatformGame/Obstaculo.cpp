#include "Obstaculo.h"

namespace Entidades
{
	namespace Obstaculos
	{
		Obstaculo::Obstaculo(Id ind, Gerenciadores::Gerenciador_Grafico* ger, CoordF pos, CoordF tam) :
			Entidade(ind, ger, pos, tam)
		{
		}

		Obstaculo::~Obstaculo()
		{
		}
	}
}


