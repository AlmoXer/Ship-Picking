#include "MaterialLoader.h"


CMaterialLoader::CMaterialLoader()
{
}


CMaterialLoader::~CMaterialLoader()
{
}

void CMaterialLoader::Init()
{
	m_Desk.LoadPreset("BricksClinkerColored");
	m_Plasma.MakeTextureDiffuse("textures\\Green.png");
	m_FightDrone.LoadPreset("EarthCracked");


	m_RahmenDroneCarrier.MakeTextureSprite("textures\\Ships\\Rahmen\\DroneCarrier.png");
	m_RahmenDroneCarrier.SetTransparencyOn();
	m_RahmenTestShip.MakeTextureSprite("textures\\Ships\\Rahmen\\TestShip.png");
	m_RahmenTestShip.SetTransparencyOn();

	m_LebensAnzeige.MakeTextureSprite("textures\\Ships\\LebensAnzeige\\Anzeige.png");
	m_LebensAnzeige.SetTransparencyOn();
	m_LebensAnzeigeSchild.MakeTextureSprite("textures\\Ships\\LebensAnzeige\\Schild.png");
	m_LebensAnzeigeSchild.SetTransparencyOn();
	m_LebensAnzeigeLeben.MakeTextureSprite("textures\\Ships\\LebensAnzeige\\Leben.png");
	m_LebensAnzeigeLeben.SetTransparencyOn();
	m_LebensAnzeigeHintergrund.MakeTextureSprite("textures\\Ships\\LebensAnzeige\\Hintergrund.png");
	m_LebensAnzeigeHintergrund.SetTransparencyOn();
}

CMaterial* CMaterialLoader::getDesk()
{
	return &m_Desk;
}

CMaterial* CMaterialLoader::getPlasma()
{
	return &m_Plasma;
}

CMaterial* CMaterialLoader::getRahmenDroneCarrier()
{
	return &m_RahmenDroneCarrier;
}

CMaterial* CMaterialLoader::getRahmenTestShip()
{
	return &m_RahmenTestShip;
}

CMaterial* CMaterialLoader::getLebensAnzeige()
{
	
	return &m_LebensAnzeige;
}
CMaterial* CMaterialLoader::getLebensAnzeigeSchild()
{
	return &m_LebensAnzeigeSchild;
}
CMaterial* CMaterialLoader::getLebensAnzeigeLeben()
{
	return &m_LebensAnzeigeLeben;
}
CMaterial* CMaterialLoader::getLebensAnzeigeHintergrund()
{
	return &m_LebensAnzeigeHintergrund;
}