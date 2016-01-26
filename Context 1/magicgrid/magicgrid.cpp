#include <iostream>
#include <values.h>
#include <cstdio>
#include <cmath>

using namespace std;

int s[502][502];
int d[502][502];
int p[502][502];
int r, c, i, j;

inline
int min(int a, int b)
{
	return a > b ? b : a;
}

inline
int max(int a, int b)
{
	return a > b ? a : b;
}

int min_strength()
{
	int a, b;
	for (i = 0; i <= c; ++i)
		d[0][i] = 0;
	for (i = 0; i <= r; ++i)
		d[i][0] = 0;

	d[r][c] = 1;
	for (i = r-1; i > 0; --i)
		d[i][c] = (d[i+1][c] - s[i][c] < 1) ? 1 : d[i+1][c] - s[i][c];
	for (i = c-1; i > 0; --i)
		d[r][i] = (d[r][i+1] - s[r][i] < 1) ? 1 : d[r][i+1] - s[r][i];
	for (i = r-1; i > 0; --i)
		for (j = c-1; j > 0; --j)
		{
			if(d[i+1][j] < d[i][j+1])
				d[i][j] = d[i+1][j] - s[i][j];
			else
				d[i][j] = d[i][j+1] - s[i][j];
			if(d[i][j] < 1)
				d[i][j] = 1;
		}
	
	return d[1][1];
}

int main()
{
	int n;
	scanf("%d",&n);
	for (int u = 0; u < n; ++u)
	{
		scanf("%d %d", &r, &c);
		for (i = 1; i <= r; ++i)
			for (j = 1; j <= c; ++j)
				scanf("%d", &s[i][j]);
		cout << min_strength() << endl;
	}
	return 0;
}