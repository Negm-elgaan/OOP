// ClsDate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//my ClsDate project not Abu
#pragma warning(disable : 4996)

#include <iostream>
#include <ctime>
#include <string>
#include <vector>
using namespace std;
class ClsDate
{
        short _Day;
        short _Month;
        short _Year;
        vector <string> SplitString(string S1, string Delim)
        {
            vector <string> vString;
            short pos = 0;
            string sWord; // define a string variable
            // use find() function to get the position of the delimiters
            while ((pos = S1.find(Delim)) != std::string::npos)
            {
                sWord = S1.substr(0, pos); // store the word
                if (sWord != "")
                {
                    vString.push_back(sWord);
                }
                S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
            }
            if (S1 != "")
            {
                vString.push_back(S1); // it adds last word of the string.
            }
            return vString;
        }
        short ReadYear()
        {
            short Year;
            cout << "\nPlease enter a year to check? ";
            cin >> Year;
            return Year;
        }
        short ReadMonth()
        {
            short Month;
            cout << "\nPlease enter a Month to check? ";
            cin >> Month;
            return Month;
        }
        short ReadDay()
        {
            short day = 0;
            cout << "\nPlease enter a day to check? ";
            cin >> day;
            return day;
        }
    public:
        ClsDate()
        {
            time_t t = time(0);
            tm* now = localtime(&t);
            _Day = now->tm_mday;
            _Month = now->tm_mon + 1;
            _Year = now->tm_year + 1900;
        }
        ClsDate(short Day, short Month, short Year)
        {
            _Day = Day;
            _Month = Month;
            _Year = Year;
        }
        ClsDate(string date)
        {
            vector <string> Vdate = SplitString(date,"/");
            _Day = stoi(Vdate[0]);
            _Month = stoi(Vdate[1]);
            _Year = stoi(Vdate[2]);
        }
        ClsDate(short day, short year)
        {
            GetDateFromDayOrderInYear(day, year);
            return;
        }
        /*void GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
        {
            short RemainingDays = DateOrderInYear;
            short MonthDays = 0;
            _Year = Year;
            _Month = 1;
            while (true)
            {
                MonthDays = NumberOfDaysInAMonth(_Month, _Year);
                if (RemainingDays > MonthDays)
                {
                    RemainingDays -= MonthDays;
                    _Month++;
                }
                else
                {
                    _Day = RemainingDays;
                    break;
                }
            }
            return;
        }*/
        void Print()
        {
            cout << _Day << "/" << _Month << "/" << _Year << endl;
        }
        static bool isLeapYear(short Year)
        {
            return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
        }
        bool isLeapYear()
        {
            return isLeapYear(_Year);
        }
        static short NumberOfDaysInAMonth(short Month, short Year)
        {
            if (Month < 1 || Month > 12)
                return  0;
            int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
            return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
        }
        short NumberOfDaysInAMonth()
        {
            return NumberOfDaysInAMonth(_Month, _Year);
        }
        static short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
        {
            short TotalDays = 0;
            for (int i = 1; i <= Month - 1; i++)
            {
                TotalDays += NumberOfDaysInAMonth(i, Year);
            }
            TotalDays += Day;
            return TotalDays;
        }
        short NumberOfDaysFromTheBeginingOfTheYear()
        {
            return NumberOfDaysFromTheBeginingOfTheYear(_Day, _Month, _Year);
        }
        static short DayOfWeekOrder(short Day, short Month, short Year)
        {
            short a, y, m;
            a = (14 - Month) / 12;
            y = Year - a;
            m = Month + (12 * a) - 2;
            // Gregorian://0:sun, 1:Mon, 2:Tue...etc
            return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
        }
        short DayOfWeekOrder()
        {
            return DayOfWeekOrder(_Day, _Month, _Year);
        }
        static string DayShortName(short DayOfWeekOrder)
        {
            string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
            return arrDayNames[DayOfWeekOrder];
        }
        string DayShortName()
        {
            return DayShortName(DayOfWeekOrder());
        }
        static string MonthShortName(short MonthNumber)
        {
            string Months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
            return (Months[MonthNumber - 1]);
        }
        string MonthShortName()
        {
            return MonthShortName(_Month);
        }
        static void PrintMonthCalendar(short Month, short Year)
        {
            int NumberOfDays; // Index of the day from 0 to 6
            int current = DayOfWeekOrder(1, Month, Year);
            NumberOfDays = NumberOfDaysInAMonth(Month, Year);
            // Print the current month name
            printf("\n  _______________%s_______________\n\n", MonthShortName(Month).c_str());
            // Print the columns
            printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
            // Print appropriate spaces
            int i;
            for (i = 0; i < current; i++)
                printf("     ");
            for (int j = 1; j <= NumberOfDays; j++)
            {
                printf("%5d", j);
                if (++i == 7)
                {
                    i = 0;
                    printf("\n");
                }
            }
            printf("\n  _________________________________\n");
        }
        void PrintMonthCalender()
        {
            return PrintMonthCalendar(_Month, _Year);
        }
        static void PrintYearCalendar(int Year)
        {
            printf("\n  _________________________________\n\n");
            printf("           Calendar - %d\n", Year);
            printf("  _________________________________\n");
            for (int i = 1; i <= 12; i++)
            {
                PrintMonthCalendar(i, Year);
            }
            return;
        }
        void PrintYearCalender()
        {
            return PrintYearCalendar(_Year);
        }
        static short DaysPassed(short day , short month  , short year)
        {
            short DaysPasssed = 0 ;
            for (short i = 1 ; i < month ; i++)
            DaysPasssed += NumberOfDaysInAMonth(i,year);
        return DaysPasssed + day ;
        }
        short DaysPassed()
        {
            return DaysPassed(_Day, _Month, _Year);
        }
        static ClsDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
        {
            ClsDate Date;
            short RemainingDays = DateOrderInYear;
            short MonthDays = 0;
            Date._Year = Year;
            Date._Month = 1;
            while (true)
            {
                MonthDays = NumberOfDaysInAMonth(Date._Month, Year);
                if (RemainingDays > MonthDays)
                {
                    RemainingDays -= MonthDays;
                    Date._Month++;
                }
                else
                {
                    Date._Day = RemainingDays;
                    break;
                }
            }
            return Date;
        }
        ClsDate GetDateFromDayOrderInYear(short DateOrderInYear)
        {
            return GetDateFromDayOrderInYear(DateOrderInYear,_Year);
        }
        static ClsDate GetNewDateAfterAddingDays(int days, short day , short month , short year)
        {
            ClsDate date ;
            float remdays = 0 ;
            short yearstoadd = 0 ;
            float remaining = days ;
            while (true)
            {
                if (remaining >= 365.25)
            {
                yearstoadd++ ;
                remaining -= 365.25 ;
            }
            else
            {
                remdays = DaysPassed(day,month,year) + remaining ;
                if (remdays >= 365.25)
                {
                    yearstoadd++ ;
                    remdays -= 365.25 ;
                }
                if (remdays == 0)
                    remdays++;
                break ;
            }
        }
        date = GetDateFromDayOrderInYear(remdays , year + yearstoadd) ;
        return date ;
        }
        ClsDate GetDateFromDayOrderInYear(int days)
        {
            return GetNewDateAfterAddingDays(days, _Day, _Month, _Year);
        }
        /*static ClsDate ReadDate()
        {
            ClsDate Date;
            Date._Day = ReadDay();
            Date._Month = ReadMonth();
            Date._Year = ReadYear();
            return Date;
        }*/
    static bool CheckDates1(ClsDate Date1 , ClsDate Date2)
    {
        return (Date2._Year > Date1._Year) || (Date2._Month > Date1._Month && Date2._Year == Date1._Year) || (Date2._Day > Date1._Day && Date2._Month == Date1._Month && Date2._Year == Date1._Year);
    }
    bool CheckDates1(ClsDate Date2)
    {
        return CheckDates1(*this, Date2);
    }
    static bool IsDate1BeforeDate2(ClsDate Date1, ClsDate Date2)
    {
        return  (Date1._Year < Date2._Year) ? true : ((Date1._Year == Date2._Year) ? (Date1._Month < Date2._Month ? true : (Date1._Month == Date2._Month ? Date1._Day < Date2._Day : false)) : false);
    }
    bool IsDate1BeforeDate2(ClsDate Date2)
    {
        return IsDate1BeforeDate2(*this, Date2);
    }
    static bool CheckDateEquailty1(ClsDate Date1 , ClsDate Date2)
    {
        return (Date1._Year == Date2._Year && Date1._Month == Date2._Month && Date1._Day == Date2._Day) ;
    }
    bool CheckDateEquailty1(ClsDate Date2)
    {
        return CheckDateEquailty1(*this, Date2);
    }
    static bool CheckDateEquailty2(ClsDate Date1 , ClsDate Date2)
    {
        return (Date1._Year == Date2._Year) ? (Date1._Month == Date2._Month ? (Date1._Day == Date2._Day ? true : false) : false) : false ;
    }
    bool CheckDateEquailty2(ClsDate Date2)
    {
        return CheckDateEquailty2(*this, Date2);
    }
    static bool IsDate1EqualDate2(ClsDate Date1, ClsDate Date2)
    {
        return (Date1._Year == Date2._Year) ? ((Date1._Month == Date2._Month) ? ((Date1._Day == Date2._Day) ? true : false) : false) : false;
    }
    static bool IsDateLastDayInMonth(ClsDate date)
    {
        short numofdays = NumberOfDaysInAMonth(date._Month,date._Year);
        return date._Day == numofdays;
    }
    bool IsDateLastDayInMonth()
    {
        return IsDateLastDayInMonth(*this);
    }
    static bool IsDateLastMonthInYear(ClsDate date)
    {
        return date._Month == 12;
    }
    bool IsDateLastMonthInYear()
    {
        return IsDateLastMonthInYear(*this);
    }
    static bool IsLastDayInMonth(ClsDate Date)
    {
        return (Date._Day == NumberOfDaysInAMonth(Date._Month, Date._Year));
    }
    bool IsLastDayInMonth()
    {
        return IsLastDayInMonth(*this);
    }
    static bool IsLastMonthInYear(short Month)
    {
        return (Month == 12);
    }
    bool IsLastMonthInYear()
    {
        return IsLastMonthInYear(_Month);
    }
    static ClsDate AddOneDayToDate(ClsDate date)
    {
        short num = NumberOfDaysInAMonth(date._Month,date._Year);
        if (++date._Day > num)
        {
            date._Day = 1 ;
            date._Month++;
        }
        if(date._Month > 12)
        {
            date._Month = 1 ;
            date._Year++;
        }
        return date;
    }
    static ClsDate IncreaseDateByOneDay(ClsDate Date)
    {
        if (IsLastDayInMonth(Date))
        {
            if (IsLastMonthInYear(Date._Month))
            {
                Date._Month = 1;
                Date._Day = 1;
                Date._Year++;
            }
            else
            {
                Date._Day = 1; Date._Month++;
            }
        }
        else
        {
            Date._Day++;
        }
        return Date;
    }
    ClsDate IncreaseDateByOneDay()
    {
        return IncreaseDateByOneDay(*this);
    }
    static int DifferenceBetweenDates(ClsDate Date1  , ClsDate Date2)
    {
        short Date2Days = DaysPassed(Date2._Day , Date2._Month , Date2._Year);
        short rem = 0 ;
        if (Date1._Year == Date2._Year)
        {
            return rem = DaysPassed(Date2._Day , Date2._Month , Date2._Year) - DaysPassed(Date1._Day , Date1._Month , Date1._Year);
        }
        else
        {
            while (Date2._Year-- > Date1._Year)
            {
                if (isLeapYear(Date2._Year))
                    rem += 366;
                else
                    rem += 365;
            }
            return (rem = rem + Date2Days) - DaysPassed(Date1._Day , Date1._Month , Date1._Year);
        }
    }
    int DifferenceBetweenDates(ClsDate Date2)
    {
        return DifferenceBetweenDates(*this, Date2);
    }
    static int DifferenceBetweenDates2(ClsDate Date1  , ClsDate Date2)
    {
        if(CheckDates1(Date1,Date2))
            return DifferenceBetweenDates(Date1,Date2);
        return DifferenceBetweenDates2(Date2,Date1) * -1 ;
    }
    int DifferenceBetweenDates2(ClsDate Date2)
    {
        return DifferenceBetweenDates2(*this, Date2);
    }
    static void  SwapDates(ClsDate Date1, ClsDate Date2)
    {
        ClsDate TempDate;
        TempDate._Year = Date1._Year;
        TempDate._Month = Date1._Month;
        TempDate._Day = Date1._Day;
        Date1._Year = Date2._Year;
        Date1._Month = Date2._Month;
        Date1._Day = Date2._Day;
        Date2._Year = TempDate._Year;
        Date2._Month = TempDate._Month;
        Date2._Day = TempDate._Day;
    }
    void SwapDates(ClsDate Date2)
    {
        return SwapDates(*this, Date2);
    }
    static int GetDifferenceInDays(ClsDate Date1, ClsDate Date2, bool IncludeEndDay = false)
    {
        int Days = 0;
        short SawpFlagValue = 1;
        if (!IsDate1BeforeDate2(Date1, Date2))
        {
            //Swap Dates
            SwapDates(Date1, Date2);
            SawpFlagValue = -1;
        }
        while(IsDate1BeforeDate2(Date1, Date2))
        {
             Days++;
            Date1 = IncreaseDateByOneDay(Date1);
        }
        return IncludeEndDay ? ++Days * SawpFlagValue : Days * SawpFlagValue;
    }
    int GetDifferenceInDays(ClsDate Date2)
    {
        return GetDifferenceInDays(*this, Date2);
    }
    static int GetAgeInDays(ClsDate Date , ClsDate CurrentDate)
    {
        int Age = 0 ;
        short days = 0 ;
        if (Date._Year == CurrentDate._Year)
            return Age = DaysPassed(Date._Day , Date._Month , Date._Year) ;
        if (isLeapYear(Date._Year))
            days = 366 - DaysPassed(Date._Day , Date._Month , Date._Year);
        else
            days = 365 - DaysPassed(Date._Day , Date._Month , Date._Year);
        while(Date._Year++ < CurrentDate._Year)
        {
            if (Date._Year == CurrentDate._Year)
            {
                Age += DaysPassed(CurrentDate._Day , CurrentDate._Month , CurrentDate._Year) + days;
                return Age ;
            }
            if (isLeapYear(Date._Year))
                Age += 366;
            else
                Age += 365 ;
        }
        Age += days ;
        return Age ;
    }
    int GetAgeInDays(ClsDate Date)
    {
        return GetAgeInDays(Date, *this);
    }
    ClsDate ReadFullDate()
    {
        ClsDate Date;
        Date._Day = ReadDay();
        Date._Month = ReadMonth();
        Date._Year = ReadYear();
        return Date;
    }
    static ClsDate IncreaseDateByOneWeek(ClsDate Date)
    {
        for (int i = 1; i <= 7; i++)
        {
            Date = IncreaseDateByOneDay(Date);
        }
        return Date;
    }
    ClsDate IncreaseDateByOneWeek()
    {
        return IncreaseDateByOneWeek(*this);
    }
    static ClsDate IncreaseDateByXWeeks(short Weeks, ClsDate Date)
    {
        for (short i = 1; i <= Weeks; i++)
        {
            Date = IncreaseDateByOneWeek(Date);
        }
        return Date;
    }
    ClsDate IncreaseDateByXWeeks(short weeks)
    {
        return IncreaseDateByXWeeks(weeks,*this);
    }
    static ClsDate IncreaseDateByOneMonth(ClsDate Date)
    {
        if (Date._Month == 12)
        {
            Date._Month = 1;
            Date._Year++;
        }
        else
        {
            Date._Month++;
        } //last check day in date should not exceed max days in the current month// example if date is 31/1/2022 increasing one month should not be 31/2/2022, it should// be 28/2/2022
        short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date._Month, Date._Year);
        if (Date._Day > NumberOfDaysInCurrentMonth)
        {
            Date._Day = NumberOfDaysInCurrentMonth;
        }
        return Date;
    }
    ClsDate IncreaseDateByOneMonth()
    {
        return IncreaseDateByOneMonth(*this);
    }
    static ClsDate IncreaseDateByXDays(short Days, ClsDate Date)
    {
        for (short i = 1; i <= Days; i++)
        {
            Date = IncreaseDateByOneDay(Date);
        }
        return Date;
    }
    ClsDate IncreaseDateByXDays(short Days)
    {
      return IncreaseDateByXDays(Days,*this) ;
    }
    static ClsDate IncreaseDateByXMonths(short Months, ClsDate Date)
    {
        for (short i = 1; i <= Months; i++)
        {
            Date = IncreaseDateByOneMonth(Date);
        }
        return Date;
    }
    ClsDate IncreaseDateByXMonths(short Months)
    {
        return IncreaseDateByXMonths(Months, *this);
    }
    static ClsDate IncreaseDateByOneYear(ClsDate Date)
    {
        Date._Year++;
        return Date;
    }
    ClsDate IncreaseDateByOneYear()
    {
        return IncreaseDateByOneYear(*this);
    }
    static ClsDate IncreaseDateByXYears(short Years, ClsDate Date)
    {
        for (short i = 1; i <= Years; i++)
        {
            Date = IncreaseDateByOneYear(Date);
        }
        return Date;
    }
    ClsDate IncreaseDateByXYears(short Years)
    {
        return IncreaseDateByXYears(Years, *this);
    }
    static ClsDate IncreaseDateByXYearsFaster(short Years, ClsDate Date)
    {
        Date._Year += Years;
        return Date;
    }
    ClsDate IncreaseDateByXYearsFaster(short Years)
    {
        return IncreaseDateByXYearsFaster(Years, *this);
    }
    static ClsDate IncreaseDateByOneDecade(ClsDate Date)
    {
        //Period of 10years
        Date._Year += 10;
        return Date;
    }
    ClsDate IncreaseDateByOneDecade()
    {
        return IncreaseDateByOneDecade(*this);
    }
    static ClsDate IncreaseDateByXDecades(short Decade, ClsDate Date)
    {
        for (short i = 1; i <= Decade * 10; i++)
        {
            Date = IncreaseDateByOneYear(Date);
        }
        return Date;
    }
    ClsDate IncreaseDateByXDecades(short Decades)
    {
        return IncreaseDateByXDecades(Decades, *this);
    }
    static ClsDate IncreaseDateByXDecadesFaster(short Decade, ClsDate Date)
    {
        Date._Year += Decade * 10;
        return Date;
    }
    ClsDate IncreaseDateByXDecadesFaster(short Decades)
    {
        return IncreaseDateByXDecadesFaster(Decades, *this);
    }
    static ClsDate IncreaseDateByOneCentury(ClsDate Date)
    {
        //Period of 100 years
        Date._Year += 100;
        return Date;
    }
    ClsDate IncreaseDateByOneCentury()
    {
        return IncreaseDateByOneCentury(*this);
    }
    static ClsDate IncreaseDateByOneMillennium(ClsDate Date)
    {
        //Period of 1000 years
        Date._Year += 1000;
        return Date;
    }
    ClsDate IncreaseDateByOneMillennium()
    {
        return IncreaseDateByOneMillennium(*this);
    }
    static ClsDate SubXDaysFromDate(short DaysToSubFrom , ClsDate Date)
    {
        short days = DaysPassed(Date._Day,Date._Month,Date._Year) ;
        if (days < DaysToSubFrom)
        {
            while(days <= DaysToSubFrom)
            {
                Date._Year-- ;
                if(isLeapYear(Date._Year))
                    days += 366;
                else
                    days += 365;
            }
            days -= DaysToSubFrom;
        }
        else
            days -= DaysToSubFrom;
        Date = GetDateFromDayOrderInYear(days,Date._Year);
        return Date;
    }
    ClsDate SubXDaysFromDate(short Days)
    {
        return SubXDaysFromDate(Days, *this);
    }
    static short NumberOfDaysInAYear(short Year)
    {
        return  isLeapYear(Year) ? 366 : 365;
    }
    short NumberOfDaysInYear()
    {
        return NumberOfDaysInAYear(_Year);
    }
    static string GetDayName(short DayOrder)
    {
        string arr[7] = { "Sunday" , "Monday" , "Tuesday" , "Wednesday" , "Thursday" , "Friday" , "Saturday"} ;
        return arr[DayOrder];
    }
    string GetDayName()
    {
        GetDayName(_Day);
    }
    static bool IsEndOfWeek0(ClsDate date)
    {
        if (date.DayOfWeekOrder() == 6)
            return true ;
        return false ;
    }
    bool IsEndOfWeek0()
    {
        return IsEndOfWeek0(*this);
    }
    static bool IsEndOfWeek1(ClsDate date)
    {
        return (date.DayOfWeekOrder() == 6) ? true : false ;
    }
    bool IsEndOfWeek1()
    {
        return IsEndOfWeek1(*this);
    }
    static bool IsWeekend0(ClsDate date)
    {
        if (date.DayOfWeekOrder() == 5 || date.DayOfWeekOrder() == 6)
            return true ;
        return false ;
    }
    bool IsWeekend0()
    {
        return IsWeekend0(*this);
    }
    static bool IsWeekend1(ClsDate date)
    {
        return (date.DayOfWeekOrder() == 5) ? true : date.DayOfWeekOrder() == 6 ? true : false ;
    }
    bool IsWeekend1()
    {
        return IsWeekend1(*this);
    }
    static bool IsBusinessDay(ClsDate date)
    {
        if (!IsWeekend0(date))
            return true ;
        return false ;
    }
    bool IsBusinessDay()
    {
        return IsBusinessDay(*this);
    }
    static short DaysUntilEndofWeek(ClsDate date)
    {
        return 6 - date.DayOfWeekOrder();
    }
    short DaysUntilEndofWeek()
    {
        return DaysUntilEndofWeek(*this);
    }
    static short DaysUntilEndOfMonth(ClsDate date)
    {
        return NumberOfDaysInAMonth(date._Month , date._Year) - (date._Day - 1) ;
    }

    static short DaysUntilEndOfYear(ClsDate date)
    {
        return NumberOfDaysInAYear(date._Year) - (DaysPassed(date._Day , date._Month , date._Year) - 1);
    }
    string DayShortName(short DayOfWeekOrder)
    {
        string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
        return arrDayNames[DayOfWeekOrder];
    }
    short IsEndOfWeek(ClsDate Date)
    {
        return  Date.DayOfWeekOrder() == 6;
    }
    /*bool IsWeekEnd(stDate Date)
    { //Weekends are Fri and Sat
        short DayIndex = DayOfWeekOrder(Date);
        return  (DayIndex == 5 || DayIndex == 6);
    }
    bool IsBusinessDay(stDate Date)
    {
        //Weekends are Sun,Mon,Tue,Wed and Thur
        /*
        short DayIndex = DayOfWeekOrder(Date);
        return  (DayIndex >= 5 && DayIndex <= 4);
        */

        //shorter method is to invert the IsWeekEnd: this will save updating code.
    /*return !IsWeekEnd(Date);
    }*/
    static short CalculateVacationDays(ClsDate DateFrom, ClsDate DateTo)
    {
        short DaysCount = 0;
        while (IsDate1BeforeDate2(DateFrom, DateTo))
        {
            if (IsBusinessDay(DateFrom))
                DaysCount++;
            DateFrom = IncreaseDateByOneDay(DateFrom);
        }
        return DaysCount;
    }
    static ClsDate ReturnDate(short VacationDays, ClsDate start)
    {
        while (VacationDays != 0)
        {
            if (IsBusinessDay(start))
                VacationDays--;
            IncreaseDateByOneDay(start);
        }
        return start;
    }
    static ClsDate CalculateVacationReturnDate(ClsDate DateFrom, short VacationDays)
    {
        short WeekEndCounter = 0;
        //in case the data  is weekend keep adding one day util you reach business day
        //we get rid of all weekends before the first business day
        while (DateFrom.IsWeekend1())
        {
            DateFrom = IncreaseDateByOneDay(DateFrom);
        }
        //here we increase the vacation dates to add all weekends to it.
        for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
        {
            if (DateFrom.IsWeekend1())
                WeekEndCounter++;
            DateFrom = IncreaseDateByOneDay(DateFrom);
        }
        //in case the return date is week end keep adding one day util you reach business day
        while (DateFrom.IsWeekend1())
        {
            DateFrom = IncreaseDateByOneDay(DateFrom);
        }
        return DateFrom;
    }
    static short ReadVacationDays()
    {
        short Days;
        cout << "\nPlease enter vacation days? ";
        cin >> Days;
        return Days;
    }
    static bool IsDate1AfterDate2S(ClsDate Date1, ClsDate Date2)
    {
        return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
    }
    static bool IsDate1AfterDate2(ClsDate Date1, ClsDate Date2)
    {
        return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
    }
    bool IsDate1AfterDate2(ClsDate Date2)
    {
        return IsDate1AfterDate2(*this, Date2);
    }
    static short compare(ClsDate Date1, ClsDate Date2)
    {
        if (IsDate1BeforeDate2(Date1, Date2))
            return -1;
        if (IsDate1EqualDate2(Date1, Date2))
            return 0;
        return 1;
    }
    static enum enDateCompare { Before = -1, Equal = 0, After = 1 };
    static enDateCompare CompareDates(ClsDate Date1, ClsDate Date2)
    {
        if (IsDate1BeforeDate2(Date1, Date2))
            return enDateCompare::Before;
        if (IsDate1EqualDate2(Date1, Date2))
            return enDateCompare::Equal;
    /*  if (IsDate1AfterDate2(Date1,Date2))
            return enDateCompare::After;*/
            //this is faster
        return enDateCompare::After;
    }
    enDateCompare CompareDates(ClsDate Date2)
    {
        return CompareDates(*this, Date2);
    }
    static ClsDate DecreaseDateByOneDay(ClsDate Date)
    {
        if (Date._Day == 1)
        {
            if (Date._Month == 1)
            {
                Date._Month = 12;
                Date._Day = 31;
                Date._Year--;
            }
            else
            {
                Date._Month--;
                Date._Day = NumberOfDaysInAMonth(Date._Month, Date._Year);
            }
        }
        else
        {
            Date._Day--;
        }
        return Date;
    }
    static ClsDate DecreaseDateByOneWeek(ClsDate Date)
    {
        for (int i = 1; i <= 7; i++)
        {
            Date = DecreaseDateByOneDay(Date);
        }
        return Date;
    }
    static ClsDate DecreaseDateByXWeeks(short Weeks, ClsDate Date)
    {
        for (short i = 1; i <= Weeks; i++)
        {
            Date = DecreaseDateByOneWeek(Date);
        }
        return Date;
    }
    static ClsDate DecreaseDateByOneMonth(ClsDate Date)
    {
        if (Date._Month == 1)
        {
            Date._Month = 12;
            Date._Year--;
        }
        else
            Date._Month--;
            //last check day in date should not exceed max days in the current month
            // example if date is 31/3/2022 decreasing one month should not be 31/2/2022, it should// be 28/2/2022
        short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date._Month, Date._Year);
        if (Date._Day > NumberOfDaysInCurrentMonth)
        {
            Date._Day = NumberOfDaysInCurrentMonth;
        }
        return Date;
    }
    static ClsDate DecreaseDateByXDays(short Days, ClsDate Date)
    {
        for (short i = 1; i <= Days; i++)
        {
            Date = DecreaseDateByOneDay(Date);
        }
        return Date;
    }
    static ClsDate DecreaseDateByXMonths(short Months, ClsDate Date)
    {
        for (short i = 1; i <= Months; i++)
        {
            Date = DecreaseDateByOneMonth(Date);
        }
        return Date;
    }
    static ClsDate DecreaseDateByOneYear(ClsDate Date)
    {
        Date._Year--;
        return Date;
    }
    static ClsDate DecreaseDateByXYears(short Years, ClsDate Date)
    {
        for (short i = 1; i <= Years; i++)
        {
            Date = DecreaseDateByOneYear(Date);
        }
        return Date;
    }
    static ClsDate DecreaseDateByXYearsFaster(short Years, ClsDate Date)
    {
        Date._Year -= Years;
        return Date;
    }
    static ClsDate DecreaseDateByOneDecade(ClsDate Date)
    {
        //Period of 10 years
        Date._Year -= 10;
        return Date;
    }
    static ClsDate DecreaseDateByXDecades(short Decade, ClsDate Date)
    {
        for (short i = 1; i <= Decade * 10; i++)
        {
            Date = DecreaseDateByOneYear(Date);
        }
        return Date;
    }
    ClsDate DecreaseDateByXDecades(short decade)
    {
        return DecreaseDateByXDecades(decade,*this);
    }
    static ClsDate DecreaseDateByXDecadesFaster(short Decade, ClsDate Date)
    {
        Date._Year -= Decade * 10;
        return Date;
    }
    ClsDate DecreaseDateByXDecadesFaster(short D)
    {
        return DecreaseDateByXDecades(D, *this);
    }
    static ClsDate DecreaseDateByOneCentury(ClsDate Date)
    {
        //Period of 100 years
        Date._Year -= 100;
        return Date;
    }
    ClsDate DecreaseDateByOneCentury()
    {
        return DecreaseDateByOneCentury(*this);
    }
    static ClsDate DecreaseDateByOneMillennium(ClsDate Date)
    {
        //Period of 1000 years
        Date._Year -= 1000;
        return Date;
    }
    ClsDate DecreaseDateByOneMillennium()
    {
        return DecreaseDateByOneMillennium(*this);
    }
};
int main()
{
    ClsDate Date1(168, 2024);
    Date1.Print();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
