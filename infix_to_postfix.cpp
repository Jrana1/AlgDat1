#include <iostream>
using namespace std;
#include <stack>
#include <string>
bool isOperand(char ch)
{
    if (ch == '+' || ch == '*' || ch == '/' || ch == '-')
    {
        return false;
    }
    return true;
}
int getPrecedenz(char op)
{

    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
}
string infix_to_postfix(string str)
{
    string str2;
    stack<char> st;
    for (auto i = 0; i < str.size(); i++)
    {
        if (isOperand(str[i]))
        {
            str2 += str[i];
        }
        else
        {
            if (st.empty())
            {
                st.push(str[i]);
            }
            else
            {
                int prec_curr = getPrecedenz(str[i]);
                int prec_top = getPrecedenz(st.top());
                if (prec_top < prec_curr)
                {
                    st.push(str[i]);
                }
                else
                {
                    while (!st.empty() && prec_curr <= getPrecedenz(st.top()))
                    {
                        str2 += st.top();
                        st.pop();
                    }
                    st.push(str[i]);
                }
            }
        }
    }
    while (!st.empty())
    {
        str2 += st.top();
        st.pop();
    }
    return str2;
}

int main()
{

    string str = "a-b*c";
    cout << infix_to_postfix(str) << endl;

    return 0;
}
