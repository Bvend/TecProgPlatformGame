#include "Jogo.h"

const float Jogo::dt = (1.f / 60);

const float Jogo::getDt()
{
    return dt;
}

Jogo::Jogo():
gerenciadorGrafico(new Gerenciadores::Gerenciador_Grafico()),
gerenciadorEventos(new Gerenciadores::Gerenciador_Eventos(gerenciadorGrafico)),
gerenciadorColisoes(new Gerenciadores::Gerenciador_Colisoes()),
faseTeste(new Fases::Fase1(gerenciadorGrafico, gerenciadorColisoes))
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

    while (gerenciadorGrafico->janelaEstaAberta())
    {
        // Processa eventos
        gerenciadorEventos->verificarEvents();

        // Gerenciar Tempo com 60 fps
        tempoDesdeUltimoUpdate += clock.restart();
        while (tempoDesdeUltimoUpdate > sf::seconds(dt))
        {
            tempoDesdeUltimoUpdate -= sf::seconds(dt);

            // Novamente processa eventos
            faseTeste->executar();

        }

        // Renderiza as coisas tudo
        gerenciadorGrafico->limparJanela();
        faseTeste->renderizarEntidades();
        gerenciadorGrafico->display();
    }
}
