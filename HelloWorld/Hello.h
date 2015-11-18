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

};