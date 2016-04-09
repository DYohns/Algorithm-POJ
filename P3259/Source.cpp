/*************************************************************

题目： P3259.Wormholes http://poj.org/problem?id=3259
题意： 农夫FJ有N(1<=N<=500)块田地，田地间有M(1<=M<=2500)条路径，有W(1<=W<=200)个虫洞
      其中，路径是双向的，通过路径需要花费一定的时间；而虫洞是单向，通过虫洞会回到以前的时间点，也就是时间会减少。
	  求FJ是否能够从某一块田地作为起点开始，然后通过路径或者虫洞回到以前的起点，也就是时光倒流回到原地。
题解： 此题可以表示为求出图中是否存在负权环，采用的算法是Bellman-Ford算法，可以求出图中的最短路径，以及是否存在负权环。
资料： wiki - https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm
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
	memset(dist, INF, sizeof(dist));	// 将所有初始化为最大值
	dist[0] = 0;
	int temp;
	for (int i = 0; i < N - 1; i++) {
		int flag = true;
		for (int j = 0; j < T; j++) {
			temp = dist[edges[j].start] + edges[j].weight;
			if (temp < dist[edges[j].end]) {	// 松弛操作
				dist[edges[j].end] = temp;
				flag = false;
			}
		}
		if (flag) {	// 若这轮无法松弛，直接判断没有负权环
			return false;
		}
	}

	for (int i = 0; i < T; i++) {	// 再次循环判断能否继续松弛
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