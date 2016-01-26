#include <cstdio>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> e;
vector<int> s;
int n, i, j, a;

bool comparar(int x,int y) 
{ 
	return x>y;
}

int main()
{
	scanf("%d", &n);
	while(n>0)
	{
		e.clear();
		s.clear();
		for (i = 0; i < n; ++i)
		{
			scanf("%d", &a);
			e.push_back(a);
		}
		for (i = 0; i < n; ++i)
		{
			scanf("%d", &a);
			s.push_back(a);
		}

		sort(s.begin(), s.end(), comparar);

		int k;
		bool is=true;		
		for (i = 0; i < s.size(); ++i)
		{
			k = 0;
			sort(e.begin(), e.end(), comparar);
			for ( j = 0; j < e.size() && k < s[i]; ++j )
			{
				if( e[j]>0 )
				{
					--e[j];
					++k;
				}
				else
					break;

			}

			if(k < s[i])
			{
				is = false;
				break;
			}
		}
		
		if(!is)
			printf("N\n");
		else
		{
			int sum = 0;
			for (i = 0; i < e.size(); ++i)
				sum += e[i];
			if(sum > 0)
				printf("N\n");	
			else
				printf("E\n");
		}

		scanf("%d", &n);
	}
	return 0;
}