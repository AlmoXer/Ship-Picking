#pragma once
#include "Vektoria\Placement.h"
#include "GeoLoader.h"
#include "IDDistributor.h"


typedef unsigned int elementID;

class CElement : public Vektoria::CPlacement
{
public:
	CElement();
	~CElement();
	CGeoLoader *m_GeoLoader;
	CGeo m_Geo;

	IDDistributor *m_IDDistributor;
	elementID ID;

	CMaterialLoader *m_MaterialLoader;
	CMaterial m_Material;

	std::string Name;

	std::string getName();
	elementID getID();


};

