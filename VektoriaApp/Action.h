#pragma once
#include <vector>
#include "cereal/cereal.hpp"
#include "cereal/types/vector.hpp"
#include "cereal/archives/portable_binary.hpp"

#include "IClassID.h"
#include "Packet.h"

class CAction : public IClassID
{
public:
	CAction();
	~CAction();

	std::vector<shipID>& GetSubjects();

	virtual void Execute() = 0;
	virtual Net::CPacket* BuildPacket() = 0;

	template<class Archive>
	void serialize(Archive& archive)
	{
		archive(_classID, _subjectIDs);
	}
protected:
	std::vector<shipID> _subjectIDs;
};

