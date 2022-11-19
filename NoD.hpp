#ifndef NOD_HPP
#define NOD_HPP

#include <iostream>

using namespace std;

template <typename T>
class NoD
{
	T		dado;
	NoD*	prox;
	NoD*	prev;

	public:
		NoD(void): dado(), prox(nullptr), prev(nullptr) {};
		NoD(T dado): dado(dado), prox(nullptr), prev(nullptr) {};
		~NoD(void) {};

	template<typename L>
	friend class Pilha;
};

#endif
