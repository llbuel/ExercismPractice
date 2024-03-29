#ifndef GIGASECOND_H
#define GIGASECOND_H

#include "boost/date_time/posix_time/posix_time.hpp"
#include <string>

namespace gigasecond {

boost::posix_time::ptime advance(boost::posix_time::ptime input);

}

#endif
