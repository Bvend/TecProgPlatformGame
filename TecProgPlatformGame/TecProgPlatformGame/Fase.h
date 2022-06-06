#pragma once
#include<SFML/Graphics.hpp>
#include "Gerenciador_Grafico.h"
#include "Gerenciador_Colisoes.h"
#include "ListaEntidades.h"
#include "Inimigo_A.h"
#include "Inimigo_B.h"
#include "Jogador.h"
#include "Obst_A.h"

class Fase
{
protected:
	Gerenciador_Grafico* pGerenciadorGrafico;
	Gerenciador_Colisoes* pGerenciadorColisoes;
	ListaEntidades* listaEntidades;
	const float dt;

	Jogador* jogador1;

public:
	Fase(Gerenciador_Grafico* GerenciadorGrafico = NULL, Gerenciador_Colisoes* pGerenciadorColisoes = NULL, float deltaTime = (1.f/60.f));
	~Fase();

	void inicializarEntidades();

	void updateFase();
	void moveEntidades();
	void colidirEntidades();
	void atualizarPosicaoEntidades();
	void renderizarEntidades();
};

