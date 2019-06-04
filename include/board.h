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
        sNumber getBoardN(int i, int j);
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
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
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

    for(int i = 0; i < 9; i++) // configurating board
    {
        for(int j = 0; j < 9; j++)
        {
            sconfig >> itemp;
            board[i][j].setNumber(itemp);
            if(itemp == 0)
            {
                board[i][j].setSolved(0);
            }
            else
            {
                board[i][j].setSolved(1);
            }
                        
        }
    }
}

sNumber Board::getBoardN(int i, int j)
{
    return board[i][j];
}