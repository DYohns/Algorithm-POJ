###题目

[P1860. Currency Exchange](http://poj.org/problem?id=1860)

###题解

这是一道图算法，涉及有关最短路径Bellman-Ford算法，不过此题并不是求负权环，而是利用Bellman-Ford算法求出正权环，所以在初始化图中，是将dist中设为0，而不是Infinity

###资源

 * wiki: [https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm](https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm)
 * youtube: [https://www.youtube.com/watch?v=iTW2yFYd1Nc](https://www.youtube.com/watch?v=iTW2yFYd1Nc)
