


class Board
{
    private:
    char** grid;
    int size;
    int winThreshold;


    public:
    Board(int,int);
    void printBoard();
    bool isValidMove(int x, int y);
    void addMove(int x , int y, char c);

};


