#include "Fase1.h"
#include "Jogo.h"

#define CAMINHO_FASE1 "./recurssos/Fase1/Fase1.png"

namespace Fases
{
	Fase1::Fase1(Gerenciadores::Gerenciador_Grafico* GerenciadorGrafico, Gerenciadores::Gerenciador_Colisoes* pGerenciadorColisoes, Jogo* jogo):
		Fase(GerenciadorGrafico, pGerenciadorColisoes, jogo)
	{
		pontoFinal = CoordF(1240.f, 190.f);
		//inicializarEntidades();
		//pGerenciadorColisoes->setListaEntidades(listaEntidades);
		inicializarCorpo(CAMINHO_FASE1, CoordF(0.f, 0.f), CoordF(1280.f, 720.f));
	}
	
	Fase1::~Fase1()
	{
	}

	/* Função para alocar dinamicamente as entidades na fase
	e incluir elas na lista de entidades */
	void Fase1::inicializarEntidades()
	{
		posicionarJogadores();
		gerarChao();
		gerarPlataformas();
		gerarSois();
		gerarMolas();
		gerarEspinhos();
		gerarCachorros();

		pGerenciadorColisoes->setListaEntidades(listaEntidades);
	}

	void Fase1::gerarPlataformas()
	{
		CoordF posicao(0.f, 0.f);

		int i, j;

		for (i = 0; i < 2; i++)
		{
			posicao.setY(POSICAO_Y_CHAO - (i + 1) * 200);

			for (j = 0; j < 3; j++)
			{
				posicao.setX(1280 - (160.f * (j + 1 - i) + LARGURA_PLATAFORMA * (j + 1)));
				Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(pGerenciadorGrafico, posicao, CoordF(LARGURA_PLATAFORMA, ALTURA_PLATAFORMA));
				listaEntidades->adicionarEntidade(plataforma);
				posicoesDisponiveis.push_back(CoordF(plataforma->getCentroX(), plataforma->getCima()));
			}
		}	
	}
}