#include "Gerenciador_Grafico.h"
#include <cstring>
#include <iostream>

#define LARGURA 1280
#define ALTURA 720

Gerenciador_Grafico::Gerenciador_Grafico() :
window(new sf::RenderWindow(sf::VideoMode(LARGURA, ALTURA), "Jogo", sf::Style::Titlebar | sf::Style::Close)),
view(new sf::View(sf::Vector2f(LARGURA / 2.f, ALTURA / 2.f), sf::Vector2f((float) LARGURA, (float) ALTURA))),
mapaTextura()
{
	window->setView(*view);
	window->setFramerateLimit(60);
}

Gerenciador_Grafico::~Gerenciador_Grafico()
{
	for (map<const char*, Texture*>::iterator it = mapaTextura.begin(); it != mapaTextura.end(); ++it) {
		delete (it->second);
	}
	
	delete window;
	delete view;
}

sf::RenderWindow* Gerenciador_Grafico::getWindow() const
{
	return window;
}

bool Gerenciador_Grafico::isWindowOpen()
{
	return window->isOpen();
}

void Gerenciador_Grafico::clearWindow()
{
	window->clear();
}

void Gerenciador_Grafico::render(sf::RectangleShape* body)
{
	window->draw(*body);
}

void Gerenciador_Grafico::display()
{
	if (isWindowOpen())
	{
		window->display();
	}
}

void Gerenciador_Grafico::closeWindow()
{
	window->close();
}

/* Função para ajustar a view de acordo de com a posição de 
   determinado ente, geralmente o jogador
   ATENCAO - TAVA USANDO ENTE AGR USO PERSONAGEM */
void Gerenciador_Grafico::centralizarView(Ente* pEnte)
{
	if (pEnte->getDireita() > LARGURA / 2.f)
	{
		view->setCenter(sf::Vector2f(pEnte->getDireita(), pEnte->getCima()));//ALTURA / 2 + (pEnte->getCima() - ALTURA / 2)/5));
	}
	else
	{
		view->setCenter(sf::Vector2f(LARGURA / 2.f, pEnte->getCima()));
	}
	window->setView(*view);
}

sf::Texture* Gerenciador_Grafico::loadTextura(const char* path)
{
	map<const char*, Texture*>::iterator it;
	for (it = mapaTextura.begin(); it != mapaTextura.end(); ++it) {
		if (!strcmp(it->first, path))
			return it->second;
	}

	Texture* tex = new Texture();

	if (!tex->loadFromFile(path)) {
		std::cout << "ERRO! houve falha ao carregar arquivo!" << std::endl;
		exit(1);
	}
	
	mapaTextura.insert(std::pair<const char*, Texture*>(path, tex));

	return tex;
}
