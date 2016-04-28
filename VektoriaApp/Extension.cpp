#include "Extension.h"


CExtension::CExtension()
{
}


CExtension::~CExtension()
{
}

CShip* CExtension::getShip()
{
	return m_Ship;
}
void CExtension::init(CShip*p_Ship, std::string p_Name)
{
	m_Ship = p_Ship;
	Name = p_Name;
}