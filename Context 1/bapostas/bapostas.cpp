#include <iostream>
#include <values.h>
#include <cstdio>
#include <cmath>

int a[10000];
int n, r;

int maiorganho()
{
	int max, aux;
	max = aux = 0;

	for (int i = 0; i < n; ++i)
	{
		if(aux+a[i]>0)
			aux += a[i];
		else
			aux = 0;
		if(aux > max)
			max = aux;
	}

	return max;
}

int main()
{
	while(1)
	{
		scanf("%d", &n);
		if(n==0)
			break;
		for (int i = 0; i < n; ++i)
			scanf("%d",&a[i]);
		r = maiorganho();
		if(r>0)
			printf("The maximum winning streak is %d.\n", r);
		else
			printf("Losing streak.\n");
	}
	return 0;
}