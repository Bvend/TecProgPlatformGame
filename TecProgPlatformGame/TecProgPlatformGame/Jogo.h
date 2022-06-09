#pragma once
#include <time.h>
#include "Fase.h"
#include "Gerenciador_Eventos.h"

class Jogo
{
private:
<<<<<<< HEAD
	Gerenciador_Grafico* gerenciadorGrafico;
	Gerenciador_Eventos* gerenciadorEventos;
	Gerenciador_Colisoes* gerenciadorColisoes;
	Fase* faseTeste;
	static const float dt;
=======
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
>>>>>>> 91dcff85e6c0a5b60e1520e6cef76ba4e4b29c12

public:
	static const float getDt();

	Jogo();
	~Jogo();

	void executar();
};

