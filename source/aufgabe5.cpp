#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

bool is_multiple_of_3(unsigned int const& c) {
	return (c % 3 == 0);
}

bool is_not_multiple_of_3(unsigned int const&c) {
	return (c % 3 != 0);
}

TEST_CASE("filter alle vielfache von drei", " [ erase ] ")
{
	vector<unsigned int> vec(100);
	for (auto& v: vec) {
		v = rand() % 101;
	}

	vec.erase(remove_if(vec.begin(), vec.end(), is_not_multiple_of_3), vec.end());
	REQUIRE(all_of(vec.begin(), vec.end(), is_multiple_of_3));
}
int main(int argc, char * argv[])
{
	return Catch::Session().run(argc, argv);
}