#include <iostream>
using namespace std;

// Custom Stack Implementation (No STL)
class Stack
{
    char arr[100];
    int topIndex;

public:
    Stack()
    {
        topIndex = -1;
    }

    void push(char val)
    {
        if (topIndex >= 99)
        {
            cout << "Stack Overflow\n";
            return;
        }
        topIndex++;
        arr[topIndex] = val;
    }

    void pop()
    {
        if (topIndex < 0)
        {
            cout << "Stack Underflow\n";
            return;
        }
        topIndex--;
    }

    char top()
    {
        if (topIndex < 0)
        {
            // Returning a null character if empty
            return '\0';
        }
        return arr[topIndex];
    }

    bool empty()
    {
        return topIndex == -1;
    }
};

// Algorithm to check if brackets are balanced
bool isValid(char str[], int length)
{
    Stack s;

    for (int i = 0; i < length; i++)
    {
        char ch = str[i];
        
        // 1. If opening bracket, push to stack
        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        // 2. If closing bracket, check for matching pair
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            // Instantly invalid if no opening brackets are left
            if (s.empty())
            {
                return false;
            }
            
            // Check for perfect pair
            if ((ch == ')' && s.top() == '(') ||
                (ch == '}' && s.top() == '{') ||
                (ch == ']' && s.top() == '['))
            {
                s.pop();
            }
            else
            {
                return false; // Mismatch found
            }
        }
    }

    // If the stack is empty at the end, every bracket found its match!
    return s.empty();
}

int main()
{
    // Test Case
    char testStr[] = "{[()]}";
    int length = 6;

    cout << "Is '{[()]}' valid? : " << (isValid(testStr, length) ? "True" : "False") << "\n";

    return 0;
}