#pragma once
#include <SFML/Graphics.hpp>
#include "Gerenciador_Grafico.h"
using namespace sf;
class Animacao
{
private:
	
	//const unsigned int contadorImagem;
	//unsigned int imagemAtual;
	const unsigned int contadorImagem;
	unsigned int imagemAtual;
	Texture* textura;
	float tempoTotal;
	const float switchTime;
	IntRect RectSize;

public:
	Animacao(const char* path, const unsigned int contImag, const float st);
	~Animacao() {}

	void update(const float dt, bool AEsquerda);
	void reset();
	IntRect getSize() const;
	Texture* getTextura() const;

};

