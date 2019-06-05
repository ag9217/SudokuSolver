class sNumber
{
protected:
    int data = 0;
    int conf = 0;

public:
    //constructor & destructor
    sNumber();
    sNumber(int a);
    ~sNumber();

    //access functions
    int setNumber(int b);
    int setConf(int c);
    int getNumber();
    int getConf();

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

int sNumber::setConf(int c)
{
    conf = c;
}

int sNumber::getConf()
{
    return conf;
}