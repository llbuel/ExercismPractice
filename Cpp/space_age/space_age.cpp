#include "space_age.h"

namespace space_age {

space_age::space_age(long int age){
    setAge(age);
}

void space_age::setAge(long int age){
    m_age_seconds = age;
    m_age_earth_years = (double)m_age_seconds / m_earth_sec_to_years;
}

}