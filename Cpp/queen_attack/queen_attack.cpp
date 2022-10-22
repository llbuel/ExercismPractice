#include "queen_attack.h"

namespace queen_attack {

chess_board::chess_board() : m_whitePos(std::make_pair(0, 3)), m_blackPos(std::make_pair(7, 3)) {}

chess_board::chess_board(const std::pair<int, int> whitePos, const std::pair<int, int> blackPos) :
    m_whitePos(whitePos), m_blackPos(blackPos) {
    if (whitePos == blackPos) {
        throw std::domain_error("Queen positions must be different.");
    }
}
    
std::pair<int, int> chess_board::white() const{
    return m_whitePos;
}

std::pair<int, int> chess_board::black() const{
    return m_blackPos;
}

bool chess_board::can_attack() const{
    if ((white().first == black().first) || (white().second == black().second)) {
        return true;
    }
    else if (((black().second - white().second) / (black().first - white().first) == 1) || ((black().second - white().second) / (black().first - white().first) == -1)) {
        return true;
    }
    else {
        return false;
    }
}

chess_board::operator std::string() const {
    std::string board_layout{ "_ _ _ _ _ _ _ _\n"
                              "_ _ _ _ _ _ _ _\n"
                              "_ _ _ _ _ _ _ _\n"
                              "_ _ _ _ _ _ _ _\n"
                              "_ _ _ _ _ _ _ _\n"
                              "_ _ _ _ _ _ _ _\n"
                              "_ _ _ _ _ _ _ _\n"
                              "_ _ _ _ _ _ _ _\n" };

    int whiteQ_row = m_whitePos.first;
    int whiteQ_col = m_whitePos.second;
    int whiteQ_pos = (16 * whiteQ_row) + (2 * whiteQ_col);

    int blackQ_row = m_blackPos.first;
    int blackQ_col = m_blackPos.second;
    int blackQ_pos = (16 * blackQ_row) + (2 * blackQ_col);

    board_layout.replace(whiteQ_pos, 1, "W");
    board_layout.replace(blackQ_pos, 1, "B");

    return board_layout;
}

}