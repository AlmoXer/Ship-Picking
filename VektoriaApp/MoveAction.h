#pragma once
#include "Action.h"
#include <vector>
#include <stdexcept>
#include <strstream>
#include <iostream>
#include "cereal/cereal.hpp"
#include "cereal/types/vector.hpp"
#include "cereal/archives/portable_binary.hpp"
class CMoveAction :
	public CAction
{
public:
	CMoveAction();
	CMoveAction(CMoveAction& const init);


	CMoveAction(const CMoveAction& other)
	{
		_subjectIDs = std::vector<shipID>(other._subjectIDs);
		_destinations = std::vector<float>(other._destinations);
	}


	///Initializes this action with a copy of the data given by a packet.
	CMoveAction(Net::CPacket* initializer);
	~CMoveAction();

	void Add(shipID subjID, float dest_x, float dest_y);

	void Execute() override;
	Net::CPacket* BuildPacket() override;

	template<class Archive>
	void serialize(Archive &archive)
	{
		archive(cereal::base_class<CAction>(this), _destinations);	
	}

private:
	std::vector<float> _destinations;
};

