#pragma once
#include <time.h>
#include "JardimVerde.h"
#include "JardimFlores.h"
#include "Menu_Principal.h"
#include "Menu_Fases.h"
#include "Menu_Jogadores.h"
#include "Menu_Ranking.h"
#include "Gerenciador_Eventos.h"

class Fase;
class Fase2;

enum class Execucao
{
	MENU_PRINCIPAL,
	MENU_FASES,
	MENU_JOGADORES,
	MENU_RANKING
};

class Jogo
{
private:
	Gerenciadores::Gerenciador_Grafico* gerenciadorGrafico;
	Gerenciadores::Gerenciador_Eventos* gerenciadorEventos;
	Gerenciadores::Gerenciador_Colisoes* gerenciadorColisoes;
	Fases::JardimFlores faseJardimVerde;
	Fases::JardimFlores faseJardimFlores;
	Menus::Menu_Principal* menu_principal;
	Menus::Menu_Fases* menu_fases;
	Menus::Menu_Jogadores* menu_jogadores;
	Menus::Menu_Ranking* menu_ranking;
	static const float dt;
	Execucao emExecucao;
	Entidades::Personagens::Jogador* jogador1;
	Entidades::Personagens::Jogador* jogador2;

public:
	static const float getDt();

	Jogo();
	~Jogo();

	void setEmExecucao(Execucao executar);

	void loopPrincipal();

	void executar();

	void renderizar();
};

