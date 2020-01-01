#pragma once

struct Object
{
	//virtual int get(char*) = 0;
	//virtual char* put() = 0;
	//virtual int type() = 0;
	//virtual char* name() = 0;
	//virtual bool cmp(Object*) = 0;
	//virtual Object* copy() = 0;
	virtual void Print() const = 0;
	virtual ~Object() {};
};