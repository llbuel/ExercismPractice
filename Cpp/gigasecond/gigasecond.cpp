#include "gigasecond.h"

namespace gigasecond {

boost::posix_time::ptime advance(boost::posix_time::ptime input) {
    boost::posix_time::time_duration time_added(boost::posix_time::hours(277777)+boost::posix_time::minutes(46)+boost::posix_time::seconds(40));
    boost::posix_time::ptime new_time = input + time_added;

    return new_time;
}

}