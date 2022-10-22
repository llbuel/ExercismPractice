#ifndef PHONE_NUMBER_H
#define PHONE_NUMBER_H

#include <string>
#include <stdexcept>

namespace phone_number {

class phone_number {
private:
    std::string numberStr_;
    std::string areaCode_;
    std::string number_;
    mutable std::string formattedNumber_;

    std::string parseNumber(std::string input);
    void setFormattedNumber(std::string input) const;

public:
    phone_number(std::string numberStr);

    std::string number() const { return number_; }
    std::string area_code() const { return areaCode_; }

    operator std::string() const;

};

}

#endif