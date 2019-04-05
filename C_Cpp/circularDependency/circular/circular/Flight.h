#pragma once

#include "main.h"
#include "Service.h"

class Flight
{
	string m_strName;
	Service* m_pService;
public:
	Flight();
	Flight(string strName);
	void SetService(Service* pService);
	void SetName(string strName);
	string GetName();
	void PrintDetails();
};