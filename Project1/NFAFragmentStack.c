#include "NFAFragmentStack.h"

/*
�\��:
	��l�ƽu
�Ѽ�:
	pS -- ���|���w
*/

void InitNFAFragmentStack(NFAFragmentStack*pS) {
	pS->top = -1;
}

/*
�\��:
	�N��Ʊ��J���|��
�Ѽ�:
	pS--���|���w
	Elem -- �J���|�����w
��^��:
	��
*/

void PushNFAFragment(NFAFragmentStack*pS, NFAFragment Elem) {
	//���|���F, push ����
	if (MAX_STACK_LENGTH - 1 <= pS->top)
		return;

	pS->top++;
	pS->buffer[pS->top] = Elem;		//�N�������J���|����

	return;
}

/*
�\��:
	�N���|���� pop out
�Ѽ�:
	pS -- ���|���w
��^��:
	�p�G���\ pop out �����h�^�Ǥ�������
	�Y�����\�h��^ -1
*/

NFAFragment PopNFAFragment(NFAFragment*pS) {
	int pos;
	NFAFragment fragment = { 0, 0 };

	//���|����, pop ����

	if (NFAFragmentStackEmpty(pS))
		return fragment;
	pos = pS->top;
	pS->top--;
}