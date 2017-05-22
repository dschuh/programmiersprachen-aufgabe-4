#include <cstdlib>     //std :: rand ()
#include <vector>      //std :: vector < >
#include <list>        //std :: list < >
#include <iostream>    //std :: cout
#include <iterator>    //std :: ostream_iterator < >
#include <set>
#include <map>
using namespace std;

int main ()
{
//make list with random values from 0 to 100 (including 0 and 100)
list<unsigned int> l0(100);
for(auto& l : l0){
    l = rand()%101;
}
//copy elements to vector
vector<unsigned int> v0(100);
copy(l0.begin (), l0.end(), v0.begin());
//copy elements to set
std::set<unsigned int> s0 (v0.begin(), v0.end());
//print number of unique elements
std::cout << s0.size() << " unterschiedliche Zahlen" << "\n";
//print elements not in list
for(int i=0; i<=100; ++i){
    if(s0.count(i)==0){
        cout << i << endl;
    }    
}

map<unsigned int, unsigned int> m0;
for (auto& i : v0){
		m0[i]+= 1;
	}
for (auto& m : m0){
    cout << "Zahl : "<< m.first << ",  Häufigkeit : " << m.second << "\n";
}

return 0;
}