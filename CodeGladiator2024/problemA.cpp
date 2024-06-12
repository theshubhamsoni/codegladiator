#include <iostream>
#include <vector>
#include <functional>
#include <cmath>

using namespace std;

class Solution {
  public:
    void long_distance()
    {
      long paulDistance;
      long paulSpeed;
      long paulStops;
      long ninaDistance;
      long ninaSpeed;
      long ninaStops;

      cin >> paulDistance >> paulSpeed >> paulStops;
      cin >> ninaDistance >> ninaSpeed >> ninaStops;

      auto calculate_time = [](long distance, long speed, long stops) {
        if(speed <= 0) return (long long)-1;
        long long time = (distance/speed + stops);
        return (long long) ceil(time);
      };

      long long paulTime = calculate_time(paulDistance, paulSpeed, paulStops);
      long long ninaTime = calculate_time(ninaDistance, ninaSpeed, ninaStops);

      if(paulTime > ninaTime)
      {
        cout << "NINA" << endl << ceil(ninaTime) << endl;
      }
      else if (paulTime < ninaTime)
      {
        cout << "PAUL" << endl << ceil(paulTime) << endl;
      }
      else
      {
        cout << "BOTH" << endl << ceil(paulTime) << endl;
      }
      return;
    }
};

int main()
{
  int testcases=0;
  cin >> testcases;
  Solution solution;
  for(int i = 0; i < testcases; i++)
  {
    solution.long_distance();
  }
  return 0;
}
