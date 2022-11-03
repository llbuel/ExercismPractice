#include "robot_simulator.h"

namespace robot_simulator {

const int Bearing::NORTH{100};
const int Bearing::SOUTH{101};
const int Bearing::EAST{110};
const int Bearing::WEST{111};

void Robot::turn_right() {
    switch (m_currentBearing) {
        case Bearing::NORTH:
            m_currentBearing = Bearing::EAST;
            break;
        case Bearing::EAST:
            m_currentBearing = Bearing::SOUTH;
            break;
        case Bearing::SOUTH:
            m_currentBearing = Bearing::WEST;
            break;
        case Bearing::WEST:
            m_currentBearing = Bearing::NORTH;
            break;
    }
}

void Robot::turn_left() {
    switch (m_currentBearing) {
        case Bearing::NORTH:
            m_currentBearing = Bearing::WEST;
            break;
        case Bearing::WEST:
            m_currentBearing = Bearing::SOUTH;
            break;
        case Bearing::SOUTH:
            m_currentBearing = Bearing::EAST;
            break;
        case Bearing::EAST:
            m_currentBearing = Bearing::NORTH;
            break;
    }
}

void Robot::advance() {
    switch (m_currentBearing) {
        case Bearing::NORTH:
            m_currentPosition.second += 1;
            break;
        case Bearing::EAST:
            m_currentPosition.first += 1;
            break;
        case Bearing::SOUTH:
            m_currentPosition.second -= 1;
            break;
        case Bearing::WEST:
            m_currentPosition.first -= 1;
            break;
    }
}

void Robot::execute_sequence(const std::string& movementSequence) {
    for(std::size_t i = 0; i < movementSequence.size(); ++i) {
        switch (movementSequence[i]) {
            case 'R':
                turn_right();
                break;
            case 'L':
                turn_left();
                break;
            case 'A':
                advance();
                break;
            default:
                break;
        }
    }
}

}