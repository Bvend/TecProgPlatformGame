#include "Fase.h"

Fase::Fase(Gerenciador_Grafico* GerenciadorGrafico, Gerenciador_Colisoes* GerenciadorColisoes, float deltaTime):
jogador1(new Jogador(2, CoordF((100.f), (100.f)), CoordF((100.f), (100.f)), jogador)),
pGerenciadorGrafico(GerenciadorGrafico),
pGerenciadorColisoes(GerenciadorColisoes),
dt(deltaTime),
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
    Obst_A* parede0 = new Obst_A(CoordF(40.f, 620.f), CoordF((1200.f), (100.f)));
    Obst_A* parede1 = new Obst_A(CoordF(440.f, 220.f), CoordF((400.f), (100.f)));
    Obst_A* parede2 = new Obst_A(CoordF(1280.f, 620.f), CoordF((1200.f), (100.f)));
    Inimigo_A* inimigo0 = new Inimigo_A(15, CoordF(610.f, 520.f), CoordF(100.f, 100.f), inimigo_A);
    Inimigo_B* inimigo1 = new Inimigo_B(15, CoordF(610.f, 120.f), CoordF(100.f, 100.f), inimigo_A);

    // Inclui entidades na lista
    listaEntidades->adicionarEntidade(jogador1);
    listaEntidades->adicionarEntidade(parede0);
    listaEntidades->adicionarEntidade(parede1);
    listaEntidades->adicionarEntidade(parede2);
    listaEntidades->adicionarEntidade(inimigo0);
    listaEntidades->adicionarEntidade(inimigo1);
}

/* Função para mover, colidir e atualizar a posicao de 
todas as entidades na fase */
void Fase::updateFase()
{
    moveEntidades();
    colidirEntidades();
    atualizarPosicaoEntidades();
}

/* Função para mover todas as entidades moveis na fase */
void Fase::moveEntidades()
{
    Elemento<Entidade>* pElEntidade = NULL;

    Entidade* pEntidade = NULL;

    int qtdEntidades = listaEntidades->getLength();

    pElEntidade = listaEntidades->getElemento(0);

    for (int i = 0; i < qtdEntidades; i++)
    {
        pEntidade = pElEntidade->getItem();
        pEntidade->executar(dt);
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
            if (pPersonagem->getNumVidas() <= 0 && pPersonagem->getID() != jogador)
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
    pGerenciadorGrafico->centralizarView(jogador1);

    Elemento<Entidade>* pElEntidade = NULL;

    Entidade* pEntidade = NULL;

    int qtdEntidades = listaEntidades->getLength();

    pElEntidade = listaEntidades->getElemento(0);

    for (int i = 0; i < qtdEntidades; i++)
    {
        pEntidade = pElEntidade->getItem();
        pGerenciadorGrafico->render(pEntidade->getBody());
        pElEntidade = pElEntidade->getPprox();
    }
}