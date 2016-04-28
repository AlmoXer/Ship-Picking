#include "DebugHelper.h"


CDebugHelper::CDebugHelper()
{
}


CDebugHelper::~CDebugHelper()
{
}

void CDebugHelper::Init()
{
	AllocConsole();
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);
}

void CDebugHelper::write(string p_string)
{
	cout << p_string << endl;
}

void CDebugHelper::write(int p_int)
{
	cout << p_int << endl;
}
void CDebugHelper::write(float p_float)
{
	cout << p_float << endl;
}

void CDebugHelper::writeHitPoint(float p_x, float p_y, float p_z)
{
	cout << "HItpoint :" << "X: " << p_x << "Y: " << p_y << "Z: " << p_z << endl;
}