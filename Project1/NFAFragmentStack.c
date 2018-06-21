#include "NFAFragmentStack.h"

/*
功能:
	初始化線
參數:
	pS -- 堆疊指針
*/

void InitNFAFragmentStack(NFAFragmentStack*pS) {
	pS->top = -1;
}

/*
功能:
	將資料推入堆疊中
參數:
	pS--堆疊指針
	Elem -- 入堆疊的指針
返回值:
	空
*/

void PushNFAFragment(NFAFragmentStack*pS, NFAFragment Elem) {
	//堆疊滿了, push 失敗
	if (MAX_STACK_LENGTH - 1 <= pS->top)
		return;

	pS->top++;
	pS->buffer[pS->top] = Elem;		//將元素插入堆疊頂部

	return;
}

/*
功能:
	將堆疊頂部 pop out
參數:
	pS -- 堆疊指針
返回值:
	如果成功 pop out 元素則回傳元素的值
	若不成功則返回 -1
*/

NFAFragment PopNFAFragment(NFAFragment*pS) {
	int pos;
	NFAFragment fragment = { 0, 0 };

	//堆疊為空, pop 失敗

	if (NFAFragmentStackEmpty(pS))
		return fragment;
	pos = pS->top;
	pS->top--;
}