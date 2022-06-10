#pragma once
#include "Gerenciador_Colisoes.h"
#include "Inimigo_A.h"
#include "Inimigo_B.h"
#include "Inimigo_C.h"
#include "Jogador.h"
#include "Plataforma.h"
#include "Mola.h"
#include "Espinho.h"

namespace Fases
{
	class Fase
	{
	protected:
		Gerenciadores::Gerenciador_Grafico* pGerenciadorGrafico;
		Gerenciadores::Gerenciador_Colisoes* pGerenciadorColisoes;
		Listas::ListaEntidades* listaEntidades;
		Entidades::Personagens::Jogador* jogador1;

	public:
		Fase(Gerenciadores::Gerenciador_Grafico* GerenciadorGrafico = NULL, Gerenciadores::Gerenciador_Colisoes* pGerenciadorColisoes = NULL, float deltaTime = (1.f / 60.f));
		~Fase();

		void inicializarEntidades();

		void executar();

		void executarEntidades();

		void colidirEntidades();

		void atualizarPosicaoEntidades();

		void renderizarEntidades();
	};
}

