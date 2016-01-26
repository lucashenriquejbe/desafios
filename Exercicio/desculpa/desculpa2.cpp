#include <algorithm>
#include <iostream>
#include <values.h>
#include <cstdio>

using namespace std;

int w[200], v[100];
int n, W;

inline int max(int a, int b)
{
	return a > b ? a : b;
}

int mochila_din(int n, int W)
{
	int K[n+1][W+1];
	for (int i = 0; i <= W; ++i)
		K[0][i] = 0;
	for (int i = 0; i <= n; ++i)
		K[i][0] = 0;

	for (int i = 1; i <= W; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if(w[j-1] <= i)
				K[j][i] = max(K[j-1][i], K[j-1][i-w[j-1]] + v[j-1]);
			else
				K[j][i] = K[j-1][i];
		}
	}
	
	return K[n][W];
}

int main()
{
	n = W = 1;
	int k = 1;
	while(true)
	{
		scanf("%d %d", &W, &n);

		for (int i = 0; i < n; ++i)
			scanf("%d %d", &w[i], &v[i]);
		
		if(W==0 && n==0)
			break;

		cout << "Teste " << k++ << endl << mochila_din(n, W) << endl;

	}

	return 0;
}