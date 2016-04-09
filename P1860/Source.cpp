/*
	题目：http://poj.org/problem?id=1860
	题解：这是一道图算法，涉及有关最短路径Bellman-Ford算法
		 不过此题并不是求负权环，而是利用Bellman-Ford算法求出正权环。
	资源：https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm
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

// 复杂度O()中，V，E分别代表图的点和边，该算法复杂度为O(VE)
bool Bellman_Ford(int N, int M, int S, double V) {
	memset(dist, 0, sizeof(dist));	// 初始化图，由于是求正权环，所以不是把每个值设置为Infinite，而是为0，复杂度O(V)
	dist[S - 1] = V;
	double temp;
	bool flag;
	for (int i = 0; i < N - 1; i++) {	// 复杂度为O(VE)
		flag = false;
		for (int j = 0; j < M * 2; j++) {	// 对每条边进行松弛操作，复杂度为O(E)
			temp = (dist[edges[j].start] - edges[j].commission) * edges[j].rate;
			if (temp > dist[edges[j].end]) {
				dist[edges[j].end] = temp;
				flag = true;
			}
		}
		if (flag == false) {	// 这里添加一个flag，可以提前判断此循环是否没有边可以松弛，提前退出循环，复杂度为O(E)
			break;
		}
	}
	for (int i = 0; i < M * 2; i++) {	// 求出是否有正权环的存在
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