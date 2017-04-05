#pragma once
#include <iostream>
using namespace std;
class stack
{
public:
	void push_back() { cout << "stach push\n"; }
	void pop_back() { cout << "stack pop back\n"; }
};
class queue
{
public:
	void pop_front() { cout << "queue pop\n"; }
	void push_back() { cout << "queue pop\n"; }
};
class seq
{
private:
	stack sck;
	queue que;
public:
	void push_back() { sck.push_back(); }
	void pop_back() { sck.pop_back(); }
	void push_front() { que.push_back(); }
	void pop_front() { cout << "defined seq's pop_front\n";  }
};
