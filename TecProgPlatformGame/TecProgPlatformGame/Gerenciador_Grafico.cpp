#include "Gerenciador_Grafico.h"

namespace Gerenciadores
{
	Gerenciador_Grafico::Gerenciador_Grafico():
		tamanhoJanela(1280.f, 720.f),
		janela(new sf::RenderWindow(sf::VideoMode(static_cast<unsigned int>(tamanhoJanela.getX()), static_cast<unsigned int>(tamanhoJanela.getY())), "Jogo", sf::Style::Default)),
		mapaTextura()
	{
	}

	Gerenciador_Grafico::~Gerenciador_Grafico()
	{
		for (std::map<const char*, sf::Texture*>::iterator it = mapaTextura.begin(); it != mapaTextura.end(); ++it) {
			delete (it->second);
		}

		janela = NULL;
	}

	float Gerenciador_Grafico::getAlturaJanela()
	{
		return tamanhoJanela.getY();
	}

	float Gerenciador_Grafico::getLarguraJanela()
	{
		return tamanhoJanela.getX();
	}

	sf::RenderWindow* Gerenciador_Grafico::getJanela() const
	{
		return janela;
	}

	void Gerenciador_Grafico::verificarEvento()
	{
		sf::Event event;

		if (janelaEstaAberta())
		{
			while (janela->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					fecharJanela();
				}
			}
		}
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

	void Gerenciador_Grafico::renderizarCorpo(sf::RectangleShape* corpo)
	{
		if (janelaEstaAberta())
		{
			janela->draw(*corpo);
		}
	}

	void Gerenciador_Grafico::renderizarTexto(sf::Text* texto)
	{
		if (janelaEstaAberta())
		{
			janela->draw(*texto);
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

	/* O uso de mapaTextura nessa classe foi inspirado nos vídeos do então monitor Matheus Burda */
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
