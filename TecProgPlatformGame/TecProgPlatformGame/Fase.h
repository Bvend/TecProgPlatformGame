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
	class Fase : public Ente
	{
	protected:
		Gerenciadores::Gerenciador_Colisoes* pGerenciadorColisoes;
		Listas::ListaEntidades* listaEntidades;
		//vector<>
		Entidades::Personagens::Jogador* jogador1;
		sf::Texture texturaFundo;
		sf::Sprite SpriteFundo;

	public:
		Fase(Gerenciadores::Gerenciador_Grafico* GerenciadorGrafico = NULL, Gerenciadores::Gerenciador_Colisoes* pGerenciadorColisoes = NULL);
		virtual ~Fase();

		void inicializarEntidades();

		void executar();

		void executarEntidades();

		void colidirEntidades();

		void atualizarPosicaoEntidades();

		void renderizarEntidades();
	};
}

