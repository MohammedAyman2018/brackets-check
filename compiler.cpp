#include <iostream>
#include <string>
using namespace std;

// تعريف حجم
#define size 5

char Carly_Brackets_Stack[size];
int Carly_Top = -1;

// Carly brackets functions
void cpush()
{
    if (Carly_Top == size - 1)
        cout << "stack is full" << endl;
    else
    {
        Carly_Top++;
        Carly_Brackets_Stack[Carly_Top] = '{';
    }
}

int cpop()
{
    int val;
    if (Carly_Top == -1)
    {
        cout << "stack is empty" << endl;
        return -1;
    }

    else
        return Carly_Top--;
}

char Normal_Brackets_Stack[size];
int Normal_Top = -1;

void push()
{
    if (Normal_Top == size - 1)
        cout << "stack is full" << endl;
    else
    {
        Normal_Top++;
        Normal_Brackets_Stack[Normal_Top] = '(';
    }
}

int pop()
{
    int val;
    if (Normal_Top == -1)
    {
        cout << "stack is empty" << endl;
        return -1;
    }

    else
        return Normal_Top--;
}

int main()
{
    char str[80];
    cout << "Enter a number and a string:\n";
    cin.getline(str, 80); //take a string

    for (int i = 0; str[i] != '\0'; i++)
    {
        /* code */
        char prev = str[i - 1];

        if (((str[i] == ')' && prev == '{')) || ((str[i] == '}' && prev == '(')))
        {
            cout << "your expression isn't correct check letter number " << i + 1 << endl;
            return 0;
        }

        if (str[i] == '(')
            push();
        else if (str[i] == ')')
        {
            if (Normal_Brackets_Stack[Normal_Top] == '\0')
            {
                cout << "YOU CLOSED NORMAL BRACKET YOU DID NOT OPEN" << endl;
                return 0;
            }
            else
                pop();
        }
        else if (str[i] == '{')
            cpush();
        else if (str[i] == '}')
        {
            if (Carly_Brackets_Stack[Carly_Top] == '\0')
            {
                cout << "YOU CLOSED CARLY BRACKET YOU DID NOT OPEN" << endl;
                return 0;
            }
            else
                cpop();
        }
    }

    if (Normal_Top == -1 && Carly_Top == -1)
        cout << "Your expression is correct" << endl;

    else if (Normal_Top != -1)
    {
        if (Carly_Top != -1)
        {
            cout << "You have " << Carly_Top + 1 << " carly brackets opend without closed" << endl;
            cout << "You have " << Normal_Top + 1 << " normal brackets opend without closed" << endl;
        }
        else
            cout << "You have " << Normal_Top + 1 << " normal brackets opend without closed" << endl;
    }
    else if (Carly_Top != -1)
        cout << "You have " << Carly_Top + 1 << " carly brackets opend without closed" << endl;

    return 0;
}