#include <cstdlib>     //std :: rand ()
#include <vector>      //std :: vector < >
#include <list>        //std :: list < >
#include <iostream>    //std :: cout
#include <iterator>    //std :: ostream_iterator < >
#include <set>
#include <map>

int main ()
{
//make list with random values from 0 to 100 (including 0 and 100)
std::list<unsigned int> l0(100);
for(auto& l : l0){
    l = std::rand()%101;
}
//copy elements to vector
std::vector<unsigned int> v0(100);
std::copy(std::begin (l0), std::end(l0), std::begin(v0));
//copy elements to set
std::set<unsigned int> s0 (std::begin(v0), std::end(v0));
//print number of unique elements
std::cout << s0.size() << " unterschiedliche Zahlen" << "\n";
//print elements not in list
for(int i=0; i<=100; ++i){
    if(s0.count(i)==0){
        std::cout << i << std::endl;
    }    
}

std::map<unsigned int, unsigned int> m0;
unsigned int h=1;
for(auto& l : l0){
    if(m0.find(l)!=m0.end()){
        m0.find(l).second +=1;
    } else{
      m0.insert(std::make_pair(l, h));
    }
}
for (auto& m : m0){
    std::cout << "Zahl : "<< m.first << " Häufigkeit : " << m.second << "\n";
}


return 0;
}