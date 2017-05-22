#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include "circle.hpp"
using namespace std;

TEST_CASE ("vergleiche circles", "[sort]")
{
vector<Circle> vec0(20);
for (auto& c : vec0)
{
    c=Circle{{10,10}, (rand()%101), {0.5}};
}
sort(vec0.begin(), vec0.end());
REQUIRE(is_sorted(vec0.begin(), vec0.end()));

vector<Circle> vec1(20);
for (auto& c : vec1)
{
    c=Circle{{10,10}, (rand()%101), {0.5}};
}
sort(vec1.begin(), vec1.end(), [](Circle const& lhs, Circle const& rhs) -> bool {
        return (lhs.getRadius() < rhs.getRadius());} );
REQUIRE(is_sorted(vec1.begin(), vec1.end()));

vector<unsigned int> v1{1, 2, 3, 4, 5, 6, 7, 8, 9};
vector<unsigned int> v2{9, 8, 7, 6, 5, 4, 3, 2, 1};
vector<unsigned int> v3(9);
transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), [](unsigned int a, unsigned int b){return a+b;});
REQUIRE(all_of(v3.begin(), v3.end(), [](unsigned int a){return a == 10;}));
}

int main (int argc, char * argv[])
{
return Catch::Session().run(argc, argv);
}