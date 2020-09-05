#pragma once
#include <iostream>
#include<sapi.h>
#include <atlconv.h>
#include <string>
using namespace std;

class Translate
{
public:
	Translate(string, string);
	Translate();
	void set_spanish(string _word);
	void set_english(string _word);
	void set_flag(int _f);
	string get_spanish();
	string get_english();
	int get_flag();
	void hablar(int);
	bool operator < (const Translate& p)const;
	bool operator != (const Translate& p)const;
	bool operator == (const Translate& p)const;
	friend ostream& operator << (ostream& o, const Translate& p);
private:
	string _spanish;
	string _english;
};

