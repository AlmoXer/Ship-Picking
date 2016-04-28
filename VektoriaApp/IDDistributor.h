#pragma once
class IDDistributor
{
	public:
		static IDDistributor& instance()
		{
			static IDDistributor *instance = new IDDistributor();
			return *instance;
		}
	unsigned long m_ID;
	unsigned int m_Counter;
	
	unsigned long getID(int p_Element, int p_Selectable, int  p_Type, int p_Player);



private:
	IDDistributor();
	~IDDistributor();

};

