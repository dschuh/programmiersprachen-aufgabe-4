#define CATCH_CONFIG_RUNNER
#include "List.hpp"
#include <catch.hpp>


TEST_CASE("Testing aufgabe 2", "[constructor, empty, size]")
{
	List <int> l0;
	REQUIRE (l0.empty()); 	
	REQUIRE (l0.size()==0);	
		
}

TEST_CASE("add an element with push_front", "[modifiers]")
{
List<int> list;
list.push_front(42);
REQUIRE(42==list.front());
}
 
TEST_CASE("add an element with push_back", "[modifiers]")
{
List<int> list;
list.push_back(41);
REQUIRE(41==list.back());
}  

TEST_CASE("delete an element with pop_front", "[modifiers]")
{
List<int> list;
list.push_front(41);
list.push_back(42);
list.push_back(43);
REQUIRE(41==list.front());
list.pop_front();
REQUIRE(42==list.front());
}  

TEST_CASE("delete an element with pop_back", "[modifiers]")
{
List<int> list;
list.push_front(22);
list.push_back(23);
list.push_back(24);
list.push_back(25);
REQUIRE(22==list.front());
REQUIRE(25==list.back());
list.pop_back();
REQUIRE(24==list.back());
} 

TEST_CASE("should be empty after clearing ", "[modifiers]")
{
List < int > list ;
list.push_front(1);
list.push_front(2);
list.push_front(3);
list.push_front(4);
list.clear ();
REQUIRE(list.empty());
}

TEST_CASE("should be an empty range after default construction ", "[iterators]")
{
List<int> list;
auto b = list.begin();
auto e = list.end();
REQUIRE(b==e);
}

TEST_CASE("provide acces to the first element with begin", "[iterators]")
{
List<int> list;
list.push_front(42);
REQUIRE(42 == *list.begin());
}
//weitere testcases für begin und end

TEST_CASE("copy constructor", "[constructor]")
{
List<int> list;
list.push_front(1);
list.push_front(2);
list.push_front(3);
list.push_front(4);
List<int> list2 { list };
REQUIRE (list == list2);
}
//test reverse

TEST_CASE("move constructor", "[constructor]")
{
List<int> list;
list.push_front(1);
list.push_front(2);
list.push_front(3);
list.push_front(4);
List<int> list2 (std::move(list));
REQUIRE(0 == list.size());
REQUIRE(list.empty());
REQUIRE(4 == list2.size());
}


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}