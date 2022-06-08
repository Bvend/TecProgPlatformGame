#pragma once
#include<SFML/Graphics.hpp>
#include"CoordenadaTL.h"
#include <map>

class Gerenciador_Grafico
{
private:
	sf::RenderWindow* window;
	sf::View* view;
	std::map<const char*, sf::Texture*> mapaTextura;
	
public:
	Gerenciador_Grafico();
	~Gerenciador_Grafico();

	sf::RenderWindow* getWindow() const;
	bool isWindowOpen();
	void clearWindow();
	void renderizar(sf::RectangleShape* body);
	void display();
	void closeWindow();
	void centralizarView(CoordF pos, CoordF tam);
	sf::Texture* loadTextura(const char* path);
};
