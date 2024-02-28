> [!Caution]
> 이 문제집은 정답 코드만 나와있습니다. C++ 언어로 제공됩니다.
> 
> 유형에 대해 어느 정도 숙지하고 있는 사람들을 위한 문제집입니다.
> 
> 문제를 아예 처음부터 푸는 사람들을 위한 문제집이 아닙니다.
> 
> 문제를 한 번 이상 풀어본 경험이 있다면 복기하기에 좋습니다.

# BOJ(백준 온라인 저지) 유형별 고난이도 문제 코드
- 코딩테스트에서 자주 나오는 문제 유형별로 어려운 문제들을 선정했습니다.
- 난이도는 실버 상위 ~ 골드 하위 수준입니다.
- 링크를 누르면 정답 코드로 이동합니다. 문제를 풀려면 코드 상단에 있는 링크를 통해 이동해주세요.

## 목차 (ABC순)
### Back Tracking
[1182 Silver2 부분수열의 합](/BackTracking/1182_s2_subsequence.cpp)
- 백트래킹의 기초인 dfs 탐색에 대해 알아봅니다.

[9663 Gold4 N-Queen](/BackTracking/9663_g4_nqueen.cpp)
- 크게 두 가지 방법이 존재합니다.
- 정석 방법을 찾기 위해서는 꽤 많은 고민이 필요합니다.
- 대각선 방향의 위치값도 저장한다면 어떨까요?

### Binary Search
[1654 Silver2 랜선 자르기](/BinarySearch/1654_s2_lancutting.cpp)
- 문제만 봤을 때는 이분 탐색이라고 생각하기 힘듭니다.
- Parametric Search 유형의 대표적인 문제이며 최적화 문제를 결정 문제로 푸는 법에 대해 배웁니다.

[2295 Gold4 세 수의 합](/BinarySearch/2295_g4_sumofthree.cpp)
- O(N³) 문제를 O(N²LogN) 문제로 치환하는 방법에 대해 알아봅니다.
- Meet in the middle 알고리즘의 대표적인 문제입니다.

[11997 Gold3 Load Balancing](/BinarySearch/11997_g3_loadbalancing.cpp)
- 영어에 주의하세요!
- 중복 값을 제거하고 좌표 압축을 하는 이분 탐색의 개념과, 동적계획법을 사용한 누적합의 개념이 필요합니다.
- 좌표 압축을 왜 해야 하는지에 대한 해답을 제시하는 정석과도 같은 문제입니다.

[1450 Gold1 냅색문제](/BinarySearch/1450_g1_knapsack2.cpp)
- 우리가 알던 그 배낭문제와는 좀 다릅니다.
- Meet in the middle 알고리즘의 심화

### DP (Dynamic Programming)
[12865 Gold5 평범한 배낭](/DP/12865_g5_knapsack.cpp)
- 우리가 알던 그 배낭 문제입니다.
- 골드5라고 하기엔 꽤나 난이도 있는 문제

[9251 Gold5 LCS](/DP/9251_g5_lcs.cpp)
- Longest Common Subsequence
- 처음에는 이해하기 어렵습니다. 그림으로 이해하면 쉬운 문제

[11054 Gold4 가장 긴 바이토닉 부분 수열](/DP/11054_g4_lbs.cpp)
- LIS와 LDS를 합친 문제
- LIS 개념을 알고 있다면 푸는데 크게 어려움은 없습니다.
- LIS에서 짚고 넘어가야할 부분이 있다면, DP[X]가 언제나 정답을 반환해주지 않을 수도 있다는 것입니다. (DP[4] 라고 해서 이것이 항상 4번째 값 까지 탐색했을 때 가장 긴 증가하는 부분수열이라고 확정할 수 없다는 얘기입니다. 하지만 N까지 탐색했을 때에는 정답이 되어야 합니다.)

[11049 Gold3 행렬의 곱셈](/DP/11049_g3_matrix.cpp)
- 어려운 문제이지만 행렬의 곱하기 방식을 잘 생각해봅시다.

[11066 Gold3 파일 합치기](/DP/11066_g3_filecomb.cpp)
- 위 문제와 비슷한 방식으로 풀 수 있습니다.
- Knuth Optimization이 가능합니다. 심화 학습을 하고 싶다면 크누스 최적화를 적용하여 풀어보세요.

### Deque
[5430 Gold5 AC](/Deque/5430_g5_ac.cpp)
- 데크를 사용하면 시퀀스 컨테이너의 요소들을 물리적으로 뒤집지 않고 논리적으로 풀 수 있습니다.

### Divide And Conquer
[1074 Silver1 Z](/DivideAndConquer/1074_s1_z.cpp)
- 분할 정복의 대표적인 문제

[1992 Silver1 쿼드 트리](/DivideAndConquer/1992_s1_quadtree.cpp)
- 흑백 이미지를 압축하는 쿼드 트리 자료구조에 대해 알아봅니다.
- 문자열 출력이 관건입니다. 분할 정복 과정에서 문자열이 합쳐지거나 분리되면 메모리 초과가 발생합니다.

### 기하학(Geometry)
[11758 Gold5 CCW](/Geometry/11758_g5_ccw.cpp)
- CCW 알고리즘
- 결정론적 문제를 컴퓨터로 풀 때, 부동 소수점을 사용할 수 없습니다. 정수만으로 어떻게 결정론적 기하학 문제를 풀 수 있을까요?

[2166 Gold5 다각형의 면적](/Geometry/2166_g5_polygon.cpp)
- CCW 알고리즘을 적용하여 다각형의 면적을 구해봅시다.
- 벡터의 외적은 곧 두 벡터가 이루는 평행사변형의 넓이입니다.
- 수학에서 사용하는 외적은 오른손 법칙을 따릅니다. 즉, 반시계 방향으로 두 벡터를 Cross한 값이 양수가 됩니다. (Direct X 같은 라이브러리에서 사용하는 왼손 좌표계와 다르다는 것에 유의)

### Graph
[2178 Silver1 미로 탐색](Graph/2178_s1_bfsmaze.cpp)
- DFS는 최단거리를 보장하지 않습니다. BFS로 풀어야 합니다.

[7569 Gold5 토마토](Graph/7569_g5_bfs.cpp)
- BFS로 탐색하면서 값을 점점 증가시켜가야 합니다.
- 3차원 공간에서 생각하는게 어렵다면 2차원 버전의 문제도 있습니다.

[1753 Gold4 최단 경로](Graph/1753_g4_dijkstra.cpp)
- 다익스트라 알고리즘
- 우선순위 큐를 사용해서 시간복잡도를 줄여야 합니다.

[1197 Gold4 최소 스패닝 트리](Graph/1197_g4_mst.cpp)
- MST(Minimum Spanning Tree)
- Union Find 알고리즘으로 사이클 여부를 확인하면서 탐색합니다.
- 크루스칼, 프림 알고리즘의 기반

[14502 Gold4 연구소](Graph/14502_g4_lab.cpp)
- 쉬운 문제처럼 보이지만 탐색 방법을 어떻게 정하는지에 따라 시간복잡도가 크게 달라질 수 있습니다.

[1005 Gold3 ACM Craft](Graph/1005_g3_acmcraft.cpp)
- 위상 정렬과 동적계획법의 콜라보

[11780 Gold2 플로이드2](Graph/11780_g2_floyd2.cpp)
- 플로이드 워셜 알고리즘에서 한 단계 더 나아갑니다.
- 각 위치에서의 경로를 하나의 배열로 나타낼 수 있습니다.

### Greedy
[1931 Silver1 회의실 배정](Greedy/1931_s1_meetingroom.cpp)
- 정렬 방법을 잘 고민해봅시다.

[1911 Gold5 흙길 보수하기](Greedy/1911_g5_dirtroad.cpp)
- 예외 처리 과정이 험난할 수 있습니다.
- 정수만으로 올림(ceiling)을 구현하는 방법도 있습니다.

### 정수론(Number Theory)
[1629 Silver1 곱셈](NumberTheory/1629_s1_multiple.cpp)
- 지수 법칙과 모듈러 성질을 이용합니다.
- 분할 정복 개념을 이용합니다.

[6064 Silver1 카잉 달력](NumberTheory/6064_s1_kaiing.cpp)
- GCD(최대공약수)와 LCM(최소공배수) 개념을 이용합니다.
- 라이브러리가 없다면? GCD는 유클리드 호제법으로 구할 수 있고, LCM은 M과 N의 곱을 GCD로 나눈 것이 됩니다.

### Trie
[14725 Gold3 개미굴](Trie/14725_g3_antcave.cpp)
- 문자열 탐색 시간을 크게 단축시키는 트라이 알고리즘에 대해 배워봅니다.
- 문자가 아닌 문자열을 저장하는 노드를 구현하기 위해 map 구조를 사용합니다.

### Two Pointer
[2470 Gold5 두 용액](TwoPointer/1644_g3_sumofpn.cpp)
- 투 포인터의 기본 격인 문제

[1644 Gold3 소수의 연속합](TwoPointer/1644_g3_sumofpn.cpp)
- 소수를 구하는 과정에서의 시간복잡도를 줄여야 합니다. 에라토스테네스의 체 정도만 써도 충분히 빠릅니다.
- 투 포인터를 사용하는 과정에서 각 포인터의 시작점을 어떻게 둬야 할지 고민해봅시다.