#include <iostream>
#include <cstdio>

int d[102][102];
int p[102][102];


using namespace std;

int main()
{
	int n, k, i, j;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		for (i = 0; i < 102; ++i)
			for (j = 0; j < 102; ++j)
			{
				d[i][j] = 0;
				p[i][j] = 0;
			}
		scanf("%d", &k);
		for (i = 1; i < k; ++i)
			for (j = 1; j <= i; ++j)
				scanf("%d", &p[i][j]);
		
		for (i = 0; i < n; ++i){
			for (j = 0; j < n; ++j)
				cout << p[i][j] << " ";
			cout << endl;
		}
	}
	return 0;
}