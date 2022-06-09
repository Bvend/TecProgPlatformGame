#pragma once
#include "Inimigo.h"
#include "Obst_A.h"
#include "Projetil.h"
#include "ListaEntidades.h"

class Inimigo_B : public Inimigo
{
private:
	Jogador* pJogador;
	int direcao;
	float cooldown;
	ListaEntidades* pListaEntidades;
	Obst_A* pPlataforma;
	float velMov;

public:
	Inimigo_B(Gerenciador_Grafico* ger = NULL, CoordF pos = CoordF(0.0f, 0.0f), ListaEntidades* pLE = NULL, Obst_A* pPt = NULL);
	~Inimigo_B();

	void setJogador(Jogador* pJ);

	void colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar);

	int direcaoProjetil();

	void executar();

	void mover();
};

