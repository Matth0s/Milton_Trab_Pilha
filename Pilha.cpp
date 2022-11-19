// Parte desse código foi retirado do Exemplo 7, pra servir de base para criação da pilha.

#include "Pilha.hpp"
#include <fstream>

struct t_Ponto
{
	int	x;
	int	y;

	t_Ponto(void): x(), y() {};
	t_Ponto(int x, int y): x(x), y(y) {};

	void	mudarPonto(int x, int y) {
		this->x = x;
		this->y = y;
	};
};

std::ostream&	operator<<( std::ostream& output, const t_Ponto &rhs )
{
	output << "[" << rhs.x << ", " << rhs.y << "]";
	return (output);
}

void	PreencheUsandoPilha(int lin, int col, char marca, string* linha)
{
	Pilha<t_Ponto>	pilhaponto;
	t_Ponto			pnt;
	char			c;

	// coloca o primeiro ponto na Pilha (nao testa se é interior)
	c = linha[lin][col];
	if ( c != '1' && c != marca ) {
		pnt.mudarPonto(col, lin);
		cout << pnt << endl << endl;
		pilhaponto.push(pnt);
	}

	while ( !pilhaponto.empty() ) // enquanto a pilha não estiver vazia
	{
		pnt = pilhaponto.top();
		pilhaponto.pop();
		lin = pnt.y;
		col = pnt.x;
		linha[lin][col] = marca;

		c = linha[lin - 1][col];
		if ( c != '1' && c != marca ) {
			pnt.mudarPonto(col, lin - 1);
			pilhaponto.push(pnt);
		}
		c = linha[lin + 1][col];
		if ( c != '1' && c != marca ) {
			pnt.mudarPonto(col, lin + 1);
			pilhaponto.push(pnt);
		}
		c = linha[lin][col + 1];
		if ( c != '1' && c != marca ) {
			pnt.mudarPonto(col + 1, lin);
			pilhaponto.push(pnt);
		}
		c = linha[lin][col - 1];
		if ( c != '1' && c != marca ) {
			pnt.mudarPonto(col -1, lin);
			pilhaponto.push(pnt);
		}
	}
}

void	Testa_Pilha(void)
{
	int			num_linhas_matriz_pontos;
	ifstream	arq_com_regiao_a_ser_preenchida; // arquivo que contem a matriz de pontos
	string		linhas_primeira[100];
	string		linhas_segunda[100];
	int i = 0; // conta numero de linhas da matriz. Todas as linhas devem começar e terminar por um caracter '1'


	arq_com_regiao_a_ser_preenchida.open("matriz_pontos_regiao.txt");
	if (!arq_com_regiao_a_ser_preenchida.is_open())
		return ;
	while (!arq_com_regiao_a_ser_preenchida.eof()) {
		getline(arq_com_regiao_a_ser_preenchida, linhas_primeira[i]);
		linhas_segunda[i] = string(linhas_primeira[i]);
		i++;
	}

	num_linhas_matriz_pontos = i;
	cout << "Numero de Linhas da Matriz de Pontos: " << num_linhas_matriz_pontos << endl;
	arq_com_regiao_a_ser_preenchida.close();

	cout << string(25, '_') << endl;

	for (int i = 0; i < num_linhas_matriz_pontos; i++)
		cout << linhas_primeira[i] << endl;

	cout << string(25, '_') << endl;

	PreencheUsandoPilha(3, 2, '@', linhas_primeira);
	for(int i = 0; i < num_linhas_matriz_pontos; i++ )
		cout << linhas_primeira[i] << endl;

	cout << string(25, '_') << endl;

	PreencheUsandoPilha(3, 2, '-', linhas_segunda); // tem que ser passado as coordenadas de um ponto interior da figura.
	for(int i = 0; i < num_linhas_matriz_pontos; i++ )
		cout << linhas_segunda[i] << endl;

	cout << string(25, '_') << endl;


}

#include <cstdlib>

int main()
{
	cout << "+-------------------------------------------------------------------------------------+" << endl;
	cout << "| Exemplo 701: Usando Pilhas para preencher uma região (Pilha implementada com listas |" << endl;
	cout << "+-------------------------------------------------------------------------------------+" << endl << endl;

	Pilha<int> Pilhainteiro;

	for (int i = 0; i < 20; i++) {
		Pilhainteiro.push(rand() % 10000);
	}
	Pilhainteiro.print();

	cout << endl;
	while (Pilhainteiro.size()) {
		cout << Pilhainteiro.top() << (Pilhainteiro.size() != 1 ? " | " : "\n");
		Pilhainteiro.pop();
	}
	cout << endl;
	Pilhainteiro.print();

	Testa_Pilha();

	return 0;
}