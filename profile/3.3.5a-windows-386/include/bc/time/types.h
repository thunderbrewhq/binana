#ifndef BC_TIME_TYPES_H
#define BC_TIME_TYPES_H

// TimeRec
DECLARE_STRUCT(Blizzard__Time__TimeRec);

// TimeRec
struct Blizzard__Time__TimeRec {
    int32_t year;
    int32_t month;
    int32_t day;
    int32_t hour;
    int32_t minute;
    int32_t second;
    int32_t nanosecond;
    int32_t dayOfWeek;
    int32_t dayOfYear;
};

// UnixTime
typedef int32_t Blizzard__Time__UnixTime;

// Timestamp
typedef int64_t Blizzard__Time__Timestamp;

// Second
typedef uint32_t Blizzard__Time__Second;

// Millisecond
typedef uint32_t Bizzard__Time__Millisecond;

// Microsecond
typedef uint64_t Blizzard__Time__Microsecond;

// Nanosecond
typedef uint64_t Blizzard__Time__Nanosecond;

#endif
