#pragma once
#include "Gerenciador_Grafico.h"

enum Animacao_ID {
	parado = 0,
	andar,
	pular,
	atacar
};

class AnimacaoMovimento
{
private:
	//map<Animacao_ID, AnimacaoIndividual*> mapaAnimacao;
	Animacao_ID atualAnimacao;
	Texture* textura;
	RectangleShape body;
	static Gerenciador_Grafico* pGerenGrafico;

public:
	AnimacaoMovimento();
	~AnimacaoMovimento();
};

