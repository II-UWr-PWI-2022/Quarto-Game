#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;
class fieldOnBoard{
    public:
    bool isOccupied=false;
    int XpositionOfLeftUpCorner;
    int YpositionOfLeftUpCorner;
    int XpositionOfRightDownCorner;
    int YpositionOfRightDownCorner;
    /*Code for pawns
    Contains 4 characters
    1. d/l dark or light (color)
    2. b/s big or small
    3. c/s shape: circle or square
    4. h/s hollow-top or solid-top
    if NULL then ther is no piece
    */
    string whatTypeOfPieceisOn=NULL;
};
int main(){
    //defining variables
    bool endingConidtion=false;
    bool ifPlayerWon;
    //Rendering window
    RenderWindow window(VideoMode(800,600), "Quarto game", Style::Close);
    window.display();
    //Setting Vsync
    window.setVerticalSyncEnabled(true);
    //loading textures
    Texture backgroundTexture;
    backgroundTexture.loadFromFile("Resources/plansza.png");
    //making sprites
    Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0,0);
    //defining fields on board
    /*
          a1
        b1 a2
       c1 b2 a3
     d1 c2 b3 a4
       d2 c3 b4
        d3 c4
          d4
    */
    fieldOnBoard a1;
    a1.XpositionOfLeftUpCorner=376;
    a1.YpositionOfLeftUpCorner=115;
    a1.XpositionOfRightDownCorner=429;
    a1.YpositionOfRightDownCorner=168;
    fieldOnBoard a2;
    a2.XpositionOfLeftUpCorner=428;
    a2.YpositionOfLeftUpCorner=169;
    a2.XpositionOfRightDownCorner=481;
    a2.YpositionOfRightDownCorner=222;
    fieldOnBoard a3;
    a3.XpositionOfLeftUpCorner=484;
    a3.YpositionOfLeftUpCorner=220;
    a3.XpositionOfRightDownCorner=537;
    a3.YpositionOfRightDownCorner=273;
    fieldOnBoard a4;
    a4.XpositionOfLeftUpCorner=535;
    a4.YpositionOfLeftUpCorner=272;
    a4.XpositionOfRightDownCorner=588;
    a4.YpositionOfRightDownCorner=325;
    fieldOnBoard b1;
    b1.XpositionOfLeftUpCorner=323;
    b1.YpositionOfLeftUpCorner=167;
    b1.XpositionOfRightDownCorner=376;
    b1.YpositionOfRightDownCorner=220;
    fieldOnBoard b2;
    b2.XpositionOfLeftUpCorner=377;
    b2.YpositionOfLeftUpCorner=221;
    b2.XpositionOfRightDownCorner=430;
    b2.YpositionOfRightDownCorner=274;
    fieldOnBoard b3;
    b3.XpositionOfLeftUpCorner=431;
    b3.YpositionOfLeftUpCorner=275;
    b3.XpositionOfRightDownCorner=484;
    b3.YpositionOfRightDownCorner=327;
    fieldOnBoard b4;
    b4.XpositionOfLeftUpCorner=485;
    b4.YpositionOfLeftUpCorner=328;
    b4.XpositionOfRightDownCorner=538;
    b4.YpositionOfRightDownCorner=381;
    fieldOnBoard c1;
    c1.XpositionOfLeftUpCorner=271;
    c1.YpositionOfLeftUpCorner=222;
    c1.XpositionOfRightDownCorner=324;
    c1.YpositionOfRightDownCorner=275;
    fieldOnBoard c2;
    c2.XpositionOfLeftUpCorner=325;
    c2.YpositionOfLeftUpCorner=276;
    c2.XpositionOfRightDownCorner=378;
    c2.YpositionOfRightDownCorner=329;
    fieldOnBoard c3;
    c3.XpositionOfLeftUpCorner=379;
    c3.YpositionOfLeftUpCorner=330;
    c3.XpositionOfRightDownCorner=432;
    c3.YpositionOfRightDownCorner=383;
    fieldOnBoard c4;
    c4.XpositionOfLeftUpCorner=433;
    c4.YpositionOfLeftUpCorner=384;
    c4.XpositionOfRightDownCorner=486;
    c4.YpositionOfRightDownCorner=437;
    fieldOnBoard d1;
    d1.XpositionOfLeftUpCorner=215;
    d1.YpositionOfLeftUpCorner=275;
    d1.XpositionOfRightDownCorner=268;
    d1.YpositionOfRightDownCorner=328;
    fieldOnBoard d2;
    d2.XpositionOfLeftUpCorner=269;
    d2.YpositionOfLeftUpCorner=329;
    d2.XpositionOfRightDownCorner=322;
    d2.YpositionOfRightDownCorner=382;
    fieldOnBoard d3;
    d3.XpositionOfLeftUpCorner=323;
    d3.YpositionOfLeftUpCorner=383;
    d3.XpositionOfRightDownCorner=381;
    d3.YpositionOfRightDownCorner=436;
    fieldOnBoard d4;
    d4.XpositionOfLeftUpCorner=382;
    d4.YpositionOfLeftUpCorner=437;
    d4.XpositionOfRightDownCorner=435;
    d4.YpositionOfRightDownCorner=490;
    //game loop
    while(window.isOpen()){
        Event event;
        //Closing window
        while(window.pollEvent(event)){
            if(event.type==Event::Closed){
                window.close();
            }
        }
        //Drawing to screen
        window.clear();
        //if game ends
        if(endingConidtion==true){
            //if player won
            if(ifPlayerWon==true){

            }
            //if player loose
            else{

            }
        }

        window.draw(backgroundSprite);
        window.display();
    }
}