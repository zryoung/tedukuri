#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n;
vector<int> chosen; // ��ѡ�����
void calc(int x) {
	if (x == n + 1) { // ����߽�
		for (int i = 0; i < chosen.size(); i++)
			printf("%d ", chosen[i]);
		puts("");
		return;
	}
    //"��ѡx"��֧
	calc(x + 1); // ���������
	//"ѡx"��֧
	chosen.push_back(x); // ��¼x�ѱ�ѡ��
	calc(x + 1); // ��������� 
	chosen.pop_back(); // ׼�����ݵ���һ����֮ǰ����ԭ�ֳ�
}
int main() {
	cin >> n;
	calc(1);  // �������еĵ������
}
