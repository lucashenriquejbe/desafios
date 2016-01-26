#include <iostream>
#include <cstdio>
#include <cmath>

int n;

using namespace std;

int main()
{
	unsigned long long int res, aux;
	int a[100000];
	int t, i, j;
	scanf("%d", &t);

	while(t--)
	{
		res = aux = 0;

		scanf("%d", &n);
		for (i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
			aux += a[i];
		}
		for (i = 0; i < n; ++i)
		{
			res += ((aux%1300031)*(a[i]%1300031))%1300031; 
			aux-=a[i];
		}
		cout << res%1300031 << endl;
	}
	return 0;
}