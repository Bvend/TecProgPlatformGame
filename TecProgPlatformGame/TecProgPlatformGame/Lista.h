#pragma once
#include <stdlib.h>

namespace Listas
{
	template <class TL> class Lista
	{
	public:
		template <class TE> class Elemento
		{
		private:
			Elemento<TE>* pProx;
			TE* pitem;

		public:

			void setPprox(Elemento<TE>* p) { this->pProx = p; }
			void setItem(TE* i) { this->pitem = i; }
			Elemento<TE>* getPprox() { return pProx; }
			TE* getItem() { return pitem; }

			Elemento()
			{
				pProx = nullptr;
				pitem = nullptr;
			}

			~Elemento()
			{
				pProx = nullptr;
				pitem = nullptr;
			}
		};

	private:
		Elemento<TL>* pPrimeiro;
		Elemento<TL>* pUltimo;
		int tam;

	public:
		Lista();
		~Lista();

		int getTam()
		{
			return this->tam;
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
				Elemento<TL>* temp = new Elemento<TL>;
				temp->setItem(item);
				pUltimo->setPprox(temp);
				pUltimo = temp;
			}
			tam++;
		}

		TL* pop(TL* item)
		{
			Elemento<TL>* temp = pPrimeiro;
			Elemento<TL>* tempAnt = nullptr;

			while (temp != nullptr) {
				if (temp->getItem() == item)
				{
					if (temp == pPrimeiro) {
						pPrimeiro = temp->getPprox();
					}
					else if (temp == pUltimo) {
						tempAnt->setPprox(nullptr);
						pUltimo = tempAnt;
					}
					else {
						tempAnt->setPprox(temp->getPprox());
					}
					delete temp;
					tam--;
					return item;
				}
				tempAnt = temp;
				temp = temp->getPprox();
			}
			return nullptr;
		}

		TL* pop(int pos)
		{
			if (pos >= tam || pos < 0)
			{
				exit(1);
			}

			Elemento<TL>* tmp = pPrimeiro;
			Elemento<TL>* tmpAnt = nullptr;

			for (int i = 0; i < pos; i++)
			{
				tmpAnt = tmp;
				tmp = tmp->getPprox();
			}

			if (tmp == pPrimeiro)
			{
				pPrimeiro = tmp->getPprox();
			}
			else if (tmp == pUltimo)
			{
				pUltimo = tmpAnt;
				tmpAnt->setPprox(nullptr);
			}
			else
			{
				tmpAnt->setPprox(tmp->getPprox());
			}

			TL* pItem = tmp->getItem();

			delete (tmp);
			tam--;

			return pItem;
		}

		void esvaziar()
		{
			if (pPrimeiro)
			{
				Elemento<TL>* tmp = pPrimeiro;
				int i = 0;

				while (tmp != nullptr && i < tam)
				{
					pPrimeiro = (tmp->getPprox());
					delete tmp;
					tmp = pPrimeiro;
					i++;
				}
			}

			pUltimo = nullptr;
			tam = 0;
		}
	};

	template<class TL>
	Lista<TL>::Lista()
	{
		pPrimeiro = nullptr;
		pUltimo = nullptr;
		tam = 0;
	}

	template<class TL>
	Lista<TL>::~Lista()
	{
		esvaziar();
	}
}
