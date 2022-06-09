#include "Jogo.h"

<<<<<<< HEAD
const float Jogo::dt = (1.f / 60);

const float Jogo::getDt()
{
    return dt;
}
=======
Jogo::Jogo() :
GerenciadorGrafico(new Gerenciador_Grafico),
LES(new ListaEntidades()),
GerenciadorEventos(new Gerenciador_Eventos(GerenciadorGrafico)),
dt(1.f / 60.f),
BackGroundShape(Vector2f(1280.f, 720.f))
{
    /*Textura de Player*/
    Texture playerTexture;
    playerTexture.loadFromFile("Player1.png");

    /*Textura de Enemy*/
    Texture enemyTexture;
    enemyTexture.loadFromFile("Alien1.png");
    /*
    Vector2u enemyTextureSize = enemyTexture.getSize();
    enemyTextureSize.x /= 3;
    enemyTextureSize.y /= 4;
    */
    
    /*Textura de BackGround*/
    Texture* BackGroundTexture;
    BackGroundTexture = new Texture;
    BackGroundTexture->loadFromFile("BackGround.jpg");
   
   
    player1 = new Jogador(500, CoordF((200.f), (200.f)), CoordF((41.f), (100.f)), jogador);
    parede = new Obst_A(CoordF(40.f, 620.f), CoordF((1200.f), (100.f)));
    parede1 = new Obst_A(CoordF(440.f, 220.f), CoordF((400.f), (100.f)));
    parede2 = new Obst_A(CoordF(1280.f, 620.f), CoordF((1200.f), (100.f)));
    parede3 = new Obst_A(CoordF(1250.f, 350.f), CoordF((400.f), (100.f)));
    inimigo = new Inimigo_A(0, CoordF(610.f, 520.f), CoordF(100.f, 100.f), inimigo_A);

    BackGroundShape.setTexture(BackGroundTexture);
    player1->setTexture(&playerTexture);
    inimigo->setTexture(&enemyTexture);

    // Inclui entidades na lista
    LES->adicionarEntidade(player1);
    LES->adicionarEntidade(parede); 
    LES->adicionarEntidade(parede1);
    LES->adicionarEntidade(parede2);
    LES->adicionarEntidade(parede3);
    LES->adicionarEntidade(inimigo);

    // Inicializa Gerenciador de colisões
    GerenciadorColisoes = new Gerenciador_Colisoes(LES);
>>>>>>> 91dcff85e6c0a5b60e1520e6cef76ba4e4b29c12

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
<<<<<<< HEAD
            faseTeste->updateFase();

        }

        // Renderiza as coisas tudo
        gerenciadorGrafico->clearWindow();
        faseTeste->renderizarEntidades();
        gerenciadorGrafico->display();
=======
            player1->move(dt);
            inimigo->move(dt);
            GerenciadorColisoes->checarColisoes();
            player1->atualizarPos();
            inimigo->atualizarPos();
            BackGroundShape.setPosition(player1->getPosicao().getX()-600, player1->getPosicao().getY()-400);
        }

        // Renderiza as coisas tudo
        GerenciadorGrafico->clearWindow();
        GerenciadorGrafico->centralizarView(player1);
        GerenciadorGrafico->render(&BackGroundShape);
        GerenciadorGrafico->render(player1->getBody());
        GerenciadorGrafico->render(parede->getBody());
        GerenciadorGrafico->render(parede1->getBody());
        GerenciadorGrafico->render(parede2->getBody());
        GerenciadorGrafico->render(parede3->getBody());
        GerenciadorGrafico->render(inimigo->getBody());
        GerenciadorGrafico->display();
>>>>>>> 91dcff85e6c0a5b60e1520e6cef76ba4e4b29c12
    }
}
