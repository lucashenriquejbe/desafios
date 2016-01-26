#include <iostream>
#include <values.h>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>

short i, j, x, y, n, w;
short s;
short v[101];

using namespace std;

short max(short a, short b) {
	return (a>b) ? a : b;
}

bool soma_subconjunto(short k, short u)
{
	if( u == 0 )
		return true;
	if( k>n )
		return false;
	else
	{
		short r = soma_subconjunto(k+1, u);
		if( !r && v[k]<=u )
			r = soma_subconjunto(k+1, u-v[k]);
		return r;
	}
		
}

bool soma_subconjunto_din(short W)
{
	bool t[n+1][W+1], s;

	for (i = 0; i <= n; ++i)
		t[i][0] = true;
	for (i = 1; i <= W; ++i)
	{
		t[0][i] = false;
		for (j = 1; j <= n; ++j)
		{
			s = t[j-1][i];
			if( !s && v[j-1]<=i)
				s = t[j-1][i-v[j-1]];
			t[j][i] = s;
		}
	}
	return t[n][W];
}

bool tesouro() 
{

	short dif = abs(x-y);
	short W = s-dif;
	if(W%2!=0)
		return false;
	W /= 2;

	return soma_subconjunto_din(W);
}

int main() {
	s = 0;
	x = y = n = 1;
	short m;
	for(short k=1;;++k) 
	{
		scanf("%hd %hd %hd", &x, &y, &n);

		if(n==0 && x==0 && y==0)
			break;

				
		for (i = 0; i < n; ++i) {
			scanf("%hd", &v[i]);
			s += v[i];
		}

		cout << "Teste " << k << endl;
		cout << (tesouro() ? 'S' : 'N') << endl << endl;

		s = 0;
	}

	return 0;
}