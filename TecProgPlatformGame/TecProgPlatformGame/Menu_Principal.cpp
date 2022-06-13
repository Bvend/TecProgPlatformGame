#include "Menu_Principal.h"
#include "Jogo.h"

#define CAMINHO_MENU_PRINCIPAL "./recurssos/Menu/Menu_Principal.png"

namespace Menus
{
	Menu_Principal::Menu_Principal(Gerenciadores::Gerenciador_Grafico* ger, Jogo* jogo):
		Menu(Id::MENU_PRINCIPAL, ger, jogo)
	{
		opcoes = { "Jardinzinho", "Selecionar Fase", "Selecionar Jogadores", "Jogar", "Rankings", "Sair"};
		coordenadas = { {110.f,47.f}, {45.f,205.f}, {44.f,303.f}, {45.f,399.f}, {45.f, 499.f}, {44.f, 597.f} };
		tamanhos = { 55, 35, 35, 35, 35, 35};
		num_botoes = opcoes.size();

		inicializarCorpo(CAMINHO_MENU_PRINCIPAL, CoordF(0.f, 0.f), CoordF(1280.f, 720.f));

		inicializarBotoes();
	}

	Menu_Principal::~Menu_Principal()
	{
	}

	void Menu_Principal::pressionarBotao()
	{
		switch (posicao)
		{
		case 1:
			pJogo->setEmExecucao(Execucao::MENU_FASES);
			break;

		case 2:
			pJogo->setEmExecucao(Execucao::MENU_JOGADORES);
			break;

		case 3:
			if (pJogo->getComecarNaFase1())
			{
				pJogo->inicializarFaseJardimVerde();
			}
			else
			{
				pJogo->inicializarFaseJardimFlores();
			}
			break;

		case 4:
			pJogo->setEmExecucao(Execucao::MENU_RANKING);
			break;

		case 5:
			pGerenciadorGrafico->fecharJanela();
			break;
		}
	}
}
