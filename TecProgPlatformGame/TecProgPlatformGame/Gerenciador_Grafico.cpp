#include "Gerenciador_Grafico.h"

#define LARGURA 1280
#define ALTURA 720

Gerenciador_Grafico::Gerenciador_Grafico():
window(new sf::RenderWindow(sf::VideoMode(1280, 720), "Jogo", sf::Style::Titlebar | sf::Style::Close)),
view(new sf::View(sf::Vector2f(LARGURA / 2.f, ALTURA / 2.f), sf::Vector2f((float) LARGURA, (float) ALTURA))),
mapaTextura()
{
	window->setView(*view);
}

Gerenciador_Grafico::~Gerenciador_Grafico()
{
	for (std::map<const char*, sf::Texture*>::iterator it = mapaTextura.begin(); it != mapaTextura.end(); ++it) {
		delete (it->second);
	}
	
	window = NULL;
	delete view;
}

sf::RenderWindow* Gerenciador_Grafico::getWindow() const
{
	return window;
}

bool Gerenciador_Grafico::isWindowOpen()
{
	return (window->isOpen());
}

void Gerenciador_Grafico::clearWindow()
{
	if (isWindowOpen())
	{
		window->clear();
	}
}

void Gerenciador_Grafico::renderizar(sf::RectangleShape* body)
{
	if (isWindowOpen())
	{
		window->draw(*body);
	}
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
	if (isWindowOpen())
	{
		window->close();
	}
}

/* Função para ajustar a view de acordo de com a posição de 
   determinado ente, geralmente o jogador
   ATENCAO - TAVA USANDO ENTE AGR USO PERSONAGEM */
void Gerenciador_Grafico::centralizarView(CoordF pos, CoordF tam)
{
	if (pos.getX() + tam.getX() > LARGURA / 2.f)
	{
		view->setCenter(sf::Vector2f(pos.getX() + tam.getX(), pos.getY()));//ALTURA / 2 + (pEnte->getCima() - ALTURA / 2)/5));
	}
	else
	{
		view->setCenter(sf::Vector2f(LARGURA / 2.f, pos.getY()));
	}
	if (isWindowOpen())
	{
		window->setView(*view);
	}
}

sf::Texture* Gerenciador_Grafico::loadTextura(const char* path)
{
	std::map<const char*, sf::Texture*>::iterator it;
	for (it = mapaTextura.begin(); it != mapaTextura.end(); ++it) {
		if (!strcmp(it->first, path))
			return it->second;
	}

	sf::Texture* tex = new sf::Texture();

	if (!tex->loadFromFile(path)) {
		std::cout << "ERRO! houve falha ao carregar arquivo!" << std::endl;
		exit(1);
	}
	
	mapaTextura.insert(std::pair<const char*, sf::Texture*>(path, tex));

	return tex;
}
