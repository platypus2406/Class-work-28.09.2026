#include <iostream>

void rmMtx(int** mtx, size_t m)
{
	for (size_t i = 0; i < m; ++i)
		delete[] mtx[i];

	delete[] mtx;
}

int** convert(const int* t, size_t n, const size_t* lns, size_t rows)
{
	int** mtx = new int*[rows];

	size_t k = 0;

	for (size_t i = 0; i < rows; ++i)
	{
		mtx[i] = new int[lns[i]];

		for (size_t j = 0; j < lns[i]; ++j)
			mtx[i][j] = t[k++];
	}

	return mtx;
}

void printMtx(int** mtx, const size_t* lns, size_t rows)
{
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < lns[i]; ++j)
			std::cout << mtx[i][j] << ' ';

		std::cout << '\n';
	}
}

int main()
{
	size_t n = 0;
	std::cin >> n;

	if (!std::cin || n == 0)
		return 1;

	int* t = new int[n];

	for (size_t i = 0; i < n; ++i)
		std::cin >> t[i];

	if (std::cin.fail())
	{
		delete[] t;
		return 1;
	}

	size_t rows = 0;
	std::cin >> rows;

	size_t* lns = new size_t[rows];

	for (size_t i = 0; i < rows; ++i)
		std::cin >> lns[i];

	int** mtx = convert(t, n, lns, rows);

	printMtx(mtx, lns, rows);

	rmMtx(mtx, rows);
	delete[] lns;
	delete[] t;

	return 0;
}
