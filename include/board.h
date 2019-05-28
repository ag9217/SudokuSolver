using namespace std;
class Board
{
    protected:
        sNumber* board[11][11];
    public:
        //constructor & destructor
        Board();
        ~Board();

        //functionality
        void draw();
        void set();
};

Board::Board()
{
    //filling board with zeroes and border with 10's
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            if(i == 0 || i == 10 || j == 0 || j == 10) //creating special case for border
            {
                board[i][j] = new sNumber(10);
                continue;
            }
            board[i][j] = new sNumber(1);
        }
    }
}

Board::~Board()
{
        for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            delete board[i][j];
        }
    }
}

void Board::draw()
{
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            cout << "|" << (*board[i][j]).getNumber();
        }
        cout << "|" << endl;
    }
}

void Board::set()
{
    //delcaring variables
    ifstream sconfig("..\\config\\config.txt");

    //temp variables
    int itemp;

    for(int i = 1; i < 10; i++) // configurating board
    {
        for(int j = 1; j < 10; j++)
        {
            sconfig >> itemp;
            (*board[i][j]).setNumber(itemp);
        }
    }
}