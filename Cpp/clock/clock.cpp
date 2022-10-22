#include "clock.h"

namespace date_independent {

std::string clock::at::createString(int hour, int minute) {
    if (minute < 0) {
        while (minute < 0) {
            minute += 60;
            hour -= 1;
        }
    }
    
    if (hour < 0) {
        while (hour < 0) {
            hour += 24;
        }
    }

    if (minute > 59) {
        while (minute > 59) {
            minute -= 60;
            hour += 1;
        }
    }
    
    if (hour > 23) {
        while (hour > 23) {
            hour -= 24;
        }
    }
    
    m_hour = hour;
    m_minute = minute;

    std::string hourStr{ std::to_string(hour) };
    std::string minuteStr{ std::to_string(minute) };

    if (hourStr.length() == 1) {
        hourStr = "0"+hourStr;
    }

    if (minuteStr.length() == 1) {
        minuteStr = "0"+minuteStr;
    }

    m_thisTime = hourStr+":"+minuteStr;
    return m_thisTime;
}

std::string clock::at::plus(int minutes) {
    std::string newTime;

    m_minute += minutes;

    newTime = createString(m_hour, m_minute);

    m_thisTime = newTime;
    return m_thisTime;
}

clock::at::operator std::string() const {
        std::string time = m_thisTime;
        return time;
}

bool clock::at::operator==(const at& rhs) const {
    return m_thisTime == rhs.m_thisTime;
}

bool clock::at::operator!=(const at& rhs) const {
    return m_thisTime != rhs.m_thisTime;
}

}