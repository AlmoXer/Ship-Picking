#pragma once
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <string>

using namespace std;
class CDebugHelper
{
public:
	static CDebugHelper* instance()
	{
		static CDebugHelper *instance = new CDebugHelper();
		return instance;
	}

	void Init();
	void write(string p_string);
	void write(int p_int);
	void write(float p_float);
	void writeHitPoint(float p_x, float p_y, float p_z);

private:
	CDebugHelper();
	~CDebugHelper();

};

