#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int monthDay[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Calendar
{
public:
    int date, month, reminded;
    string eventName;

    int checkDate, checkMonth;

    Calendar(int _date, int _month, int _reminded, string _eventName)
    {
        date = _date;
        month = _month;
        reminded = _reminded;
        eventName = _eventName;

        checkDate = date - reminded;
        checkMonth = month;

        if (checkDate <= 0)
        {
            checkMonth--;
            checkDate = monthDay[checkMonth - 1] + checkDate;
        }
    }

    bool operator<(const Calendar &other) const
    {
        if (month == other.month)
        {
            if (date == other.date)
                return reminded < other.reminded;
            else
                return date < other.date;
        }
        else
            return month < other.month;
    }

    bool isNeedChecked(int _date, int _month)
    {
        if (_month <= month && _month >= checkMonth)
            return _date <= date && _date >= checkDate;

        return false;
    }

    bool isNeedPrint(int _date, int _month)
    {
    }
};

int main()
{
    int year;
    scanf("%d\n", &year);

    if (year % 4 == 0)
        monthDay[1] = 29;

    vector<Calendar> vecCalendar;
    char input;

    int date, month, reminded;
    char eventName[256];

    while (scanf("%c", &input) && input != '#')
    {
        if (input == 'A')
        {
            scanf("%d %d %d %[^\n]\n", &date, &month, &reminded, &eventName);
            vecCalendar.push_back(Calendar(date, month, reminded, eventName));
        }
        else if (input == 'D')
        {
            sort(vecCalendar.begin(), vecCalendar.end());
            scanf("%d %d", &date, &month);

            printf("Today is: %d %d\n", date, month);
            int i, len = vecCalendar.size();

            for (i = 0; i < len; i++)
                if (vecCalendar[i].isNeedChecked(date, month))
                    break;

            for (; i < len; i++)
            {
                if (vecCalendar[i].isNeedChecked(date, month))
                {
                    int many = vecCalendar[i].reminded - (vecCalendar[i].date - date) + 1;
                    string temp = "*";
                    for (int j = 1; j < many; j++)
                        temp += "*";

                    if (date == vecCalendar[i].date && month == vecCalendar[i].month)
                        temp = "*TODAY*";

                    printf(" %d %d %s %s\n", vecCalendar[i].date, vecCalendar[i].month, temp.c_str(), vecCalendar[i].eventName.c_str());
                }
            }

            printf("\n");
        }
    }
    // for (int i = 0; i < vecCalendar.size(); i++)
    // {
    //     printf("(%d %d - %d %d) %d %s\n", vecCalendar[i].checkDate, vecCalendar[i].checkMonth, vecCalendar[i].date, vecCalendar[i].month, vecCalendar[i].reminded, vecCalendar[i].eventName.c_str());
    // }
}