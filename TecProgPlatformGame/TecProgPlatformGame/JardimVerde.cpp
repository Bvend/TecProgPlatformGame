#include "JardimVerde.h"
#include "Jogo.h"

#define CAMINHO_JARDIMVERDE "./recurssos/JardimVerde/JardimVerde.png"

namespace Fases
{
	JardimVerde::JardimVerde(Gerenciadores::Gerenciador_Grafico* GerenciadorGrafico, Gerenciadores::Gerenciador_Colisoes* pGerenciadorColisoes, Jogo* jogo):
		Fase(GerenciadorGrafico, pGerenciadorColisoes, jogo)
	{
		pontoFinal = CoordF(1240.f, 190.f);
		//inicializarEntidades();
		//pGerenciadorColisoes->setListaEntidades(listaEntidades);
		inicializarCorpo(CAMINHO_JARDIMVERDE, CoordF(0.f, 0.f), CoordF(1280.f, 720.f));
	}
	
	JardimVerde::~JardimVerde()
	{
	}

	/* Função para alocar dinamicamente as entidades na fase
	e incluir elas na lista de entidades */
	void JardimVerde::inicializarEntidades()
	{
		gerarChao();
		gerarPlataformas();
		encontrarPosicoesDisponiveisPlataformas();
		gerarSois();
		gerarMolas();
		gerarEspinhos();
		gerarCachorros();
		posicionarJogadores();

		pGerenciadorColisoes->setListaEntidades(listaEntidades);
	}

	void JardimVerde::gerarPlataformas()
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
				//posicoesDisponiveis.push_back(CoordF(plataforma->getCentroX(), plataforma->getCima()));
			}
		}	
	}
}