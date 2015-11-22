#pragma once

class CHelloWorld
{
public:
	CHelloWorld();
	~CHelloWorld();
	void SayHello();
protected:
private:
	weak_ptr<int> _weakPtr;
	void TestTime();
	void TestString();
	void TestResource();
	void TestThread();

	std::mutex _mutex;
	std::condition_variable _condition;
};