#include <iostream>
using namespace std;

class date
{
public:
	date() {}

	date(int d, int m, int y); 

	// À±³â °è»ê
	bool isleap();
	
	void displayinfo();
	
private:
	const int days[12] { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int day{ 1 };
	int month{ 1 };
	int year{ 2021 };

	void setyear(int y);// { year = y >= 1930 && y <= 2021 ? y : 2021; }

	void setmonth(int m); // { month = m >= 1 && m <= 12 ? m : 1; }

	void setday(int d);
	
};

date::date(int d, int m, int y) {
	setyear(y);
	setmonth(m);
	setday(d);
}

bool date::isleap()
{
	return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

void date::displayinfo()
{
	cout << "Day : " << day << '\n';
	cout << "Month : " << month << '\n';
	cout << "Year : " << year << '\n';
}

void date::setyear(int y) { year = y >= 1930 && y <= 2021 ? y : 2021; }
void date::setmonth(int m) { month = m >= 1 && m <= 12 ? m : 1; }
void date::setday(int d)
{
	day = d >= 1 && d <= days[month - 1] + (month == 2 && isleap()) ? d : 1;
}

int main()
{
	date d(2, 4, 2020);

	d.displayinfo();
}