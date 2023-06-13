#include <iostream>

const int N = 5;
int nn = N - 1;
int Tab[N] = { 0, 1, 2, 3, 4 };

int P[N], C[N];
bool PR[N];

void rev(int m)
{
	int i = 1;
	int j = m;
	int temp;
	while (i < j)
	{
		temp = Tab[i];
		Tab[i] = Tab[j];
		Tab[j] = temp;
		i++;
		j--;
	}
}

void antylex(int m)
{
	int temp;
	if (m == 1) {
		for (int k = 1; k <= nn; ++k) {
			std::cout << Tab[k];
		}
		std::cout << std::endl;
	}
	else {
		for (int i = 1; i <= m; ++i) {
			antylex(m - 1);
			if (i < m) {
				temp = Tab[i];
				Tab[i] = Tab[m];
				Tab[m] = temp;
				rev(m - 1);
			}
		}
	}
}

int B(int m, int i) {
	if (m % 2 == 0 && m > 2) {
		if (i < m - 1) {
			return i;
		}
		else {
			return m - 2;
		}
	}
	else {
		return m - 1;
	}
}

void perm(int m) {
	int temp;
	if (m == 1) {
		for (int k = 1; k <= nn; ++k) {
			std::cout << Tab[k];
		}
		std::cout << std::endl;
	}
	else {
		for (int i = 1; i <= m; ++i) {
			perm(m - 1);
			if (i < m) {
				temp = Tab[m];
				Tab[m] = Tab[B(m,i)];
				Tab[B(m, i)] = temp;
			}
		}
	}
}

void perm2() {
	int temp;
	for (int i = 1; i <= nn; ++i) {
		P[i] = i;
		C[i] = 1;
		PR[i] = true;
	}
		C[nn] = 0;
		for (int k = 1; k <= nn; ++k) {
			std::cout << P[k];
		}
		std::cout << std::endl;
		int j = 1;
		int m;
		int l;
		bool p;
		while (j < nn) {
			j = 1; 
			m = 0;
			while (C[j] == nn - j + 1) {
				C[j] = 1;
				p = !(PR[j]);
				PR[j] = p;
				if (PR[j] == true) {
					m++;
				}
				j++;
			}
				if (j < nn) {
					if (PR[j] == true) {
						l = C[j] + m ;
					}
					else {
						l = nn - j + 1 - C[j] + m;
					}
					temp = P[l];
					P[l] = P[l + 1];
					P[l + 1] = temp;
					for (int x = 1; x <= nn; ++x) {
						std::cout << P[x];
					}
					std::cout << std::endl;
					C[j] = C[j] + 1;
				}


		}
}

int main()
{
	antylex(4);
	std::cout << std::endl;
	for (int i = 1; i <= nn; ++i) {
		Tab[i] = i;
	}
	perm(4);
	std::cout << std::endl;
	perm2();
	return 0;
};
