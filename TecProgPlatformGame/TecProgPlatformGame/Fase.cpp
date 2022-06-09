#include "Fase.h"

Fase::Fase(Gerenciador_Grafico* GerenciadorGrafico, Gerenciador_Colisoes* GerenciadorColisoes, float deltaTime):
pGerenciadorGrafico(GerenciadorGrafico),
pGerenciadorColisoes(GerenciadorColisoes),
jogador1(new Jogador(Id::JOGADOR, pGerenciadorGrafico, CoordF((100.f), (100.f)), CoordF((100.f), (100.f)), 10)),
listaEntidades(new ListaEntidades())
{
    inicializarEntidades();
	pGerenciadorColisoes->setListaEntidades(listaEntidades);
}

Fase::~Fase()
{
    pGerenciadorGrafico = NULL;
    pGerenciadorColisoes = NULL;

    delete listaEntidades; // OBS: a destrutora de listaEntidades desaloca cada entidade
}

/* Função para alocar dinamicamente as entidades na fase
e incluir elas na lista de entidades */
void Fase::inicializarEntidades()
{
    listaEntidades->adicionarEntidade(jogador1);

    Obst_A*     parede0 = new Obst_A(pGerenciadorGrafico, CoordF(40.f, 620.f), CoordF((1200.f), (100.f)));
    Obst_A*     parede1 = new Obst_A(pGerenciadorGrafico, CoordF(440.f, 220.f), CoordF((400.f), (100.f)));
    Obst_A*     parede2 = new Obst_A(pGerenciadorGrafico, CoordF(1280.f, 620.f), CoordF((1200.f), (100.f)));
    Obst_B*        mola = new Obst_B(pGerenciadorGrafico, CoordF(1140.f, 570.f), CoordF((150.f), (50.f)));
    Obst_C*     espinho = new Obst_C(pGerenciadorGrafico, CoordF(1400.f, 590.f), CoordF((200.f), (30.f)));
    Inimigo_A* inimigo0 = new Inimigo_A(pGerenciadorGrafico, CoordF(610.f, 520.f), CoordF(100.f, 100.f));
    Inimigo_A* inimigo1 = new Inimigo_A(pGerenciadorGrafico, CoordF(720.f, 520.f), CoordF(100.f, 100.f));
    Inimigo_B* inimigo2 = new Inimigo_B(pGerenciadorGrafico, CoordF(640.f, 120.f), CoordF(100.f, 100.f), listaEntidades, parede1);
    inimigo2->setJogador(jogador1);

    // Inclui entidades na lista
    listaEntidades->adicionarEntidade(parede0);
    listaEntidades->adicionarEntidade(parede1);
    listaEntidades->adicionarEntidade(parede2);
    listaEntidades->adicionarEntidade(mola);
    listaEntidades->adicionarEntidade(espinho);
    listaEntidades->adicionarEntidade(inimigo0);
    listaEntidades->adicionarEntidade(inimigo1);
    listaEntidades->adicionarEntidade(inimigo2);
    //listaEntidades->adicionarEntidade(inimigo1);
}

/* Função para mover, colidir e atualizar a posicao de 
todas as entidades na fase */
void Fase::updateFase()
{
    executaEntidades();
    colidirEntidades();
    atualizarPosicaoEntidades();
}

/* Função para mover todas as entidades moveis na fase */
void Fase::executaEntidades()
{
    Elemento<Entidade>* pElEntidade = NULL;

    Entidade* pEntidade = NULL;

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
    Personagem* pPersonagem = NULL;

    Elemento<Entidade>* pElEntidade = NULL;

    Entidade* pEntidade = NULL;

    int qtdEntidades = listaEntidades->getLength();

    pElEntidade = listaEntidades->getElemento(0);

    for (int i = 0; i < qtdEntidades; i++)
    {
        pEntidade = pElEntidade->getItem();
        pElEntidade = pElEntidade->getPprox();
        if (pPersonagem = dynamic_cast<Personagem*>(pEntidade))
        {
            if (pPersonagem->getNumVidas() <= 0 && pPersonagem->getId() != Id::JOGADOR)
            {
                listaEntidades->deletarEntidade(pEntidade);
            }
            else
            {
                pEntidade->atualizarPos();
            }
        }
    }
}

/* Função para renderizar o corpo de todas as entidades na fase */
void Fase::renderizarEntidades()
{
    // renderizar entidades a partir da view do jogador
    if (jogador1)
    {
        pGerenciadorGrafico->centralizarView(jogador1->getPosicao(), jogador1->getTamanho());
    }

    Elemento<Entidade>* pElEntidade = NULL;

    Entidade* pEntidade = NULL;

    int qtdEntidades = listaEntidades->getLength();

    pElEntidade = listaEntidades->getElemento(0);

    for (int i = 0; i < qtdEntidades; i++)
    {
        pEntidade = pElEntidade->getItem();
        pEntidade->renderizar();
        pElEntidade = pElEntidade->getPprox();
    }
}