#include "PrimeSoccer.h"
#include <iostream>
#include <math.h>
using namespace std;
double PrimeSoccer::getProbability(int skillOfTeamA, int skillOfTeamB)
{
	const int MAXSCORE = 36;
	int NUMBEROFINTERVALS = 18;
	double finalScoreProbabilities [19][2];
	double probabilityOfTeamA = (double) skillOfTeamA / 100.0;
	double probabilityOfTeamB = (double) skillOfTeamB / 100.0;
	for(int n = 0; n <= NUMBEROFINTERVALS; n++)
	{
            double c = getBinomialCoefficient(NUMBEROFINTERVALS, n);
//            cout << "C for n = " << n << " is " << c << "\n";
            finalScoreProbabilities[n][0] = c * pow(probabilityOfTeamA, (double)n) * pow(1.0 - probabilityOfTeamA, (double) NUMBEROFINTERVALS - (double) n);
            finalScoreProbabilities[n][1] = c * pow(probabilityOfTeamB, (double)n) * pow(1.0 - probabilityOfTeamB, (double) NUMBEROFINTERVALS - (double) n);
            cout << n << "-" << finalScoreProbabilities[n][0] << "\n";
            cout << n << "-" << finalScoreProbabilities[n][1] << "\n";
	}
	
        double probabilityOfPrime = 
                finalScoreProbabilities[2][0] + finalScoreProbabilities[2][1] +
                finalScoreProbabilities[3][0] + finalScoreProbabilities[3][1] + 
                finalScoreProbabilities[5][0] + finalScoreProbabilities[5][1] +
                finalScoreProbabilities[7][0] + finalScoreProbabilities[7][1] +
                finalScoreProbabilities[11][0] + finalScoreProbabilities[11][1] +
                finalScoreProbabilities[13][0] + finalScoreProbabilities[13][1] +
                finalScoreProbabilities[17][0] + finalScoreProbabilities[17][1]; 
        
	cout << probabilityOfPrime;
	return probabilityOfPrime;
}

unsigned long long PrimeSoccer::getFactorial(int n)
{
    return n <= 1 ? 1 : n * getFactorial(n -1);
}

double PrimeSoccer::getBinomialCoefficient(int n, int k)
{
    return getFactorial(n) / (getFactorial(k) * getFactorial(n-k));
}


