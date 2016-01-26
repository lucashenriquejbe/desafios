#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <values.h>
#include <iostream>
#include <algorithm>

using namespace std;

int T[1550][1550];
const int s[] = {-1, 0, 1, 0};

int main()
{

	int n, i, j, a, p, x, y, l, c, minl, minc, maxl, maxc;
	scanf("%d", &n);
	while(n)
	{
		minl = minc = MAXINT;
		maxl = maxc = -1;
		a = p = 0;

		for(i=0;i<1550;++i)
			memset(T[i],0,sizeof(T[i]));
		while(n--)
		{
			scanf("%d %d %d %d", &x, &y, &l, &c);

			if(minl > x)
				minl = x;
			if(minc > y)
				minc = y;
			if(maxl < x+l)
				maxl = x+l;
			if(maxc < y+c)
				maxc = y+c;

			for(i=x;i<x+l;++i)
				for(j=y;j<y+c;++j)
					T[i][j] = 1;

		}

		for(i=minl;i<maxl;++i)
			for(j=minc;j<maxc;++j)
				if(T[i][j])
				{
					++a;
					p+=4;

					if(j>0 && T[i][j-1])
						--p;
					if(i>0 && T[i-1][j])
						--p;
					if(T[i][j+1])
						--p;
					if(T[i+1][j])
						--p;
				}

		printf("%d %d\n", a, p);

		scanf("%d", &n);
	}
	return 0;
}