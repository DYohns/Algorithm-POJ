/*************************************************************

��Ŀ�� P3259.Wormholes http://poj.org/problem?id=3259
���⣺ ũ��FJ��N(1<=N<=500)����أ���ؼ���M(1<=M<=2500)��·������W(1<=W<=200)���涴
      ���У�·����˫��ģ�ͨ��·����Ҫ����һ����ʱ�䣻���涴�ǵ���ͨ���涴��ص���ǰ��ʱ��㣬Ҳ����ʱ�����١�
	  ��FJ�Ƿ��ܹ���ĳһ�������Ϊ��㿪ʼ��Ȼ��ͨ��·�����߳涴�ص���ǰ����㣬Ҳ����ʱ�⵹���ص�ԭ�ء�
��⣺ ������Ա�ʾΪ���ͼ���Ƿ���ڸ�Ȩ�������õ��㷨��Bellman-Ford�㷨���������ͼ�е����·�����Լ��Ƿ���ڸ�Ȩ����
���ϣ� wiki - https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm
      youtube - https://www.youtube.com/watch?v=iTW2yFYd1Nc

**************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;
const int INF = 10000;
const int MAXM = 2500 * 2 + 200 + 10;
const int MAXN = 510;
struct Edge {
	int start;
	int end;
	int weight;
};
Edge edges[MAXM];
int dist[MAXN];

bool Bellman_Ford(int N, int T) {
	memset(dist, INF, sizeof(dist));	// �����г�ʼ��Ϊ���ֵ
	dist[0] = 0;
	int temp;
	for (int i = 0; i < N - 1; i++) {
		int flag = true;
		for (int j = 0; j < T; j++) {
			temp = dist[edges[j].start] + edges[j].weight;
			if (temp < dist[edges[j].end]) {	// �ɳڲ���
				dist[edges[j].end] = temp;
				flag = false;
			}
		}
		if (flag) {	// �������޷��ɳڣ�ֱ���ж�û�и�Ȩ��
			return false;
		}
	}

	for (int i = 0; i < T; i++) {	// �ٴ�ѭ���ж��ܷ�����ɳ�
		temp = dist[edges[i].start] + edges[i].weight;
		if (temp < dist[edges[i].end]) {
			return true;
		}
	}
	return false;
}


int main() {
	int F, N, M, W;
	int _start, _end, _weight;
	cin >> F;
	while (F--) {
		cin >> N >> M >> W;
		int t = 0;
		for (int i = 0; i < M; i++) {
			cin >> _start >> _end >> _weight;
			edges[t].start = _start - 1;
			edges[t].end = _end - 1;
			edges[t].weight = _weight;
			t++;
			edges[t].start = _end - 1;
			edges[t].end = _start - 1;
			edges[t].weight = _weight;
			t++;
		}
		for (int i = 0; i < W; i++) {
			cin >> _start >> _end >> _weight;
			edges[t].start = _start - 1;
			edges[t].end = _end - 1;
			edges[t].weight = _weight * -1;
			t++;
		}
		if (Bellman_Ford(N, t)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	return 0;
}