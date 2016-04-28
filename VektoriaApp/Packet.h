#pragma once
#include <stdexcept>
#include <string>
#include "cereal/cereal.hpp"
#include "cereal/types/string.hpp"
#include "IClassID.h"
typedef unsigned int uint;
typedef unsigned long shipID;

namespace Net {
	class CPacket
	{
	public:
		CPacket();
		CPacket(classID foreignID, std::string& data);
		~CPacket();

		classID GetForeignClassID() const;
		const std::string& GetData() const;

		void Set(classID foreignID, const std::string& data);

		template<class Archive>
		void serialize(Archive& archive)
		{
			archive(_foreign_id, _data);
		}

	private:
		classID _foreign_id;
		std::string _data;
	};
}
