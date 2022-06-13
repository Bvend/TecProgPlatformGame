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
    faseJardimVerde(gerenciadorGrafico, gerenciadorColisoes, this),
    faseJardimFlores(gerenciadorGrafico, gerenciadorColisoes, this),
    menu_principal(new Menus::Menu_Principal(gerenciadorGrafico, this)),
    menu_fases(new Menus::Menu_Fases(gerenciadorGrafico, this)),
    menu_jogadores(new Menus::Menu_Jogadores(gerenciadorGrafico, this)),
    menu_ranking(new Menus::Menu_Ranking(gerenciadorGrafico, this)),
    emExecucao(Execucao::MENU_PRINCIPAL)
{
    //faseTeste.setJogador1(jogador1);
    //faseTeste.setJogador2(jogador2);
    //faseTeste.inicializarEntidades();
	loopPrincipal();
}

Jogo::~Jogo()
{
    delete gerenciadorGrafico;
    delete gerenciadorEventos;
    delete gerenciadorColisoes;
    delete menu_principal;
    delete menu_fases;
    delete menu_ranking;

    if (jogador1)
        delete jogador1;
    if (jogador2)
        delete jogador2;
}

void Jogo::setEmExecucao(Execucao executar)
{
    emExecucao = executar;
}

void Jogo::loopPrincipal()
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
            //faseTeste.executar();
            executar();

        }

        // Renderiza as coisas tudo
        gerenciadorGrafico->limparJanela();
        //faseTeste.renderizarEntidades();
        renderizar();
        gerenciadorGrafico->display();
    }
}

void Jogo::executar()
{
    switch (emExecucao)
    {
    case Execucao::MENU_PRINCIPAL:
        menu_principal->executar();
        break;
    case Execucao::MENU_FASES:
        menu_fases->executar();
        break;
    case Execucao::MENU_JOGADORES:
        menu_jogadores->executar();
        break;
    case Execucao::MENU_RANKING:
        menu_ranking->executar();
        break;
    }
}

void Jogo::renderizar()
{
    switch (emExecucao)
    {
    case Execucao::MENU_PRINCIPAL:
        menu_principal->renderizar();
        break;
    case Execucao::MENU_FASES:
        menu_fases->renderizar();
        break;
    case Execucao::MENU_JOGADORES:
        menu_jogadores->renderizar();
        break;
    case Execucao::MENU_RANKING:
        menu_ranking->renderizar();
        break;
    }
}
