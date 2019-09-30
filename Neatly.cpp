// PRINT-NEATLY(l, n, M);
// set up 2-d dynamic array for values for extra white space
// set up extras array
#include <string>
#include <iostream>

using namespace std;


void PRINT_NEATLY(int n, int MaxLength, string* l)
{
int M = MaxLength;
int** extras = 0;
extras = new int*[n];
for(int i = 0; i < n; i++)
	{
	extras[i] = new int[n];
	}
// set up costs array
int** lc = 0;
lc = new int*[n];
for(int a = 0; a < n; a++)
	{
	lc[a] = new int[n];
	}

// set up total cost array (1-d)
int* c = 0;
c = new int[n+1];
for(int b = 0; b <= n; b++)
	{
	c[b] = 2147483647;
	}

// Compute extras[i; j] for 1 <= i <= j <= n.
for(int k = 1; k <= n; k++)
	{
	extras[k][k] = M - l[k].length();
	for(int j = k + 1; j <= n; j++)
		{
			extras[k][j] = extras[k][j-1]�- l[j].length() - 1;
		}
	}
// Compute lc[i][j] for 1 <= i <= j <= n
for(int i = 1; i <= n; i++)
	{
	for(int j = i; j <= n; j++)
		{
		if(extras[i][j] < 0)
			{
			lc[i][j] = 1;
			}
		else
			{
			if j == n and extras[i][j]== 0)
				{
				lc[i][j] = 0;
				}
			else
				{
				lc[i][j] = (extras[i][j])^3;
				}
			}
		}
	}
// Compute c[j] and p[j] for 1 <= j <= n
c[0] = 0;
for(int d = 0; d < n; d++)
{
	c[d] = 32767;
	for(int e = 0; e < d; e++)
	{
		if c[e-1] + lc[e][d] < c[d])
		{
			c[d] = c[e - 1] + lc[e][d];
			p[d] = e;
		}
	}
}
//return c and p
}