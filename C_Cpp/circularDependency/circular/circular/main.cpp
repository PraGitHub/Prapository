#include "main.h"
#include "Service.h"
#include "Flight.h"

int main()
{
	Service* pServiceIndigo = new Service("Indigo");

	Flight* pFlight1 = new Flight("B-M-1001");
	Flight* pFlight2 = new Flight("B-D-2001");
	Flight* pFlight3 = new Flight("Dabba Flight");

	pFlight1->SetService(pServiceIndigo);
	pFlight2->SetService(pServiceIndigo);
	pFlight3->SetService(pServiceIndigo);

	pServiceIndigo->AddFlight(pFlight1);
	pServiceIndigo->AddFlight(pFlight2);
	pServiceIndigo->AddFlight(pFlight3);

	pServiceIndigo->PrintDetails();

	pFlight1->PrintDetails();
	pFlight2->PrintDetails();
	pFlight3->PrintDetails();

	pServiceIndigo->RemoveFlight(pFlight3);

	pServiceIndigo->PrintDetails();

	pFlight1->PrintDetails();
	pFlight2->PrintDetails();
	pFlight3->PrintDetails();
}