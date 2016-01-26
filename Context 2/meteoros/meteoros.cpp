#include <algorithm>
#include <iostream>
#include <values.h>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
 
using namespace std;
 
 
int main()
{
	int c,n;
	pair<int, int> p1, p2, p;
	
	for(int i=1;; ++i )
	{
		c = 0;
 
		scanf("%d %d %d %d", &p1.first, &p1.second, &p2.first, &p2.second);
 
		if(p1.first == 0 && p1.second == 0 && p2.first == 0 && p2.second == 0)
			return 0;
 
		scanf("%d", &n);
 
		for(int j=0;j<n;++j)
		{
			scanf("%d %d", &p.first, &p.second);
			if( p.first >= p1.first && p.first <= p2.first && p.second >= p2.second && p.second <= p1.second )
				++c;
		}
 
		printf("Teste %d\n", i);
		printf("%d\n\n", c);
	}
	
	return 0;
} 