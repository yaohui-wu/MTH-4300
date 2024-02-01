#include <iostream>
#include <string>
#include <stack>

bool balanced(std::string);

int main()
{
    std::string bal1 = "(2 + [ 3 - (4*2) + 5] - 6)";
    std::string bal2 = "(((x + [y + (z * [w - [1]])])) + [4])";
    std::string bal3 = "()";
    std::string unbal1 = "(x[y)z]";
    std::string unbal2 = "(1 + (2 + (3 + 4]]]";
    std::string unbal3 = "1]";
    std::string unbal4 = "(((1 + 2";

    std::cout << "You should see:\n111\n0000\n";
    std::cout << balanced(bal1) << balanced(bal2) << balanced(bal3) << std::endl;
    std::cout << balanced(unbal1) << balanced(unbal2) << balanced(unbal3) << balanced(unbal4) << std::endl;

    return 0;
}

/*
Return true if the parentheses and brackets contained within s are balanced,
otherwise return false.
*/
bool balanced(std::string s)
{
    // A stack to store the parentheses and brackets.
    std::stack<char> stack;

    for (int i = 0; i < s.size(); i++)
    {
        // Push open parentheses or brackets to the stack.
        if (s[i] == '(' || s[i] == '[')
        {
            stack.push(s[i]);
        }
        else if (s[i] == ')' || s[i] == ']')
        {
            // No open parentheses or brackets to match the closed ones.
            if (stack.empty())
            {
                return false;
            }

            // A pair of open and close parentheses or brackets.
            if (stack.top() == '(' && s[i] == ')' || stack.top() == '[' && s[i] == ']')
            {
                stack.pop();
            }
            // Mismatched parentheses or brackets.
            else
            {
                return false;
            }
        }
    }

    // If the stack is empty then all of the parentheses or brackets are balanced.
    return stack.empty();
}