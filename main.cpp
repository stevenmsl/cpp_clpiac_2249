#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol2249;

/*
Input: circles = [[2,2,1]]
Output: 5
Explanation:
The figure above shows the given circle.
The lattice points present inside the circle are (1, 2), (2, 1), (2, 2), (2, 3), and (3, 2) and are shown in green.
Other points such as (1, 1) and (1, 3), which are shown in red, are not considered inside the circle.
Hence, the number of lattice points present inside at least one circle is 5.
*/

tuple<vector<vector<int>>, int>
testFixture1()
{
  auto circles = vector<vector<int>>{{2, 2, 1}};
  return make_tuple(circles, 5);
}

/*
Input: circles = [[2,2,2],[3,4,1]]
Output: 16
Explanation:
The figure above shows the given circles.
There are exactly 16 lattice points which are present inside at least one circle.
Some of them are (0, 2), (2, 0), (2, 4), (3, 2), and (4, 4).
*/

tuple<vector<vector<int>>, int>
testFixture2()
{
  auto circles = vector<vector<int>>{{2, 2, 2}, {3, 4, 1}};
  return make_tuple(circles, 16);
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see: " << get<1>(f) << endl;
  Solution sol;
  cout << sol.countPoints(get<0>(f)) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Expect to see: " << get<1>(f) << endl;
  Solution sol;
  cout << sol.countPoints(get<0>(f)) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}