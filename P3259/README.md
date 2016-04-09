
###题目

[P3259. Wormholes](http://poj.org/problem?id=3259)

###题意

农夫FJ有N(1<=N<=500)块田地，田地间有M(1<=M<=2500)条路径，有W(1<=W<=200)个虫洞。其中，路径是双向的，通过路径需要花费一定的时间；而虫洞是单向，通过虫洞会回到以前的时间点，也就是时间会减少。求FJ是否能够从某一块田地作为起点开始，然后通过路径或者虫洞回到以前的起点，也就是时光倒流回到原地。

###题解

此题可以表示为求出图中是否存在负权环，采用的是Bellman-Ford算法，可以求出图中的最短路径，以及是否存在负权环。

###资料

 * wiki: [https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm](https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm)
 * youtube: [https://www.youtube.com/watch?v=iTW2yFYd1Nc](https://www.youtube.com/watch?v=iTW2yFYd1Nc)
 
