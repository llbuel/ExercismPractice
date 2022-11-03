#ifndef ROBOT_SIMULATOR_H
#define ROBOT_SIMULATOR_H

#include <utility>
#include <string>

namespace robot_simulator {

struct Bearing {
private:
    int m_bearing{};

public:
    static const int NORTH;
    static const int SOUTH;
    static const int EAST;
    static const int WEST;

    Bearing(int bearing) { m_bearing = bearing; }

    int getBearing() const { return m_bearing; }
};

class Robot {
private:
    std::pair<int, int> m_startPosition;
    int m_startBearing;
    std::pair<int, int> m_currentPosition;
    int m_currentBearing;

public:
    Robot() : m_startPosition({0, 0}), m_startBearing(Bearing::NORTH), m_currentPosition(m_startPosition), m_currentBearing(m_startBearing) {}
    Robot(std::pair<int, int> startPosition, Bearing startBearing) : m_startPosition(startPosition), m_startBearing(startBearing.getBearing()), m_currentPosition(m_startPosition), m_currentBearing(m_startBearing) {}

    void turn_right();
    void turn_left();
    void advance();
    void execute_sequence(const std::string& movementSequence);
    std::pair<int, int> get_position() const { return m_currentPosition; }
    int get_bearing() const { return m_currentBearing; }

};

}

#endif