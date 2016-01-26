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

map<string, int> alunos;

int main()
{
	int n, m, inst=1;
	string nome;
	while(scanf("%d", &n)!=EOF) 
	{
		cin >> nome >> m;

		for (int j = 0; nome.size()!=20; ++j)
	    		nome.push_back('0');
	    for (int i = 0; i < n-1; ++i)
	    {
	    	string nome2;
	    	int k2;
	    	cin >> nome2 >> k2;
	    	for (int j = 0; nome2.size()!=20; ++j)
	    		nome2.push_back('0');
	    	if(k2 < m)
	    	{
	    		m = k2;
	    		nome = nome2;
	    	}
	    	else if(k2 == m)
	    		if(nome.compare(nome2)<0)
	    			nome = nome2;
	    }

	    cout << "Instancia " << inst++ << endl;
	    for (int i = 0; i < nome.size() && nome[i]!='0'; ++i)
	    	cout << nome[i];
	    cout << endl << endl;

	}

	return 0;
}