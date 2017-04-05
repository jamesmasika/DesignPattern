#pragma once
#include <iostream>  
using namespace std;
template <typename T>
class Singleton
{
public:
	static T* instance()
	{
		if (!t_)
		{
			t_ = new T();
		}
		return t_;
	}
private:
	Singleton();
	static T* t_;
};

template <typename T>
T* Singleton<T>::t_ = NULL;

class Stu
{
public:
	void print()
	{
		cout << "this is Stu" << endl;
	}
};
