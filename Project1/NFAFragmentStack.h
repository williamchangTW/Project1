#ifndef _NFAFRAGMENTSTACK_H_
#define _NFAFRAGMENTSTACK_H_

//include c lib header 

//include other header file

#include "RegexpToNFA.h"

//def data structure

#define MAX_STACK_LENGTH 1024	//stack max length 

//stack
typedef struct _NFAFragmentStack {
	NFAFragment buffer[MAX_STACK_LENGTH]; //stack
	int top;	//point the top of stack
}NFAFragmentStack;

//claim variarity

void InitNFAFragmentStack(NFAFragmentStack*pS);
void PushNFAFragment(NFAFragmentStack*pS, NFAFragment Elem);
NFAFragment PopNFAFragment(NFAFragmentStack*pS);
int NFAFragmentStackEmpty(NFAFragmentStack*pS);

//claim global variarity

#endif // !_NFAFRAGMENTSTACK_H_

