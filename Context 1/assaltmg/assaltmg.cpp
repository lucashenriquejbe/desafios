#include <bits/stdc++.h>
#include <algorithm>
#include <values.h>

using namespace std;

int D[1<<21];
int T[1<<21];
int m, d, minimo;

int main()
{
	register int t, c, i, b, j, aux, tam, k;
	
	cin >> t;

	while(t--)
	{
		cin >> m >> d;
		for (i = 0; i < d; ++i)
		{
			cin >> c;
			D[1<<i] = 0;
			while(c--)
			{
				cin >> aux;
				D[1<<i] |= 1<<aux;
			}
		}

		T[0] = 0;
		minimo = m==0? 0 : MAXINT;
		for(i=1;i<1<<d;i++)
		{
			b = i&-i;
			T[i] = T[i-b] | D[b];
			if(__builtin_popcount(T[i])>=m)
				minimo = min(minimo, __builtin_popcount(i));
		}

		if(minimo == MAXINT)
			cout << "Desastre!" << endl;
		else
			cout << minimo << endl;	
	}

	return 0;
}