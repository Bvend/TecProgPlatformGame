#pragma once
#include <iostream>
#include <cmath>
using namespace std;

template <typename TL>
class Coordenada
{
private: //Nessa versão x e y são privados, por isso use getX() e getY() 
	TL x;
	TL y;

public:
	//TL y;
	//TL x;

	Coordenada(TL x, TL y);
	Coordenada();
	~Coordenada() { }

	TL getX() { return x; }
	TL getY() { return y; }

	void setX(TL x);
	void setY(TL y);

	void atualizarX(TL cx);
	void atualizarY(TL cy);

	void calculaAbs();

	void operator=(Coordenada<TL> outro);
	void operator+=(Coordenada<TL> outro);
	void operator-=(Coordenada<TL> outro);
	void operator*=(float escalar);
	void operator/=(float escalar);

	Coordenada<TL> operator+(Coordenada<TL> outro);
	Coordenada<TL> operator-(Coordenada<TL> outro);
	Coordenada<TL> operator*(Coordenada<TL> outro);
	Coordenada<TL> operator*(double escalar);
	Coordenada<TL> operator/(Coordenada<TL> outro);
	Coordenada<TL> operator/(double escalar);
};

typedef Coordenada<float> CoordF;
typedef Coordenada<double> CoordD;
typedef Coordenada<int> CoordI;
typedef Coordenada<unsigned int> CoordU;

template<typename TL>
inline Coordenada<TL>::Coordenada(TL x, TL y) :
	x(x),
	y(y)
{
}

template<typename TL>
inline Coordenada<TL>::Coordenada()
{
	this->x = 0;
	this->y = 0;
}

/* Função para atribuir um valor a coord x */
template<typename TL>
inline void Coordenada<TL>::setX(TL x)
{
	this->x = x;
}

/* Função para atribuir um valor a coord y */
template<typename TL>
inline void Coordenada<TL>::setY(TL y)
{
	this->y = y;
}

/* Função para atualizar x a partir de um valor já atribuido */
template<typename TL>
inline void Coordenada<TL>::atualizarX(TL cx)
{
	this->x = this->x + cx;
}

/* Função para atualizar y a partir de um valor já atribuido */
template<typename TL>
inline void Coordenada<TL>::atualizarY(TL cy)
{
	this->y = this->y + cy;
}

template<typename TL>
inline void Coordenada<TL>::calculaAbs()
{
	x = fabs(x);
	y = fabs(y);
}

template<typename TL>
void Coordenada<TL>::operator=(Coordenada<TL> outro)
{
	this->x = outro.getX();
	this->y = outro.getY();
}

template<typename TL>
void Coordenada<TL>::operator+=(Coordenada<TL> outro)
{
	this->x = this->x + outro.getX();
	this->y = this->y + outro.getY();
}

template<typename TL>
void Coordenada<TL>::operator-=(Coordenada<TL> outro)
{
	this->x -= outro.getX();
	this->y -= outro.getY();
}

template<typename TL>
void Coordenada<TL>::operator*=(float escalar)
{
	this->x = this->y * escalar;
	this->y = this->y * escalar;
}

template<typename TL>
void Coordenada<TL>::operator/=(float escalar)
{
	if (escalar != 0.0f) {
		this->x /= escalar;
		this->y = escalar;
	}
	else {
		cout << "Erro!! Não eh possivel dividir por 0!" << endl;
	}
}

template<typename TL>
Coordenada<TL> Coordenada<TL>::operator+(Coordenada<TL> outro)
{
	return Coordenada<TL>(this->x + outro.getX(), this->y + outro.getY());
}

template<typename TL>
Coordenada<TL> Coordenada<TL>::operator-(Coordenada<TL> outro)
{
	return Coordenada<TL>(this->x - outro.getX(), this->y - outro.getY());
}

template<typename TL>
Coordenada<TL> Coordenada<TL>::operator*(Coordenada<TL> outro)
{
	return Coordenada<TL>(this->x * outro.getX(), this->y * outro.getY());
}

template<typename TL>
Coordenada<TL> Coordenada<TL>::operator*(double escalar)
{
	return Coordenada<TL>(this->x * escalar, this->y * escalar);
}

template<typename TL>
Coordenada<TL> Coordenada<TL>::operator/(Coordenada<TL> outro)
{
	if (outro.getX() == 0.0f || outro.getY() == 0.0f) {
		cout << "Erro!! Não eh possivel dividir por 0!" << endl;
		exit(1);
	}

	return Coordenada<TL>(this->x / outro.getX(), this->y / outro.getY());
}

template<typename TL>
Coordenada<TL> Coordenada<TL>::operator/(double escalar)
{
	if (escalar == 0.0f) {
		cout << "Erro!! Não eh possivel dividir por 0!" << endl;
		exit(1);
	}
	
	return Coordenada<TL>(this->x / escalar, this->y / escalar);
}
