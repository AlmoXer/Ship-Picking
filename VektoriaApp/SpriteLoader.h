#pragma once
#include "Vektoria\Root.h"

using namespace Vektoria;
class CSpriteLoader
{
public:
	static CSpriteLoader& instance()
	{
		static CSpriteLoader *instance = new CSpriteLoader();
		return *instance;
	}

	CMaterial m_MPlasma;
	CGeoQuad m_GPlasma;
	
	void Init();
	CGeoQuad* getPlasma();
	
private:

	CSpriteLoader();
	~CSpriteLoader();
};

