#include <cstdlib>     //std :: rand ()
#include <vector>      //std :: vector < >
#include <list>        //std :: list < >
#include <iostream>    //std :: cout
#include <iterator>    //std :: ostream_iterator < >
#include <algorithm>   //std :: reverse , std :: generate

using namespace std;

int main ()
{
std::vector<int> v0(10);    //erstellt vektorcontainer mit 10 feldern
for (auto& v : v0) {        //rang-based for-loop iteriert über elemente des vektors
    v = std::rand();        //und füllt sie mit "zufalls"zahlen
}
std::copy (std::begin (v0), std::end (v0),                      //kopiert die werte von v0 in den Outputstream
            std::ostream_iterator<int>(std::cout, "\n"));

std::list<int> l0(v0.size());                                   //erstellt eine Liste und kopiert die werte des vektors in die Liste
std::copy (std::begin (v0), std::end(v0), std::begin(l0));

std::list<int> l1(std::begin(l0), std::end(l0));                //erstellt eine Liste identisch zu l0
std::reverse(std::begin(l1), std::end(l1));                     //dreht die reihenfolge um
std::copy (std::begin(l1), std::end(l1),                        
            std::ostream_iterator<int>(std::cout, "\n"));       //kopiert die werte von l1 in den Outputstream

l1.sort();
std::copy(l1.begin(), l1.end(),
            std::ostream_iterator<int>(std::cout, "\n"));       //sortiert die liste und kopiert die werte von l1 in den Outputstream

std::generate(std::begin(v0), std::end(v0), std::rand);         //füllt v0 mit neuen "zufalls"werten und kopiert diese in den Outputstream
std::copy(v0.rbegin(), v0.rend(),
            std::ostream_iterator<int>(std::cout, "\n"));

return 0;
}