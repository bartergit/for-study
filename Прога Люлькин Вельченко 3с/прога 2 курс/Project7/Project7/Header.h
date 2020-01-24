#pragma once
#ifndef TIMENEW_H_INCLUDED
#define TIMENEW_H_INCLUDED
#include <iostream>
#include <time.h>

class TimeL
{
protected:
	int Hour; // ����
	int Min; // ������
	int Sec; // �������
	virtual void printMyself(std::ostream& out) const; // ������� ������������ ������ ������ �������� ��� ������ �������� �������
public:
	TimeL(); // ���������� � ������� ��������
	TimeL(int h, int m, int s); // ����������� � �������, ������� ����������� � �������
	TimeL(const TimeL&c); // ����������� �����������
	~TimeL(); // ����������
	friend std::ostream& operator<< (std::ostream &, const TimeL&); // ������������� �������� ������ (����� ��� ����� � ���������)
	// ������� ������: ��-�� ����, ��� ���� �������� � �������� ������ �����������, �� ��� ���� ����������� ������ � ������ ������, � ����� ����� ������������� �������� ������ ����� ���������
};

class TimeFull : public TimeL
{
protected:
	virtual void printMyself(std::ostream& out) const; // ������� ������������ ������ ������ �������� ��� ������ ������� �������
public:
	TimeFull() :TimeL() {}; // ����������� � ������� �������� (������ �������� ������, ����� �������������� � ����������� ������, �.�. �������� � ����� ������� � �������� ����� �������� ������ �� ������������)
	TimeFull(int h, int m, int s) :TimeL(h, m, s) {}; // � ������ ���������� ��� �����, ������� ��������� ��� ������
};


//////////////////////////////
//////////////////////////////

TimeL::TimeL() // ����������� �������� �������
{
	time_t currentTime; // ��������������� ����������, � ������� ������� ������� �����
	struct tm *localTime; // ���������, � ������� ������������ ����� ��������� �������� ���� � �����
	time(&currentTime);                   // �������� ������� �����
	localTime = localtime(&currentTime);  // ������������ � ��������� Hour = localTime->tm_hour;
	Hour = localTime->tm_hour; // � ���������� ������ ��� ������ ��� ������
	Min = localTime->tm_min;
	Sec = localTime->tm_sec;
}
TimeL::TimeL(int h, int m, int s) // ����������� �� ����� ��������
{
	if (h > 24 || h < 0) Hour = 0; // �� ������ ���������, ����� �� ���� 28 �����, 140 ����� � -6 ������. ���� ���� ������, �� ������� 0
	else Hour = h;
	if (m > 60 || h < 0) Min = 0;
	else Min = m;
	if (m > 60 || h < 0) Sec = 0;
	else Sec = s;
}
TimeL::TimeL(const TimeL&c) // ����������� �����������
{
	Hour = c.Hour; // �� ��� ������ ������� �����������
	Min = c.Min;
	Sec = c.Sec;
}
TimeL::~TimeL() // ����������
{
	Hour = 0; // ��� ��� �����
	Min = 0;
	Sec = 0;
}

void TimeL::printMyself(std::ostream& out) const // ��������� ����� �������� �������
{
	out << Hour << ":" << Min << ":" << Sec;
};

// ���������� ��������� <<
std::ostream& operator<< (std::ostream &out, const TimeL&c)
{
	c.printMyself(out); // ������ ����� ���� � �������� �� ������� ������
	return out; // � �������!
}

void TimeFull::printMyself(std::ostream& out) const // ����� ����������� ������ �������
{
	out << Hour << ":" << Min << ":" << Sec;
	if (Hour > 5 && Hour <= 9) out << " (����)"; // ���� - � 5 �� 9
	else if (Hour > 9 && Hour <= 17) out << " (����)";// ���� - � 9 �� 17
	else if (Hour > 17 && Hour <= 22) out << " (����)"; // ����� - � 17 �� 22
	else if (Hour > 22 && Hour <= 5) out << " (�����)"; // ���� - � 22 �� 5

};
#endif // TIMENEW_H_INCLUDED