#include "meetup.h"

namespace meetup {

boost::gregorian::date scheduler::getDayteenth(boost::gregorian::greg_year year_start, boost::gregorian::greg_month month_start, boost::gregorian::greg_day day_start, short unsigned int dayteenth) const {
    boost::gregorian::day_iterator day_itr(boost::gregorian::date(year_start, month_start, day_start));
    boost::gregorian::date meetupDate{ *day_itr };
    boost::gregorian::gregorian_calendar::day_of_week_type dow_check{ dayteenth };

    boost::gregorian::greg_day dom_check_low = Days::LowTeenthBound;
    boost::gregorian::greg_day dom_check_high = Days::HighTeenthBound;

    while (!((meetupDate.day_of_week() == dow_check) && (meetupDate.day() > dom_check_low) && (meetupDate.day() < dom_check_high))) {
        ++day_itr;
        meetupDate = *day_itr;
    }

    return meetupDate;
}

boost::gregorian::date scheduler::getNDayOfWeek(boost::gregorian::greg_year year_start, boost::gregorian::greg_month month_start, boost::gregorian::greg_day day_start, short unsigned int day_of_week, short unsigned int xday_of_month) const {
    boost::gregorian::day_iterator day_itr(boost::gregorian::date(year_start, month_start, day_start));
    boost::gregorian::week_iterator wk_itr(boost::gregorian::date(year_start, month_start, day_start));
    boost::gregorian::date meetupDate{ *day_itr };
    boost::gregorian::gregorian_calendar::day_of_week_type dow_check = day_of_week;
    int week_check = meetupDate.week_number();
    int week_of_month = meetupDate.week_number() + xday_of_month;

    while (!((meetupDate.day_of_week() == dow_check) && (week_check == week_of_month))) {
        if (meetupDate.day_of_week() != dow_check) {
            ++day_itr;
            meetupDate = *day_itr;
        }
        else if (week_check != week_of_month) {
            ++wk_itr;
            week_check++;
            meetupDate = *wk_itr;
        }
    }

    return meetupDate;
}

boost::gregorian::date scheduler::getLastDayOfMonth(boost::gregorian::greg_year year_start, boost::gregorian::greg_month month_start, boost::gregorian::greg_day day_start, short unsigned int day_of_week) const {
    boost::gregorian::date meetupDate{ boost::gregorian::date(year_start, month_start, day_start) };
    int monthDayEnd{ 0 };

    if (day_of_week > meetupDate.end_of_month().day_of_week()) {
        monthDayEnd = meetupDate.end_of_month().day() - (Days::DaysInWeek - (day_of_week - meetupDate.end_of_month().day_of_week()));
    }
    else {
        monthDayEnd = meetupDate.end_of_month().day() - (meetupDate.end_of_month().day_of_week() - day_of_week);
    }

    return boost::gregorian::date(year_start, month_start, monthDayEnd);
}

}