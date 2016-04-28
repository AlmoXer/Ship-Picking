#pragma once
#include "Vektoria\Root.h"

using namespace Vektoria;
class CMaterialLoader
{
public:
	static CMaterialLoader& instance()
	{
		static CMaterialLoader *instance = new CMaterialLoader();
		return *instance;
	}

	CMaterial m_Desk;
	CMaterial m_Plasma;
	CMaterial m_FightDrone;

	CMaterial m_RahmenDroneCarrier;
	CMaterial m_RahmenTestShip;

	CMaterial m_LebensAnzeige;
	CMaterial m_LebensAnzeigeSchild;
	CMaterial m_LebensAnzeigeLeben;
	CMaterial m_LebensAnzeigeHintergrund;


	void Init();
	CMaterial* getDesk();
	CMaterial* getPlasma();
	CMaterial* getRahmenDroneCarrier();
	CMaterial* getRahmenTestShip();

	CMaterial* getLebensAnzeige();
	CMaterial* getLebensAnzeigeSchild();
	CMaterial* getLebensAnzeigeLeben();
	CMaterial* getLebensAnzeigeHintergrund();
private:

	CMaterialLoader();
	~CMaterialLoader();
};

