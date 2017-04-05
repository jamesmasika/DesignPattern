#pragma once
#include <iostream>
using namespace std;
class ReplaceAG
{
public:
	virtual void Replace() = 0;
};

class LRUAG : public ReplaceAG
{
	void Replace()
	{
		cout << "LRUAG\n";
	}
};

class FIFOAG : public ReplaceAG
{
	void Replace()
	{
		cout << "FIFOAG\n";
	}
};

class RANDOMAG : ReplaceAG
{
	void Replace()
	{
		cout << "randomAG\n";
	}
};

//class cache
//{
//private:
//	ReplaceAG *m_rag;
//public:
//	cache(ReplaceAG * rag) :m_rag(rag) {}
//	~cache() {}
//	void Replace() { m_rag->Replace(); }
//};
enum RA {LRU, FIFO, RANDOM};
class cache
{
private:
	ReplaceAG *m_rag;
public:
	cache(enum RA ra)
	{
		if (ra == LRU)
			m_rag = new LRUAG();

	}
	~cache() { delete m_rag; }
	void Replace() { m_rag->Replace(); }
};

