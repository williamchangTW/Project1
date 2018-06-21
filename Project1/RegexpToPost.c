#include "RegexpToPost.h"

/*
�\��:
	�N��J���W��ܦ����ܦ� Parser tree postfix ����C
�Ѽ�:
	re -- ���W��ܦ����w
��^��:
	Parser tree postfix �ƭӫ��w
*/

char *re2post(char *re) {
	int nalt;				//��ܲ{�b���h�֭� branch
	int natom;		//��ܲ{�b���h�֭��I
	static char buf[8000];
	char *dst;

	struct {			//�w�q��Ƶ��c
		int nalt;
		int natom;
	} paren[1000], *p;

	p = paren;		//���w���V���`�I
	dst = buf;
	nalt = 0;
	natom = 0;
	if (strlen(re) >= sizeof buf / 2) 
		return NULL;
	
	for (; *re; re++) {
		switch (*re) {
		case '(':
			if (natom > 1) {
				--natom;
				*dst++ = '.';
			}
			if (p >= paren + 100)
				return NULL;
			p->nalt = nalt;
			p->natom = natom;
			p++;
			nalt = 0;
			natom = 0;
			break;

		case '|':
			if (natom == 0)
				return NULL;
			while (--natom > 0)
				*dst++ = '.';
			nalt++;
			break;
		case ')':
			if (p == paren)
				return NULL;
			if (natom == 0)
				return NULL;
			while (--natom > 0)
				*dst++ = '.';
			for (; nalt > 0; nalt--)
				*dst++ = '|';
			--p;
			nalt = p->nalt;
			natom = p->natom;
			natom++;
			break;
		case '*':
		case '+':
		case '?':
			if (natom == 0)
				return NULL;
			*dst++ = re;
			break;
		default:
			if (natom > 1) {
				--natom;		//���Ʀ^�k��s
				*dst++ = '.';	//�M��A�� dst ���w�[�W�@���_�I
			}
			*dst++ = *re;	//���M�N����l�� re ���w
			natom++;
			break;
		}
	}
	if (p != paren)
		return NULL;
	while (--natom > 0)
		*dst++ = '.';
	for (; nalt > 0; nalt--)
		*dst++ = '|';		//�@�@�M���ٯd�b nalt buffer �������
	*dst = 0;		//�M�Ű��|
	
	return buf;
}
