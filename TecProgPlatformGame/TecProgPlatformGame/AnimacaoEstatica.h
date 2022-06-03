#pragma once
#include "Gerenciador_Grafico.h"
class AnimacaoEstatica
{
private:
	Texture* textura;
	RectangleShape body;
	Gerenciador_Grafico* pGerenGrafico;

public:
	AnimacaoEstatica();
	~AnimacaoEstatica();
	void inicializa(const char* path, CoordF posicao, CoordF tamanho, float escala);
	void update(CoordF posicao);
	void render();
};

