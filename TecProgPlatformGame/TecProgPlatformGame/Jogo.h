#pragma once
#include <time.h>
#include "Fase.h"
#include "Gerenciador_Eventos.h"

class Jogo
{
private:
	Gerenciadores::Gerenciador_Grafico* gerenciadorGrafico;
	Gerenciadores::Gerenciador_Eventos* gerenciadorEventos;
	Gerenciadores::Gerenciador_Colisoes* gerenciadorColisoes;
	Fases::Fase* faseTeste;
	static const float dt;

public:
	static const float getDt();

	Jogo();
	~Jogo();

	void executar();
};

