// observePattern.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "obj.h"
#include "������ģʽ-����.h"
#include "����ģʽ.h"
#include "������ģʽ.h"

int main()
{
	Blog *blog = new ConcreteBlog("chenxun");
	Observer *ob1 = new ConcreteObserver("xiaowang", blog);
	Observer *ob2 = new ConcreteObserver("xiaozhang", blog);
	blog->Attach(ob1);
	blog->Attach(ob2);
	blog->SetStatus("�������²���");
	blog->Notify();

	Sequence *s1 = new Stack();
	Sequence *s22 = new Queue();
	s1->push(1); s1->pop();
	s22->push(1); s22->pop();


	Stu *s = Singleton<Stu>::instance();
	Stu *s2 = Singleton<Stu>::instance();
	if (s == s2)
	{
		cout << "equals." << endl;
	}

	FatBuilder fat;
	Director director(&fat);
	ThinBuilder thin;
	Director dict(&thin);
	director.Create();
	return 0;
	delete s1; delete s2;

	delete blog;
	delete ob1;
	delete ob2;
    return 0;
}

