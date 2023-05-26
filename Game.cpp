#include "Game.h"
#include "Dino.h"
#include "Enemy.h"
#include "Super_Enemy.h"
#include "Bullet.h"
#include "Menu.h"

Game::Game( sf::RenderWindow& m_window) : m_running(false) 
{
    // Load sound files
    m_jumpSoundBuffer.loadFromFile("images/audio.ogg");
    m_doubleJumpSoundBuffer.loadFromFile("images/audio.ogg");
    m_duckSoundBuffer.loadFromFile("images/audio.ogg");
    m_enemyHitSoundBuffer.loadFromFile("images/audio.ogg");

    // Set up sounds
    m_jumpSound.setBuffer(m_jumpSoundBuffer);
    m_doubleJumpSound.setBuffer(m_doubleJumpSoundBuffer);
    m_duckSound.setBuffer(m_duckSoundBuffer);
    m_enemyHitSound.setBuffer(m_enemyHitSoundBuffer);
    // Load the background image
    
   
    

}

void Game::start(sf::Sprite background) {
    // In some other class
   
    backgroundImage = background;
    backgroundImage.setScale(1.0f, 1.0f); // Adjust the scale as needed
    sf::Sprite bk ;
    sf::Texture bkk;
    if (!bkk.loadFromFile("images/background.png")) {
        // Handle error
    }


    bk.setTexture(bkk);
    m_window.draw(bk);
    m_window.display();
    m_running = true;
}

void Game::stop() {
    m_running = false;
}

bool Game::isRunning() const {
    return m_running;
}

void Game::processEvents() {
    sf::Event event;
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_window.close();
        }
        else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::W) {

                m_doubleJumpSound.play();
            }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                    
                    m_duckSound.play();
                }
                
            }
            
            
        }
        
    }



void Game::update(  Enemy& enemy, Super_Enemy& superEnemy, Bullet& bullet) {
    
        
        enemy.move();
        superEnemy.move();
        bullet.move();
        
}