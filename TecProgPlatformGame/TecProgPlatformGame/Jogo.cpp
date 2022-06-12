#include "Jogo.h"

const float Jogo::dt = 0.0167f;

const float Jogo::getDt()
{
    return dt;
}

Jogo::Jogo() :
    gerenciadorGrafico(new Gerenciadores::Gerenciador_Grafico()),
    gerenciadorEventos(new Gerenciadores::Gerenciador_Eventos(gerenciadorGrafico)),
    gerenciadorColisoes(new Gerenciadores::Gerenciador_Colisoes()),
    jogador1(new Entidades::Personagens::Jogador(Id::JOGADOR1, gerenciadorGrafico)),
    jogador2(new Entidades::Personagens::Jogador(Id::JOGADOR2, gerenciadorGrafico)),
    faseTeste(gerenciadorGrafico, gerenciadorColisoes, this)
{
    faseTeste.setJogador1(jogador1);
    faseTeste.setJogador2(jogador2);
    faseTeste.inicializarEntidades();
	executar();
}

Jogo::~Jogo()
{
    delete gerenciadorGrafico;
    delete gerenciadorEventos;
    delete gerenciadorColisoes;
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
            faseTeste.executar();

        }

        // Renderiza as coisas tudo
        gerenciadorGrafico->limparJanela();
        faseTeste.renderizarEntidades();
        gerenciadorGrafico->display();
    }
}
