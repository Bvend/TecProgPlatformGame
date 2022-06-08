#include "Jogo.h"

const float Jogo::dt = (1.f / 60);

const float Jogo::getDt()
{
    return dt;
}

Jogo::Jogo():
gerenciadorGrafico(new Gerenciador_Grafico()),
gerenciadorEventos(new Gerenciador_Eventos(gerenciadorGrafico)),
gerenciadorColisoes(new Gerenciador_Colisoes()),
faseTeste(new Fase(gerenciadorGrafico, gerenciadorColisoes))
{
	executar();
}

Jogo::~Jogo()
{
    delete gerenciadorGrafico;
    delete gerenciadorEventos;
    delete gerenciadorColisoes;
    delete faseTeste;
}

void Jogo::executar()
{
    sf::Clock clock;
    sf::Time tempoDesdeUltimoUpdate;

    while (gerenciadorGrafico->isWindowOpen())
    {
        // Processa eventos
        gerenciadorEventos->verificarEvents();

        // Gerenciar Tempo com 60 fps
        tempoDesdeUltimoUpdate += clock.restart();
        while (tempoDesdeUltimoUpdate > sf::seconds(dt))
        {
            tempoDesdeUltimoUpdate -= sf::seconds(dt);

            // Novamente processa eventos
            faseTeste->updateFase();

        }

        // Renderiza as coisas tudo
        gerenciadorGrafico->clearWindow();
        faseTeste->renderizarEntidades();
        gerenciadorGrafico->display();
    }
}
