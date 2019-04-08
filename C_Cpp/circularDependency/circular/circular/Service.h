#pragma once

#include "main.h"
#include "Flight.h"

class Flight;

class Service
{
	string m_strName;
	vector<Flight*> m_Flights;
public:
	Service();
	Service(string strName);
	void AddFlight(Flight* pFlight);
	void RemoveFlight(Flight* pFlight);
	string GetName();
	void PrintDetails();
};