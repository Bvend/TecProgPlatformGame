#pragma once
#include "Fase.h"

namespace Fases
{
	class Fase1 : public Fase
	{
	private:
		
	public:
		Fase1(Gerenciadores::Gerenciador_Grafico* GerenciadorGrafico = NULL, Gerenciadores::Gerenciador_Colisoes* pGerenciadorColisoes = NULL);
		~Fase1();
	};
}


