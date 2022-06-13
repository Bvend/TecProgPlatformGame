#pragma once
#include <time.h>
#include "JardimVerde.h"
#include "JardimFlores.h"
#include "Menu_Principal.h"
#include "Menu_Fases.h"
#include "Menu_Jogadores.h"
#include "Menu_Ranking.h"

class Fase;
class Fase2;

enum class Execucao
{
	MENU_PRINCIPAL,
	MENU_FASES,
	MENU_JOGADORES,
	MENU_RANKING,
	FASE_JARDIM_VERDE,
	FASE_JARDIM_FLORES
};

class Jogo
{
private:
	Gerenciadores::Gerenciador_Grafico* gerenciadorGrafico;
	Gerenciadores::Gerenciador_Colisoes* gerenciadorColisoes;
	Fases::JardimVerde* faseJardimVerde;
	Fases::JardimFlores* faseJardimFlores;
	Menus::Menu_Principal* menu_principal;
	Menus::Menu_Fases* menu_fases;
	Menus::Menu_Jogadores* menu_jogadores;
	Menus::Menu_Ranking* menu_ranking;
	static const float dt;
	Execucao emExecucao;
	bool multiplayer;
	bool comecarNaFase1;
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

	void setMultiplayer(bool multiplayer);
	bool getMultiplayer() const;

	void setComecarNaFase1(bool comecarNaFase1);
	bool getComecarNaFase1() const;

	void inicializarFaseJardimVerde();
	void inicializarFaseJardimFlores();

	void avancarFase(Entidades::Personagens::Jogador* pJog);
};

