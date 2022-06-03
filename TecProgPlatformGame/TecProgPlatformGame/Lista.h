#pragma once
#include "Elemento.h"

template <class TL> class Lista
{
private:
	Elemento<TL>* pPrimeiro;
	Elemento<TL>* pUltimo;
	int len;

public:
	Lista();
	~Lista();

	int getLen() 
	{
		return this->len; 
	}

	TL* getItem(int posicao) 
	{
		Elemento<TL>* temp = pPrimeiro;
		if (posicao == 0)
			return temp->getItem();
		for (int i = 0; i < posicao; i++) {
			temp = temp->getPprox();
		}
		return temp->getItem();
	}

	Elemento<TL>* getElemento(int posicao)
	{
		Elemento<TL>* temp = pPrimeiro;
		if (posicao == 0)
			return temp;
		for (int i = 0; i < posicao; i++) {
			temp = temp->getPprox();
		}
		return temp;
	}

	void push(TL* item) 
	{
		if (pPrimeiro == nullptr) {
			pPrimeiro = new Elemento<TL>;
			pPrimeiro->setItem(item);
			pUltimo = pPrimeiro;
		}
		else {
			Elemento<TL> *temp = new Elemento<TL>;
			temp->setItem(item);
			pUltimo->setPprox(temp);
			pUltimo = temp;
		}
		len++;
	}

	void pop(TL* item)
	{
		Elemento<TL> *temp = pPrimeiro;
		Elemento<TL> *tempAnt = nullptr;
		
		while (temp->getItem() != item) {
			tempAnt = temp;
			temp = temp->getPprox();
		}
		if (temp == pPrimeiro) {
			pPrimeiro = temp->getPprox();
		}
		else if (temp == pUltimo) {
			tempAnt->getPprox() = nullptr;
			pUltimo = tempAnt;
		}
		else {
			tempAnt->setPprox(temp->getPprox());
		}
		delete temp;
		len--;
	}

	void esvaziar()
	{
		Elemento<TL>* tmp = pPrimeiro;
		int i = 0;

		while (tmp != nullptr && i < len)
		{
			// delete pPrimeiro->getItem(); ----------------------atention please
			pPrimeiro = tmp->getPprox();
			delete tmp;
			tmp = pPrimeiro;
			i++;
		}

		pUltimo = nullptr;
		len = 0;
	}
};

template<class TL>
Lista<TL>::Lista()
{
	pPrimeiro = nullptr;
	pUltimo = nullptr;
	len = 0;
}

template<class TL>
Lista<TL>::~Lista()
{
	esvaziar();
}
