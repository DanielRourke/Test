#include <string>


class Player
{
    protected:
    char playerSymbol;
    std::string name;
    public:
    Player(int i, char s) : name("Player " + to_string(i)) , playerSymbol(s){}
    // {
    //    name = ;
    //     cout << "What is the Player Symbol for " << name << " : " ;
    //     cin >> playerSymbol ;
    // }
    virtual void getMove( int& x, int& y ) =0;
    char retSymbol()
    {
        return playerSymbol;
    }

};