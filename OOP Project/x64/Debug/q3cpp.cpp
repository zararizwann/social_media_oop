#include <iostream>
using namespace std;

class CalendarDate {
private:
    int day;
    int month;
    int year;

    // checks if year is leap yeaar
    bool isLeapYear(int y) const {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }


    int daysInMonth(int m, int y) const {     // returns days in month m of year y
        if (m == 2)
            return isLeapYear(y) ? 29 : 28; // feb
        if (m == 4 || m == 6 || m == 9 || m == 11)
            return 30; // apr,jun,sep,nov
        return 31; // all other months
    }

   
    bool isValid(int d, int m, int y) const { // checks if the given date is valid
        if (y < 1) return false;
        if (m < 1 || m > 12) return false;
        if (d < 1 || d > daysInMonth(m, y)) return false;
        return true;
    }

                        // resets date to default 01-01-2000
    void resetToDefault() {
        day = 1;
        month = 1;
        year = 2000;
    }

    // convert current date to total days from 01-01-2000
    int toTotalDays() const {
        int totalDays = 0;
        for (int y = 2000; y < year; y++)
            totalDays += isLeapYear(y) ? 366 : 365; // add year days
        for (int m = 1; m < month; m++)
            totalDays += daysInMonth(m, year); // add month days
        totalDays += day - 1; // add day
        return totalDays;
    }

    
    void fromTotalDays(int totalDays) {// sets date from total days since 01-01-2000
        year = 2000;
        month = 1;
        day = 1;

        while (true) { // handle year
            int daysThisYear = isLeapYear(year) ? 366 : 365;
            if (totalDays < daysThisYear) break;
            totalDays -= daysThisYear;
            year++;
        }
        while (true) { // handle month
            int daysThisMonth = daysInMonth(month, year);
            if (totalDays < daysThisMonth) break;
            totalDays -= daysThisMonth;
            month++;
        }
        day = totalDays + 1; // final day
    }

    // return month name for printing
    const char* monthName(int m) const {
        const char* names[] = { "January","February","March","April","May","June",
                               "July","August","September","October","November","December" };
        return names[m - 1];
    }

    // prints number in 2 digits (eg 01,02)
    void printTwoDigits(int number) const {
        if (number < 10) cout << "0";
        cout << number;
    }

public:

    // default constructor
    CalendarDate() { resetToDefault(); }

                               // constructor with day, month, year
    CalendarDate(int d, int m, int y) {
        if (isValid(d, m, y)) {
            day = d; month = m; year = y;
        }
        else {
            resetToDefault(); // invalid reset
            cout << "Invalid Date! Reset to: 01-01-2000\n";
        }
    }

       // constructor with total days from base
    CalendarDate(int daysToAdd) {
        resetToDefault();
        fromTotalDays(daysToAdd);
    }

    // copy constructor
    CalendarDate(const CalendarDate& other) {
        day = other.day; month = other.month; year = other.year;
    }

    // assignment operator
    CalendarDate& operator=(const CalendarDate& other) {
        if (this != &other) {
            day = other.day; month = other.month; year = other.year;
        }
        return *this;
    }

    // check if current year is leap
    bool isLeapYear() const { return isLeapYear(year); }

    // check if date valid
    bool isValid() const { return isValid(day, month, year); }

    // add n days to current date
    void addDays(int n) { fromTotalDays(toTotalDays() + n); }

    // subtract n days from current date
    void subtractDays(int n) {
        int current = toTotalDays();
        if (n > current) { cout << "Error: cant go before 01-01-2000\n"; return; }
        fromTotalDays(current - n);
    }

   
    void print(int fmt) const {
        if (fmt == 1) { printTwoDigits(day); cout << "-"; printTwoDigits(month); cout << "-" << year; }
        else if (fmt == 2) { cout << monthName(month) << " " << day << ", " << year; }
        else if (fmt == 3) { cout << year << "/"; printTwoDigits(month); cout << "/"; printTwoDigits(day); }
    }

    // arithmetic operators
    CalendarDate operator+(int numDays) const { CalendarDate result = *this; result.addDays(numDays); return result; }
    CalendarDate operator-(int numDays) const { CalendarDate result = *this; result.subtractDays(numDays); return result; }
    int operator-(const CalendarDate& other) const { return toTotalDays() - other.toTotalDays(); }

    // compound assignments
    CalendarDate& operator+=(int numDays) { addDays(numDays); return *this; }
    CalendarDate& operator-=(int numDays) { subtractDays(numDays); return *this; }

    CalendarDate& operator++() { addDays(1); return *this; }
    CalendarDate operator++(int) { CalendarDate temp = *this; addDays(1); return temp; }
    CalendarDate& operator--() { subtractDays(1); return *this; }
    CalendarDate operator--(int) { CalendarDate temp = *this; subtractDays(1); return temp; }

  
    bool operator==(const CalendarDate& other) const { return toTotalDays() == other.toTotalDays(); }
    bool operator!=(const CalendarDate& other) const { return toTotalDays() != other.toTotalDays(); }
    bool operator< (const CalendarDate& other) const { return toTotalDays() < other.toTotalDays(); }
    bool operator> (const CalendarDate& other) const { return toTotalDays() > other.toTotalDays(); }
    bool operator<=(const CalendarDate& other) const { return toTotalDays() <= other.toTotalDays(); }
    bool operator>=(const CalendarDate& other) const { return toTotalDays() >= other.toTotalDays(); }

                  // print all formats
    void operator()() const { print(1); cout << "\n"; print(2); cout << "\n"; print(3); cout << "\n"; }

    // stream operators
    friend ostream& operator<<(ostream& out, const CalendarDate& d) {
        if (d.day < 10) out << "0";
        out << d.day << "-";
        if (d.month < 10) out << "0";
        out << d.month << "-" << d.year;
        return out;
    }

    friend istream& operator>>(istream& in, CalendarDate& d) {
        int day, month, year;
        in >> day >> month >> year;
        if (d.isValid(day, month, year)) {
            d.day = day; d.month = month; d.year = year;
        }
        else {
            d.resetToDefault();
            cout << "Invalid Date! Reset to: 01-01-2000\n";
        }
        return in;
    }

    // friend operator for int + date
    friend CalendarDate operator+(int numDays, const CalendarDate& d) { return d + numDays; }
};

int main() {
    CalendarDate workingDate; 
    int choice = 0;

    do {
        cout << "\n============================================\n";
        cout << "       Calendar Management System           \n";
        cout << "============================================\n";
        cout << " 1.  Enter a new date\n";
        cout << " 2.  Display date\n";
        cout << " 3.  Add days\n";
        cout << " 4.  Subtract days\n";
        cout << " 5.  Compare two dates\n";
        cout << " 6.  Find difference between two dates\n";
        cout << " 7.  Test increment operators (++ prefix & postfix)\n";
        cout << " 8.  Test decrement operators (-- prefix & postfix)\n";
        cout << " 9.  Test compound operators += and -=\n";
        cout << " 10. Check leap year\n";
        cout << " 11. Display in all formats (function call operator)\n";
        cout << " 12. Exit\n";
        cout << "--------------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter date (DD MM YYYY): ";
            cin >> workingDate;

        }
        else if (choice == 2) {
            cout << "Date: " << workingDate << "\n";

        }
        else if (choice == 3) {
            cout << "Days to add: ";
            int daysToAdd; cin >> daysToAdd;
            workingDate += daysToAdd; // add days
            cout << "New Date: " << workingDate << "\n";

        }
        else if (choice == 4) {
            cout << "Days to subtract: ";
            int daysToRemove; cin >> daysToRemove;
            workingDate -= daysToRemove; // subtract days
            cout << "New Date: " << workingDate << "\n";

        }
        else if (choice == 5) {
            cout << "Enter second date (DD MM YYYY): ";
            CalendarDate otherDate; cin >> otherDate;
            cout << "Equal?          " << (workingDate == otherDate ? "Yes" : "No") << "\n";
            cout << "Not equal?      " << (workingDate != otherDate ? "Yes" : "No") << "\n";
            cout << "First < Second? " << (workingDate < otherDate ? "Yes" : "No") << "\n";
            cout << "First > Second? " << (workingDate > otherDate ? "Yes" : "No") << "\n";
            cout << "First <= Second?" << (workingDate <= otherDate ? "Yes" : "No") << "\n";
            cout << "First >= Second?" << (workingDate >= otherDate ? "Yes" : "No") << "\n";

        }
        else if (choice == 6) {
            cout << "Enter second date (DD MM YYYY): ";
            CalendarDate otherDate; cin >> otherDate;
            int gap = workingDate - otherDate;
            if (gap < 0) gap = -gap;
            cout << "Difference: " << gap << " days\n";

        }
        else if (choice == 7) {
            cout << "Before:        " << workingDate << "\n";
            ++workingDate;
            cout << "After prefix++: " << workingDate << "\n";

            CalendarDate snapshot = workingDate++;
            cout << "Postfix++ returned (old): " << snapshot << "\n";
            cout << "After postfix++:          " << workingDate << "\n";

        }
        else if (choice == 8) {
            cout << "Before:        " << workingDate << "\n";
            --workingDate;
            cout << "After prefix--: " << workingDate << "\n";

            CalendarDate snapshot = workingDate--;
            cout << "Postfix-- returned (old): " << snapshot << "\n";
            cout << "After postfix--:          " << workingDate << "\n";

        }
        else if (choice == 9) {
            cout << "Days to add (+=): ";
            int addAmount; cin >> addAmount;
            workingDate += addAmount;
            cout << "After +=: " << workingDate << "\n";

            cout << "Days to subtract (-=): ";
            int removeAmount; cin >> removeAmount;
            workingDate -= removeAmount;
            cout << "After -=: " << workingDate << "\n";

        }
        else if (choice == 10) {
            cout << (workingDate.isLeapYear() ? "Yes, it is a leap year.\n" : "No, not a leap year.\n");

        }
        else if (choice == 11) {
            workingDate(); 

        }
        else if (choice == 12) {
            cout << "Exiting. Goodbye!\n";

        }
        else {
            cout << "Invalid choice. Please enter 1-12.\n";
        }

    } while (choice != 12);

    return 0;
}