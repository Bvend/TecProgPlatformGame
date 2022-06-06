#pragma once
#include<SFML/Graphics.hpp>
#include "Fase.h"
#include "Gerenciador_Eventos.h"

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

