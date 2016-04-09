/*
	��Ŀ��http://poj.org/problem?id=1860
	��⣺����һ��ͼ�㷨���漰�й����·��Bellman-Ford�㷨
		 �������Ⲣ������Ȩ������������Bellman-Ford�㷨�����Ȩ����
	��Դ��https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm
		 https://www.youtube.com/watch?v=iTW2yFYd1Nc
*/

#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 110;
const int MAXM = 220;
struct Edge {
	int start, end;
	double rate, commission;
} edges[MAXM];

double dist[MAXN];

// ���Ӷ�O()�У�V��E�ֱ����ͼ�ĵ�ͱߣ����㷨���Ӷ�ΪO(VE)
bool Bellman_Ford(int N, int M, int S, double V) {
	memset(dist, 0, sizeof(dist));	// ��ʼ��ͼ������������Ȩ�������Բ��ǰ�ÿ��ֵ����ΪInfinite������Ϊ0�����Ӷ�O(V)
	dist[S - 1] = V;
	double temp;
	bool flag;
	for (int i = 0; i < N - 1; i++) {	// ���Ӷ�ΪO(VE)
		flag = false;
		for (int j = 0; j < M * 2; j++) {	// ��ÿ���߽����ɳڲ��������Ӷ�ΪO(E)
			temp = (dist[edges[j].start] - edges[j].commission) * edges[j].rate;
			if (temp > dist[edges[j].end]) {
				dist[edges[j].end] = temp;
				flag = true;
			}
		}
		if (flag == false) {	// �������һ��flag��������ǰ�жϴ�ѭ���Ƿ�û�б߿����ɳڣ���ǰ�˳�ѭ�������Ӷ�ΪO(E)
			break;
		}
	}
	for (int i = 0; i < M * 2; i++) {	// ����Ƿ�����Ȩ���Ĵ���
		temp = (dist[edges[i].start] - edges[i].commission) * edges[i].rate;
		if (temp > dist[edges[i].end]) {
			return true;
		}
	}
	return false;
}


int main() {
	int  N, M, S;
	double V;
	cin >> N >> M >> S >> V;

	int a, b;
	double r_ab, c_ab, r_ba, c_ba;
	int t = 0;


	for (int i = 0; i < M; i++) {
		cin >> a >> b >> r_ab >> c_ab >> r_ba >> c_ba;
		edges[t].start = a - 1;
		edges[t].end = b - 1;
		edges[t].rate = r_ab;
		edges[t].commission = c_ab;
		t++;
		edges[t].start = b - 1;
		edges[t].end = a - 1;
		edges[t].rate = r_ba;
		edges[t].commission = c_ba;
		t++;
	}

	if (Bellman_Ford(N, M, S, V)) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}