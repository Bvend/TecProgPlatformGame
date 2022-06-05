#pragma once
#include<SFML/Graphics.hpp>
#include "Jogador.h"
#include "Inimigo.h"
#include "ListaEntidades.h"
#include "Fase.h"
#include "Gerenciador_Eventos.h"
#include "Gerenciador_Colisoes.h"
#include "Obst_A.h"
#include "Inimigo_A.h"

class Jogo
{
private:
	Gerenciador_Grafico* GerenciadorGrafico;
	Gerenciador_Eventos* GerenciadorEventos;
	Gerenciador_Colisoes* GerenciadorColisoes;

	const float dt;

	RectangleShape BackGroundShape;
	Obst_A* parede;
	Obst_A* parede1;
	Obst_A* parede2;
	Obst_A* parede3;
	Inimigo_A* inimigo;
	Jogador *player1;
	ListaEntidades* LES;

public:
	Jogo();

	~Jogo();

	void executar();
};

