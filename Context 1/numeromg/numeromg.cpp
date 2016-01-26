#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

inline
int conv(char a)
{
	return a >= 'A' ? a-55 : a-48;
}

char trans(int a)
{
	return a >= 10 ? a+55 : a+48;
}

int main()
{
	string a, b, res;
	cin >> a >> b;
	
	int aux, i, j, x, y, r=0;
	while(!(a.compare("0")==0 && b.compare("a")))
	{
		res.clear();		
		r=0;
		for (i = a.size()-1, j = b.size()-1; i >= 0 && j >= 0; --i, --j)
		{
			x = conv(a[i]);
			y = conv(b[j]);
			res.insert(res.begin(), trans((r+x+y)%36));
			r = (r+x+y)/36;
		}
		if(a.size() > b.size())
			for (int k = i; k >= 0; --k)
			{
				x = conv(a[k]);
				res.insert(res.begin(), trans((r+x)%36));
				r = (r+x)/36;
			}
		else if(a.size() < b.size())
			for (int k = j; k >= 0; --k)
			{
				y = conv(b[k]);
				res.insert(res.begin(), trans((r+y)%36));
				r = (r+y)/36;
			}
		if(r>0)
			res.insert(res.begin(), trans(r));

		cout << res << endl;

		cin >> a >> b;
	}
	return 0;
}