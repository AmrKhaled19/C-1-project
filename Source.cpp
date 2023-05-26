#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;

#include "Character.h"
#include "Game.h"
#include "Menu.h"
#include "Dino.h"
#include "Enemy.h"
#include "Super_Enemy.h"
#include "Bullet.h"
#include "Scoreboard.h"
#include "GameOver.h"
#include "Level.h"
#include "Profile.h"


enum class GameState {
    StartingScreen,
    ChooseProfile,
    Menu,
    difficultyselection,
    ScenerySelection,
    CharacterSelection,
    Howtoplay,
    Playing,
    GameOver
};
int main()
{
    // Create game window
    sf::RenderWindow window(sf::VideoMode(1500, 1000), "Dino Game");
    sf::Texture Background;
    Background.loadFromFile("images/background.png");
    sf::Sprite background;
    background.setTexture(Background);
    // Load game resources
    sf::Music music;
    if (!music.openFromFile("images/audio.ogg")) {
        // Handle error
    }
    
    // Create game objects
   
    Clock clock;
    Menu menu(window, music, Background); 
    Game game(window);
    Dino dino;
    Enemy enemy;
    Super_Enemy superEnemy;
    Bullet bullet;
    Scoreboard scoreboard;
    GameOver gameOver(window);
    Level level;

    // Initialize game state
    GameState gameState = GameState::StartingScreen;

    // Game loop
    music.play();
    while (window.isOpen()) {
        switch (gameState) {
        case GameState::StartingScreen:
            window.clear();
            menu.processEvents1();
            menu.displayStartingScreen();
            if (!menu.isStartingScreenVisible()) {
                gameState = GameState::Menu;
            }
            break;

        case GameState::Menu:
            window.clear();
            window.draw(background);
            menu.displayMenu();
            menu.processEvents();
            if (menu.isOptionSelected()) {
                gameState = GameState::difficultyselection;
                menu.hide();
            }
            break;

        case GameState::difficultyselection:
            window.clear();
            menu.selectDifficulty();
            if (menu.isDifficultySelected()) {
                gameState = GameState::ScenerySelection;
            }
            else if (menu.isOptionSelected() == false)
            {
                

                gameState = GameState::Menu;
                
            }
            break;
        

        case GameState::ScenerySelection:
            window.clear();
            menu.ScenerySelection(window);
            if (menu.isScenerySelected()) {
                gameState = GameState::CharacterSelection;
            }
            break;

        case GameState::CharacterSelection:
            window.clear();
            menu.CharacterSelection(window);
            if (menu.isCharacterSelected()) {
                gameState = GameState::Howtoplay;
                menu.HowToPlay(window);
            }
            break;
        case GameState::Howtoplay:
            window.clear();
            menu.HowToPlay(window);
            if (menu.ishowtoplay()) {
                gameState = GameState::ChooseProfile;
                sf::Sprite background = menu.getBackground();
                game.start(background);
            }
            break;
        case GameState::ChooseProfile:
            window.clear();
            menu.displayProfileMenu();
            menu.processEvents_d();
            if (!menu.UserSelected()) {
                gameState = GameState::Playing;
                menu.hide();
            }
            break;
        case GameState::Playing:
            window.clear();
            
            dino.draw(window, menu.getchar());
            game.start(background);
            game.processEvents();
            dino.move();
            enemy.move();
            superEnemy.move();
            bullet.move();
            if (dino.isCollidingWith(enemy.getSprite()) || dino.isCollidingWith(superEnemy.getSprite())) {
                enemy.hit();
                superEnemy.hit();
                bullet.reset();
                scoreboard.incrementScore();
                game.update(enemy, superEnemy, bullet);
            }

            if (scoreboard.getScore() >= level.getScoreThreshold()) {
                level.increment();
                enemy.increaseSpeed();
                superEnemy.increaseSpeed();
                superEnemy.changeSize();
            }
            game.update(enemy, superEnemy, bullet);
            dino.draw(window, menu.getchar());
            enemy.draw(window);
            superEnemy.draw(window);
            bullet.draw(window);
            scoreboard.draw(window);
            break;

        case GameState::GameOver:
            window.clear();
            gameOver.processEvents();
            gameOver.display();
            if (gameOver.isRestartSelected()) {
                gameOver.hide();
                scoreboard.reset();
                level.reset();
                enemy.reset();
                superEnemy.reset();
                sf::Sprite background = menu.getBackground();
                game.start(background);
                gameState = GameState::Playing;
            }
            break;
        }
        window.display();
    }
    return 0;
}
