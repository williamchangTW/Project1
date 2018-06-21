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

	//將正規表示式字元或字串轉換成 Parser tree 序列
	post = re2post(regexp);

	//將 Parser tree 序列轉換成 NFA
	start = post2nfa(post);

	return 0;
}

/*
功能:
	初始化一個狀態
	
返回值:
	狀態指針
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
功能:
	將開始狀態和接受狀態組成一個 Fragment
參數:
	StartState
	AcceptState
返回值:
	Fragment 結構指針
*/

NFAFragment MakeNFAFragment(NFAState *StartState, NFAState *AcceptState) {
	NFAFragment n = { StartState, AcceptState };
	return n;
}

/*
功能:
	將 Parser tree 的 post 轉換成 NFA
參數:
	postfix -- 解析樹的後序指針
返回值:
	NFA 開始狀態指針
*/

const char VoidTrans = '$ '; //表示空轉換
NFAState*post2nfa(char *postfix) {
	char *p;									//pointer
	NFAFragment fragment1, fragment2, fm;		//NFA fragment structure  
	NFAFragment fragment = {0, 0};				//初始化返回 NFA fragment
	NFAState *NewStartState, *NewAcceptState;	//開始狀態及結接受狀態指針

	return fragment.StartState;
}