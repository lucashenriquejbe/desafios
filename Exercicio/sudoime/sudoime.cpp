#include <iostream>
#include <values.h>
#include <cstdlib>
#include <cstdio>

int n, i, j, k, W;
int l[9], c[9], q[3][3];
short v[9][9];

using namespace std;

bool sudoime()
{
	for (i = 0; i < 9; ++i)
	{
		for (j = 0; j < 9; ++j)
		{
			l[i] ^= v[i][j];
			c[j] ^= v[i][j];
			q[i/3][j/3] ^= v[i][j];
		}
	}

	for (i = 0; i < 9; ++i)
		if(l[i] || c[i] || q[i/3][i%3])
			return false;
	return true;
}

int main() {

	scanf("%d", &n);

	W = 0;
	for (i = 1; i <= 9; ++i) 
		W ^= i;

	for (k = 1; k <= n; ++k)
	{
		for (i = 0; i < 9; ++i){
			l[i] = W;
			c[i] = W;
			q[i/3][i%3] = W;
			for (j = 0; j < 9; ++j)
				scanf("%hd", &v[i][j]);
		}

		cout << "Instancia " << k << endl;
		cout << (sudoime() ? "SIM" : "NAO") << endl << endl;
	}

	return 0;
}