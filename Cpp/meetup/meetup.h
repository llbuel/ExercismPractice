#ifndef MEETUP_H
#define MEETUP_H

#include <boost/date_time/gregorian/gregorian.hpp>

namespace meetup {

struct Days {
    static const short unsigned int FirstDayOfMonth      = 1U;
    
    static const short unsigned int Sunday               = 0U;
    static const short unsigned int Monday               = 1U;
    static const short unsigned int Tuesday              = 2U;
    static const short unsigned int Wednesday            = 3U;
    static const short unsigned int Thursday             = 4U;
    static const short unsigned int Friday               = 5U;
    static const short unsigned int Saturday             = 6U;

    static const short unsigned int LowTeenthBound      = 12U;
    static const short unsigned int HighTeenthBound     = 20U;

    static const short unsigned int FirstDayOfWeek       = 1U;
    static const short unsigned int SecondDayOfWeek      = 2U;
    static const short unsigned int ThirdDayOfWeek       = 3U;
    static const short unsigned int FourthDayOfWeek      = 4U;

    static const short unsigned int FirstXOfMonth        = 0U;
    static const short unsigned int SecondXOfMonth       = 1U;
    static const short unsigned int ThirdXOfMonth        = 2U;
    static const short unsigned int FourthXOfMonth       = 3U;

    static const short unsigned int DaysInWeek           = 7U;
};

class scheduler {
private:
    const boost::gregorian::date firstDateofMonth_;
    boost::gregorian::date meetupDate_;

public:
    scheduler(boost::gregorian::greg_month month, int year) : firstDateofMonth_(year, month, Days::FirstDayOfMonth) {}

    boost::gregorian::date getDayteenth(boost::gregorian::greg_year year_start, boost::gregorian::greg_month month_start, boost::gregorian::greg_day day_start, short unsigned int dayteenth) const;
    boost::gregorian::date getNDayOfWeek(boost::gregorian::greg_year year_start, boost::gregorian::greg_month month_start, boost::gregorian::greg_day day_start, short unsigned int day_of_week, short unsigned int xday_of_month) const;
    boost::gregorian::date getLastDayOfMonth(boost::gregorian::greg_year year_start, boost::gregorian::greg_month month_start, boost::gregorian::greg_day day_start, short unsigned int day_of_week) const;

    boost::gregorian::date sunteenth() const { return (getDayteenth(firstDateofMonth_.year(), firstDateofMonth_.month(), firstDateofMonth_.day(), Days::Sunday)); }
    boost::gregorian::date monteenth() const { return (getDayteenth(firstDateofMonth_.year(), firstDateofMonth_.month(), firstDateofMonth_.day(), Days::Monday)); }
    boost::gregorian::date tuesteenth() const { return (getDayteenth(firstDateofMonth_.year(), firstDateofMonth_.month(), firstDateofMonth_.day(), Days::Tuesday)); }
    boost::gregorian::date wednesteenth() const { return (getDayteenth(firstDateofMonth_.year(), firstDateofMonth_.month(), firstDateofMonth_.day(), Days::Wednesday)); }
    boost::gregorian::date thursteenth() const { return (getDayteenth(firstDateofMonth_.year(), firstDateofMonth_.month(), firstDateofMonth_.day(), Days::Thursday)); }
    boost::gregorian::date friteenth() const { return (getDayteenth(firstDateofMonth_.year(), firstDateofMonth_.month(), firstDateofMonth_.day(), Days::Friday)); }
    boost::gregorian::date saturteenth() const { return (getDayteenth(firstDateofMonth_.year(), firstDateofMonth_.month(), firstDateofMonth_.day(), Days::Saturday)); }

    boost::gregorian::date first_sunday() const { return (getNDayOfWeek(firstDateofMonth_.year(), firstDateofMonth_.month(), firstDateofMonth_.day(), Days::Sunday, Days::FirstXOfMonth)); }
    boost::gregorian::date first_monday() const { return (getNDayOfWeek(firstDateofMonth_.year(), firstDateofMonth_.month(), firstDateofMonth_.day(), Days::Monday, Days::FirstXOfMonth)); }
    boost::gregorian::date first_tuesday() const { return (getNDayOfWeek(firstDateofMonth_.year(), firstDateofMonth_.month(), firstDateofMonth_.day(), Days::Tuesday, Days::FirstXOfMonth)); }
    boost::gregorian::date first_wednesday() const { return (getNDayOfWeek(firstDateofMonth_.year(), firstDateofMonth_.month(), firstDateofMonth_.day(), Days::Wednesday, Days::FirstXOfMonth)); }
    boost::gregorian::date first_thursday() const { return (getNDayOfWeek(firstDateofMonth_.year(), firstDateofMonth_.month(), firstDateofMonth_.day(), Days::Thursday, Days::FirstXOfMonth)); }
    boost::gregorian::date first_friday() const { return (getNDayOfWeek(firstDateofMonth_.year(), firstDateofMonth_.month(), firstDateofMonth_.day(), Days::Friday, Days::FirstXOfMonth)); }
    boost::gregorian::date first_saturday() const { return (getNDayOfWeek(firstDateofMonth_.year(), firstDateofMonth_.month(), firstDateofMonth_.day(), Days::Saturday, Days::FirstXOfMonth)); }

    boost::gregorian::date second_sunday() const { return (getNDayOfWeek(firstDateofMonth_.year(), firstDateofMonth_.month(), firstDateofMonth_.day(), Days::Sunday, Days::SecondXOfMonth)); }
    boost::gregorian::date second_monday() const { return (getNDayOfWeek(firstDateofMonth_.year(), firstDateofMonth_.month(), firstDateofMonth_.day(), Days::Monday, Days::SecondXOfMonth)); }
    boost::gregorian::date second_tuesday() const { return (getNDayOfWeek(firstDateofMonth_.year(), firstDateofMonth_.month(), firstDateofMonth_.day(), Days::Tuesday, Days::SecondXOfMonth)); }
    boost::gregorian::date second_wednesday() const { return (getNDayOfWeek(firstDateofMonth_.year(), firstDateofMonth_.month(), firstDateofMonth_.day(), Days::Wednesday, Days::SecondXOfMonth)); }
    boost::gregorian::date second_thursday() const { return (getNDayOfWeek(firstDateofMonth_.year(), firstDateofMonth_.month(), firstDateofMonth_.day(), Days::Thursday, Days::SecondXOfMonth)); }
    boost::gregorian::date second_friday() const { return (getNDayOfWeek(firstDateofMonth_.year(), firstDateofMonth_.month(), firstDateofMonth_.day(), Days::Friday, Days::SecondXOfMonth)); }
    boost::gregorian::date second_saturday() const { return (getNDayOfWeek(firstDateofMonth_.year(), firstDateofMonth_.month(), firstDateofMonth_.day(), Days::Saturday, Days::SecondXOfMonth)); }
    
    boost::gregorian::date third_sunday() const { return (getNDayOfWeek(firstDateofMonth_.year(), firstDateofMonth_.month(), firstDateofMonth_.day(), Days::Sunday, Days::ThirdXOfMonth)); }
    boost::gregorian::date third_monday() const { return (getNDayOfWeek(firstDateofMonth_.year(), firstDateofMonth_.month(), firstDateofMonth_.day(), Days::Monday, Days::ThirdXOfMonth)); }
    boost::gregorian::date third_tuesday() const { return (getNDayOfWeek(firstDateofMonth_.year(), firstDateofMonth_.month(), firstDateofMonth_.day(), Days::Tuesday, Days::ThirdXOfMonth)); }
    boost::gregorian::date third_wednesday() const { return (getNDayOfWeek(firstDateofMonth_.year(), firstDateofMonth_.month(), firstDateofMonth_.day(), Days::Wednesday, Days::ThirdXOfMonth)); }
    boost::gregorian::date third_thursday() const { return (getNDayOfWeek(firstDateofMonth_.year(), firstDateofMonth_.month(), firstDateofMonth_.day(), Days::Thursday, Days::ThirdXOfMonth)); }
    boost::gregorian::date third_friday() const { return (getNDayOfWeek(firstDateofMonth_.year(), firstDateofMonth_.month(), firstDateofMonth_.day(), Days::Friday, Days::ThirdXOfMonth)); }
    boost::gregorian::date third_saturday() const { return (getNDayOfWeek(firstDateofMonth_.year(), firstDateofMonth_.month(), firstDateofMonth_.day(), Days::Saturday, Days::ThirdXOfMonth)); }

    boost::gregorian::date fourth_sunday() const { return (getNDayOfWeek(firstDateofMonth_.year(), firstDateofMonth_.month(), firstDateofMonth_.day(), Days::Sunday, Days::FourthXOfMonth)); }
    boost::gregorian::date fourth_monday() const { return (getNDayOfWeek(firstDateofMonth_.year(), firstDateofMonth_.month(), firstDateofMonth_.day(), Days::Monday, Days::FourthXOfMonth)); }
    boost::gregorian::date fourth_tuesday() const { return (getNDayOfWeek(firstDateofMonth_.year(), firstDateofMonth_.month(), firstDateofMonth_.day(), Days::Tuesday, Days::FourthXOfMonth)); }
    boost::gregorian::date fourth_wednesday() const { return (getNDayOfWeek(firstDateofMonth_.year(), firstDateofMonth_.month(), firstDateofMonth_.day(), Days::Wednesday, Days::FourthXOfMonth)); }
    boost::gregorian::date fourth_thursday() const { return (getNDayOfWeek(firstDateofMonth_.year(), firstDateofMonth_.month(), firstDateofMonth_.day(), Days::Thursday, Days::FourthXOfMonth)); }
    boost::gregorian::date fourth_friday() const { return (getNDayOfWeek(firstDateofMonth_.year(), firstDateofMonth_.month(), firstDateofMonth_.day(), Days::Friday, Days::FourthXOfMonth)); }
    boost::gregorian::date fourth_saturday() const { return (getNDayOfWeek(firstDateofMonth_.year(), firstDateofMonth_.month(), firstDateofMonth_.day(), Days::Saturday, Days::FourthXOfMonth)); }

    boost::gregorian::date last_sunday() const { return (getLastDayOfMonth(firstDateofMonth_.year(), firstDateofMonth_.month(), firstDateofMonth_.day(), Days::Sunday)); }
    boost::gregorian::date last_monday() const { return (getLastDayOfMonth(firstDateofMonth_.year(), firstDateofMonth_.month(), firstDateofMonth_.day(), Days::Monday)); }
    boost::gregorian::date last_tuesday() const { return (getLastDayOfMonth(firstDateofMonth_.year(), firstDateofMonth_.month(), firstDateofMonth_.day(), Days::Tuesday)); }
    boost::gregorian::date last_wednesday() const { return (getLastDayOfMonth(firstDateofMonth_.year(), firstDateofMonth_.month(), firstDateofMonth_.day(), Days::Wednesday)); }
    boost::gregorian::date last_thursday() const { return (getLastDayOfMonth(firstDateofMonth_.year(), firstDateofMonth_.month(), firstDateofMonth_.day(), Days::Thursday)); }
    boost::gregorian::date last_friday() const { return (getLastDayOfMonth(firstDateofMonth_.year(), firstDateofMonth_.month(), firstDateofMonth_.day(), Days::Friday)); }
    boost::gregorian::date last_saturday() const { return (getLastDayOfMonth(firstDateofMonth_.year(), firstDateofMonth_.month(), firstDateofMonth_.day(), Days::Saturday)); }
};

}

#endif