#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include<bits/stdc++.h>
using namespace std;
using namespace sf;
class button{
    public:
        bool isPressed=false;
        int Yposition;
        int Xposition;
        bool isMouseOn=false;
        Text text;
};
int main(){
    //Defining variables
    Vector2i mouseWindowPosition;
    Text goBack;
    //rendering window "window"
    RenderWindow window(VideoMode(800,600), "Quarto game - menu", Style::Default);
    window.display();
    //setting vsync
    window.setVerticalSyncEnabled(true);
    //loading textures
    Texture backgroundTexture;
    backgroundTexture.loadFromFile("Resources/background.png");
    //making sprites
    Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0,0);
    //loading arial font
    Font font;
    font.loadFromFile("Resources/Arial.ttf");
    //adding option to go back in menu by clicking esc key
    goBack.setFont(font);
    goBack.setFillColor(Color(0,0,0));
    goBack.setString("To return to the menu, press escape key.");
    goBack.setCharacterSize(25);
    goBack.setPosition(Vector2f(150,550));
    //making buttons, their colors and texboxes
    //play button
    button play;
    RectangleShape playButton(Vector2f(200.f,50.f));
    playButton.setFillColor(Color(128,128,128));
    playButton.setOutlineThickness(5.f);
    playButton.setOutlineColor(Color(100,100,100));
    play.text.setFont(font);
    play.text.setString("Play");
    play.text.setFillColor(Color(255,0,0));
    play.text.setCharacterSize(30);
    //settings button
    button settings;
    RectangleShape settingsButton(Vector2f(200.f,50.f));
    settingsButton.setFillColor(Color(128,128,128));
    settingsButton.setOutlineThickness(5.f);
    settingsButton.setOutlineColor(Color(100,100,100));
    //instruction button
    button instruction;
    //credits button
    button credits;
    //ranking button
    button ranking;
    //help button
    button help;
    //Pvp button
    button PvP;
    //PvE button
    button PvE;
    //hard button
    button hard;
    //normal button
    button normal;
    //easy button 
    button easy;
    //setting position of buttons and text
    //play
    play.Xposition=70;
    play.Yposition=200;
    playButton.setPosition(Vector2f(play.Xposition, play.Yposition));
    play.text.setPosition(Vector2f(play.Xposition+65, play.Yposition+7));

    //settings

    //game loop
    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type==Event::Closed){
                window.close();
            }
        }
        //Getting mouse position
        mouseWindowPosition=Mouse::getPosition(window);
        //Checking if it's over button
        if (mouseWindowPosition.x >= play.Xposition && mouseWindowPosition.y >= play.Yposition && mouseWindowPosition.x <= play.Xposition + 200 && mouseWindowPosition.y <= play.Yposition + 50){
            play.isMouseOn = true;
            if(Mouse::isButtonPressed(Mouse::Left)==true){
                play.isPressed=true;
            }
        }
        else{
            play.isMouseOn=false;
        }
        //Changing fill color if it is over button
        if(play.isMouseOn==true){
            playButton.setFillColor(Color(100,100,100));
        }
        else{
            playButton.setFillColor(Color(128,128,128));
        }
        //Drawing to screen
        window.clear();
        window.draw(backgroundSprite);
        if(play.isPressed==false){
            window.draw(playButton);
            window.draw(play.text);
        }
        if(play.isPressed==true){
            window.draw(goBack);
        }
        if(Keyboard::isKeyPressed(Keyboard::Escape)==true){
            play.isPressed=false;
        }   
        window.display();
    }
}