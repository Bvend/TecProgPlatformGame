#pragma once
#include <time.h>
#include "Fase1.h"
#include "Fase2.h"
#include "Gerenciador_Eventos.h"

class Fase;
class Fase2;

class Jogo
{
private:
	Gerenciadores::Gerenciador_Grafico* gerenciadorGrafico;
	Gerenciadores::Gerenciador_Eventos* gerenciadorEventos;
	Gerenciadores::Gerenciador_Colisoes* gerenciadorColisoes;
	Fases::Fase2 faseTeste;
	static const float dt;
	Entidades::Personagens::Jogador* jogador1;
	Entidades::Personagens::Jogador* jogador2;

public:
	static const float getDt();

	Jogo();
	~Jogo();

	void executar();
};

