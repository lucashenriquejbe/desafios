#include <algorithm>
#include <iostream>
#include <values.h>
#include <cstdio>
#include <map>

using namespace std;

int w[100], v[100];
int n, W;

map< pair<int, int>, int > moch;

inline int max(int a, int b)
{
	return a > b ? a : b;
}

int mochila(int n, int W)
{
	if(n == 0)
		return 0;
	if(W == 0)
		return 0;
	if(w[n]<=W)
	{
		if(moch.find(make_pair(n, W)) != moch.end())
			return moch[make_pair(n, W)];
		else
			moch[make_pair(n, W)] = max(mochila(n-1, W), mochila(n, W-w[n]) + v[n]);
	}
	else
	{
		if(moch.find(make_pair(n, W)) != moch.end())
			return moch[make_pair(n, W)];
		else
			moch[make_pair(n, W)] = mochila(n-1, W);
	}
}

int main()
{
	scanf("%d %d", &n, &W);

	for (int i = 0; i < n; ++i)
		scanf("%d %d", &w[i], &v[i]);

	cout << mochila(n-1, W) << endl;

	return 0;
}