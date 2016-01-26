#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int n;
string pre;
string em;

int find(char c, string str, int p, int q)
{
	for (int i = p; i <= q; ++i)
		if(str[i] == c)
			return i;
	return -1;
}

void pos(int root, int p, int q)
{
	int a, i, r=-1;
	a = em.find(pre[root]);
	
	if(p>=q)
	{
		printf("%c",pre[root]);
		return;
	}

	if(a-1>=p)
	{
		r = find(pre[root+1], em, p, a-1);
		if(r>=0)
			pos(root+1,p,a-1);
	}
	if(a+1<=q){
		r = -1;
		for(i=1;i<n && r<0;++i)
			r = find(pre[root+i], em, a+1, q);
		if(r>=0)
			pos(root+i-1,a+1,q);
	}
	printf("%c", pre[root]);
}

int main()
{
	int k, i;
	scanf("%d", &k);
	while(k--)
	{
		pre.clear();
		em.clear();
		scanf("%d", &n);
		cin >> pre;
		cin >> em;

		pos(0,0,n-1);
		printf("\n");
		
	}
	return 0;
}