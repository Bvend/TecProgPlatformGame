#pragma once
#include <time.h>
#include "JardimVerde.h"
#include "JardimFlores.h"
#include "Gerenciador_Eventos.h"

class Fase;
class Fase2;

class Jogo
{
private:
	Gerenciadores::Gerenciador_Grafico* gerenciadorGrafico;
	Gerenciadores::Gerenciador_Eventos* gerenciadorEventos;
	Gerenciadores::Gerenciador_Colisoes* gerenciadorColisoes;
	Fases::JardimFlores faseTeste;
	static const float dt;
	Entidades::Personagens::Jogador* jogador1;
	Entidades::Personagens::Jogador* jogador2;

public:
	static const float getDt();

	Jogo();
	~Jogo();

	void executar();
};

