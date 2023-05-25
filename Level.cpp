#include "Level.h"

Level::Level() : m_level(1) {}

void Level::increment() {
    ++m_level;
}

int Level::getScoreThreshold() const {
    return m_level ;
}

void Level::reset() {
    m_level = 1;
}