#ifndef _REGEXPTONFA_H_
#define _REGEXPTONFA_H_

//include C lib header file

#include <stdio.h>

//def data structure

typedef struct _NFAState {
	char Transform;			//state transfer label, use '$ ' to point 'epsilon transfer'
	struct _NFAState *Next1; //point to next state
	struct _NFAState *Next2; //point to next state
	int Name;				//state name
	int AcceptFlag;			//1 represent accept and 0 represent denie
}NFAState;

//Fragment structure is a NFA fragment
typedef struct _NFAFragment {
	NFAState *StartState;	//Startstate
	NFAState *AcceeptState;	//Accept
}NFAFragment;

//claim variarity

NFAState*CreateNFAState();
NFAState*post2nfa(char *postfix);
NFAFragment MakeNFAFragment(NFAState *StartState, NFAState *AcceptState);

//claim global variarity

extern int nstate;
extern const char VoidTrans;
extern char*regexp;

#endif // !_REGEXPTONFA