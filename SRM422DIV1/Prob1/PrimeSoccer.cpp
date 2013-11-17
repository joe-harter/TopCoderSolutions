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

        double SumofGreaterA = 0;
        double SumofGreaterB = 0;
	for(int n = NUMBEROFINTERVALS; n >= 0; n--)
	{
            double probabilityA = n == 0 ? 1 : pow(probabilityOfTeamA, n);
            double probabilityB = n == 0 ? 1 : pow(probabilityOfTeamB, n);
            
            
            finalScoreProbabilities[n][0] = probabilityA - SumofGreaterA; 
            finalScoreProbabilities[n][1] = probabilityB - SumofGreaterB;
            SumofGreaterA += finalScoreProbabilities[n][0]; 
            SumofGreaterB += finalScoreProbabilities[n][1];
            cout << n << "-" << finalScoreProbabilities[n][0] << "\n";
            cout << n << "-" << finalScoreProbabilities[n][1] << "\n";
	}
	
        double probabilityOfPrime = finalScoreProbabilities[1][0] + finalScoreProbabilities[1][1] +
                finalScoreProbabilities[2][0] + finalScoreProbabilities[2][1] +
                finalScoreProbabilities[3][0] + finalScoreProbabilities[3][1] + 
                finalScoreProbabilities[5][0] + finalScoreProbabilities[5][1] +
                finalScoreProbabilities[7][0] + finalScoreProbabilities[7][1] +
                finalScoreProbabilities[11][0] + finalScoreProbabilities[11][1] +
                finalScoreProbabilities[13][0] + finalScoreProbabilities[13][1] +
                finalScoreProbabilities[17][0] + finalScoreProbabilities[17][1]; 
        );
	cout << probabilityOfPrime;
	return probabilityOfPrime;
}


