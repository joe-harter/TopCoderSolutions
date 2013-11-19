#include <math.h>
#include <string>
using namespace std;

class MultiNumber
{
	public: 
		string check(int number);
		int productOfDigits(int number);
};

string MultiNumber::check(int number)
{
        bool multi = false;
        for (int i = 1; i < floor(log10(number)) + 1 && multi == false; i++)
        {
                int right = (int) (number % (int) pow(10, i));
                int left = (int) ((number - (number % (int) pow(10, i))) / pow(10, i));

                multi = productOfDigits(left) == productOfDigits(right);
        }

        return multi ? "YES": "NO";
}

int MultiNumber::productOfDigits(int number)
{
        int product = 1;

        for (int i = floor(log10(number)) + 1; i > 0; i--)
        {
                int digit =  (int) (number / (int) pow(10, i - 1));
                number = (int) (number % (int) pow(10, i - 1));
                product *= digit;
        }

        return product;
}
