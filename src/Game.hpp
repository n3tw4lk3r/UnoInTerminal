#pragma once

#include <chrono>
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <thread>
#include <vector>

#include "Card.hpp"
#include "Player.hpp"
#include "utils.hpp"

class Game {
public:
    explicit Game(size_t cnt, size_t delay);

private:
    constexpr static size_t kMinPlayersNumber = 2;
    constexpr static size_t kMaxPlayersNumber = 10;

    const size_t kDelay;
    const size_t kPlayersCnt;
    const size_t kUserIdx;

    size_t currentPlayerIdx;
    bool directionIsReversed;
    bool drawsTwo;
    bool drawsFour;
    bool skips;

    std::vector<Card> drawPile;
    std::vector<Card> discardPile;
    std::vector<std::shared_ptr<Player>> players;

    void startNewGame();
    void fillPile();
    void shufflePile();
    void dealCards();
    void printGameInfo();
    void printUno();
    void printGameOver();
    void nextPlayer();
    bool tryNextMove();
    Card takeCardFromDrawPile();
};
