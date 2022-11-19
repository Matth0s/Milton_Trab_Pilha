#ifndef PILHA_HPP
#define PILHA_HPP

#include "NoD.hpp"

#include <sstream>

template <typename T>
class Pilha
{
	private:
		int		tamanho;
		NoD<T>*	inicio;
		NoD<T>*	fim;

	public:
		Pilha(void): tamanho(0), inicio(nullptr), fim(nullptr) {};

		bool	empty(void);
		int		size(void);
		T		top(void);
		void	push(T dado);
		void	pop(void);
		void	print(void);

};

template<typename T>
bool	Pilha<T>::empty(void) {
	return (tamanho == 0);
};

template<typename T>
int		Pilha<T>::size(void) {
	return (tamanho);
};

template<typename T>
T		Pilha<T>::top(void) {
	if (fim)
		return (fim->dado);
	return(T());
};

template<typename T>
void	Pilha<T>::push(T dado) {
	NoD<T>*	aux = new NoD<T>(dado);

	if (inicio) {
		fim->prox = aux;
		aux->prev = fim;
		fim = aux;
	} else {
		inicio = fim = aux;
	}
	tamanho++;
};

template<typename T>
void	Pilha<T>::pop() {
	NoD<T>*	aux;

	if (tamanho) {
		if (inicio == fim) {
			delete fim;
			inicio = fim = nullptr;
		} else {
			aux = fim->prev;
			aux->prox = nullptr;
			delete fim;
			fim = aux;
		}
		tamanho--;
	}
};

template<typename T>
void	Pilha<T>::print(void) {

	int	index = 1;

	for (NoD<T>* aux = fim; aux; aux = aux->prev) {
		std::ostringstream	out;
		out << aux->dado;
		cout << string(tamanho - (out.str().size() + 1)/2, ' ') << aux->dado << endl;
		cout << string(tamanho - index, ' ') << string(index * 2 - 1, '_') << endl;
		index++;
	}
	if (this->empty()) {
		cout << "\n! Pilha Vazia !\n" << endl;
	}
	cout << endl;

};

#endif