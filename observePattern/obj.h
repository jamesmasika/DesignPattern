#include <iostream>  
#include <string>  
#include <vector>  
#include <list>  
using namespace std;

class Observer
{
public:
	Observer() {}
	virtual ~Observer() {}
	virtual void Update() {};
};

class Blog
{
public:
	Blog() {}
	virtual ~Blog() {}

	void Attach(Observer* observer)
	{
		vec_observer.push_back(observer);
	}

	void Romve(Observer* observer)
	{
		vector<Observer*>::iterator iter;
		for (iter = vec_observer.begin(); iter != vec_observer.end(); ++iter)
		{
			if ((*iter) == observer)
				vec_observer.erase(iter);
		}
	}

	void Notify()
	{
		vector<Observer*>::iterator iter;
		for (iter = vec_observer.begin(); iter != vec_observer.end(); ++iter)
		{
			(*iter)->Update();
		}
	}

	virtual void SetStatus(string sts) {}
	virtual string GetStatus() { return m_status; };

private:
	vector<Observer*> vec_observer;
protected:
	string m_status;
};

class ConcreteBlog :public Blog
{
public:
	ConcreteBlog(string name) :m_blog_name(name) {}
	~ConcreteBlog() {}

	void SetStatus(string sts)
	{
		m_status = "csdnÍ¨Öª£º " + m_blog_name + sts;
	}

	string GetStatus()
	{
		return m_status;
	}

private:
	string m_blog_name;
};

class ConcreteObserver :public Observer
{
private:
	string m_observer_name;
	Blog *m_blog;
public:
	ConcreteObserver(string name, Blog* blog) :m_observer_name(name), m_blog(blog) {}
	~ConcreteObserver() {}

	void Update()
	{
		string status = m_blog->GetStatus();
		cout << m_observer_name << "-----------" << status << endl;
	}
};