#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include<bits/stdc++.h>
using namespace std;
using namespace sf;

int main(){
    //rendering window "window"
    RenderWindow window(VideoMode(800,600), "Quatro game - menu", Style::Default);
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
    //game loop
    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type==Event::Closed){
                window.close();
            }
        }
        window.clear();
        window.draw(backgroundSprite);
        window.display();
    }
}