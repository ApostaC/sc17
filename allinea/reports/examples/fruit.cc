// This example is licensed by Red Hat under the Creative Commons Attribution-ShareAlike 3.0 Unported License.
// Original: https://access.redhat.com/site/documentation/en-US/Red_Hat_Enterprise_Linux/6/html/Developer_Guide/debuggingprettyprinters.html

enum Fruits {Orange, Apple, Banana};

class Fruit
{
  int fruit;

 public:
  Fruit (int f)
    {
      fruit = f;
    }
};

int main()
{
  Fruit myFruit(Apple);
  return 0;             // line 20
}
