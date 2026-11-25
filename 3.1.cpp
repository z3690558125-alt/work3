
#include <iostream>
#include <iomanip>
using namespace std;

class Date {
private:
    int year;
    int month;
    int day;

    bool isLeap(int y) const {
        return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
    }

    int getDays(int y, int m) const {
        int days[] = { 0, 31, 28, 31, 30, 31, 30,
                      31, 31, 30, 31, 30, 31 };

        if (m == 2 && isLeap(y))
            return 29;

        return days[m];
    }

    bool isValid(int y, int m, int d) const {
        if (y < 1 || m < 1 || m > 12)
            return false;

        return d >= 1 && d <= getDays(y, m);
    }

public:
    Date(int y = 1900, int m = 1, int d = 1) {
        if (isValid(y, m, d)) {
            year = y;
            month = m;
            day = d;
        }
        else {
            year = 1900;
            month = 1;
            day = 1;
        }
    }

    void Init(int y, int m, int d) {
        if (isValid(y, m, d)) {
            year = y;
            month = m;
            day = d;
        }
        else {
            cout << "日期不合法，已设置为默认日期！" << endl;
            year = 1900;
            month = 1;
            day = 1;
        }
    }

    int getYear() {
        return year;
    }

    int getMonth() {
        return month;
    }

    int getDay() {
        return day;
    }

    void setYear(int y) {
        if (isValid(y, month, day))
            year = y;
        else
            cout << "年份设置失败！" << endl;
    }

    void setMonth(int m) {
        if (isValid(year, m, day))
            month = m;
        else
            cout << "月份设置失败！" << endl;
    }

    void setDay(int d) {
        if (isValid(year, month, d))
            day = d;
        else
            cout << "日期设置失败！" << endl;
    }

    void display() {
        cout << "Date: "
            << setfill('0')
            << setw(4) << year << "-"
            << setw(2) << month << "-"
            << setw(2) << day << endl;
    }

    int calWeekday() {
        int y = year;
        int m = month;
        int d = day;

        if (m == 1 || m == 2) {
            y--;
            m += 12;
        }

        int w = (d + 2 * m + 3 * (m + 1) / 5
            + y + y / 4 - y / 100
            + y / 400 + 1) % 7;

        return w;
    }

    bool isLeapYear() {
        return isLeap(year);
    }

    void nextDay() {
        day++;

        if (day > getDays(year, month)) {
            day = 1;
            month++;

            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }
};

int main() {
    int y, m, d;

    cout << "请输入年月日：";
    cin >> y >> m >> d;

    Date date(y, m, d);

    cout << "\n输出结果：" << endl;

    date.display();

    string weekdays[] = {
        "星期日", "星期一", "星期二",
        "星期三", "星期四", "星期五", "星期六"
    };

    cout << "Weekday: "
        << weekdays[date.calWeekday()] << endl;

    cout << "是否为闰年："
        << (date.isLeapYear() ? "是" : "否") << endl;

    cout << "下一天：" << endl;
    date.nextDay();
    date.display();

    return 0;
}
