#pragma once
class List
{
private:
	string* book;
	long size;

public:
	enum { MAX_SIZE = 1000 };
	void SetValue(string value, long pos);
	string GetValue(long pos);
	void Input();
	void Resize(long numValues);
	void Clear();
	void Display();
	List();
	~List();

}; 