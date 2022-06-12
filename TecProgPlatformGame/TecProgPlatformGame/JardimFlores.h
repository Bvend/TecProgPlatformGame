#pragma once
#include "Fase.h"

namespace Fases
{
	class JardimFlores : public Fase
	{
	private:
	public:
		JardimFlores(Gerenciadores::Gerenciador_Grafico* GerenciadorGrafico = NULL, Gerenciadores::Gerenciador_Colisoes* pGerenciadorColisoes = NULL, Jogo* jogo = NULL);
		~JardimFlores();

		void inicializarEntidades();

		void gerarPlataformas();

		void gerarFlorChefe();
	};
}

