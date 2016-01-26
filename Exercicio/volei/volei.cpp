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

set<int> X, Y;
int N, maximo;
int pontos[100][2];
int g[204][204];
int marc[204];
int pred[204];
int nmarcados;

void dfs(int v, int t){
	int j;
	marc[v]=1;
	nmarcados++;
	if( nmarcados == 204 ) return;
	if( pred[t]!=-1) return;
	for(j=0;j < 204;j++){
	  	if(g[v][j] > 0 && marc[j]==0){
	     	pred[j]=v;
			dfs(j, t);
	   	}
	}
}

int fff(int s, int t){
    int cont=0;
    while (1){
      for (int i=0;i<204;i++){
          pred[i]=-1;
          marc[i]=0;
      }
      nmarcados=0;
      dfs(0, t);
	  if (pred[t]==-1) break;
      for (int i=t;pred[i]!=-1;i=pred[i]){
          g[pred[i]][i]--;
          g[i][pred[i]]++;
      }
      cont++;
    }
    return cont;
}

bool intercepte(int x, int y)
{
	int c=0;
	for (int i = 0; i < N; ++i)
	{
		int j = (i+1)%N;
		if(pontos[j][1] == pontos[i][1] && y == pontos[i][1])
		{
			int a = min(pontos[i][0],pontos[j][0]);
			int b = max(pontos[i][0],pontos[j][0]);
			if(x>=a && x<=b)
				return true;
		}
		if(pontos[j][0] == pontos[i][0] && x == pontos[i][0])
		{
			int a = min(pontos[i][1],pontos[j][1]);
			int b = max(pontos[i][1],pontos[j][1]);
			if(y>=a && y<=b)
				return true;
		}
		if( ((y > pontos[i][1] && y <= pontos[j][1]) 
			|| (y > pontos[j][1] && y <= pontos[i][1]))
			&& (pontos[i][0]<=x || pontos[j][0]<=x))
			if(pontos[i][0]+(y-pontos[i][1])/(pontos[j][1]-pontos[i][1])*(pontos[j][0]-pontos[i][0])<x)
				++c;
	}

	return c%2==0 ? false : true;
}

int main()
{
	int x, y;
	
	while(scanf("%d", &N) && N)
	{
		X.clear();
		Y.clear();

		for (int i = 0; i < 204; ++i)
			for (int j = 0; j < 204; ++j)
				g[i][j] = 0;

		for (int i = 0; i < N; ++i)
		{
			scanf("%d %d", &x, &y);
			pontos[i][0] = x;
			pontos[i][1] = y;
			X.insert(x);
			Y.insert(y);
		}

		map< pair<int, int>, bool > parxy;
		map<int, int> indx;
		map<int, int> indy;
		int a = 1;
		for (set<int>::iterator i = X.begin(); i != X.end(); ++i){
			for (set<int>::iterator j = Y.begin(); j != Y.end(); ++j){
				if(!intercepte(*i, *j)){
					parxy[make_pair(*i, *j)] = true;
					if(indx[*i]==0)
						indx[*i] = a++;
					if(indy[*j]==0)
						indy[*j] = a++;
					g[indx[*i]][indy[*j]] = 1;
					g[indy[*j]][203] = 1;
					g[0][indx[*i]] = 1;
				}
			}
		}

		int d = fff(0,203);
		printf("%ld\n",  X.size() + Y.size() - d);
	}
	return 0;
}

