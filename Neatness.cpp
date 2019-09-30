#include "Neatness.h"
#include <string>
#include <iostream>

int PrettyPrinter::getPenalty()
{
 return mPenalty;
}

void PrettyPrinter::setPenalty(int p)
{
 mPenalty = p;
}

void PrettyPrinter::setMaxLength(int m)
{
 mMaxLength = m;
}

void PrettyPrinter::setNumWords(int n)
{
 mNumWords = n;
}

int PrettyPrinter::Penalty(string *wordArray, int i, int j)
{
	int lengthSum = 0;
	for(int a = i; a <= j; a++)
	{
		
		lengthSum = lengthSum + wordArray[a].length();
	}
	if(lengthSum > mMaxLength)
	{
		mPenalty = -1;
	}
	else 
	{
		int Extras = mMaxLength - j + i - lengthSum;
		if(Extras < 0)
		{
			mPenalty = -1;
		}
		else
		{
			if(j == mNumWords && Extras >= 0)
			{
              mPenalty = 0;
			}
			else
			{
				mPenalty = Extras^3;
			}
		}
	}
	return mPenalty;
}

void PrettyPrinter::PRINT_NEATLY(int n, int MaxLength, string* wordArray)
{
    int CharsLeft, cost, i, j, p, lp, lq, lj, sum_lk;
	int* lineend = 0;
	int* c = 0;
	lineend = new int[n];
	c = new int[n];
	for(i = n-1; i >= 0; i--)
    {
        p = i;
        lp = wordArray[p].length();
		lq = 0;
		if(p+1 <= n-1)
		{
        lq = wordArray[p+1].length();
		}
        CharsLeft = MaxLength - lp;
        while (lq != 0 && (CharsLeft - lq -1) > 0 && p < n-1)
          {
           CharsLeft = CharsLeft - lq - 1;
           p += 1;
           lq = wordArray[p+1].length();
          }
        if(p = n-1)
          {
          c[i] = 0;
          lineend[i] = n-1;
          }
         else
          {
               c[i] =  2147483647; // the Maximum number for this type
               sum_lk = 0;
               for(j = i; j <= p; j++)
                  {
                   lj = wordArray[j].length();
                   sum_lk = sum_lk + lj; 
                   cost = ( MaxLength -j + i - sum_lk )^3 + c[j+1];
                    if(cost < c[i])
                      {
                      c[i] = cost;
                      lineend[i] = j;
                      }
                   }
          } 
      }

     // Print paragraph
     int start = 0;
	 int w;
     while(start <= n-1)
         {
             for(w = start; w <= lineend[start]; w++)
			 {
             cout <<  wordArray[w] << " ";
             }
             cout << endl;
             start = lineend[start] + 1;
          }
}