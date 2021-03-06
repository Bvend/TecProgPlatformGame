#include "Fase.h"
#include "Jogo.h"

namespace Fases
{
    Fase::Fase(Gerenciadores::Gerenciador_Grafico* GerenciadorGrafico, Gerenciadores::Gerenciador_Colisoes* GerenciadorColisoes, Jogo* jogo, Id ind):
        Ente(ind, GerenciadorGrafico),
        listaEntidades(new Listas::ListaEntidades()),
        pGerenciadorColisoes(GerenciadorColisoes),
        pJogo(jogo),
        pJogador1(NULL),
        pJogador2(NULL),
        posicaoInicialJogador(CoordF(0.f, POSICAO_Y_CHAO - ALTURA_JOGADOR)),
        pontoFinal(0.f, 0.f),
        numJogadores(0),
        avancarFase(false)
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
        numJogadores++;
    }

    void Fase::setJogador2(Entidades::Personagens::Jogador* pJogador)
    {
        pJogador2 = pJogador;
        listaEntidades->adicionarEntidade(pJogador2);
        numJogadores++;
    }

    void Fase::incrementarNumJogadores()
    {
        numJogadores++;
    }

    void Fase::limparFase()
    {
        posicoesDisponiveis.clear();

        listaEntidades->deletarEntidades();
    }

    void Fase::adicionarEntidade(Entidades::Entidade* pEntidade)
    {
        listaEntidades->adicionarEntidade(pEntidade);
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

        Entidades::Entidade* pEntidade = NULL;

        int qtdEntidades = listaEntidades->getTamanho();

        pElEntidade = listaEntidades->getElemento(0);

        for (int i = 0; i < qtdEntidades; i++)
        {
            pEntidade = pElEntidade->getItem();

            if (pEntidade && (pEntidade->getId() == Id::PLATAFORMA) && (pEntidade->getCima() != POSICAO_Y_CHAO))
            {
                float j = pEntidade->getEsquerda() + 60.f;
                while (j < pEntidade->getDireita() - 60.f)
                {
                    posicoesDisponiveis.push_back(CoordF(j, pEntidade->getCima()));
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

    /* Fun??o para mover, colidir e atualizar a posicao de
    todas as entidades na fase */
    void Fase::executar()
    {
        executarEntidades();
        colidirEntidades();
        atualizarPosicaoEntidades();
        checarProgresso();
    }

    /* Fun??o para mover todas as entidades moveis na fase */
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

    /* Fun??o para verificar colis?es
    e reposicionar as entidades que colidirem */
    void Fase::colidirEntidades()
    {
        pGerenciadorColisoes->checarColisoes();
    }

    /* Fun??o para atualizar a posi??o das entidades na tela,
    de acordo com o movimento e as colis?es previamente verificadas */
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
            else if (pEntidade->getId() == Id::JOGADOR1 || pEntidade->getId() == Id::JOGADOR2)
            {
                listaEntidades->removerEntidadeSemDeletar(pEntidade);
                numJogadores--;
            }
            else
            {
                listaEntidades->deletarEntidade(pEntidade);
            }
        }
    }

    void Fase::checarProgresso()
    {
        if (numJogadores == 0 && !avancarFase)
        {
            this->limparFase();
            pJogo->setEmExecucao(Execucao::MENU_PRINCIPAL);
        }
        else if (id == Id::FASE1)
        {
            if (pJogador1 && pJogador1->intersecta(pontoFinal))
            {
                listaEntidades->removerEntidadeSemDeletar(pJogador1);
                numJogadores--;
                pJogador1->setPosicao(CoordF(0.f, POSICAO_Y_CHAO - ALTURA_JOGADOR));
            }

            if (pJogo->getMultiplayer() && pJogador2->intersecta(pontoFinal))
            {
                listaEntidades->removerEntidadeSemDeletar(pJogador2);
                numJogadores--;
                pJogador2->setPosicao(CoordF(0.f, POSICAO_Y_CHAO - ALTURA_JOGADOR));
            }

            if (numJogadores == 0)
            {
                this->limparFase();
                pJogo->setEmExecucao(Execucao::FASE_JARDIM_FLORES);
            }
        }
        else if (id == Id::FASE2)
        {
            if (pJogador1->intersecta(pontoFinal))
            {
                listaEntidades->removerEntidadeSemDeletar(pJogador1);
                pJogador1->setPosicao(CoordF(0.f, POSICAO_Y_CHAO - ALTURA_JOGADOR));
                numJogadores--;
            }

            if (pJogo->getMultiplayer() && pJogador2->intersecta(pontoFinal))
            {
                listaEntidades->removerEntidadeSemDeletar(pJogador2);
                pJogador2->setPosicao(CoordF(0.f, POSICAO_Y_CHAO - ALTURA_JOGADOR));
                numJogadores--;
            }

            if (numJogadores == 0)
            {
                this->limparFase();
                pJogo->setEmExecucao(Execucao::MENU_PRINCIPAL);
            }
        }
    }

    /* Fun??o para renderizar o corpo de todas as entidades na fase */
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