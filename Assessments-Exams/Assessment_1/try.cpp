#include <iostream>
#include <string>
#include <cstdint>
#include <stdexcept>
#include <cstddef>
#include <cassert>

class Date
{
private:
	unsigned short day, month;
	unsigned year;

	bool validDate(unsigned short day, unsigned short month, unsigned year)
	{
		if (day == 0 || day > 31 || month == 0 || month > 12)
			return false;

		switch (month)
		{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			return true;
		case 4: case 6: case 9: case 11:
			return day <= 30;
		case 2:
			return day <= 28 + leapYear(year);
		}
		return false;
	}

	bool leapYear(unsigned year)
	{
		return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
	}

public:
	Date(unsigned int day, unsigned int month, unsigned int year) : day(day), month(month), year(year)
	{
		if (!validDate(day, month, year))
		{
			throw std::invalid_argument("Invalid date!");
		}

		//this->day = day;
		//this->month = month;
		//this->year = year;
	}

	unsigned int getDay() const { return day; }

	unsigned int getMonth() const { return month; }

	unsigned int getYear() const { return year; }

	bool operator==(const Date& rhs) const
	{
		return this->day == rhs.day && this->month == rhs.month && this->year == rhs.year;
	}

	bool operator<(const Date& rhs) const
	{
		if (this->year < rhs.year)
		{
			return true;
		}
		else if (this->year == rhs.year)
		{
			if (this->month < rhs.month)
			{
				return true;
			}
			else if (this->month == rhs.month)
			{
				if (this->day < rhs.day) {
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}

	friend std::ostream& operator<<(std::ostream& out, const Date& date)
	{
		out << date.day << " " << date.month << " " << date.year << std::endl;
		return out;
	}

	/*void print() const
	{
		std::cout << day << '.' << month << '.' << year;
	}*/
};

class Registration
{
private:
	std::string id;
	Date date;
public:
	Registration(const std::string& id, const Date& date) : id(id), date(date)
	{

	}

	bool operator==(const Registration& rhs) const
	{
		return id == rhs.id && date == rhs.date;
	}

	bool operator<(const Registration& rhs) const
	{
		return date < rhs.date || (date == rhs.date && id < rhs.id);
	}

	friend std::ostream& operator<<(std::ostream& out, const Registration& reg)
	{
		out << reg.id << " " << reg.date << std::endl;
		return out;
	}
};

class RegistrationList
{
private:
	Registration** list;
	size_t capacity;
	size_t used;
public:
	RegistrationList() : list(nullptr), capacity(0), used(0)
	{
		
	}
	RegistrationList(std::size_t capacity) : capacity(capacity)
	{
		try
		{
			list = new Registration*[capacity];
			for (size_t i = 0; i < capacity; ++i) {
				list[i] = nullptr;
			}
		}
		catch (const std::bad_alloc& e)
		{
			std::cout << "no memory, bratmi" << e.what() << std::endl;
		}
	}
	~RegistrationList()
	{
		for (size_t i = 0; i < capacity; ++i) {
			delete[] list[i];
		}
		delete[] list;
	}

	void insert(const std::string& id, const Date& date)
	{
		if (used == capacity || capacity == 0)
		{
			throw std::out_of_range("nz");
		}

		list[used] = new Registration(id, date);
		bool flag = false;
		Registration temp(id, date);
		for (size_t i = 0; i < used; ++i)
		{
			if (*list[i] == temp)
			{
				flag = true;
				break;
			}
		}
		if (flag == true)
		{
			throw std::exception();
		}

		for (size_t i = 0; i < used; ++i)
		{
			if (temp < *list[i])
			{
				for (size_t j = i; j < used; ++j)
				{
					*list[j + 1] = *list[j];
				}
				*list[i] = temp;
				break;
			}
		}
		std::cout << "Tuk se chupq!" << std::endl;
		++used;
	}

	const Registration& at(std::size_t index) const
	{
		if (!(index >= 0 && index <= used))
		{
			throw std::out_of_range("asd");
		}
		return *list[index];
	}

	const Registration& operator[](std::size_t index) const
	{
		assert(index >= 0 && index <= used);
		return *list[index];
	}

	bool empty() const
	{
		return used == 0;
	}

	size_t capacity_from_aliexpress() const
	{
		return capacity;
	}

	size_t size() const
	{
		return used;
	}

	void print() const
	{
		for (size_t i = 0; i < used; ++i)
		{
			std::cout << *list[i] << std::endl;
		}
	}
};

int main()
{
	size_t N;
	std::cin >> N;

	std::string idBuf;
	unsigned short day, month;
	unsigned year;

	RegistrationList list(N);
	for (size_t i = 0; i < N; ++i)
	{
		std::cin >> idBuf >> day >> month >> year;
		try
		{
			Date dateBuf(day, month, year);
			list.insert(idBuf, dateBuf);
		}
		catch (const std::exception& e)
		{
			std::cout << e.what();
		}
	}
	list.print();
	return 0;
}
