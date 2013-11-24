#include <iostram>
#include <stack>
#include <string>
#include <assert.h>

using namespace std;

int main(void)
{
    int test_case;
    cin >> test_case;
    while(test_case--)
    {
        string s;
        cin >> s;
        stack<char> ss;
        bool correct_flag(true);
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[')
            {
                ss.push(s[i]);
            }
            else if (s[i] == ')')
            {
                if (ss.top() != '(')
                {
                    correct_flag = false;
                    break;
                }
                ss.pop();
            }
            else if (s[i] == ']')
            {
                if (ss.top() != '[')
                {
                    correct_flag = false;
                    break;
                }
                ss.pop();
            }
            else
            {
                assert(0);
            }
        }//end for
        if (ss.empty() && correct_flag)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
