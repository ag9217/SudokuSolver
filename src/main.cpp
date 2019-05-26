#include <iostream>
using namespace std;

class sNumber
{
private:
    int data = 0;
    int state = 0;

public:
    //constructor & destructor
    sNumber();
    sNumber(int a);
    ~sNumber();

    //access functions
    int setNumber(int b);
    int setState(int c);
    int getNumber();
    int getState();
};

sNumber::sNumber()
{
}

sNumber::sNumber(int a)
{
    data = a;
}

sNumber::~sNumber()
{
}

int sNumber::setNumber(int b)
{
    data = b;
}

int sNumber::getNumber()
{
    return data;
}

int sNumber::setState(int c)
{
    state = c;
}

int sNumber::getState()
{
    return state;
}

void printboard(sNumber *board[11][11]);

int main()
{
    cout << "Hello" << endl;
    bool solved = 0;

    sNumber *board[11][11];

    //filling board with zeroes and border with 10's
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            board[i][j] = new sNumber(0);
        }
    }

    printboard(board);

    while (!solved)
    {
        return 0;
    }
}

void printboard(sNumber *board[11][11])
{
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            cout << "|" << (*board[i][j]).getNumber();
        }
        cout << "|" << endl;
    }
}