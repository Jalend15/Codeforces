#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>

#define pb push_back
#define mp make_pair
#define S second
#define F first

typedef long long ll;
typedef double ld;

using namespace std;

int amo, bad;
int cnt[3];
string s;

string val[] = {"lios", "liala", "etr", "etra", "initis", "inites"};
int rod[] = {0, 1, 0, 1, 0, 1};
int tip[] = {1, 1, 0, 0, 2, 2};

int type (string x)
{
	for (int i = 0; i < 6; i++)
		if (x.size () >= val[i].size ())
		{
//			cout << x.substr (x.size ()-val[i].size (), val[i].size ()) << " " << val[i] << endl;
			if (x.substr (x.size ()-val[i].size (), val[i].size ()) == val[i])
			{
			 	cnt[rod[i]]++;
			 	return tip[i];
			}
		}
	puts ("NO");
	exit (0);
}

int main ()
{
	/*#ifndef ONLINE_JUDGE
		freopen ("input", "r", stdin);
		freopen ("output", "w", stdout);
	#endif*/

	bool was = 0;
	while (cin >> s)
	{
		int x = type (s);
		amo++;

		if (was)
		{
			if (x != 2) bad = 1;
        }
        else
        {
			if (x == 2) bad = 1;
			if (!x) was = 1;
        }
	}

	if (amo > 1 && (bad || (cnt[0] && cnt[1]) || !was))
		puts ("NO");
	else
		puts ("YES");

	return 0;
}

