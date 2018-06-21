#include "RegexpToPost.h"

/*
功能:
	將輸入正規表示式轉變成 Parser tree postfix 的串列
參數:
	re -- 正規表示式指針
返回值:
	Parser tree postfix 數個指針
*/

char *re2post(char *re) {
	int nalt;				//表示現在有多少個 branch
	int natom;		//表示現在有多少個點
	static char buf[8000];
	char *dst;

	struct {			//定義資料結構
		int nalt;
		int natom;
	} paren[1000], *p;

	p = paren;		//指針指向父節點
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
				--natom;		//把資料回歸到零
				*dst++ = '.';	//然後再把 dst 指針加上一個斷點
			}
			*dst++ = *re;	//不然就為原始的 re 指針
			natom++;
			break;
		}
	}
	if (p != paren)
		return NULL;
	while (--natom > 0)
		*dst++ = '.';
	for (; nalt > 0; nalt--)
		*dst++ = '|';		//一一清空還留在 nalt buffer 中的資料
	*dst = 0;		//清空堆疊
	
	return buf;
}
