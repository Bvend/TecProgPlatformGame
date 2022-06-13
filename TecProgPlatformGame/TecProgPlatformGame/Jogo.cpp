#include "Jogo.h"

const float Jogo::dt = 0.0167f;

const float Jogo::getDt()
{
    return dt;
}

Jogo::Jogo() :
    gerenciadorGrafico(new Gerenciadores::Gerenciador_Grafico()),
    gerenciadorColisoes(new Gerenciadores::Gerenciador_Colisoes()),
    jogador1(new Entidades::Personagens::Jogador(Id::JOGADOR1, gerenciadorGrafico)),
    jogador2(new Entidades::Personagens::Jogador(Id::JOGADOR2, gerenciadorGrafico)),
    faseJardimVerde(new Fases::JardimVerde(gerenciadorGrafico, gerenciadorColisoes, this, Id::FASE1)),
    faseJardimFlores(new Fases::JardimFlores(gerenciadorGrafico, gerenciadorColisoes, this, Id::FASE2)),
    menu_principal(new Menus::Menu_Principal(gerenciadorGrafico, this)),
    menu_fases(new Menus::Menu_Fases(gerenciadorGrafico, this)),
    menu_jogadores(new Menus::Menu_Jogadores(gerenciadorGrafico, this)),
    menu_ranking(new Menus::Menu_Ranking(gerenciadorGrafico, this)),
    emExecucao(Execucao::MENU_PRINCIPAL),
    multiplayer(false),
    comecarNaFase1(true)
{
	loopPrincipal();
}

Jogo::~Jogo()
{
    delete gerenciadorGrafico;
    delete gerenciadorColisoes;
    delete menu_principal;
    delete menu_fases;
    delete menu_ranking;

    delete jogador1;
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
        gerenciadorGrafico->verificarEvento();

        // Gerenciar Tempo com 60 fps
        tempoDesdeUltimoUpdate += clock.restart();
        while (tempoDesdeUltimoUpdate > sf::seconds(dt))
        {
            tempoDesdeUltimoUpdate -= sf::seconds(dt);

            // Novamente processa eventos
            executar();
        }

        // Renderiza as coisas tudo
        gerenciadorGrafico->limparJanela();
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
    case Execucao::FASE_JARDIM_VERDE:
        faseJardimVerde->executar();
        break;
    case Execucao::FASE_JARDIM_FLORES:
        faseJardimFlores->executar();
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
    case Execucao::FASE_JARDIM_VERDE:
        faseJardimVerde->renderizarEntidades();
        break;
    case Execucao::FASE_JARDIM_FLORES:
        faseJardimFlores->renderizarEntidades();
        break;
    }
}

void Jogo::setMultiplayer(bool multiplayer)
{
    this->multiplayer = multiplayer;
    std::cout << multiplayer << std::endl;
}

bool Jogo::getMultiplayer() const
{
    return multiplayer;
}

void Jogo::setComecarNaFase1(bool comecarNaFase1)
{
    this->comecarNaFase1 = comecarNaFase1;
    std::cout << comecarNaFase1 << std::endl;
}

bool Jogo::getComecarNaFase1() const
{
    return comecarNaFase1;
}

void Jogo::inicializarFaseJardimVerde()
{
    faseJardimVerde->setJogador1(jogador1);
    jogador1->setEstaVivo(true);
    if (multiplayer)
    {
        faseJardimVerde->setJogador2(jogador2);
        jogador2->setEstaVivo(true);
    }
    faseJardimVerde->inicializarEntidades();
    emExecucao = Execucao::FASE_JARDIM_VERDE;
}

void Jogo::inicializarFaseJardimFlores()
{
    faseJardimFlores->setJogador1(jogador1);
    jogador1->setEstaVivo(true);
    if (multiplayer)
    {
        faseJardimFlores->setJogador2(jogador2);
        jogador2->setEstaVivo(true);
    }
    faseJardimFlores->inicializarEntidades();
    emExecucao = Execucao::FASE_JARDIM_FLORES;
}

void Jogo::avancarFase(Entidades::Personagens::Jogador* pJog)
{
    faseJardimFlores->adicionarEntidade(static_cast<Entidades::Entidade*>(pJog));
    faseJardimFlores->incrementarNumJogadores();
}
