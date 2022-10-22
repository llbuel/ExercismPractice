#ifndef QUEEN_ATTACK_H
#define QUEEN_ATTACK_H

#include <stdexcept>
#include <string>

namespace queen_attack {

class chess_board {
private:
    const std::pair<int, int> m_whitePos;
    const std::pair<int, int> m_blackPos;
    const std::string m_board_pic;

public:
    chess_board();
    chess_board(const std::pair<int, int> whitePos, const std::pair<int, int> blackPos);
    
    std::pair<int, int> white() const;
    std::pair<int, int> black() const;
    bool can_attack() const;

    explicit operator std::string() const;
};

}

#endif