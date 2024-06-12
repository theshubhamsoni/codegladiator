#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution 
{
  public : 
    int maxPair(vector<int> &weight, int participants)
    {
      map<int,int> weightMap;
      set<pair<int, int>> weightSet;
      int maxCount = 0;

      for(int i = 0; i < participants - 1; i++)
      {
        for(int j = i + 1; j < participants; j++)
        {
          int sum = weight[i] + weight[j];
          if((weightSet.find({i, sum}) == weightSet.end()) && 
             (weightSet.find({j, sum}) == weightSet.end()))
          {
            weightSet.insert({i, sum}); weightSet.insert({j, sum});
            maxCount = max(maxCount, ++weightMap[sum]);
          }
        }
      }
      return maxCount;
    }
};


int main()
{
  int participants;
  cin >> participants;
  vector<int> weight(participants, 0);
  for(int i = 0; i < participants ; i++) cin >> weight[i];
  cout << Solution().maxPair(weight, participants) << endl;
  return 0;
}
