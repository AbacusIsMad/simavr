#ifndef EU_DST_H
#define EU_DST_H
#ifdef __cplusplus
extern "C" {
#endif
#include <time.h>
#include <inttypes.h>
    int eu_dst(const time_t * timer, int32_t * z) {
        struct tm tmptr;
        uint8_t month, mday, hour, day_of_week, d;
        int n;
                        gmtime_r(timer, &tmptr);
                        month = tmptr.tm_mon;
                        day_of_week = tmptr.tm_wday;
                        mday = tmptr.tm_mday - 1;
                        hour = tmptr.tm_hour;
        if ((month > MARCH) && (month < OCTOBER))
                            return ONE_HOUR;
        if (month < MARCH)
                            return 0;
        if (month > OCTOBER)
                            return 0;
                        n = tmptr.tm_mday - 1;
                        n -= day_of_week;
                        n += 7;
                        d = n % 7;
                        n = 31 - d;
                        n /= 7;
                        d = d + 7 * n;
        if (month == MARCH) {
            if (d < mday)
                return 0;
            if (d > mday)
                return ONE_HOUR;
            if (hour < 2)
                return 0;
            return ONE_HOUR;
        }
        if (d < mday)
                            return ONE_HOUR;
        if (d > mday)
                            return 0;
        if (hour < 2)
                            return ONE_HOUR;
                        return 0;
    }
#ifdef __cplusplus
}
#endif
#endif
