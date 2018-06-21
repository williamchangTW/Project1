#include "RegexpToNFA.h"
#include "RegexpToPost.h"
#include "NFAFragmentStack.h"

NFAFragmentStack FragmentStack; //stack, prepare to store NFA fragment

char *regexp = "ab";

int main(int argc, char **argv) {
	char *post;
	NFAState *start;

	//initialize
	InitNFAFragmentStack(&FragmentStack);

	//�N���W��ܦ��r���Φr���ഫ�� Parser tree �ǦC
	post = re2post(regexp);

	//�N Parser tree �ǦC�ഫ�� NFA
	start = post2nfa(post);

	return 0;
}

/*
�\��:
	��l�Ƥ@�Ӫ��A
	
��^��:
	���A���w
*/
int nstate = 1;
NFAState*CreateNFAState() {
	NFAState *s = (NFAState*)malloc(sizeof(NFAState));

	s->Name = nstate++;
	s->Transform = '\0';
	s->Next1 = NULL;
	s->Next2 = NULL;
	s->AcceptFlag = 0;

	return s;
}

/*
�\��:
	�N�}�l���A�M�������A�զ��@�� Fragment
�Ѽ�:
	StartState
	AcceptState
��^��:
	Fragment ���c���w
*/

NFAFragment MakeNFAFragment(NFAState *StartState, NFAState *AcceptState) {
	NFAFragment n = { StartState, AcceptState };
	return n;
}

/*
�\��:
	�N Parser tree �� post �ഫ�� NFA
�Ѽ�:
	postfix -- �ѪR�𪺫�ǫ��w
��^��:
	NFA �}�l���A���w
*/

const char VoidTrans = '$ '; //��ܪ��ഫ
NFAState*post2nfa(char *postfix) {
	char *p;									//pointer
	NFAFragment fragment1, fragment2, fm;		//NFA fragment structure  
	NFAFragment fragment = {0, 0};				//��l�ƪ�^ NFA fragment
	NFAState *NewStartState, *NewAcceptState;	//�}�l���A�ε��������A���w

	return fragment.StartState;
}