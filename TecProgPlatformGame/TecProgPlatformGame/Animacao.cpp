#include "Animacao.h"

Animacao::Animacao(const char* path, const unsigned int contImag, const float st) :
	contadorImagem(contImag),
	imagemAtual(0),
	textura(Gerenciador_Grafico().loadTextura(path)),
	tempoTotal(0.0f),
	RectSize(),
	switchTime(st)
{
	if (textura == nullptr) {
		cout << "Erro! nao ha textura na Animacao Individual!" << endl;
		exit(1);
	}

	RectSize.width = textura->getSize().x / float(contadorImagem);
	RectSize.height = textura->getSize().y;
}

/*Atualiza o frame*/
void Animacao::update(const float dt, bool AEsquerda)
{
	tempoTotal += dt;

	if (tempoTotal >= switchTime) {
		tempoTotal -= switchTime;
		imagemAtual++;

		if (imagemAtual >= contadorImagem)
			imagemAtual = 0;
	}

	if (!AEsquerda) {/*Observar isso! */
		RectSize.left = (imagemAtual + 1) * abs(RectSize.width);
		RectSize.width = -abs(RectSize.width);
	}
	else {
		RectSize.left = imagemAtual * abs(RectSize.width);
		RectSize.width = abs(RectSize.width);
	}
}
/*Função resetar imagem*/
void Animacao::reset()
{
	imagemAtual = 0;
	tempoTotal = 0;
}

/*Recebe tamanho*/
IntRect Animacao::getSize() const
{
	return IntRect(RectSize);
}

/*Recebe Textura*/
Texture* Animacao::getTextura() const
{
	return textura;
}