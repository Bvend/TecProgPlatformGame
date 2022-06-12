#pragma once
#include "Fase.h"
#include "Cachorro.h"

namespace Fases
{
	class Fase1 : public Fase
	{
	private:
		
	public:
		Fase1(Gerenciadores::Gerenciador_Grafico* GerenciadorGrafico = NULL, Gerenciadores::Gerenciador_Colisoes* pGerenciadorColisoes = NULL, Jogo* jogo = NULL);
		~Fase1();

		void inicializarEntidades();

		void gerarPlataformas();
	};
}


