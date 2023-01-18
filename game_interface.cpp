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
    if empty then ther is no piece
    */
    string whatTypeOfPieceisOn="";
};
class fieldNextToBoard{
    public:
    bool isPieceStillOn=true;
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
    if empty then ther is no piece
    */
    string whatTypeOfPieceIsOn;
};
class piece{
    public:
    int Xposition;
    int Yposiiton;
    string code;
    string OnWhichFieldIsIt;
    Sprite sprt;
    bool isChosenToBePlaced=false;
    Texture tex;
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
    //defining fields next to the board (pieces starting positions)
    /*
    l1              r1
    l2              r2
    l3              r3
    l4              r4
    l5              r5
    l6              r6
    l7              r7
    l8              r8
    */
    fieldNextToBoard l1;
    l1.XpositionOfLeftUpCorner=8;
    l1.YpositionOfLeftUpCorner=16;
    l1.XpositionOfRightDownCorner=61;
    l1.YpositionOfRightDownCorner=69;
    l1.whatTypeOfPieceIsOn="dbch";
    fieldNextToBoard l2;
    l2.XpositionOfLeftUpCorner=8;
    l2.YpositionOfLeftUpCorner=93;
    l2.XpositionOfRightDownCorner=61;
    l2.YpositionOfRightDownCorner=142;
    l2.whatTypeOfPieceIsOn="dbcs";
    fieldNextToBoard l3;
    l3.XpositionOfLeftUpCorner=8;
    l3.YpositionOfLeftUpCorner=166;
    l3.XpositionOfRightDownCorner=61;
    l3.YpositionOfRightDownCorner=116;
    l3.whatTypeOfPieceIsOn="dbsh";
    fieldNextToBoard l4;
    l4.XpositionOfLeftUpCorner=8;
    l4.YpositionOfLeftUpCorner=239;
    l4.XpositionOfRightDownCorner=61;
    l4.YpositionOfRightDownCorner=291;
    l4.whatTypeOfPieceIsOn="dbss";
    fieldNextToBoard l5;
    l5.XpositionOfLeftUpCorner=8;
    l5.YpositionOfLeftUpCorner=319;
    l5.XpositionOfRightDownCorner=61;
    l5.YpositionOfRightDownCorner=363;
    l5.whatTypeOfPieceIsOn="dsch";
    fieldNextToBoard l6;
    l6.XpositionOfLeftUpCorner=8;
    l6.YpositionOfLeftUpCorner=391;
    l6.XpositionOfRightDownCorner=61;
    l6.YpositionOfRightDownCorner=435;
    l6.whatTypeOfPieceIsOn="dscs";
    fieldNextToBoard l7;
    l7.XpositionOfLeftUpCorner=8;
    l7.YpositionOfLeftUpCorner=465;
    l7.XpositionOfRightDownCorner=61;
    l7.YpositionOfRightDownCorner=510;
    l7.whatTypeOfPieceIsOn="dssh";
    fieldNextToBoard l8;
    l8.XpositionOfLeftUpCorner=8;
    l8.YpositionOfLeftUpCorner=539;
    l8.XpositionOfRightDownCorner=61;
    l8.YpositionOfRightDownCorner=588;
    l8.whatTypeOfPieceIsOn="dsss";
    fieldNextToBoard r1;
    r1.XpositionOfLeftUpCorner=737;
    r1.YpositionOfLeftUpCorner=14;
    r1.XpositionOfRightDownCorner=790;
    r1.YpositionOfRightDownCorner=60;
    r1.whatTypeOfPieceIsOn="lbch";
    fieldNextToBoard r2;
    r2.XpositionOfLeftUpCorner=737;
    r2.YpositionOfLeftUpCorner=88;
    r2.XpositionOfRightDownCorner=790;
    r2.YpositionOfRightDownCorner=139;
    r2.whatTypeOfPieceIsOn="lbcs";
    fieldNextToBoard r3;
    r3.XpositionOfLeftUpCorner=737;
    r3.YpositionOfLeftUpCorner=164;
    r3.XpositionOfRightDownCorner=790;
    r3.YpositionOfRightDownCorner=213;
    r3.whatTypeOfPieceIsOn="lbsh";
    fieldNextToBoard r4;
    r4.XpositionOfLeftUpCorner=737;
    r4.YpositionOfLeftUpCorner=236;
    r4.XpositionOfRightDownCorner=790;
    r4.YpositionOfRightDownCorner=286;
    r4.whatTypeOfPieceIsOn="lbss";
    fieldNextToBoard r5;
    r5.XpositionOfLeftUpCorner=737;
    r5.YpositionOfLeftUpCorner=313;
    r5.XpositionOfRightDownCorner=790;
    r5.YpositionOfRightDownCorner=360;
    r5.whatTypeOfPieceIsOn="lsch";
    fieldNextToBoard r6;
    r6.XpositionOfLeftUpCorner=737;
    r6.YpositionOfLeftUpCorner=385;
    r6.XpositionOfRightDownCorner=790;
    r6.YpositionOfRightDownCorner=435;
    r6.whatTypeOfPieceIsOn="lscs";
    fieldNextToBoard r7;
    r7.XpositionOfLeftUpCorner=737;
    r7.YpositionOfLeftUpCorner=459;
    r7.XpositionOfRightDownCorner=790;
    r7.YpositionOfRightDownCorner=506;
    r7.whatTypeOfPieceIsOn="lssh";
    fieldNextToBoard r8;
    r8.XpositionOfLeftUpCorner=737;
    r8.YpositionOfLeftUpCorner=535;
    r8.XpositionOfRightDownCorner=790;
    r8.YpositionOfRightDownCorner=582;
    r8.whatTypeOfPieceIsOn="lsss";
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
    //loadig textures for pieces and defining them
    piece dbch;
    dbch.tex.loadFromFile("Resources/pieces/dbch.png");
    dbch.sprt.setTexture(dbch.tex);
    dbch.Xposition=l1.XpositionOfLeftUpCorner;
    dbch.Yposiiton=l1.YpositionOfLeftUpCorner;
    dbch.sprt.setPosition(Vector2f(dbch.Xposition, dbch.Yposiiton));
    dbch.code="dbch";
    dbch.OnWhichFieldIsIt="l1";
    piece dbcs;
    dbcs.tex.loadFromFile("Resources/pieces/dbcs.png");
    dbcs.sprt.setTexture(dbcs.tex);
    dbcs.Xposition=l2.XpositionOfLeftUpCorner;
    dbcs.Yposiiton=l2.YpositionOfLeftUpCorner;
    dbcs.sprt.setPosition(Vector2f(dbcs.Xposition, dbcs.Yposiiton));
    dbcs.code="dbcs";
    dbcs.OnWhichFieldIsIt="l2";
    piece dbsh;
    dbsh.tex.loadFromFile("Resources/pieces/dbsh.png");
    dbsh.sprt.setTexture(dbsh.tex);
    dbsh.Xposition=l3.XpositionOfLeftUpCorner;
    dbsh.Yposiiton=l3.YpositionOfLeftUpCorner;
    dbsh.sprt.setPosition(Vector2f(dbsh.Xposition, dbsh.Yposiiton));
    dbsh.code="dbsh";
    dbsh.OnWhichFieldIsIt="l3";
    piece dbss;
    dbss.tex.loadFromFile("Resources/pieces/dbss.png");
    dbss.sprt.setTexture(dbss.tex);
    dbss.Xposition=l4.XpositionOfLeftUpCorner;
    dbss.Yposiiton=l4.YpositionOfLeftUpCorner;
    dbss.sprt.setPosition(Vector2f(dbss.Xposition, dbss.Yposiiton));
    dbss.code="dbss";
    dbss.OnWhichFieldIsIt="l4";
    piece dsch;
    dsch.tex.loadFromFile("Resources/pieces/dsch.png");
    dsch.sprt.setTexture(dsch.tex);
    dsch.Xposition=l5.XpositionOfLeftUpCorner;
    dsch.Yposiiton=l5.YpositionOfLeftUpCorner;
    dsch.sprt.setPosition(Vector2f(dsch.Xposition, dsch.Yposiiton));
    dsch.code="dsch";
    dsch.OnWhichFieldIsIt="l5";
    piece dscs;
    dscs.tex.loadFromFile("Resources/pieces/dscs.png");
    dscs.sprt.setTexture(dscs.tex);
    dscs.Xposition=l6.XpositionOfLeftUpCorner;
    dscs.Yposiiton=l6.YpositionOfLeftUpCorner;
    dscs.sprt.setPosition(Vector2f(dscs.Xposition, dscs.Yposiiton));
    dscs.code="dscs";
    dscs.OnWhichFieldIsIt="l6";
    piece dssh;
    dssh.tex.loadFromFile("Resources/pieces/dssh.png");
    dssh.sprt.setTexture(dssh.tex);
    dssh.Xposition=l7.XpositionOfLeftUpCorner;
    dssh.Yposiiton=l7.YpositionOfLeftUpCorner;
    dssh.sprt.setPosition(Vector2f(dssh.Xposition, dssh.Yposiiton));
    dssh.code="dssh";
    dssh.OnWhichFieldIsIt="l7";
    piece dsss;
    dsss.tex.loadFromFile("Resources/pieces/dsss.png");
    dsss.sprt.setTexture(dsss.tex);
    dsss.Xposition=l8.XpositionOfLeftUpCorner;
    dsss.Yposiiton=l8.YpositionOfLeftUpCorner;
    dsss.sprt.setPosition(Vector2f(dsss.Xposition, dsss.Yposiiton));
    dsss.code="dsss";
    dsss.OnWhichFieldIsIt="l8";
    piece lbch;
    lbch.tex.loadFromFile("Resources/pieces/lbch.png");
    lbch.sprt.setTexture(lbch.tex);
    lbch.Xposition=r1.XpositionOfLeftUpCorner;
    lbch.Yposiiton=r1.YpositionOfLeftUpCorner;
    lbch.sprt.setPosition(Vector2f(lbch.Xposition, lbch.Yposiiton));
    lbch.code="lbch";
    lbch.OnWhichFieldIsIt="r1";
    piece lbcs;
    lbcs.tex.loadFromFile("Resources/pieces/lbcs.png");
    lbcs.sprt.setTexture(lbcs.tex);
    lbcs.Xposition=r2.XpositionOfLeftUpCorner;
    lbcs.Yposiiton=r2.YpositionOfLeftUpCorner;
    lbcs.sprt.setPosition(Vector2f(lbcs.Xposition, lbcs.Yposiiton));
    lbcs.code="lbcs";
    lbcs.OnWhichFieldIsIt="r2";
    piece lbsh;
    lbsh.tex.loadFromFile("Resources/pieces/lbsh.png");
    lbsh.sprt.setTexture(lbsh.tex);
    lbsh.Xposition=r3.XpositionOfLeftUpCorner;
    lbsh.Yposiiton=r3.YpositionOfLeftUpCorner;
    lbsh.sprt.setPosition(Vector2f(lbsh.Xposition, lbsh.Yposiiton));
    lbsh.code="lbsh";
    lbsh.OnWhichFieldIsIt="r3";
    piece lbss;
    lbss.tex.loadFromFile("Resources/pieces/lbss.png");
    lbss.sprt.setTexture(lbss.tex);
    lbss.Xposition=r4.XpositionOfLeftUpCorner;
    lbss.Yposiiton=r4.YpositionOfLeftUpCorner;
    lbss.sprt.setPosition(Vector2f(lbss.Xposition, lbss.Yposiiton));
    lbss.code="lbss";
    lbss.OnWhichFieldIsIt="r4";
    piece lsch;
    lsch.tex.loadFromFile("Resources/pieces/lsch.png");
    lsch.sprt.setTexture(lsch.tex);
    lsch.Xposition=r5.XpositionOfLeftUpCorner;
    lsch.Yposiiton=r5.YpositionOfLeftUpCorner;
    lsch.sprt.setPosition(Vector2f(lsch.Xposition, lsch.Yposiiton));
    lsch.code="lsch";
    lsch.OnWhichFieldIsIt="r5";
    piece lscs;
    lscs.tex.loadFromFile("Resources/pieces/lscs.png");
    lscs.sprt.setTexture(lscs.tex);
    lscs.Xposition=r6.XpositionOfLeftUpCorner;
    lscs.Yposiiton=r6.YpositionOfLeftUpCorner;
    lscs.sprt.setPosition(Vector2f(lscs.Xposition, lscs.Yposiiton));
    lscs.code="lscs";
    lscs.OnWhichFieldIsIt="r6";
    piece lssh;
    lssh.tex.loadFromFile("Resources/pieces/lssh.png");
    lssh.sprt.setTexture(lssh.tex);
    lssh.Xposition=r7.XpositionOfLeftUpCorner;
    lssh.Yposiiton=r7.YpositionOfLeftUpCorner;
    lssh.sprt.setPosition(Vector2f(lssh.Xposition, lssh.Yposiiton));
    lssh.code="lssh";
    lssh.OnWhichFieldIsIt="r7";
    piece lsss;
    lsss.tex.loadFromFile("Resources/pieces/lsss.png");
    lsss.sprt.setTexture(lsss.tex);
    lsss.Xposition=r8.XpositionOfLeftUpCorner;
    lsss.Yposiiton=r8.YpositionOfLeftUpCorner;
    lsss.sprt.setPosition(Vector2f(lsss.Xposition, lsss.Yposiiton));
    lsss.code="lsss";
    lsss.OnWhichFieldIsIt="r8";
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
        /*if(endingConidtion==true){
            //if player won
            if(ifPlayerWon==true){

            }
            //if player loose
            else{

            }
        }*/
        //drawing background
        window.draw(backgroundSprite);
        //drawing pieces
        window.draw(dbch.sprt);
        window.draw(dbcs.sprt);
        window.draw(dbsh.sprt);
        window.draw(dbss.sprt);
        window.draw(dsch.sprt);
        window.draw(dscs.sprt);
        window.draw(dssh.sprt);
        window.draw(dsss.sprt);
        window.draw(lbch.sprt);
        window.draw(lbcs.sprt);
        window.draw(lbsh.sprt);
        window.draw(lbss.sprt);
        window.draw(lsch.sprt);
        window.draw(lscs.sprt);
        window.draw(lssh.sprt);
        window.draw(lsss.sprt);
        window.display();
    }
}