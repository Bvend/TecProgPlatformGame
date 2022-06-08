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
	Inimigo_B(Id ind = Id::VAZIO, Gerenciador_Grafico* ger = NULL, CoordF pos = CoordF(0.0f, 0.0f), CoordF tam = CoordF(0.0f, 0.0f), int vid = 0, ListaEntidades* pLE = NULL, Obst_A* pPt = NULL);
	~Inimigo_B();

	void setJogador(Jogador* pJ);

	void colisao(int direcao_colisao, Entidade* pEntidade, bool reposicionar);

	void executar();
};

