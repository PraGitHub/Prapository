#include "Flight.h"

Flight::Flight()
{
	m_pService = nullptr;
	m_strName = "FLIGHT";
}

Flight::Flight(string strName)
{
	m_pService = nullptr;
	m_strName = strName;
}

void Flight::SetName(string strName)
{
	m_strName = strName;
}

string Flight::GetName()
{
	return m_strName;
}

void Flight::SetService(Service* pService)
{
	m_pService = pService;
}

void Flight::PrintDetails()
{
	cout << "Flight :: PrintDetails :: Flight name = " << m_strName.c_str() << endl;
	if (m_pService)
	{
		cout << "Flight :: PrintDetails :: Service name = " << m_pService->GetName().c_str()<<endl;
	}
}