class sNumber
{
private:
    int data = 0;
    int state = 0;
    bool solved = 0;

public:
    //constructor & destructor
    sNumber();
    sNumber(int a);
    ~sNumber();

    //access functions
    int setNumber(int b);
    int setState(int c);
    bool setSolved(bool b);
    int getNumber();
    int getState();
    bool getSolved();

    //functionality
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

bool sNumber::setSolved(bool b)
{
    solved = b;
}

bool sNumber::getSolved()
{
    return solved;
}