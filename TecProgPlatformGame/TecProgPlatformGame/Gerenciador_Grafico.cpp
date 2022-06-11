#include "Gerenciador_Grafico.h"

#define LARGURA 1280
#define ALTURA 720

namespace Gerenciadores
{
	Gerenciador_Grafico::Gerenciador_Grafico() :
		janela(new sf::RenderWindow(sf::VideoMode(1280, 720), "Jogo", sf::Style::Default)),
		//vista(new sf::View(sf::Vector2f(LARGURA / 2.f, ALTURA / 2.f), sf::Vector2f((float) LARGURA, (float) ALTURA))),
		mapaTextura()
	{
		//janela->setView(*vista);
	}

	Gerenciador_Grafico::~Gerenciador_Grafico()
	{
		for (std::map<const char*, sf::Texture*>::iterator it = mapaTextura.begin(); it != mapaTextura.end(); ++it) {
			delete (it->second);
		}

		janela = NULL;
		//delete vista;
	}

	sf::RenderWindow* Gerenciador_Grafico::getJanela() const
	{
		return janela;
	}

	bool Gerenciador_Grafico::janelaEstaAberta()
	{
		return (janela->isOpen());
	}

	void Gerenciador_Grafico::limparJanela()
	{
		if (janelaEstaAberta())
		{
			janela->clear(sf::Color::White);
		}
	}

	void Gerenciador_Grafico::renderizar(sf::RectangleShape* body)
	{
		if (janelaEstaAberta())
		{
			janela->draw(*body);
		}
	}

	void Gerenciador_Grafico::display()
	{
		if (janelaEstaAberta())
		{
			janela->display();
		}
	}

	void Gerenciador_Grafico::fecharJanela()
	{
		if (janelaEstaAberta())
		{
			janela->close();
		}
	}

	/* Função para ajustar a view de acordo de com a posição de
	   determinado ente, geralmente o jogador
	   ATENCAO - TAVA USANDO ENTE AGR USO PERSONAGEM */
	   /*
	   void Gerenciador_Grafico::centralizarVista(CoordF pos, CoordF tam)
	   {
		   if (pos.getX() + tam.getX() > LARGURA / 2.f)
		   {
			   vista->setCenter(sf::Vector2f(pos.getX() + tam.getX(), ALTURA / 2.f));
		   }
		   else
		   {
			   vista->setCenter(sf::Vector2f(LARGURA / 2.f, ALTURA / 2.f));
		   }
		   if (janelaEstaAberta())
		   {
			   janela->setView(*vista);
		   }
	   }
	   */

	sf::Texture* Gerenciador_Grafico::carregarTextura(const char* caminho)
	{
		std::map<const char*, sf::Texture*>::iterator it;
		for (it = mapaTextura.begin(); it != mapaTextura.end(); it++)
		{
			if (!strcmp(it->first, caminho))
			{
				return it->second;
			}
		}

		sf::Texture* tex = new sf::Texture();

		try
		{
			if (!tex->loadFromFile(caminho))
			{
				throw "Falha ao carregar arquivo de Textura";
			}

			mapaTextura.insert(std::pair<const char*, sf::Texture*>(caminho, tex));
		}
		catch (const char* e)
		{
			delete tex;
			std::cout << "ERRO - " << e << std::endl; 
			exit(1);
		}

		return tex;
	}
}
