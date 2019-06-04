class sNumber
{
private:
    int data = 0;
    int state = 0;
    bool conf = 0; //to know if number is from config, so we do not alter data
    bool solved = 0;

public:
    //constructor & destructor
    sNumber();
    sNumber(int a);
    ~sNumber();

    //access functions
    int setNumber(int b);
    int setState(int c);
    int setConf(int a);
    bool setSolved(bool b);
    int getNumber();
    int getState();
    int getConf();
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

int sNumber::setConf(int a)
{
    conf = a;
}

int sNumber::getConf()
{
    return conf;
}

bool sNumber::setSolved(bool b)
{
    solved = b;
}

bool sNumber::getSolved()
{
    return solved;
}