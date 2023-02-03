//#include "Set.h"
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

//#include "Set.h"
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

#include "Set.h"
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int main()
{
    Set s;
    assert(s.empty());
    ItemType x = 90000;
    assert(!s.get(42, x) && x == 90000); // x unchanged by get failure
    s.insert(10);
    assert(!s.empty());
    assert(s.size() == 1);
    assert(s.get(0, x) && x == 10);
    s.insert(22);
    assert(s.size() == 2);
    assert(s.get(1, x) && x == 22);
    s.insert(4);
    assert(s.get(2, x) && x == 22);

    Set s2;
    s2.insert(9);
    s2.insert(8);
    s2.insert(32);
    s2.insert(0);
    s2.insert(53);
    assert(s2.size() == 5);
    s2.erase(1);
    assert(s2.size() == 5);
    s2.erase(8);
    assert(s2.size() == 4);
    s2.swap(s);
    assert(s.contains(32) && s.size() == 4);
    assert(s.get(3, x) && x == 53);

    cout << "Passed all tests" << endl;

    //Set s;
    //assert(s.empty());
    //ItemType x = "arepa";
    //assert(!s.get(42, x) && x == "arepa"); // x unchanged by get failure
    //s.insert("chapati");
    //assert(!s.empty());
    //assert(s.size() == 1);
    //assert(s.get(0, x) && x == "chapati");
    //s.insert("drama");
    //assert(s.size() == 2);
    //assert(s.get(1, x) && x == "drama");
    //s.insert("demons");
    //assert(s.get(2, x) && x == "drama");

    //Set s2;
    //s2.insert("balloon");
    //s2.insert("clean");
    //s2.insert("apple");
    //s2.insert(" ");
    //s2.insert("zebra");
    //assert(s2.size() == 5);
    //s2.erase("nice");
    //assert(s2.size() == 5);
    //s2.erase("clean");
    //assert(s2.size() == 4);
    //s2.swap(s);
    //assert(s.contains("balloon") && s.size() == 4);
    //assert(s.get(3, x) && x == "zebra");

    //cout << "Passed all tests" << endl;
}