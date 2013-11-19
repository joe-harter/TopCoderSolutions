#include <vector>
#include <string>
#include <iostream>
#include <assert.h>
#include <map>
#include <algorithm>
using namespace std;

class BirthdayCake
{
	public:
		int howManyFriends(vector<string> availableFruits, vector<string> friendsDislikings, int k);

};

int BirthdayCake::howManyFriends(vector<string> availableFruits, vector<string> friendsDislikings, int k)
{
    vector<string> test;
    vector<int> sorted;
    vector<int>::iterator it;
    bool found;
    it = sorted.begin();
    
    int numFriends = friendsDislikings.size();
    
    for(int i = 0; i < availableFruits.size(); i++)
    {
        string fruitName = availableFruits.at(i);
        int numLikings = numFriends;
        for(int d = 0; d < numFriends; d++)
        {
            string friendLikings = friendsDislikings.at(d).insert(0, " ");
            friendLikings.insert(friendLikings.size(), " ");
            found = friendLikings.find(" " + fruitName + " ") != std::string::npos;
            numLikings -= found ? 1 : 0;
        }
        it = sorted.insert(it, numLikings);
    }
    
    sort(sorted.begin(), sorted.end());
    return sorted.at(availableFruits.size() - k);
    
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
        cout << "All assertions passed" << "\n";
        return 0;
}
