#include "Gerenciador_Eventos.h"

Gerenciador_Eventos::Gerenciador_Eventos(Gerenciador_Grafico *GerenciadorGrafico):
pGerenciadorGrafico(GerenciadorGrafico)
{
    pWindow = NULL;
    if (GerenciadorGrafico != NULL)
    {
        pWindow = GerenciadorGrafico->getWindow();
    }
}

Gerenciador_Eventos::~Gerenciador_Eventos()
{
    pGerenciadorGrafico = NULL;
    pWindow = NULL;
}

void Gerenciador_Eventos::verificarEvents()
{
	sf::Event event;

    while (pWindow->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
        {
            pGerenciadorGrafico->closeWindow();
        }
        //if (event.type == sf::Event::KeyPressed)
            //pInputM->handleKeyPressed(event.key.code);
        //if (event.type == sf::Event::KeyReleased)
            //pInputM->handleKeyReleased(event.key.code);
    }
}
