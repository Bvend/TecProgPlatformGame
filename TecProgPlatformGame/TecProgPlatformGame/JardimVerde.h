#pragma once
#include "Fase.h"
#include "Cachorro.h"

namespace Fases
{
	class JardimVerde : public Fase
	{
	private:
		
	public:
		JardimVerde(Gerenciadores::Gerenciador_Grafico* GerenciadorGrafico = NULL, Gerenciadores::Gerenciador_Colisoes* pGerenciadorColisoes = NULL, Jogo* jogo = NULL);
		~JardimVerde();

		void inicializarEntidades();

		void gerarPlataformas();
	};
}


