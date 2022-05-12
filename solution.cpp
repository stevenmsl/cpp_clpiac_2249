#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
using namespace sol2249;
using namespace std;

/*takeaways
  - use brute force
  - or you can start from the center and look
    for the lattice points that can be covered
    by a circle
    - this approach requires you to remember
      all the lattice points as you need to
      eliminate duplicates as they might be
      in more than one circle

*/

int Solution::countPoints(vector<vector<int>> &circles)
{
  auto in = [](int x, int y, int cx, int cy, int r)
  {
    /* distance needs to be within r from the center
       - it's equal to r^2 where (x,y) is on the
         circumference
    */
    return (x - cx) * (x - cx) + (y - cy) * (y - cy) <= r * r;
  };

  auto result = 0;
  for (auto x = 0; x <= 5; x++)
    for (auto y = 0; y <= 5; y++)
      for (auto &c : circles)
      {
        if (in(x, y, c[0], c[1], c[2]))
        {
          result++;
          /* at least one circle */
          break;
        };
      }

  return result;
}