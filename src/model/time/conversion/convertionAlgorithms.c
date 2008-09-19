#include <time.h>

#ifndef WIN32
#include <limits.h>
#include <errno.h>
#endif

const int SECSPERDAY = 24 * 60 * 60;
const int SECSPERHOUR = 60 * 60;
const int SECSPERMIN = 60;
const int EPOCH_WDAY = 4;
const int DAYSPERWEEK = 7;
const int EPOCH_YEAR = 1970;
const int DAYSPERNYEAR = 365;
const int __year_lengths[ 2 ] = { 365, 366 };
#define isleap(y) (((y) % 4) == 0 && (((y) % 100) != 0 || ((y) % 400) == 0))
#define LEAPS_THRU_END_OF(y) ((y) / 4 - (y) / 100 + (y) / 400)
const int TM_YEAR_BASE = 1900;
const int __mon_lengths[ 2 ][ 12 ] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
                                       31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
                                     };
static struct tm *offtime_u(time_t, long, struct tm *);

extern long timezone;

struct tm *
_gmtime_r(const time_t *timep, struct tm *p_tm)
{
	tzset();
    return (offtime_u((time_t)*timep, 0L, p_tm));
}

struct tm *
_localtime_r(const time_t *timep, struct tm *p_tm)
{
    struct tm *rt;

	tzset();
    rt = offtime_u(*timep, - timezone, p_tm);
    return (rt);
}


static struct tm *
offtime_u(time_t t, long offset, struct tm *tmptr)
{
    long        days;
    long        rem;
    long        y;
    int     yleap;
    const int   *ip;

    days = t / SECSPERDAY;
    rem = t % SECSPERDAY;
    rem += offset;
    while (rem < 0) {
        rem += SECSPERDAY;
        --days;
    }
    while (rem >= SECSPERDAY) {
        rem -= SECSPERDAY;
        ++days;
    }
    tmptr->tm_hour = (int)(rem / SECSPERHOUR);
    rem = rem % SECSPERHOUR;
    tmptr->tm_min = (int)(rem / SECSPERMIN);
    tmptr->tm_sec = (int)(rem % SECSPERMIN);

    tmptr->tm_wday = (int)((EPOCH_WDAY + days) % DAYSPERWEEK);
    if (tmptr->tm_wday < 0)
        tmptr->tm_wday += DAYSPERWEEK;
    y = EPOCH_YEAR;
    while (days < 0 || days >= (long)__year_lengths[yleap = isleap(y)]) {
        long newy;

        newy = y + days / DAYSPERNYEAR;
        if (days < 0)
            --newy;
        days -= ((long)newy - (long)y) * DAYSPERNYEAR +
            LEAPS_THRU_END_OF(newy > 0 ? newy - 1L : newy) -
            LEAPS_THRU_END_OF(y > 0 ? y - 1L : y);
        y = newy;
    }
    tmptr->tm_year = (int)(y - TM_YEAR_BASE);
    tmptr->tm_yday = (int)days;
    ip = __mon_lengths[yleap];
    for (tmptr->tm_mon = 0; days >=
        (long)ip[tmptr->tm_mon]; ++(tmptr->tm_mon))
            days = days - (long)ip[tmptr->tm_mon];
    tmptr->tm_mday = (int)(days + 1);
    tmptr->tm_isdst = 0;

#ifdef _LP64
    /* do as much as possible before checking for error. */
    if ((y > (long)INT_MAX + TM_YEAR_BASE) ||
        (y < (long)INT_MIN + TM_YEAR_BASE)) {
        errno = EOVERFLOW;
        return (NULL);
    }
#endif
    return (tmptr);
}
