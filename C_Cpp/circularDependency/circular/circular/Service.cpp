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
	if (m_Flights.size() <= 0)
	{
		return;
	}
	for (vector<Flight*>::iterator iter = m_Flights.begin(); iter != m_Flights.end(); ++iter)
	{
		if ((*iter)->GetName() == pFlight->GetName())
		{
			m_Flights.erase(iter);
			break;
		}
	}
}

void Service::PrintDetails()
{
	cout << "Service::PrintDetails :: Service name = " << m_strName.c_str() << endl;
	if (m_Flights.size() <= 0)
	{
		return;
	}
	for (vector<Flight*>::iterator iter = m_Flights.begin(); iter != m_Flights.end(); ++iter)
	{
		Flight* pFlight = *iter;
		cout << "\tService::PrintDetails :: Flight name = " << pFlight->GetName().c_str() << endl;
	}
}