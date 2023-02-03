//#include "newSet.h"
//#include <iostream>
//#include <cassert>
//using namespace std;
//
//void test()
//{
//    Set uls;
//    assert(uls.insert(20));
//    assert(uls.insert(10));
//    assert(uls.size() == 2);
//    assert(uls.contains(10));
//    ItemType x = 30;
//    assert(uls.get(0, x) && x == 10);
//    assert(uls.get(1, x) && x == 20);
//}
//
//int main()
//{
//    test();
//    cout << "Passed all tests" << endl;
//}

//#include "newSet.h"
//#include <string>
//#include <iostream>
//#include <cassert>
//using namespace std;
//
//void test()
//{
//    Set ss;
//    assert(ss.insert("roti"));
//    assert(ss.insert("pita"));
//    assert(ss.size() == 2);
//    assert(ss.contains("pita"));
//    ItemType x = "laobing";
//    assert(ss.get(0, x) && x == "pita");
//    assert(ss.get(1, x) && x == "roti");
//}
//
//int main()
//{
//    test();
//    cout << "Passed all tests" << endl;
//}


#include "newSet.h"

#include<iostream>
#include<string>
#include<cassert>

using namespace std;

int main() {

    Set a(1000);   // a can hold at most 1000 distinct items
    Set b(5);      // b can hold at most 5 distinct items
    Set c;         // c can hold at most DEFAULT_MAX_ITEMS distinct items
    ItemType v[6] = { 4, 3, 9, 2, 5, 0 };
    //ItemType v[6] = { "ha", "nice", "boo", "cool", "fine", "epic" };

    // No failures inserting 5 distinct items into b
    for (int k = 0; k < 5; k++)
        assert(b.insert(v[k]));

    // Failure if we try to insert a sixth distinct item into b
    assert(b.size() == 5);
    assert(!b.insert(v[5]));
    assert(b.size() == 5);
    assert(c.size() == 0);

    // Display each set
    a.dump();
    b.dump();

    // When two Sets' contents are swapped, their capacities are swapped
    // as well:
    a.swap(b);
    assert(!a.insert(v[5]) && b.insert(v[5]));
    a.dump();
    b.dump();

    // Add to set c
    for (int k = 4; k >= 0; k--) {
        assert(c.insert(v[k]));
    }

    // Display c
    c.dump();

    // Use copy constructor 
    Set d(c);
    d.dump();
    d.insert(v[5]);
    d.dump();

    cerr << "ALL TESTS PASSED" << endl;
}