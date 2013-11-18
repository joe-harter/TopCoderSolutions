#include "PrimeSoccer.h"
#include <assert.h>
#include <iostream>
using namespace std;

int main()
{
	PrimeSoccer obj;
        double p = 0;
        
        p = obj.getProbability(100, 100);
        assert (p == 0);
        
        p = obj.getProbability(50, 50);
        assert (p == .5265618908306351);
        
        p = obj.getProbability(12, 89);
        assert (p > .67720471688);
        assert (p < .67720471689);
        
        p = obj.getProbability(89, 12);
        assert (p > .67720471688);
        assert (p < .67720471689);
        
        p = obj.getProbability(0, 0);
        assert (p == 0);
        
	cout << "All assertions passed.\n";
	return 0;
}
