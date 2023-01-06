#include <iostream>

#include "Piece.h"

using namespace std;

int main()
{
    Piece piece[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    cout << "Hello world!" << endl;

    for(int i = 0; i < 16; i++)
    {
        cout << piece[i].getPieceType() << endl;
        cout << piece[i].isPieceUsed() << endl;
        piece[i].setPieceAsUsed();
        cout << piece[i].isPieceUsed() << endl << endl;
    }

    return 0;
}
