#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <values.h>
#include <iostream>
#include <algorithm>

using namespace std;

int K, L;
vector< pair<int, int> > v;

int nuvem()
{
	int C[K+1][K+1];
	for (int i = 1; i <= K; ++i)
		for (int j = i; j <= K; ++j)
			C[i][j] = (j-i+1)*v[j-1].second;
	int F[L+1][K+1];
	for (int i = 1; i <= K; ++i)
		F[1][i] = C[1][i];
	for (int i = 2; i <= L; ++i)
	{
		for (int j = 1; j <= K; ++j)
		{
			F[i][j] = C[1][j];
			for (int k = 1; k < j; ++k)
				F[i][j] = min(F[i][j], F[i-1][k]+C[k+1][j]);
		}
	}
	return F[L][K];
}

int main()
{
	int a, b;
	while(scanf("%d %d", &K, &L) && K && L)
	{
		v.clear();
		for (int i = 0; i < K; ++i)
		{
			scanf("%d %d", &a, &b);
			v.push_back( make_pair(a,b) );
		}

		sort(v.begin(), v.end());
		
		printf("%d\n", nuvem());
	}
}