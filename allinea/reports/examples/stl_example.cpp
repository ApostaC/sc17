#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

int main()
{
    string s = "hello world";

    // sample vectors

    vector<string> a;
    for (int i = 0; i < 2; ++i)
    {
        a.push_back("an A string");
    }
    
    vector<string> b;
    for (int i = 0; i < 3; ++i)
    {
        b.push_back("a B string");
    }
    
    vector<string> c;
    for (int i = 0; i < 4; ++i)
    {
        c.push_back("a C string");
    }
    
    vector<string> v;

    // Add five instances of the same string to our vector.
    for (int i = 0; i < 5; ++i)
    {
        cout << s << endl;
        v.push_back(s);
    }

    // Now add five copies of the same string to our vector. Should
    // have little effect, as the standard std:string is "implicitly
    // shared" (using Qt terminology).
    for (int i = 0; i < 5; ++i)
    {
        cout << s << endl;
        v.push_back(string(s));
    }

    vector<vector<string> > allv;
    
    allv.push_back(a);
    allv.push_back(b);
    allv.push_back(c);
    allv.push_back(v);
    
    // sample deques

    deque<string> dequeA;
    for (int i = 0; i < 2; ++i)
    {
        dequeA.push_back("a deque-A string");
    }
    
    deque<string> dequeB;
    for (int i = 0; i < 3; ++i)
    {
        dequeB.push_back("a deque-B string");
    }
    
    deque<deque<string> > allDeque;
    
    allDeque.push_back(dequeA);
    allDeque.push_back(dequeB);

    // sample lists

    list<string> listA;
    for (int i = 0; i < 2; ++i)
    {
        listA.push_back("a list-A string");
    }
    
    list<string> listB;
    for (int i = 0; i < 3; ++i)
    {
        listB.push_back("a list-B string");
    }
    
    list<list<string> > allList;
    
    allList.push_back(listA);
    allList.push_back(listB);

    list<int> listOfInts;
    for (int i = 0; i < 3; ++i)
    {
        listOfInts.push_back((i + 1) * 3);
    }
    
    vector<list<list<string> > > vectorOfListOfListOfStrings;

    vectorOfListOfListOfStrings.push_back(allList);
    
    deque<vector<list<list<string> > > > dequeOfVectorOfListOfListOfStrings;

    dequeOfVectorOfListOfListOfStrings.push_back(vectorOfListOfListOfStrings);
    
    list<deque<vector<list<list<string> > > > > listOfDequeOfStuff;

    listOfDequeOfStuff.push_back(dequeOfVectorOfListOfListOfStrings);
    
    // sample pairs

    pair<string, string> pairOfStringAndString("Bilbo", "Baggins");

    pair<deque<string>, list<list<string> > >
        pairOfDequeOfStringsAndListOfListOfStrings(dequeB, allList);
    
    // sample sets

    set<string> setA;
    
    setA.insert("set-A string one");
    setA.insert("set-A string two");
    setA.insert("set-A string three");

    set<string> setB;
    
    setB.insert("set-B string one");
    setB.insert("set-B string two");
    setB.insert("set-B string three");
    setB.insert("set-B string four");
    
    set<set<string> > allSets;
    
    allSets.insert(setA);
    allSets.insert(setB);
    
    // sample multisets

    multiset<string> multisetA;
    
    multisetA.insert("multiset-A string one");
    multisetA.insert("multiset-A string two");
    multisetA.insert("multiset-A string three");
    multisetA.insert("multiset-A string one");
    multisetA.insert("multiset-A string two");
    multisetA.insert("multiset-A string three");

    multiset<string> multisetB;
    
    multisetB.insert("multiset-B string one");
    multisetB.insert("multiset-B string two");
    multisetB.insert("multiset-B string four");
    multisetB.insert("multiset-B string three");
    multisetB.insert("multiset-B string one");
    multisetB.insert("multiset-B string four");
    
    multiset<multiset<string> > allMultisets;
    
    allMultisets.insert(multisetA);
    allMultisets.insert(multisetB);
    allMultisets.insert(multisetA);
    allMultisets.insert(multisetA);
    allMultisets.insert(multisetB);
    
    // sample maps

    map<string, string> mapA;

    mapA["one"] = "map-A string one";
    mapA["two"] = "map-A string two";
    mapA["three"] = "map-A string three";

    map<string, string> mapB;

    mapB["one"] = "map-B string one";
    mapB["two"] = "map-B string two";
    mapB["three"] = "map-B string three";
    mapB["four"] = "map-B string four";

    map<string, map<string, string> > allMaps;
    
    allMaps["Map A"] = mapA;
    allMaps["Map B"] = mapB;
    
    // sample multimaps

    multimap<string, string> multimapA;

    multimapA.insert(make_pair("one", "multimap-A string one"));
    multimapA.insert(make_pair("two", "multimap-A string two"));
    multimapA.insert(make_pair("three", "multimap-A string three"));
    multimapA.insert(make_pair("one", "multimap-A string four"));
    multimapA.insert(make_pair("two", "multimap-A string five"));
    multimapA.insert(make_pair("three", "multimap-A string six"));

    multimap<string, string> multimapB;

    multimapB.insert(make_pair("one", "multimap-B string one"));
    multimapB.insert(make_pair("two", "multimap-B string two"));
    multimapB.insert(make_pair("three", "multimap-B string three"));
    multimapB.insert(make_pair("four", "multimap-B string four"));
    multimapB.insert(make_pair("one", "multimap-B string five"));
    multimapB.insert(make_pair("four", "multimap-B string six"));

    multimap<string, multimap<string, string> > allMultimaps;
    
    allMultimaps.insert(make_pair("Map A", multimapA));
    allMultimaps.insert(make_pair("Map B", multimapB));
    allMultimaps.insert(make_pair("Map A", multimapA));
    allMultimaps.insert(make_pair("Map A", multimapA));
    allMultimaps.insert(make_pair("Map B", multimapB));
    
    // *** *** //

    int arrayOfInts[5];
    for (int i = 0; i < 5; ++i)
    {
        arrayOfInts[i] = i + 1;
    }
    
    char* arrayOfChars[5];
    for (int i = 0; i < 5; ++i)
    {
        const int stringLength(strlen("a heap char*") + 1);
        
        arrayOfChars[i] = new char[stringLength];

        strcpy(arrayOfChars[i], "a heap char*");
    }
    
    string* arrayOfStrings[5];
    for (int i = 0; i < 5; ++i)
    {
        arrayOfStrings[i] = new string("a heap string");
    }

    // Nice big loop to allow us to inspect all of our data structures

    bool exitLoop(false);

    for (int i = 0; i < 1000 and not exitLoop; ++i)
    {
	stringstream ss;
	ss << i;
	ss >> s;
    }
    
    return 0;
}
