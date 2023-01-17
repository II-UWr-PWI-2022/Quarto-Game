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
    3. c/q shape: circle or square
    4. h/d hollow-top or solid-top
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