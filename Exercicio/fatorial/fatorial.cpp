#include <set>
#include <map>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <values.h>
#include <iostream>
#include <algorithm>

using namespace std;

long long int fat[1000001];


int main()
{
	int n, i=1;
	fat[0] = 1;
	fat[1] = 1;
	for (int j = 2; j <= 1000000 ; ++j)
	{
		fat[j] = j*fat[j-1];
		while(fat[j]%10==0)
			fat[j] /= 10;
		fat[j] %= 1000000;
	}

	while(scanf("%d", &n)!=EOF)
	{
		printf("Instancia %d\n", i++);
		printf("%lld\n\n", fat[n]%10);
	}
	return 0;
}