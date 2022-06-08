#pragma once
#include "Gerenciador_Colisoes.h"
#include "Inimigo_A.h"
#include "Inimigo_B.h"
#include "Jogador.h"
#include "Obst_A.h"
#include "Obst_B.h"
#include "Obst_C.h"

class Fase
{
protected:
	Gerenciador_Grafico* pGerenciadorGrafico;
	Gerenciador_Colisoes* pGerenciadorColisoes;
	ListaEntidades* listaEntidades;
	Jogador* jogador1;

public:
	Fase(Gerenciador_Grafico* GerenciadorGrafico = NULL, Gerenciador_Colisoes* pGerenciadorColisoes = NULL, float deltaTime = (1.f/60.f));
	~Fase();

	void inicializarEntidades();

	void updateFase();

	void executaEntidades();

	void colidirEntidades();

	void atualizarPosicaoEntidades();

	void renderizarEntidades();
};

