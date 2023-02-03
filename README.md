# 2023-CS32-HW1

Here is a C++ class definition for an abstract data type Set of strings, representing the concept of a collection of strings, without duplicates. (A web server might record unique visitors to a website using a set of strings, for example.) To make things simpler for you, the case of letters in a string matters, so that the strings Roti and rOtI are not considered duplicates.

class Set
{
  public:
    Set();         // Create an empty set (i.e., one whose size() is 0).

    bool empty();  // Return true if the set is empty, otherwise false.

    int size();    // Return the number of items in the set.

    bool insert(const std::string& value);
      // Insert value into the set if it is not already present.  Return
      // true if the value is actually inserted.  Leave the set unchanged
      // and return false if value is not inserted (perhaps because it
      // was already in the set or because the set has a fixed capacity and
      // is full).

    bool erase(const std::string& value);
      // Remove the value from the set if it is present.  Return true if the
      // value was removed; otherwise, leave the set unchanged and
      // return false.
     
    bool contains(const std::string& value);
      // Return true if the value is in the set, otherwise false.
     
    bool get(int i, std::string& value);
      // If 0 <= i < size(), copy into value the item in the set that is
      // strictly greater than exactly i items in the set and return true.
      // Otherwise, leave value unchanged and return false.

    void swap(Set& other);
      // Exchange the contents of this set with the other one.
};
(When we don't want a function to change a parameter representing a value of the type stored in the set, we pass that parameter by constant reference. Passing it by value would have been perfectly fine for this problem, but we chose the const reference alternative because that will be more suitable after we make some generalizations in a later problem.)

Notice that the comment for the get function implies that for a 5-item set ss, ss.get(0, x) will copy the smallest item in the set into x (because the smallest item is greater than 0 items in the set), and ss.get(4, x) will copy the largest item (because the largest item is greater than 4 items in the set). The words greater than, smallest, etc., are all interpreted in the context of what the > operator for string indicates about the relative order of two strings:

    Set ss;
    ss.insert("lavash");
    ss.insert("roti");
    ss.insert("chapati");
    ss.insert("injera");
    ss.insert("roti");
    ss.insert("matzo");
    ss.insert("injera");
    assert(ss.size() == 5);  // duplicate "roti" and "injera" were not added
    string x;
    ss.get(0, x);
    assert(x == "chapati");  // "chapati" is greater than exactly 0 items in ss
    ss.get(4, x);
    assert(x == "roti");  // "roti" is greater than exactly 4 items in ss
    ss.get(2, x);
    assert(x == "lavash");  // "lavash" is greater than exactly 2 items in ss
Here's an example of the swap function:

    Set ss1;
    ss1.insert("laobing");
    Set ss2;
    ss2.insert("matzo");
    ss2.insert("pita");
    ss1.swap(ss2);
    assert(ss1.size() == 2  &&  ss1.contains("matzo")  &&  ss1.contains("pita")  &&
           ss2.size() == 1  &&  ss2.contains("laobing"));
Notice that the empty string is just as good a string as any other; you should not treat it in any special way:

    Set ss;
    ss.insert("dosa");
    assert(!ss.contains(""));
    ss.insert("tortilla");
    ss.insert("");
    ss.insert("focaccia");
    assert(ss.contains(""));
    ss.erase("dosa");
    assert(ss.size() == 3  &&  ss.contains("focaccia")  &&  ss.contains("tortilla")  &&
                ss.contains(""));
    string v;
    assert(ss.get(1, v)  &&  v == "focaccia");
    assert(ss.get(0, v)  &&  v == "");
When comparing items for insert, erase, contains, and get, just use the ==, !=, >, etc., operators provided for the string type by the library. These do case-sensitive comparisons, and that's fine.

Here is what you are to do:

Determine which member functions of the Set class should be const member functions (because they do not modify the Set), and change the class declaration accordingly.

As defined above, the Set class allows the client to use a set that contains only std::strings. Someone who wanted to modify the class to contain items of another type, such as only ints or only doubles, would have to make changes in many places. Modify the class definition you produced in the previous problem to use a type alias for all values wherever the original definition used a std::string. A type alias is a name that is a synonym for some type; here is an example:

      // The following line introduces the type alias Number as a synonym
      // for the type int; anywhere the code uses the name Number, it means
      // the type int.

    using Number = int;

    int main()
    {
        Number total = 0;
        Number x;
        while (cin >> x)
            total += x;
        cout << total << endl;
    }
The advantage of using the type alias Number is that if we later wish to modify this code to sum a sequence of longs or of doubles, we need make a change in only one place: the using statement introducing the type alias Number.

(Aside: Prior to C++11 (and still usable now), the only way to introduce a type alias was to use a typedef statement, e.g. typedef int Number;. Appendix A.1.8 of the textbook describes typedef.)

To make the grader's life easier, we'll require that everyone use the same synonym for their type alias: You must use the name ItemType, with exactly that spelling and case.

Now that you have defined an interface for a set class where the item type can be easily changed, implement the class and all its member functions in such a way that the items in a set are contained in a data member that is an array. (Notice we said an array, not a pointer. It's not until problem 5 of this homework that you'll deal with a dynamically allocated array.) A set must be able to hold a maximum of DEFAULT_MAX_ITEMS items, where

    const int DEFAULT_MAX_ITEMS = 160;
Test your class for a Set of std::strings. Place your class definition and inline function implementations (if any) in a file named Set.h, and your non-inline function implementations (if any) in a file named Set.cpp. (If we haven't yet discussed inline, then if you haven't encountered the topic yourself, all your functions will be non-inline, which is fine.)

Except to add a dump function (described below), you must not add public data or function members to, delete functions from, or change the public interface of the Set class. You may add whatever private data members and private member functions you like, and you may declare private structs/classes inside the Set class if you like.

If you wish, you may add a public member function with the signature void dump() const. The intent of this function is that for your own testing purposes, you can call it to print information about the set; we will never call it. You do not have to add this function if you don't want to, but if you do add it, it must not make any changes to the set; if we were to replace your implementation of this function with one that simply returned immediately, your code must still work correctly. The dump function must not write to cout, but it's allowed to write to cerr.

Your implementation of the Set class must be such that the compiler-generated destructor, copy constructor, and assignment operator do the right things. Write a test program named testSet.cpp to make sure your Set class implementation works properly. Here is one possible (incomplete) test program:

    #include "Set.h"
    #include <iostream>
    #include <string>
    #include <cassert>
    using namespace std;

    int main()
    {
        Set s;
        assert(s.empty());
        ItemType x = "arepa";
        assert( !s.get(42, x)  &&  x == "arepa"); // x unchanged by get failure
        s.insert("chapati");
        assert(s.size() == 1);
        assert(s.get(0, x)  &&  x == "chapati");
        cout << "Passed all tests" << endl;
    }
Now change (only) the type alias in Set.h so that the Set will contain unsigned longs. Make no other changes to Set.h, and make no changes to Set.cpp. Verify that your implementation builds correctly and works properly with this alternative main routine (which again, is not a complete test of correctness):

    #include "Set.h"
    #include <iostream>
    #include <cassert>
    using namespace std;

    int main()
    {
        Set s;
        assert(s.empty());
        ItemType x = 9876543;
        assert( !s.get(42, x)  &&  x == 9876543); // x unchanged by get failure
        s.insert(123456789);
        assert(s.size() == 1);
        assert(s.get(0, x)  &&  x == 123456789);
        cout << "Passed all tests" << endl;
    }
You may need to flip back and forth a few times to fix your Set.h and Set.cpp code so that the only change to those files you'd need to make to change a set's item type is to the type alias in Set.h. (When you turn in the project, have the type alias in Set.h specify the item type to be std::string.)

Except in a using statement in Set.h introducing a type alias and in the context of #include <string> in Set.h, the word string must not appear in Set.h or Set.cpp. Except in a using statement introducing a type alias, the words unsigned and long must not appear in Set.h or Set.cpp.

(Implementation note: The swap function is easily implementable without creating any additional container of many items such as an additional array or an additional Set.)

Now that you've implemented the class, write some client code that uses it. A librarian might want a class that keeps track of the library card numbers of all patrons who check items out of the library. A patron might check out few or many items few or many times, but the card number should be included only once. (The librarian just wants to be able to know which cards are actually being used, not how many times they're used.) Implement the following class that uses a Set of unsigned longs:

    #include "Set.h"

    class CardSet
    {
      public:
        CardSet();          // Create an empty card set.

        bool add(unsigned long cardNumber);
          // Add a card number to the CardSet.  Return true if and only if the
          // card number was actually added.

        int size() const;  // Return the number of card numbers in the CardSet.

        void print() const;
          // Write to cout every card number in the CardSet exactly once, one
          // per line.  Write no other text.

      private:
        // Some of your code goes here.
    };
Your CardSet implementation must employ a private data member of type Set that uses the type alias ItemType as a synonym for unsigned long. (Notice we said a member of type Set, not of type pointer to Set.) Except for the using statement introducing the type alias, you must not make any changes to the Set.h and Set.cpp files you produced for Problem 3, so you must not add any member functions or data members to the Set class. Each of the member functions add, size, and print must delegate as much of the work that they need to do as they can to Set member functions. (In other words, they must not do work themselves that they can have Set member functions do instead.) If the compiler-generated destructor, copy constructor, and assignment operator for CardSet don't do the right thing, declare and implement them. Write a program to test your CardSet class. Name your files CardSet.h, CardSet.cpp, and testCardSet.cpp.

The words for and while must not appear in CardSet.h or CardSet.cpp, except in the implementation of CardSet::print if you wish. The characters [ (open square bracket) and * must not appear in CardSet.h or CardSet.cpp, except in comments if you wish. You do not have to change unsigned long to ItemType in CardSet.h and CardSet.cpp if you don't want to (since unlike Set, which is designed for a wide variety of item types, CardSet is specifically designed to work with unsigned longs). In the code you turn in, CardSet's member functions must not call Set::dump.

Now that you've created a set type based on arrays whose size is fixed at compile time, let's change the implementation to use a dynamically allocated array of objects. Copy the three files you produced for problem 3, naming the new files newSet.h, newSet.cpp, and testnewSet.cpp. Update those files by either adding another constructor or modifying your existing constructor so that a client can do the following:

     Set a(1000);   // a can hold at most 1000 distinct items
     Set b(5);      // b can hold at most 5 distinct items
     Set c;         // c can hold at most DEFAULT_MAX_ITEMS distinct items
     ItemType v[6] = { six distinct values of the appropriate type };

       // No failures inserting 5 distinct items into b
     for (int k = 0; k < 5; k++)
         assert(b.insert(v[k]));

       // Failure if we try to insert a sixth distinct item into b
     assert(!b.insert(v[5]));

       // When two Sets' contents are swapped, their capacities are swapped
       // as well:
     a.swap(b);
     assert(!a.insert(v[5])  &&  b.insert(v[5]));
Since the compiler-generated destructor, copy constructor, and assignment operator no longer do the right thing, declare them (as public members) and implement them. Make no other changes to the public interface of your class. (You are free to make changes to the private members and to the implementations of the member functions, and you may add or remove private members.) Change the implementation of the swap function so that the number of statement executions when swapping two sets is the same no matter how many items are in the sets. (You would not satisfy this requirement if, for example, your swap function caused a loop to visit each item in the sets, since the number of statements executed by all the iterations of the loop would depend on the number of items in the sets.)

The character [ (open square bracket) must not appear in newSet.h (but is fine in newSet.cpp).

Test your new implementation of the Set class. (Notice that even though the file is named newSet.h, the name of the class defined therein must still be Set.)

Verify that your CardSet class still works properly with this new version of Set (with ItemType being a type alias for unsigned long). You should not need to change your CardSet class or its implementation in any way, other than to #include "newSet.h" instead of "Set.h". (For this test, be sure to link with newSet.cpp, not Set.cpp.) (Before you turn in CardSet.h, be sure to restore any #includes to "Set.h" instead of "newSet.h".)
