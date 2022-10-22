#ifndef CLOCK_H
#define CLOCK_H

#include <string>

namespace date_independent {
namespace clock {

class at {
private:
    std::string m_thisTime;
    int m_hour;
    int m_minute;

    std::string createString(int hour, int minute);

public:
    at(int hour, int minute) { createString(hour, minute); }

    std::string plus(int minutes);

    operator std::string() const;
    bool operator==(const at& rhs) const;
    bool operator!=(const at& rhs) const;

};

}
}

#endif
