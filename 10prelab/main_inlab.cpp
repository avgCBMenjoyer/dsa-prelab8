#include <iostream>
#include <vector>
#include "heap.h"

using namespace std;

int main()
try
{
    vector<int> v {1, 0, 5, 7, 9, 2, 4, 6, 8};

    HeapNode heap(3);

    auto prn = [](int x, const HeapNode & h, string a)
    {
        cout << "```mermaid\ngraph TD\n"
             << "A(\"" << a << ' ' << x << "\")\n"
             << "style A fill:#ded\n"
             << h.edges() << "```\n---\n";
    };

    for (auto x : v)
    {
        heap.push(x);
        //prn(x, heap, "push");
        heap.valid();
    }

    for ( const auto & x : heap ) cout << ' ' << x.str(); cout << '\n';


    if (1)
    {
        //int a = heap.pop();
        //prn(a, heap, "pop");
        heap.valid();
        heap.push(5);
        prn(5, heap, "push");
        heap.valid();
    }

    for ( const HeapNode & x : heap ) cout << ' ' << x.str(); cout << '\n';


    //std::cout << "Maximum Value: " << heap.maxVal() << std::endl;



    while ( !heap.empty() )
    {
        int x = heap.pop();
        //prn(x, heap, "pop");
        heap.valid();
    }
}
catch (string s) { cout << "Error: " << s << '\n'; }
catch (...) { cout << "exception\n"; }
