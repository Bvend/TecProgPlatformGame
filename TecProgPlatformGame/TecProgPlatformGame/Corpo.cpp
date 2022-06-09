#include "Corpo.h"

/* Construtora */
Corpo::Corpo():
textura(NULL),
pGerenciadorGrafico(NULL)
{
}

/* Destrutora */
Corpo::~Corpo()
{
	textura = NULL;
	pGerenciadorGrafico = NULL;
}

/* Inicializa forma e textura de acordo com cada entidade */
void Corpo::inicializar(const char* caminho, CoordF posicao, CoordF tamanho, Gerenciador_Grafico* GerenciadorGrafico)
{
	setGerenciadorGrafico(GerenciadorGrafico);
	textura = pGerenciadorGrafico->carregarTextura(caminho);
	setForma(tamanho, posicao);
}

/* Atribui tamanho, posição e textura para forma */
void Corpo::setForma(CoordF tamanho, CoordF posicao)
{
	forma.setSize(sf::Vector2f(tamanho.getX(), tamanho.getY()));
	forma.setPosition(sf::Vector2f(posicao.getX(), posicao.getY()));
	forma.setTexture(textura);
}

/* Retorna ponteiro para RectangleShape forma */
sf::RectangleShape* Corpo::getForma()
{
	return (&forma);
}

/* Atribui Gerenciador Grafico */
void Corpo::setGerenciadorGrafico(Gerenciador_Grafico* GerenciadorGrafico)
{
	pGerenciadorGrafico = GerenciadorGrafico;
}

Gerenciador_Grafico* Corpo::getGerenciadorGrafico()
{
	return pGerenciadorGrafico;
}

/* Renderiza corpo na tela a partir do Gerenciador Grafico */
void Corpo::renderizar()
{
	if (pGerenciadorGrafico)
	{
		pGerenciadorGrafico->renderizar(&forma);
	}
}

/* Atribui uma posicao em x e y para o atributo forma */
void Corpo::setPosicao(CoordF posicao)
{
	forma.setPosition(sf::Vector2f(posicao.getX(), posicao.getY()));
}
