#include "JardimFlores.h"
#include "Jogo.h"

#define CAMINHO_JARDIMFLORES "./recurssos/JardimFlores/JardimFlores.png"

namespace Fases
{
	JardimFlores::JardimFlores(Gerenciadores::Gerenciador_Grafico* GerenciadorGrafico, Gerenciadores::Gerenciador_Colisoes* pGerenciadorColisoes, Jogo* jogo, Id ind):
		Fase(GerenciadorGrafico, pGerenciadorColisoes, jogo, ind)
	{
		pontoFinal = CoordF(640.f, 170.f);

		inicializarCorpo(CAMINHO_JARDIMFLORES, CoordF(0.f, 0.f), CoordF(1280.f, 720.f));
	}

	JardimFlores::~JardimFlores()
	{
	}

	void JardimFlores::inicializarEntidades()
	{
		gerarPlataformas();
		encontrarPosicoesDisponiveisPlataformas();
		gerarChao();
		gerarFlorChefe();
		gerarSois();
		gerarMolas();
		gerarEspinhos();
		gerarCachorros();
		posicionarJogadores();

		pGerenciadorColisoes->setListaEntidades(listaEntidades);
	}

	void JardimFlores::gerarPlataformas()
	{
		Entidades::Obstaculos::Plataforma* plataforma1 = new Entidades::Obstaculos::Plataforma(pGerenciadorGrafico, CoordF(0.F, 400.f), CoordF(2 * LARGURA_PLATAFORMA, ALTURA_PLATAFORMA));
		listaEntidades->adicionarEntidade(plataforma1);
		Entidades::Obstaculos::Plataforma* plataforma2 = new Entidades::Obstaculos::Plataforma(pGerenciadorGrafico, CoordF(1040.f, 400.f), CoordF(2 * LARGURA_PLATAFORMA, ALTURA_PLATAFORMA));
		listaEntidades->adicionarEntidade(plataforma2);
		Entidades::Obstaculos::Plataforma* plataforma3 = new Entidades::Obstaculos::Plataforma(pGerenciadorGrafico, CoordF(160.f, 200.f), CoordF(4 * LARGURA_PLATAFORMA, ALTURA_PLATAFORMA));
		listaEntidades->adicionarEntidade(plataforma3);
	}

	void JardimFlores::gerarFlorChefe()
	{
		Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(pGerenciadorGrafico, CoordF(520.f, 500 - 7.5), CoordF(LARGURA_PLATAFORMA, ALTURA_PLATAFORMA));
		listaEntidades->adicionarEntidade(plataforma);

		Entidades::Personagens::FlorChefe* florChefe = new Entidades::Personagens::FlorChefe(pGerenciadorGrafico, CoordF(520.f + 90, 500 - 7.5 - 60), listaEntidades, plataforma);
		florChefe->setJogador1(pJogador1);
		florChefe->setJogador2(pJogador2);
		listaEntidades->adicionarEntidade(florChefe);
	}
}