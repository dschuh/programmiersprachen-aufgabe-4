#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
using namespace std;

template <typename vector, typename predicate>
vector filter(vector const& v0, predicate const& p){
    vector v1 (v0.size());
	copy_if(v0.begin(), v0.end(), v1.begin(), p);
    return v1;
}

bool is_even (int const& n) {return n % 2 == 0;}

TEST_CASE("using template", "[template filter]")
{

vector<int> v {1,2,3,4,5,6};
vector<int> alleven = filter(v, is_even);

REQUIRE(all_of(alleven.begin(), alleven.end(), is_even));
}

int main (int argc, char * argv[])
{
return Catch::Session().run(argc, argv);
}