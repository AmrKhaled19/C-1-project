//#include "Hittable.h"
//#include <iostream>
//#include <vector>
//#include <random>
//
//enum class GameObjectType { FLYING_TREASURE, FLYING_ENEMY, STANDING_ENEMY, FLYING_HEART };
//enum class TreasureType { GOLD, SILVER, DIAMOND };
//
//class GameObject {
//public:
//    GameObjectType type;
//
//    virtual void hit(int& score, int& lives) = 0;
//};
//
//class FlyingTreasure : public GameObject {
//public:
//    TreasureType treasure_type;
//
//    void hit(int& score, int& lives) override {
//        switch (treasure_type) {
//        case TreasureType::GOLD:
//            score += 10;
//            break;
//        case TreasureType::SILVER:
//            score += 5;
//            break;
//        case TreasureType::DIAMOND:
//            score += 20;
//            break;
//        }
//        std::cout << "Flying treasure hit! Score: " << score << std::endl;
//    }
//};
//
//class FlyingEnemy : public GameObject {
//public:
//    void hit(int& score, int& lives) override {
//        lives--;
//        std::cout << "Flying enemy hit! Lives: " << lives << std::endl;
//    }
//};
//
//class StandingEnemy : public GameObject {
//public:
//    void hit(int& score, int& lives) override {
//        lives--;
//        std::cout << "Standing enemy hit! Lives: " << lives << std::endl;
//    }
//};
//
//class FlyingHeart : public GameObject {
//public:
//    void hit(int& score, int& lives) override {
//        lives++;
//        std::cout << "Flying heart hit! Lives: " << lives << std::endl;
//    }
//};
//
//int main() {
//    // Set up random number generator
//    std::random_device rd;
//    std::mt19937 gen(rd());
//
//    // Set up frequency of appearance for each game object type
//    const int FLYING_TREASURE_FREQ = 3;
//    const int FLYING_ENEMY_FREQ = 2;
//    const int STANDING_ENEMY_FREQ = 1;
//    const int FLYING_HEART_FREQ = 3;
//
//    // Create a vector of all possible flying treasure types
//    std::vector<TreasureType> treasure_types = { TreasureType::GOLD, TreasureType::SILVER, TreasureType::DIAMOND };
//
//    // Create a vector of all possible game objects, with frequency of appearance in proportion to their frequency constants
//    std::vector<GameObject*> game_objects;
//    game_objects.reserve(FLYING_TREASURE_FREQ + FLYING_ENEMY_FREQ + STANDING_ENEMY_FREQ + FLYING_HEART_FREQ);
//
//    // Add flying treasures with random treasure types
//    std::uniform_int_distribution<> treasure_dist(0, treasure_types.size() - 1);
//
//    for (int i = 0; i < FLYING_TREASURE_FREQ; ++i) {
//        FlyingTreasure* treasure = new FlyingTreasure();
//        treasure->type = GameObjectType::FLYING_TREASURE;
//        treasure->treasure_type = treasure_types[treasure_dist(gen)];
//        game_objects.push_back(treasure);
//    }
//
//    // Add flying enemies
//    for (int i = 0; i < FLYING_ENEMY_FREQ; ++i) {
//        FlyingEnemy* enemy = new FlyingEnemy();
//        enemy->type = GameObjectType::FLYING_ENEMY;
//        game_objects.push_back(enemy);
//    }
//
//    // Add standing enemies
//    for (int i = 0; i < STANDING_ENEMY_FREQ; ++i) {
//        StandingEnemy* enemy = new StandingEnemy();
//        enemy->type = GameObjectType::STANDING_ENEMY;
//        game_objects.push_back(enemy);
//    }
//
//    // Add flying hearts
//    for (int i = 0; i < FLYING_HEART_FREQ; ++i) {
//        FlyingHeart* heart = new FlyingHeart();
//        heart->type = GameObjectType::FLYING_HEART;
//        game_objects.push_back(heart);
//    }
//
//    // Shuffle the vector to randomize the order of the game objects
//    std::shuffle(game_objects.begin(), game_objects.end(), gen);
//
//    // Simulate the gameloop
//    bool game_over = false;
//    int score = 0;
//    int lives = 3;
//
//    while (!game_over) {
//        // Get user input for hit position
//        int hit_pos;
//        std::cout << "Enter hit position (0-9): ";
//        std::cin >> hit_pos;
//
//        // Check if any game object is hit at the specified position
//        bool object_hit = false;
//
//        for (GameObject* object : game_objects) {
//            if (object->type == GameObjectType::FLYING_TREASURE || object->type == GameObjectType::FLYING_ENEMY ||
//                object->type == GameObjectType::STANDING_ENEMY || object->type == GameObjectType::FLYING_HEART) {
//                if (hit_pos == gen() % 10) {
//                    object->hit(score, lives);
//                    object_hit = true;
//                    break;
//                }
//            }
//        }
//
//        // Check if the game is over
//        if (lives <= 0) {
//            game_over = true;
//            std::cout << "Game over! Final score: " << score << std::endl;
//        }
//        else {
//            std::cout << "Score: " << score << " Lives: " << lives << std::endl;
//        }
//    }
//
//    // Clean up the dynamically allocated game objects
//    for (GameObject* object : game_objects) {
//        delete object;
//    }
//
//
//
//
//        int score = 0;
//
//        auto start_time = std::chrono::steady_clock::now();
//
//        while (true) {
//            auto current_time = std::chrono::steady_clock::now();
//            auto elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(current_time - start_time).count();
//
//            if (elapsed_time >= 1) {
//                score++;
//                start_time = current_time;
//                std::cout << "Score: " << score << std::endl;
//            }
//
//
//
//    }
//
//    return 0
//}
