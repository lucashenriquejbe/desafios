#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n;
bool p[1001];
vector<int> v;

bool soma_subconjunto_din(int k, short W)
{
	bool t[k+1][W+1], s;
	int i, j;

	for (i = 0; i <= k; ++i)
		t[i][0] = true;
	for (i = 1; i <= W; ++i)
	{
		t[0][i] = false;
		for (j = 1; j <= k; ++j)
		{
			s = t[j-1][i];
			if( !s && v[j-1]<=i)
				s = t[j-1][i-v[j-1]];
			t[j][i] = s;
		}
	}
	return t[k][W];
}

bool issequenci()
{
	int aux,i,j;
	for (i = 2; i < n; ++i)
	{
		if(soma_subconjunto_din(i, v[i]))
			return false;
	}
	return true;
}

void imprimir()
{
	for (int i = 0; i < v.size(); ++i)
		printf(" %d", v[i]);
	printf("\n");
}

int main()
{
	int a, i, k=1;
	bool t;

	while(scanf("%d", &n) != EOF)
	{
		t = true;
		for (i = 1; i < 1001; ++i)
			p[i] = false;
		v.clear();

		scanf("%d", &a);
		v.push_back(a);
		p[a] = true;
		for (i = 1; i < n; ++i)
		{
			scanf("%d", &a);
			v.push_back(a);
			if(p[a])
				t = false;
			if(v[i-1] > v[i])
				t = false;
			p[a] = true;
		}
		printf("Case #%d:", k);
		imprimir();

		if(t && issequenci())
			printf("This is an A-sequence.\n");
		else
			printf("This is not an A-sequence.\n");

		++k;
	}
	return 0;
}