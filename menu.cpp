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
    RenderWindow window(VideoMode(800,600), "Quarto game - menu", Style::Close);
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
    goBack.setString("Press the escape key to return to the menu.");
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
    settings.text.setFont(font);
    settings.text.setString("Settings");
    settings.text.setFillColor(Color(255,0,0));
    settings.text.setCharacterSize(30);
    //instruction button
    button instruction;
    RectangleShape instructionButton(Vector2f(200.f,50.f));
    instructionButton.setFillColor(Color(128,128,128));
    instructionButton.setOutlineThickness(5.f);
    instructionButton.setOutlineColor(Color(100,100,100));
    instruction.text.setFont(font);
    instruction.text.setString("Instruction");
    instruction.text.setFillColor(Color(255,0,0));
    instruction.text.setCharacterSize(30);
    //ranking button
    button ranking;
    RectangleShape rankingButton(Vector2f(200.f,50.f));
    rankingButton.setFillColor(Color(128,128,128));
    rankingButton.setOutlineThickness(5.f);
    rankingButton.setOutlineColor(Color(100,100,100));
    ranking.text.setFont(font);
    ranking.text.setString("Ranking");
    ranking.text.setFillColor(Color(255,0,0));
    ranking.text.setCharacterSize(30);
    //credits button
    button credits;
    RectangleShape creditsButton(Vector2f(200.f,50.f));
    creditsButton.setFillColor(Color(128,128,128));
    creditsButton.setOutlineThickness(5.f);
    creditsButton.setOutlineColor(Color(100,100,100));
    credits.text.setFont(font);
    credits.text.setString("Credits");
    credits.text.setFillColor(Color(255,0,0));
    credits.text.setCharacterSize(30);
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
    play.text.setPosition(Vector2f(play.Xposition+67, play.Yposition+7));
    //settings
    settings.Xposition=70;
    settings.Yposition=266;
    settingsButton.setPosition(Vector2f(settings.Xposition, settings.Yposition));
    settings.text.setPosition(Vector2f(settings.Xposition+45, settings.Yposition+7));
    //instruction
    instruction.Xposition=70;
    instruction.Yposition=332;
    instructionButton.setPosition(Vector2f(instruction.Xposition, instruction.Yposition));
    instruction.text.setPosition(Vector2f(instruction.Xposition+32, instruction.Yposition+7));
    //ranking
    ranking.Xposition=70;
    ranking.Yposition=398;
    rankingButton.setPosition(Vector2f(ranking.Xposition, ranking.Yposition));
    ranking.text.setPosition(Vector2f(ranking.Xposition+45, ranking.Yposition+7));
    //credits
    credits.Xposition=70;
    credits.Yposition=464;
    creditsButton.setPosition(Vector2f(credits.Xposition, credits.Yposition));
    credits.text.setPosition(Vector2f(credits.Xposition+45, credits.Yposition+7));
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
        //Checking if it's over buttons and if player clicked it:
        //play
        if (mouseWindowPosition.x >= play.Xposition && mouseWindowPosition.y >= play.Yposition && mouseWindowPosition.x <= play.Xposition + 200 && mouseWindowPosition.y <= play.Yposition + 50){
            play.isMouseOn = true;
            if(Mouse::isButtonPressed(Mouse::Left)==true){
                play.isPressed=true;
            }
        }
        else{
            play.isMouseOn=false;
        }
        //settings
        if (mouseWindowPosition.x >= settings.Xposition && mouseWindowPosition.y >= settings.Yposition && mouseWindowPosition.x <= settings.Xposition + 200 && mouseWindowPosition.y <= settings.Yposition + 50){
            settings.isMouseOn = true;
            if(Mouse::isButtonPressed(Mouse::Left)==true){
                settings.isPressed=true;
            }
        }
        else{
            settings.isMouseOn=false;
        }
        //instruction
        if (mouseWindowPosition.x >= instruction.Xposition && mouseWindowPosition.y >= instruction.Yposition && mouseWindowPosition.x <= instruction.Xposition + 200 && mouseWindowPosition.y <= instruction.Yposition + 50){
            instruction.isMouseOn = true;
            if(Mouse::isButtonPressed(Mouse::Left)==true){
                instruction.isPressed=true;
            }
        }
        else{
            instruction.isMouseOn=false;
        }
        //ranking
        if (mouseWindowPosition.x >= ranking.Xposition && mouseWindowPosition.y >= ranking.Yposition && mouseWindowPosition.x <= ranking.Xposition + 200 && mouseWindowPosition.y <= ranking.Yposition + 50){
            ranking.isMouseOn = true;
            if(Mouse::isButtonPressed(Mouse::Left)==true){
                ranking.isPressed=true;
            }
        }
        else{
            ranking.isMouseOn=false;
        }
        //credits
        if (mouseWindowPosition.x >= credits.Xposition && mouseWindowPosition.y >= credits.Yposition && mouseWindowPosition.x <= credits.Xposition + 200 && mouseWindowPosition.y <= credits.Yposition + 50){
            credits.isMouseOn = true;
            if(Mouse::isButtonPressed(Mouse::Left)==true){
                credits.isPressed=true;
            }
        }
        else{
            credits.isMouseOn=false;
        }
        //Changing fill color if it is over buttons
        //play
        if(play.isMouseOn==true){
            playButton.setFillColor(Color(100,100,100));
        }
        else{
            playButton.setFillColor(Color(128,128,128));
        }
        //settings
        if(settings.isMouseOn==true){
            settingsButton.setFillColor(Color(100,100,100));
        }
        else{
            settingsButton.setFillColor(Color(128,128,128));
        }
        //instruction
        if(instruction.isMouseOn==true){
            instructionButton.setFillColor(Color(100,100,100));
        }
        else{
            instructionButton.setFillColor(Color(128,128,128));
        }
        //ranking
        if(ranking.isMouseOn==true){
            rankingButton.setFillColor(Color(100,100,100));
        }
        else{
            rankingButton.setFillColor(Color(128,128,128));
        }
        //credits
        if(credits.isMouseOn==true){
            creditsButton.setFillColor(Color(100,100,100));
        }
        else{
            creditsButton.setFillColor(Color(128,128,128));
        }
        //Drawing to screen
        window.clear();
        window.draw(backgroundSprite);
        if(play.isPressed==false && settings.isPressed==false && instruction.isPressed==false && ranking.isPressed==false && credits.isPressed==false){
            window.draw(playButton);
            window.draw(play.text);
            window.draw(settingsButton);
            window.draw(settings.text);
            window.draw(instructionButton);
            window.draw(instruction.text);
            window.draw(rankingButton);
            window.draw(ranking.text);
            window.draw(creditsButton);
            window.draw(credits.text);
        }
        //menu after clicking play button
        if(play.isPressed==true){
            window.draw(goBack);
        }
        //menu after clicking settings button
        if(settings.isPressed==true){
            window.draw(goBack);
        }
        //menu after clicking instruction button
        if(instruction.isPressed==true){
            window.draw(goBack);
        }
        //menu after clicking ranking button
        if(ranking.isPressed==true){
            window.draw(goBack);
        }
        //menu after clicing credits menu
        if(credits.isPressed==true){
            window.draw(goBack);
        }      
        if(Keyboard::isKeyPressed(Keyboard::Escape)==true){
            play.isPressed=false;
            settings.isPressed=false;
            instruction.isPressed=false;
            ranking.isPressed=false;
            credits.isPressed=false;
        }   
        window.display();
    }
}