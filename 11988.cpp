#include <iostream>
#include <string>
#include <sstream>
#include <list>

using namespace std;

int main()
{
  string s;
  while (getline(cin, s))
  {
    stringstream ss;
    ss << s;
    char c;
    list<char> l;
    list<char>::iterator it = l.begin();
    while (ss >> c)
    {
      if (c == '[') it = l.begin();
      else if (c == ']') it = l.end();
      else
      {
        l.insert(it, c);
      }
    }
    for (it = l.begin(); it != l.end(); it++)
    {
      cout << *it;
    }
    cout << endl;
  }
  return 0;
}
