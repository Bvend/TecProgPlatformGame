#pragma once
#include "Ente.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "ListaEntidades.h"
#include <SFML/Graphics.hpp>
class Fase:
	public Ente
{
protected:
	ListaEntidades* listaEntidades;
	Inimigo* i1;
	Jogador* jogador1;
	sf::RenderWindow* window;
public:
	Fase(Jogador* j1, sf::RenderWindow* w);
	~Fase();
	void inicializaElementos();
	ListaEntidades* getListaEntidades() { return listaEntidades; }
	void executar() {};
	void gerenciar_colisoes();
};

