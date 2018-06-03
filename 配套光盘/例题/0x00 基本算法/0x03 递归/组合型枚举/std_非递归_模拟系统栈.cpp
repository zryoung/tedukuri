#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> chosen;
int stack[100010], top = 0, address = 0, n, m;
void call(int x, int ret_addr) { // ģ���������ָ��call
	int old_top = top;
	stack[++top] = x; // ����x
	stack[++top] = ret_addr; // ���ص�ַ���
	stack[++top] = old_top; // ��ջ����¼��ǰ��topֵ
}
int ret() { // ģ���������ָ��ret
	int ret_addr = stack[top - 1];
	top = stack[top]; // �ָ���ǰ��topֵ
	return ret_addr;
}

int main() {
	cin >> n >> m;
	call(1, 0); // calc(1)
	while (top) {
		int x = stack[top - 2]; // ��ȡ����
		switch (address) {
		case 0:
			if (chosen.size()>m || chosen.size()+(n-x+1)<m) {
				address = ret(); // return
				continue;
			}
			if (x == n + 1) {
				for (int i = 0; i < chosen.size(); i++)
					printf("%d ", chosen[i]);
				puts("");
				address = ret(); // return
				continue;
			}
			chosen.push_back(x);
			call(x+1, 1); // �൱��calc(x+1)�����غ���case 1����
			address = 0;
			continue; // �ص�whileѭ����ͷ���൱�ڿ�ʼ�µĵݹ�
		case 1:
			chosen.pop_back();
			call(x+1, 2); // �൱��calc(x+1)�����غ���case 2����
			address = 0;
			continue; // �ص�whileѭ����ͷ���൱�ڿ�ʼ�µĵݹ�
		case 2:
			address = ret(); // �൱��ԭcalc������β��ִ��return
		}
	}
}

