#pragma once
#include "Fase.h"

namespace Fases
{
	class Fase2 : public Fase
	{
	private:
	public:
		Fase2(Gerenciadores::Gerenciador_Grafico* GerenciadorGrafico = NULL, Gerenciadores::Gerenciador_Colisoes* pGerenciadorColisoes = NULL, Jogo* jogo = NULL);
		~Fase2();

		void inicializarEntidades();

		void gerarPlataformas();

		void gerarFlorChefe();
	};
}

