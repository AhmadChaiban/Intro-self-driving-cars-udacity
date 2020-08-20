"""
Days Between Dates

This lesson will focus on one problem: calculating the number of days between two dates.

"""

def check_if_leap_year(year):
    if year%400==0 or year%100!=0 and year%4==0:
        return True
    return False

def year_sequence_day_extraction(year_sequence):
    total = 0
    for year in year_sequence:
        if check_if_leap_year(year):
            total += 366
        else:
            total += 365
    return total

def get_days_from_years_inbetween_dates(year_diff, year1):
    if year_diff > 0:
        year_sequence = []
        for i in range(1, year_diff):
            year_sequence.append(year1 + i)
        return year_sequence_day_extraction(year_sequence)
    else:
        return 0

def get_days_current_years(month, year):
    total = 0
    for i in range(1, month):
        if i%2 == 1 and i < 8:
            total += 31
        elif i%2 == 0 and i<8:
            if i == 2 and check_if_leap_year(year):
                total += 29
            elif i==2 and check_if_leap_year(year) == False:
                total += 28
            else:
                total += 30
        elif i%2 == 0 and i>=8:
            total+=31
        elif i%2 == 1 and i>=8:
            total+=30
        else:
            raise Exception('Invalid argument somewhere')

    return total


def daysBetweenDates(year1, month1, day1, year2, month2, day2):

    """
    Calculates the number of days between two dates.

    """
    total_days = 0

    total_days += get_days_from_years_inbetween_dates(year2-year1, year1)

    day_diff_1 = year_sequence_day_extraction([year1]) - get_days_current_years(month1, year1) - day1

    if year2 - year1 > 0:
        day_acc_2 = get_days_current_years(month2, year2) + day2
        total_days = total_days +  day_diff_1 + day_acc_2
    else:
        day_acc_2 =  get_days_current_years(month2, year2) + day2 - get_days_current_years(month1, year1) - day1
        total_days = total_days + day_acc_2

    return total_days

def testDaysBetweenDates():
    # test same day
    assert(daysBetweenDates(2017, 12, 30,
                            2017, 12, 30) == 0)
    # test adjacent days
    assert(daysBetweenDates(2017, 12, 30,
                            2017, 12, 31) == 1)
    # test new year
    assert(daysBetweenDates(2017, 12, 30,
                            2018, 1,  1)  == 2)
    # test full year difference
    assert(daysBetweenDates(2012, 6, 29,
                            2013, 6, 29)  == 365)

    assert(daysBetweenDates(2017, 2, 20,
                            2023, 10, 31) == 2444)

    assert(daysBetweenDates(2017, 8, 30,
                            2017, 12, 31) == 123)

    print("Congratulations! Your daysBetweenDates")
    print("function is working correctly!")

if __name__ == '__main__':
    testDaysBetweenDates()
