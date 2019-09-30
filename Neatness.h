// NEATNESS_H

#ifndef NEATNESS_H
#define NEATNESS_H

#include <string>
using namespace std;

class PrettyPrinter
{
private:
	
	int mPenalty;
	int mMaxLength;
	int mNumWords;

public:
	int Penalty(string*, int , int);
	int getPenalty();
	void setPenalty(int);
	void setMaxLength(int);
	void setNumWords(int);
	void PRINT_NEATLY(int, int, string*);
};

#endif