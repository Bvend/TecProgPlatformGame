#pragma once
#include "Gerenciador_Colisoes.h"
#include "Cachorro.h"
#include "Sol.h"
#include "FlorChefe.h"
#include "Jogador.h"
#include "Plataforma.h"
#include "Mola.h"
#include "Espinho.h"

#define POSICAO_Y_CHAO 640.f

class Jogo;

namespace Fases
{
	class Fase : public Ente
	{
	protected:
		Gerenciadores::Gerenciador_Colisoes* pGerenciadorColisoes;
		Listas::ListaEntidades* listaEntidades;
		std::vector<CoordF> posicoesDisponiveis;
		Entidades::Personagens::Jogador* pJogador1;
		Entidades::Personagens::Jogador* pJogador2;
		Jogo* pJogo;
		CoordF posicaoInicialJogador;
		CoordF pontoFinal;
		int numJogadores;
		bool avancarFase;

	public:
		Fase(Gerenciadores::Gerenciador_Grafico* GerenciadorGrafico = NULL, Gerenciadores::Gerenciador_Colisoes* pGerenciadorColisoes = NULL, Jogo* jogo = NULL, Id ind = Id::VAZIO);
		virtual ~Fase();

		void setJogador1(Entidades::Personagens::Jogador* pJogador);
		void setJogador2(Entidades::Personagens::Jogador* pJogador);

		void incrementarNumJogadores();

		void limparFase();

		void adicionarEntidade(Entidades::Entidade* pEntidade);

		virtual void inicializarEntidades() = 0;

		void posicionarJogadores();

		virtual void gerarChao();

		virtual void gerarPlataformas() = 0;

		void encontrarPosicoesDisponiveisPlataformas();

		void gerarMolas();

		void gerarEspinhos();

		void gerarCachorros();

		void gerarSois();

		void executar();

		void executarEntidades();

		void colidirEntidades();

		void atualizarPosicaoEntidades();

		void checarProgresso();

		void renderizarEntidades();
	};
}

