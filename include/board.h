using namespace std;
class Board
{
    protected:
        sNumber board[9][9];
    public:
        //constructor & destructor
        Board();
        ~Board();

        //functionality
        void draw();
        void set();
        sNumber get(int i, int j);
};

Board::Board()
{
    //filling board with zeroes
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            board[i][j].setNumber(0);
        }
    }
}

Board::~Board()
{

}

void Board::draw()
{
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            cout << "|" << board[i][j].getNumber();
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
            if(itemp == 0)
            {
                board[i][j].setNumber(itemp);
                board[i][j].setConf(0);
            }
            else
            {
                board[i][j].setNumber(itemp);
                board[i][j].setConf(1);
            }
        }
    }
}

sNumber Board::get(int i, int j)
{
    return board[i][j];
}