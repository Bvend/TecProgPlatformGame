#include "Fase.h"
#include "Jogo.h"

namespace Fases
{
    Fase::Fase(Gerenciadores::Gerenciador_Grafico* GerenciadorGrafico, Gerenciadores::Gerenciador_Colisoes* GerenciadorColisoes, Jogo* jogo):
        Ente(Id::FASE, GerenciadorGrafico),
        listaEntidades(new Listas::ListaEntidades()),
        pGerenciadorColisoes(GerenciadorColisoes),
        pJogo(jogo),
        pJogador1(NULL),
        pJogador2(NULL),
        posicaoInicialJogador(CoordF(0.f, POSICAO_Y_CHAO - ALTURA_JOGADOR)),
        pontoFinal(0.f, 0.f)
    {
    }

    Fase::~Fase()
    {
        pGerenciadorColisoes = NULL;

        posicoesDisponiveis.clear();

        delete listaEntidades;
    }

    void Fase::setJogador1(Entidades::Personagens::Jogador* pJogador)
    {
        pJogador1 = pJogador;
        listaEntidades->adicionarEntidade(pJogador1);
    }

    void Fase::setJogador2(Entidades::Personagens::Jogador* pJogador)
    {
        pJogador2 = pJogador;
        listaEntidades->adicionarEntidade(pJogador2);
    }

    void Fase::posicionarJogadores()
    {
        if (pJogador1)
        {
            pJogador1->setPosicao(posicaoInicialJogador);
        }
        if (pJogador2)
        {
            pJogador2->setPosicao(posicaoInicialJogador + CoordF(LARGURA_JOGADOR, 0.f));
        }
    }

    void Fase::gerarChao()
    {
        Entidades::Obstaculos::Plataforma* chao = new Entidades::Obstaculos::Plataforma(pGerenciadorGrafico, CoordF(0.f, POSICAO_Y_CHAO), CoordF((1280.f), (80.f)));
        listaEntidades->adicionarEntidade(chao);

        for (int i = 0; i < 7; i++)
        {
            posicoesDisponiveis.push_back(CoordF(i * 150.f + 190.f, chao->getCima()));
        }
    }

    void Fase::encontrarPosicoesDisponiveisPlataformas()
    {
        Listas::Lista<Entidades::Entidade>::Lista::Elemento<Entidades::Entidade>* pElEntidade = NULL;

        Entidades::Obstaculos::Plataforma* pPlataforma = NULL;

        int qtdEntidades = listaEntidades->getTamanho();

        pElEntidade = listaEntidades->getElemento(0);

        for (int i = 0; i < qtdEntidades; i++)
        {
            if ((pPlataforma = dynamic_cast<Entidades::Obstaculos::Plataforma*>(pElEntidade->getItem())) && (pPlataforma->getCima() != POSICAO_Y_CHAO))
            {
                float j = pPlataforma->getEsquerda() + 60.f;
                while (j < pPlataforma->getDireita() - 60.f)
                {
                    posicoesDisponiveis.push_back(CoordF(j, pPlataforma->getCima()));
                    j += 110.f;
                }
            }
            pElEntidade = pElEntidade->getPprox();
        }
    }

    void Fase::gerarMolas()
    {
        std::vector<CoordF>::iterator it;

        int num_molas = 0;

        while (num_molas < 3)
        {
            for (it = posicoesDisponiveis.begin(); it != posicoesDisponiveis.end();)
            {
                if (rand() % 5 == 0)
                {
                    Entidades::Obstaculos::Mola* mola = new Entidades::Obstaculos::Mola(pGerenciadorGrafico, *it + CoordF(0.f, -30.f));
                    listaEntidades->adicionarEntidade(mola);
                    it = posicoesDisponiveis.erase(it);
                    if (++num_molas == 4)
                    {
                        break;
                    }
                }
                else
                    it++;
            }
        }
    }

    void Fase::gerarEspinhos()
    {
        std::vector<CoordF>::iterator it;

        int num_espinhos = 0;

        while (num_espinhos < 3)
        {
            for (it = posicoesDisponiveis.begin(); it != posicoesDisponiveis.end();)
            {
                if (rand() % 4 == 0)
                {
                    Entidades::Obstaculos::Espinho* espinho = new Entidades::Obstaculos::Espinho(pGerenciadorGrafico, *it + CoordF(0.f, -30.f));
                    listaEntidades->adicionarEntidade(espinho);
                    it = posicoesDisponiveis.erase(it);
                    if (++num_espinhos == 4)
                    {
                        break;
                    }
                }
                else
                    it++;
            }
        }
    }

    void Fase::gerarCachorros()
    {
        std::vector<CoordF>::iterator it;

        int num_cachorros = 0;

        while (num_cachorros < 3)
        {
            for (it = posicoesDisponiveis.begin(); it != posicoesDisponiveis.end();)
            {
                if (rand() % 5 == 0)
                {
                    Entidades::Personagens::Cachorro* cachorro = new Entidades::Personagens::Cachorro(pGerenciadorGrafico, *it + CoordF(0.f, -30.f));
                    listaEntidades->adicionarEntidade(cachorro);
                    it = posicoesDisponiveis.erase(it);
                    if (++num_cachorros == 5)
                    {
                        break;
                    }
                }
                else
                    it++;
            }
        }

    }

    void Fase::gerarSois()
    {
        int num_sois = 0;

        std::vector<CoordF> copiaPosicoes;

        for (unsigned int i = 0; i < posicoesDisponiveis.size(); i++)
            copiaPosicoes.push_back(posicoesDisponiveis[i]);

        std::vector<CoordF>::iterator it;

        while (num_sois < 3)
        {
            for (it = copiaPosicoes.begin(); it != copiaPosicoes.end();)
            {
                if ((rand() % 4 == 0) && (it->getY() != POSICAO_Y_CHAO))
                {
                    Entidades::Personagens::Sol* sol = new Entidades::Personagens::Sol(pGerenciadorGrafico, *it + CoordF(0.f, -100.f));
                    listaEntidades->adicionarEntidade(sol);
                    it = copiaPosicoes.erase(it);
                    if (++num_sois == 6)
                    {
                        break;
                    }
                }
                else
                    it++;
            }
        }
    }

    /* Função para mover, colidir e atualizar a posicao de
    todas as entidades na fase */
    void Fase::executar()
    {
        executarEntidades();
        colidirEntidades();
        atualizarPosicaoEntidades();
        checarVitoria();
    }

    /* Função para mover todas as entidades moveis na fase */
    void Fase::executarEntidades()
    {
        Listas::Lista<Entidades::Entidade>::Lista::Elemento<Entidades::Entidade>* pElEntidade = NULL;

        Entidades::Entidade* pEntidade = NULL;

        int qtdEntidades = listaEntidades->getTamanho();

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
        Listas::Lista<Entidades::Entidade>::Lista::Elemento<Entidades::Entidade>* pElEntidade = NULL;

        Entidades::Entidade* pEntidade = NULL;

        int qtdEntidades = listaEntidades->getTamanho();

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

    void Fase::checarVitoria()
    {
    }

    /* Função para renderizar o corpo de todas as entidades na fase */
    void Fase::renderizarEntidades()
    {
        renderizar();

        Listas::Lista<Entidades::Entidade>::Elemento<Entidades::Entidade>* pElEntidade = NULL;

        Entidades::Entidade* pEntidade = NULL;

        int qtdEntidades = listaEntidades->getTamanho();

        pElEntidade = listaEntidades->getElemento(0);

        for (int i = 0; i < qtdEntidades; i++)
        {
            pEntidade = pElEntidade->getItem();
            pEntidade->renderizar();
            pElEntidade = pElEntidade->getPprox();
        }
    }
}