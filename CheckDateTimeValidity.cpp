void Check_within_the_boundaries(int value, std::string_view name, int left_border, int right_border) {
    if (value < left_border) {
        throw domain_error(name + " is too small"s);
    }
    if (value > right_border) {
        throw domain_error(name + " is too big"s);
    }
}

void CheckDateTimeValidity(const DateTime& dt) {
    using namespace std::literals;
    static const int MIN_YEAR = 1;
    static const int MAX_YEAR = 9999;
    static const int MIN_MONTH = 1;
    static const int MAX_MONTH = 12;
    static const int MIN_DAY = 1;
    static const int MIN_HOUR = 0;
    static const int MAX_HOUR = 23;
    static const int MIN_MINUTE = 0;
    static const int MAX_MINUTE = 59;
    static const int MIN_SECOND = 0;
    static const int MAX_SECOND = 59;

    Check_within_the_boundaries(dt.year, "year"sv, MIN_YEAR, MAX_YEAR);
    Check_within_the_boundaries(dt.month, "month"sv, MIN_MONTH, MAX_MONTH);

    const bool is_leap_year = (dt.year % 4 == 0) && !(dt.year % 100 == 0 && dt.year % 400 != 0);
    const array month_lengths = { 31, 28 + is_leap_year, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    Check_within_the_boundaries(dt.day, "day"sv, MIN_DAY, month_lengths[dt.month - 1]);
    Check_within_the_boundaries(dt.hour, "hour"sv, MIN_HOUR, MAX_HOUR);
    Check_within_the_boundaries(dt.minute, "minute"sv, MIN_MINUTE, MAX_MINUTE);
    Check_within_the_boundaries(dt.second, "second"sv, MIN_SECOND, MAX_SECOND);

    
}
