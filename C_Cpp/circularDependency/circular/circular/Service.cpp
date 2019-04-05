#include "Service.h"

Service::Service()
{
	m_strName = "SERVICE";
}

Service::Service(string strName)
{
	m_strName = strName;
}

string Service::GetName()
{
	return m_strName;
}

void Service::AddFlight(Flight* pFlight)
{
	if (pFlight)
	{
		m_Flights.push_back(pFlight);
	}
}

void Service::RemoveFlight(Flight* pFlight)
{
	
}

void Service::PrintDetails()
{
	cout << "Service::PrintDetails :: Service name = " << m_strName.c_str() << endl;
}