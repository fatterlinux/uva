#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;
const int max_init = (1 << 31) - 1;

int main()
{
    string a, c;
    char b;
    
    while (cin >> a >> b >> c)
    {
        cout << a << " " << b << " " << c << endl;
        double e = atof(a.c_str());
        double f = atof(c.c_str());
        
        if (e > max_init)
        {
                
            cout << "first number too big" <<endl;
        }
        if (f > max_init)
        {
            cout << "second number too big" <<endl;
        }
        if (b == '+' && (e+f > max_init))
        {
            cout << "result too big" << endl;
        }
        if (b == '*' && (e*f > max_init))
        {
            cout <<"result too big" <<endl;
        }
    }
    return 0;
}
