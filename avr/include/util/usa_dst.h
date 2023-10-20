#ifndef USA_DST_H
#define USA_DST_H
#ifdef __cplusplus
extern "C" {
#endif
#include <time.h>
#include <inttypes.h>
#ifndef DST_START_MONTH
#define DST_START_MONTH MARCH
#endif
#ifndef DST_END_MONTH
#define DST_END_MONTH NOVEMBER
#endif
#ifndef DST_START_WEEK
#define DST_START_WEEK 2
#endif
#ifndef DST_END_WEEK
#define DST_END_WEEK 1
#endif
    int usa_dst(const time_t * timer, int32_t * z) {
        time_t t;
        struct tm tmptr;
        uint8_t month, week, hour, day_of_week, d;
        int n;
                        t = *timer + *z;
                        gmtime_r(&t, &tmptr);
                        month = tmptr.tm_mon;
                        day_of_week = tmptr.tm_wday;
                        week = week_of_month(&tmptr, 0);
                        hour = tmptr.tm_hour;
        if ((month > DST_START_MONTH) && (month < DST_END_MONTH))
                            return ONE_HOUR;
        if (month < DST_START_MONTH)
                            return 0;
        if (month > DST_END_MONTH)
                            return 0;
        if (month == DST_START_MONTH) {
            if (week < DST_START_WEEK)
                return 0;
            if (week > DST_START_WEEK)
                return ONE_HOUR;
            if (day_of_week > SUNDAY)
                return ONE_HOUR;
            if (hour >= 2)
                return ONE_HOUR;
            return 0;
        }
        if (week > DST_END_WEEK)
                            return 0;
        if (week < DST_END_WEEK)
                            return ONE_HOUR;
        if (day_of_week > SUNDAY)
                            return 0;
        if (hour >= 1)
                            return 0;
                        return ONE_HOUR;
    }
#ifdef __cplusplus
}
#endif
#endif
