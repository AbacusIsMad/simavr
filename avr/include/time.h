#ifndef TIME_H
#define TIME_H
#ifdef __cplusplus
extern "C" {
#endif
#include <inttypes.h>
#include <stdlib.h>
    typedef uint32_t time_t;
    time_t time(time_t *timer);
    int32_t difftime(time_t time1, time_t time0);
    struct tm {
        int8_t tm_sec;
        int8_t tm_min;
        int8_t tm_hour;
        int8_t tm_mday;
        int8_t tm_wday;
        int8_t tm_mon;
        int16_t tm_year;
        int16_t tm_yday;
        int16_t tm_isdst;
    };
#ifndef __DOXYGEN__
    typedef unsigned long clock_t;
    extern char *_CLOCKS_PER_SEC_;
#define CLOCKS_PER_SEC ((clock_t) _CLOCKS_PER_SEC_)
    extern clock_t clock(void);
#endif
    time_t mktime(struct tm * timeptr);
    time_t mk_gmtime(const struct tm * timeptr);
    struct tm *gmtime(const time_t * timer);
    void gmtime_r(const time_t * timer, struct tm * timeptr);
    struct tm *localtime(const time_t * timer);
    void localtime_r(const time_t * timer, struct tm * timeptr);
    char *asctime(const struct tm * timeptr);
    void asctime_r(const struct tm * timeptr, char *buf);
    char *ctime(const time_t * timer);
    void ctime_r(const time_t * timer, char *buf);
    char *isotime(const struct tm * tmptr);
    void isotime_r(const struct tm *, char *);
    size_t strftime(char *s, size_t maxsize, const char *format, const struct tm * timeptr);
    void set_dst(int (*) (const time_t *, int32_t *));
    void set_zone(int32_t);
    void set_system_time(time_t timestamp);
    void system_tick(void);
    enum _WEEK_DAYS_ {
        SUNDAY,
        MONDAY,
        TUESDAY,
        WEDNESDAY,
        THURSDAY,
        FRIDAY,
        SATURDAY
    };
    enum _MONTHS_ {
        JANUARY,
        FEBRUARY,
        MARCH,
        APRIL,
        MAY,
        JUNE,
        JULY,
        AUGUST,
        SEPTEMBER,
        OCTOBER,
        NOVEMBER,
        DECEMBER
    };
    uint8_t is_leap_year(int16_t year);
    uint8_t month_length(int16_t year, uint8_t month);
    uint8_t week_of_year(const struct tm * timeptr, uint8_t start);
    uint8_t week_of_month(const struct tm * timeptr, uint8_t start);
    struct week_date {
        int year;
        int week;
        int day;
    };
    struct week_date * iso_week_date( int year, int yday);
    void iso_week_date_r( int year, int yday, struct week_date *);
    uint32_t fatfs_time(const struct tm * timeptr);
#define ONE_HOUR 3600
#define ONE_DEGREE 3600
#define ONE_DAY 86400
#define UNIX_OFFSET 946684800
#define NTP_OFFSET 3155673600
    void set_position(int32_t latitude, int32_t longitude);
    int16_t equation_of_time(const time_t * timer);
    int32_t daylight_seconds(const time_t * timer);
    time_t solar_noon(const time_t * timer);
    time_t sun_rise(const time_t * timer);
    time_t sun_set(const time_t * timer);
    double solar_declination(const time_t * timer);
    int8_t moon_phase(const time_t * timer);
    unsigned long gm_sidereal(const time_t * timer);
    unsigned long lm_sidereal(const time_t * timer);
#ifdef __cplusplus
}
#endif
#endif
