#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <values.h>
#include <iostream>
#include <algorithm>

using namespace std;

int F, P, E, A;
int a[25][5500];

int energia()
{
	int EDP[F+1][P+1];

	EDP[1][1] = a[1][1];
	for (int i = 2; i <= F; ++i)
		EDP[i][1] = a[i][1] + A*E;

	for (int j = 2; j <= P; ++j)
	{
		for (int i = 1; i <= F; ++i)
		{
			EDP[i][j] = EDP[i][j-1] + a[i][j];
			for (int k = 1; k <= F; ++k)
				if(EDP[i][j] > EDP[k][j-1] + a[i][j] + A*E)
					EDP[i][j] = EDP[k][j-1] + a[i][j] + A*E;
		}
	}

	int m = MAXINT;

	for (int i = 1; i <= F; ++i)
		m = min(m, EDP[i][P]);

	return m;
}

int main()
{	
	int x, y;
	
	while( scanf("%d %d %d %d", &F, &P, &E, &A) && !(F==0 && P==0 && E==0 && A==0) )
	{
		for (int i = 1; i <= P; ++i)
			for (int j = 1; j <= F; ++j)
			{
				scanf("%d %d", &x, &y);
				a[j][i] = x*y;
			}

		printf("%d\n", energia());
	}
	return 0;
}