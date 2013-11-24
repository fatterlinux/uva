#include <iostream>
#include <stack>
#include <string>
#include <assert.h>

using namespace std;

int main(void)
{
    int test_case;
    cin >> test_case;
    cin.get();//下面的getline会遇到整数后面的换行符，所以这里先丢弃换行符
    while(test_case--)
    {
        string s;
        getline(cin, s);
        stack<char> ss;
        bool correct_flag(true);
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[')
            {
                ss.push(s[i]);
            }
            else if (s[i] == ')')
            {
                if (ss.empty() || ss.top() != '(')//可能输入不合法，empty需要check
                {
                    correct_flag = false;
                    break;
                }
                ss.pop();
            }
            else if (s[i] == ']')
            {
                if (ss.empty() || ss.top() != '[')
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
        if (ss.empty() && correct_flag)//没有correct_flag的判断不行，假设就一个')'，ss是empty，可以flag不正确
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
