#include <list>
#include <string>

using namespace std;

struct Foo
{
	string str;
};

int main()
{
	list<Foo> mylist;

	for(int i = 0; i < 10; ++i)
	{
		Foo foo;
		foo.str = "bar";
		mylist.push_back(foo);
	}
}

