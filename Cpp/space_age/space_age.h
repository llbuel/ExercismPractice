#ifndef SPACE_AGE_H
#define SPACE_AGE_H

namespace space_age {

class space_age {
    private:
        long int m_age_seconds;
        double m_age_earth_years;

        const long int m_earth_sec_to_years{31557600};

        const double m_earth_to_mercury{0.2408467};
        const double m_earth_to_venus{0.61519726};
        const double m_earth_to_mars{1.8808158};
        const double m_earth_to_jupiter{11.862615};
        const double m_earth_to_saturn{29.447498};
        const double m_earth_to_uranus{84.016846};
        const double m_earth_to_neptune{164.79132};

    public:
        space_age(long int age);

        void setAge(long int age);
        long int seconds() const { return m_age_seconds; }

        double on_earth() const { return m_age_earth_years; }

        double on_mercury() const { return (m_age_earth_years / m_earth_to_mercury); }
        double on_venus() const { return (m_age_earth_years / m_earth_to_venus); }
        double on_mars() const { return (m_age_earth_years / m_earth_to_mars); }
        double on_jupiter() const { return (m_age_earth_years / m_earth_to_jupiter); }
        double on_saturn() const { return (m_age_earth_years / m_earth_to_saturn); }
        double on_uranus() const { return (m_age_earth_years / m_earth_to_uranus); }
        double on_neptune() const { return (m_age_earth_years / m_earth_to_neptune); }
};

}

#endif