#include "Ente.h"

/* Construtora */
Ente::Ente(Id ind, Gerenciadores::Gerenciador_Grafico* ger):
id(ind),
textura(NULL),
pGerenciadorGrafico(ger)
{
}

/* Destrutora */
Ente::~Ente()
{
	textura = NULL;
	pGerenciadorGrafico = NULL;
}

/* Retorna enum class Id do ente */
Id Ente::getId() const
{
	return id;
}

/* Atribui tamanho, posição e textura para forma */
void Ente::setForma(CoordF tamanho, CoordF posicao)
{
	forma.setSize(sf::Vector2f(tamanho.getX(), tamanho.getY()));
	forma.setPosition(sf::Vector2f(posicao.getX(), posicao.getY()));
	forma.setTexture(textura);
}

/* Função para retornar ponteiro para a forma do ente */
sf::RectangleShape* Ente::getForma()
{
	return (&forma);
}

/* Atribui ponteiro para GerenciadorGrafico, caso variavel recebida não seja NULL */
void Ente::setGerenciadorGrafico(Gerenciadores::Gerenciador_Grafico* ger)
{
	if (ger)
	{
		pGerenciadorGrafico = ger;
	}
	else
	{
		printf("Erro - falha ao atribuir Gerenciador Gráfico");
	}
}

/* Retorna ponteiro para Gerenciador Grafico */
Gerenciadores::Gerenciador_Grafico* Ente::getGerenciadorGrafico()
{
	return pGerenciadorGrafico;;
}

/* Inicializa forma e textura de acordo com cada ente */
void Ente::inicializarCorpo(const char* caminho, CoordF posicao, CoordF tamanho, Gerenciadores::Gerenciador_Grafico* GerenciadorGrafico)
{
	if (pGerenciadorGrafico)
	{
		textura = pGerenciadorGrafico->carregarTextura(caminho);
		setForma(tamanho, posicao);
	}
}

/* Atribui uma posicao em x e y para o atributo forma */
void Ente::setPosicao(CoordF posicao)
{
	forma.setPosition(sf::Vector2f(posicao.getX(), posicao.getY()));
}

/* Renderiza forma na tela a partir do Gerenciador Grafico */
void Ente::renderizar()
{
	if (pGerenciadorGrafico)
	{
		pGerenciadorGrafico->renderizarCorpo(&forma);
	}
}
