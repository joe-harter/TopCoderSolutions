#include <vector>
#include <string>
#include <iostream>
#include <assert.h>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;

class BirthdayCake
{
	public:
		int howManyFriends(vector<string> availableFruits, vector<string> friendsDislikings, int k);
                long countBits(long n);

};

int BirthdayCake::howManyFriends(vector<string> availableFruits, vector<string> friendsDislikings, int k)
{
    int numFriends = friendsDislikings.size();
    int numFruits = availableFruits.size();
    vector<int> sorted;
    vector<long> friendResultsPerFruit (numFruits, 0);
    vector<int>::iterator it;
    it = sorted.begin();
    bool found;
    
    for(int i = 0; i < availableFruits.size(); i++)
    {
        string fruitName = availableFruits.at(i);
        
        for(int d = 0; d < numFriends; d++)
        {
            string friendDisLikings = friendsDislikings.at(d).insert(0, " ");
            friendDisLikings.insert(friendDisLikings.size(), " ");
            found = friendDisLikings.find(" " + fruitName + " ") != std::string::npos;
            friendResultsPerFruit.at(i) += found ? 0 : pow(2, d);
        }
    }
    
    long maxFriends = 0;
    for(int p = 0; p < friendResultsPerFruit.size(); p++)
    {
        for(int s = p+1; s < friendResultsPerFruit.size(); s++)
        {
            maxFriends = max(countBits(friendResultsPerFruit.at(p) & friendResultsPerFruit.at(s)), maxFriends);
        }
    }
    
    return maxFriends;
    
}

long BirthdayCake::countBits(long n)
{
    int c;
    for (c = 0; n; c++)
        n &= n - 1;
    return c;
}

// For testing purposes only
int main()
{
    BirthdayCake obj;
    vector<string> availableFruits;
    vector<string> friendsDislikings;
    vector<string>::iterator it;
    int n;
    // Test 1 //
    it = availableFruits.begin();
    it = availableFruits.insert(it, "apple");
    it = availableFruits.insert(it, "orange");
    
    it = friendsDislikings.begin();
    it = friendsDislikings.insert(it, "strawberry");
    n = obj.howManyFriends(availableFruits, friendsDislikings, 2);
    
    assert(n == 1);
   
     // Test 2 //
     availableFruits.clear();
    friendsDislikings.clear();
    
    it = availableFruits.begin();
    it = availableFruits.insert(it, "apple");
    it = availableFruits.insert(it, "orange");
    it = availableFruits.insert(it, "strawberry");
    it = availableFruits.insert(it, "cherry");
    
    it = friendsDislikings.begin();
    it = friendsDislikings.insert(it, "apple orange");
    it = friendsDislikings.insert(it, "apple cherry");
    it = friendsDislikings.insert(it, "strawberry orange");
    it = friendsDislikings.insert(it, "cherry");
    it = friendsDislikings.insert(it, "apple");
    
    n = obj.howManyFriends(availableFruits, friendsDislikings, 2);
      assert(n == 3);
      
    // Test 3 - The pineapple test //
    availableFruits.clear();
    friendsDislikings.clear();
    
    it = availableFruits.begin();
    it = availableFruits.insert(it, "apple");
    it = availableFruits.insert(it, "orange");
    it = availableFruits.insert(it, "strawberry");
    it = availableFruits.insert(it, "cherry");
    
    it = friendsDislikings.begin();
    it = friendsDislikings.insert(it, "pineapple");
    it = friendsDislikings.insert(it, "pineapple");
    
    n = obj.howManyFriends(availableFruits, friendsDislikings, 4);
    assert(n == 2);
    
    // Test 4
    availableFruits.clear();
    friendsDislikings.clear();
    
    availableFruits.push_back("apple");
    availableFruits.push_back("orange");
    availableFruits.push_back("banana");
    
    friendsDislikings.push_back("apple orange");
    friendsDislikings.push_back("apple banana");
    friendsDislikings.push_back("banana orange");
    n = obj.howManyFriends(availableFruits, friendsDislikings, 2);
    cout << n;
    assert(n == 0);
    
        // Test 4
    availableFruits.clear();
    friendsDislikings.clear();
    
    availableFruits.push_back("apple");
    availableFruits.push_back("orange");
    availableFruits.push_back("banana");
    
    friendsDislikings.push_back("apple");
    friendsDislikings.push_back("banana");
    friendsDislikings.push_back("orange");
    n = obj.howManyFriends(availableFruits, friendsDislikings, 3);
    cout << n;
    assert(n == 0);
    
    cout << "All assertions passed" << "\n";
    return 0;
}
