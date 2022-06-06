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
	Gerenciador_Grafico* gerenciadorGrafico;
	Gerenciador_Eventos* gerenciadorEventos;
	Gerenciador_Colisoes* gerenciadorColisoes;
	Fase* faseTeste;
	const float dt;

public:
	Jogo();

	~Jogo();

	void executar();
};

