#pragma once
#include <iostream>
#include "addressbook.h"
#include "sortedlinkedlist_t.h"
#include <string>

class DateType
{
public:
    DateType();
    ~DateType();
    int GetMonth();
    int GetDay();
    int GetYear();
    void SetMonth(int month);
    void SetDay(int day);
    void SetYear(int year);
    void PrintDate();

private:
    int month;
    int day;
    int year;
};
DateType::DateType()
{
    month = 1;
    day = 1;
    year = 2000;
}
DateType::~DateType()
{}
void DateType::SetDay(int newDay)
{
    day = newDay;
}
void DateType::SetMonth(int newMonth)
{
    month = newMonth;
}
void DateType::SetYear(int newYear)
{
    year = newYear;
}
int DateType::GetDay()
{
    return day;
}
int DateType::GetMonth()
{
    return month;
}
int DateType::GetYear()
{
    return year;
}
void DateType::PrintDate()
{
    std::cout<<month << "/" << day << "/" << year << " ";
}

// Class PersonType
class PersonType : public SortedType<PersonType>
{
public:
    PersonType();
    ~PersonType();
    void Print();

private:
    std::string firstName;
    std::string lastName;
    DateType birthday;
    DateType anniversary;
};
PersonType::PersonType()
{
    firstName = "John";
    lastName = "Doe";
    birthday.SetDay(1);
    birthday.SetMonth(1);
    birthday.SetYear(1900);
    anniversary.SetDay(2);
    anniversary.SetMonth(2);
    anniversary.SetYear(1918);
}
PersonType::~PersonType()
{}
void PersonType::Print()
{
    using namespace std;
    cout << firstName << " " << lastName << " ";
    birthday.PrintDate();
    anniversary.PrintDate(); 
    cout << endl;
}