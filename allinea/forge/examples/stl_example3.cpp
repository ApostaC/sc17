#include <list>
#include <string>

using namespace std;

struct Foo
{
	int blah;
	string str;
	list<string> ll;
};

int main()
{
	list<Foo> mylist;

	for(int i = 0; i < 10; ++i)
	{
		Foo foo;
		foo.str = "bar";
		foo.blah = i;
		string str = "baz";
		for(int j = 0; j < 5; ++j)
		{
			foo.ll.push_back(str);
			str = str + str;
		}
		mylist.push_back(foo);
	}
}

