#pragma once
#include <time.h>
#include "Fase.h"
#include "Gerenciador_Eventos.h"

class Jogo
{
private:
	Gerenciador_Grafico* gerenciadorGrafico;
	Gerenciador_Eventos* gerenciadorEventos;
	Gerenciador_Colisoes* gerenciadorColisoes;
	Fase* faseTeste;
	static const float dt;

public:
	static const float getDt();

	Jogo();
	~Jogo();

	void executar();
};

