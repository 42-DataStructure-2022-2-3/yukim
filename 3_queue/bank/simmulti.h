#ifndef _SIM_MULTI_
# define _SIM_MULTI_

# include "simdef.h"
# include "simlinkedqueue.h"

void		insertCustomer(int arrivalTime, int processTime, Linkedqueue *pQueue);
void		processArrival(int currentTime, Linkedqueue *pArrivalQueue, Linkedqueue *pWaitQueue); 
queueNode*	processServiceNodeStart(int currentTime, Linkedqueue *pWaitQueue); 
queueNode*	processServiceNodeEnd(int currentTime, queueNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime); 
void		printSimCustomer(int currentTime, SimCustomer customer);
void		printWaitQueueStatus(int currentTime, Linkedqueue *pWaitQueue); 
void		printReport(Linkedqueue *pWaitQueue, int serviceUserCount, int totalWaitTime);

#endif
