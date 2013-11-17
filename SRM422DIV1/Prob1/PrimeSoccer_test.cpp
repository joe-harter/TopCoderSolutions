#include "PrimeSoccer.h"
#include <assert.h>
#include <iostream>
using namespace std;

int main()
{
	PrimeSoccer obj;
        assert (obj.getProbability(100, 100) == 0);
        assert (obj.getProbability(12, 89) == .6771);
	assert (obj.getProbability(50, 50) == .5265618908306351);
	cout << "All assertions passed.\n";
	return 0;
}
