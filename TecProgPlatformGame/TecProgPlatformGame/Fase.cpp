#include "Fase.h"

namespace Fases
{
    Fase::Fase(Gerenciadores::Gerenciador_Grafico* GerenciadorGrafico, Gerenciadores::Gerenciador_Colisoes* GerenciadorColisoes):
        Ente(Id::FASE, GerenciadorGrafico),
        pGerenciadorColisoes(GerenciadorColisoes),
        jogador1(new Entidades::Personagens::Jogador(Id::JOGADOR, pGerenciadorGrafico, CoordF((0.f), (660.f - 62.5f)), 10)),
        listaEntidades(new Listas::ListaEntidades())
    {
        inicializarEntidades();
        pGerenciadorColisoes->setListaEntidades(listaEntidades);
    }

    Fase::~Fase()
    {
        pGerenciadorColisoes = NULL;

        delete listaEntidades; // OBS: a destrutora de listaEntidades desaloca cada entidade
    }

    /* Função para alocar dinamicamente as entidades na fase
    e incluir elas na lista de entidades */
    void Fase::inicializarEntidades()
    {
        listaEntidades->adicionarEntidade(jogador1);

        Entidades::Obstaculos::Plataforma* parede0 = new Entidades::Obstaculos::Plataforma(pGerenciadorGrafico, CoordF(0.f, 640.f), CoordF((1280.f), (80.f)));
        Entidades::Obstaculos::Plataforma* parede1 = new Entidades::Obstaculos::Plataforma(pGerenciadorGrafico, CoordF(80.f, 520.f), CoordF((240.f), (15.f)));
        //Entidades::Obstaculos::Mola*          mola = new Entidades::Obstaculos::Mola(pGerenciadorGrafico, CoordF(1050.f, 570.f));
        //Entidades::Obstaculos::Espinho*     espinho = new Entidades::Obstaculos::Espinho(pGerenciadorGrafico, CoordF(850.f, 470.f));
        //Entidades::Personagens::Inimigo_A* inimigo0 = new Entidades::Personagens::Inimigo_A(pGerenciadorGrafico, CoordF(610.f, 520.f));
        //Entidades::Personagens::Inimigo_A* inimigo1 = new Entidades::Personagens::Inimigo_A(pGerenciadorGrafico, CoordF(720.f, 520.f));

        Entidades::Personagens::Inimigo_B* inimigo2 = new Entidades::Personagens::Inimigo_B(pGerenciadorGrafico, CoordF(parede1->getEsquerda() + parede1->getLargura() / 2.f, parede1->getCima() - 51.f), listaEntidades, parede1);
        inimigo2->setJogador(jogador1);
        Entidades::Personagens::Inimigo_C* inimigo3 = new Entidades::Personagens::Inimigo_C(pGerenciadorGrafico, CoordF(320.f, 540.f));

        // Inclui entidades na lista
        listaEntidades->adicionarEntidade(parede0);
        listaEntidades->adicionarEntidade(parede1);
        //listaEntidades->adicionarEntidade(mola);
        //listaEntidades->adicionarEntidade(espinho);
        //listaEntidades->adicionarEntidade(inimigo0);
        //listaEntidades->adicionarEntidade(inimigo1);
        listaEntidades->adicionarEntidade(inimigo2);
        listaEntidades->adicionarEntidade(inimigo3);
    }

    /* Função para mover, colidir e atualizar a posicao de
    todas as entidades na fase */
    void Fase::executar()
    {
        executarEntidades();
        colidirEntidades();
        atualizarPosicaoEntidades();
    }

    /* Função para mover todas as entidades moveis na fase */
    void Fase::executarEntidades()
    {
        Listas::Lista<Entidades::Entidade>::Lista::Elemento<Entidades::Entidade>* pElEntidade = NULL;

        Entidades::Entidade* pEntidade = NULL;

        int qtdEntidades = listaEntidades->getLength();

        pElEntidade = listaEntidades->getElemento(0);

        for (int i = 0; i < qtdEntidades; i++)
        {
            pEntidade = pElEntidade->getItem();
            pEntidade->executar();
            pElEntidade = pElEntidade->getPprox();
        }
    }

    /* Função para verificar colisões
    e reposicionar as entidades que colidirem */
    void Fase::colidirEntidades()
    {
        pGerenciadorColisoes->checarColisoes();
    }

    /* Função para atualizar a posição das entidades na tela,
    de acordo com o movimento e as colisões previamente verificadas */
    void Fase::atualizarPosicaoEntidades()
    {
        Entidades::Personagens::Personagem* pPersonagem = NULL;

        Listas::Lista<Entidades::Entidade>::Lista::Elemento<Entidades::Entidade>* pElEntidade = NULL;

        Entidades::Entidade* pEntidade = NULL;

        int qtdEntidades = listaEntidades->getLength();

        pElEntidade = listaEntidades->getElemento(0);

        for (int i = 0; i < qtdEntidades; i++)
        {
            pEntidade = pElEntidade->getItem();
            pElEntidade = pElEntidade->getPprox();
            if (pEntidade->getEstaVivo())
            {
                pEntidade->atualizarPos();
            }
            else
            {
                listaEntidades->deletarEntidade(pEntidade);
            }
        }
    }

    /* Função para renderizar o corpo de todas as entidades na fase */
    void Fase::renderizarEntidades()
    {
        // renderizar entidades a partir da view do jogador
        //if (jogador1)
        //{
        //    pGerenciadorGrafico->centralizarVista(jogador1->getPosicao(), jogador1->getTamanho());
        //}
        renderizar();

        Listas::Lista<Entidades::Entidade>::Elemento<Entidades::Entidade>* pElEntidade = NULL;

        Entidades::Entidade* pEntidade = NULL;

        int qtdEntidades = listaEntidades->getLength();

        pElEntidade = listaEntidades->getElemento(0);

        for (int i = 0; i < qtdEntidades; i++)
        {
            pEntidade = pElEntidade->getItem();
            pEntidade->renderizar();
            pElEntidade = pElEntidade->getPprox();
        }
    }
}