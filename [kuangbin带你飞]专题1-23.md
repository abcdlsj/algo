# [kuangbin带你飞]专题1-23

> 不求写完，因为我不是 ACM 选手，只是为了锻炼一下自己的算法水平

 `.clang-format`

``` sh
BasedOnStyle: llvm
IndentWidth: 4
```

## 专题一 简单搜索

[**POJ 1321**](https://vjudge.net/problem/POJ-1321) 棋盘问题
[**POJ 2251**](https://vjudge.net/problem/POJ-2251) Dungeon Master
[**POJ 3278**](https://vjudge.net/problem/POJ-3278) Catch That Cow
[**POJ 3279**](https://vjudge.net/problem/POJ-3279) Fliptile
[**POJ 1426**](https://vjudge.net/problem/POJ-1426) Find The Multiple
[**POJ 3126**](https://vjudge.net/problem/POJ-3126) Prime Path
[**POJ 3087**](https://vjudge.net/problem/POJ-3087) Shuffle'm Up
[**POJ 3414**](https://vjudge.net/problem/POJ-3414) Pots
[**FZU 2150**](https://vjudge.net/problem/FZU-2150) Fire Game
[**UVA 11624**](https://vjudge.net/problem/UVA-11624) Fire!
[**POJ 3984**](https://vjudge.net/problem/POJ-3984) 迷宫问题
[**HDU 1241**](https://vjudge.net/problem/HDU-1241) Oil Deposits
[**HDU 1495**](https://vjudge.net/problem/HDU-1495) 非常可乐
[**HDU 2612**](https://vjudge.net/problem/HDU-2612) Find a way

### 专题二 搜索进阶

[**HDU 1043**](https://vjudge.net/problem/HDU-1043) Eight
[**HDU 3567**](https://vjudge.net/problem/HDU-3567) Eight II
[**HDU 2181**](https://vjudge.net/problem/HDU-2181) 哈密顿绕行世界问题
[**HDU 3533**](https://vjudge.net/problem/HDU-3533) Escape
[**HDU 1560**](https://vjudge.net/problem/HDU-1560) DNA sequence
[**ZOJ 2477**](https://vjudge.net/problem/ZOJ-2477) Magic Cube
[**HDU 3085**](https://vjudge.net/problem/HDU-3085) Nightmare Ⅱ
[**HDU 1067**](https://vjudge.net/problem/HDU-1067) Gap
[**HDU 2102**](https://vjudge.net/problem/HDU-2102) A计划
[**HDU 3001**](https://vjudge.net/problem/HDU-3001) Travelling

### 专题三 Dancing Links

[**HUST 1017**](https://vjudge.net/problem/HUST-1017) Exact cover
[**ZOJ 3209**](https://vjudge.net/problem/ZOJ-3209) Treasure Map
[**HDU 2295**](https://vjudge.net/problem/HDU-2295) Radar
[**FZU 1686**](https://vjudge.net/problem/FZU-1686) 神龙的难题
[**POJ 1084**](https://vjudge.net/problem/POJ-1084) Square Destroyer
[**POJ 3074**](https://vjudge.net/problem/POJ-3074) Sudoku
[**ZOJ 3122**](https://vjudge.net/problem/ZOJ-3122) Sudoku
[**HDU 4069**](https://vjudge.net/problem/HDU-4069) Squiggly Sudoku
[**HDU 3335**](https://vjudge.net/problem/HDU-3335) Divisibility
[**HDU 4979**](https://vjudge.net/problem/HDU-4979) A simple math problem.
[**HDU 5046**](https://vjudge.net/problem/HDU-5046) Airport

### 专题四 最短路练习

[**POJ 2387**](https://vjudge.net/problem/POJ-2387) Til the Cows Come Home
[**POJ 2253**](https://vjudge.net/problem/POJ-2253) Frogger
[**POJ 1797**](https://vjudge.net/problem/POJ-1797) Heavy Transportation
[**POJ 3268**](https://vjudge.net/problem/POJ-3268) Silver Cow Party
[**POJ 1860**](https://vjudge.net/problem/POJ-1860) Currency Exchange
[**POJ 3259**](https://vjudge.net/problem/POJ-3259) Wormholes
[**POJ 1502**](https://vjudge.net/problem/POJ-1502) MPI Maelstrom
[**POJ 3660**](https://vjudge.net/problem/POJ-3660) Cow Contest
[**POJ 2240**](https://vjudge.net/problem/POJ-2240) Arbitrage
[**POJ 1511**](https://vjudge.net/problem/POJ-1511) Invitation Cards
[**POJ 3159**](https://vjudge.net/problem/POJ-3159) Candies
[**POJ 2502**](https://vjudge.net/problem/POJ-2502) Subway
[**POJ 1062**](https://vjudge.net/problem/POJ-1062) 昂贵的聘礼
[**POJ 1847**](https://vjudge.net/problem/POJ-1847) Tram
[**LightOJ 1074**](https://vjudge.net/problem/LightOJ-1074) Extended Traffic
[**HDU 4725**](https://vjudge.net/problem/HDU-4725) The Shortest Path in Nya Graph
[**HDU 3416**](https://vjudge.net/problem/HDU-3416) Marriage Match IV
[**HDU 4370**](https://vjudge.net/problem/HDU-4370) 0 or 1
[**POJ 3169**](https://vjudge.net/problem/POJ-3169) Layout

### 专题五 并查集

[**POJ 2236**](https://vjudge.net/problem/POJ-2236) Wireless Network

``` cpp
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

vector<int> fa;
vector<int> ra;
int cnt;

int find(int x) {
    if (x != fa[x]) {
        fa[x] = find(fa[x]);
    }

    return fa[x];
}

void unionset(int a, int b) {
    int x = find(a), y = find(b);
    if (x == y)
        return;
    if (ra[x] > ra[y]) {
        swap(x, y);
    }
    ra[y] += ra[x];
    fa[x] = fa[y];
    cnt--;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, d;
    cin >> n >> d;
    vector<int> vx(n + 1);
    vector<int> vy(n + 1);
    fa.resize(n + 1);
    ra.resize(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        cin >> vx[i] >> vy[i];
        fa[i] = i;
    }
    vector<vector<int>> edges(n + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int dis = (vx[i] - vx[j]) * (vx[i] - vx[j]) +
                      (vy[i] - vy[j]) * (vy[i] - vy[j]);
            if (dis <= d * d) {
                edges[i].push_back(j);
                edges[j].push_back(i);
            }
        }
    }

    vector<bool> repair(n + 1, false);
    char o;
    while (cin >> o && o) {
        if (o == 'O') {
            int x;
            cin >> x;
            repair[x] = true;
            for (int i = 0; i < edges[x].size(); i++) {
                if (repair[edges[x][i]]) {
                    unionset(edges[x][i], x);
                }
            }
        } else {
            int x, y;
            cin >> x >> y;
            if (find(x) == find(y)) {
                cout << "SUCCESS\n";
            } else {
                cout << "FAIL\n";
            }
        }
    }
}
```

[**POJ 1611**](https://vjudge.net/problem/POJ-1611) The Suspects

``` cpp
#include <iostream>
#include <vector>
using namespace std;

vector<int> fa;
vector<int> ra;
int cnt;

int find(int x) {
    if (x != fa[x]) {
        fa[x] = find(fa[x]);
    }

    return fa[x];
}

void unionset(int a, int b) {
    int x = find(a), y = find(b);
    if (x == y)
        return;
    if (ra[x] > ra[y]) {
        swap(x, y);
    }
    ra[y] += ra[x];
    fa[x] = fa[y];
    cnt--;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    while (cin >> n >> m) {
        if (m == 0 && n == 0) break;
        fa.resize(n);
        for (int i = 0; i < n; i++)
            fa[i] = i;
        ra.resize(n, 1);

        while (m--) {
            int k, a;
            cin >> k >> a;
            k--;
            while (k--) {
                int b;
                cin >> b;
                unionset(a, b);
            }
        }
        int ans = 1;
        for (int i = 1; i < n; i++) {
            if (find(0) == find(i)) {
                ans++;
            }
        }
        cout << ans << "\n";
    }
}
```

[**HDU 1213**](https://vjudge.net/problem/HDU-1213) How Many Tables

``` cpp
#include <iostream>
#include <vector>
using namespace std;

int cnt;
vector<int> father;
vector<int> ranks;
int findset(int x) {
    if (x != father[x]) {
        father[x] = findset(father[x]);
    }
    return father[x];
}
void unionset(int a, int b) {
    int x = findset(a), y = findset(b);
    if (x == y)
        return;
    if (ranks[x] > ranks[y]) {
        swap(x, y);
    }
    father[x] = y;
    ranks[y] += ranks[x];
    cnt--;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int N, M;
        cin >> N >> M;
        father.resize(N + 1);
        ranks.resize(N + 1, 1);
        cnt = N;
        for (int i = 0; i <= N; i++)
            father[i] = i;
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            unionset(a, b);
        }
        cout << cnt << "\n";
    }
    return 0;
}
```

[**HDU 3038**](https://vjudge.net/problem/HDU-3038) How Many Answers Are Wrong
[**POJ 1182**](https://vjudge.net/problem/POJ-1182) 食物链
[**POJ 1417**](https://vjudge.net/problem/POJ-1417) True Liars
[**POJ 1456**](https://vjudge.net/problem/POJ-1456) Supermarket
[**POJ 1733**](https://vjudge.net/problem/POJ-1733) Parity game
[**POJ 1984**](https://vjudge.net/problem/POJ-1984) Navigation Nightmare
[**POJ 2492**](https://vjudge.net/problem/POJ-2492) A Bug's Life
[**POJ 2912**](https://vjudge.net/problem/POJ-2912) Rochambeau
[**ZOJ 3261**](https://vjudge.net/problem/ZOJ-3261) Connections in Galaxy War
[**HDU 1272**](https://vjudge.net/problem/HDU-1272) 小希的迷宫
[**POJ 1308**](https://vjudge.net/problem/POJ-1308) Is It A Tree?

### 专题六 最小生成树

[**POJ 1251**](https://vjudge.net/problem/POJ-1251) Jungle Roads
[**POJ 1287**](https://vjudge.net/problem/POJ-1287) Networking
[**POJ 2031**](https://vjudge.net/problem/POJ-2031) Building a Space Station
[**POJ 2421**](https://vjudge.net/problem/POJ-2421) Constructing Roads
[**ZOJ 1586**](https://vjudge.net/problem/ZOJ-1586) QS Network
[**POJ 1789**](https://vjudge.net/problem/POJ-1789) Truck History
[**POJ 2349**](https://vjudge.net/problem/POJ-2349) Arctic Network
[**POJ 1751**](https://vjudge.net/problem/POJ-1751) Highways
[**POJ 1258**](https://vjudge.net/problem/POJ-1258) Agri-Net
[**POJ 3026**](https://vjudge.net/problem/POJ-3026) Borg Maze
[**POJ 1679**](https://vjudge.net/problem/POJ-1679) The Unique MST
[**HDU 1233**](https://vjudge.net/problem/HDU-1233) 还是畅通工程
[**HDU 1301**](https://vjudge.net/problem/HDU-1301) Jungle Roads
[**HDU 1875**](https://vjudge.net/problem/HDU-1875) 畅通工程再续

### 专题七 线段树

[**HDU 1166**](https://vjudge.net/problem/HDU-1166) 敌兵布阵
[**HDU 1754**](https://vjudge.net/problem/HDU-1754) I Hate It
[**POJ 3468**](https://vjudge.net/problem/POJ-3468) A Simple Problem with Integers
[**POJ 2528**](https://vjudge.net/problem/POJ-2528) Mayor's posters
[**HDU 1698**](https://vjudge.net/problem/HDU-1698) Just a Hook
[**ZOJ 1610**](https://vjudge.net/problem/ZOJ-1610) Count the Colors
[**POJ 3264**](https://vjudge.net/problem/POJ-3264) Balanced Lineup
[**HDU 4027**](https://vjudge.net/problem/HDU-4027) Can you answer these queries?
[**HDU 1540**](https://vjudge.net/problem/HDU-1540) Tunnel Warfare
[**HDU 3974**](https://vjudge.net/problem/HDU-3974) Assign the task
[**HDU 4578**](https://vjudge.net/problem/HDU-4578) Transformation
[**HDU 4614**](https://vjudge.net/problem/HDU-4614) Vases and Flowers
[**HDU 4553**](https://vjudge.net/problem/HDU-4553) 约会安排
[**POJ 1177**](https://vjudge.net/problem/POJ-1177) Picture
[**HDU 1255**](https://vjudge.net/problem/HDU-1255) 覆盖的面积
[**HDU 1542**](https://vjudge.net/problem/HDU-1542) Atlantis
[**HDU 3642**](https://vjudge.net/problem/HDU-3642) Get The Treasury

### 专题八 生成树

[**POJ 1679**](https://vjudge.net/problem/POJ-1679) The Unique MST
[**HDU 4081**](https://vjudge.net/problem/HDU-4081) Qin Shi Huang's National Road System
[**UVA 10600**](https://vjudge.net/problem/UVA-10600) ACM Contest and Blackout
[**UVA 10462**](https://vjudge.net/problem/UVA-10462) Is There A Second Way Left?
[**POJ 3164**](https://vjudge.net/problem/POJ-3164) Command Network
[**UVA 11183**](https://vjudge.net/problem/UVA-11183) Teen Girl Squad
[**HDU 2121**](https://vjudge.net/problem/HDU-2121) Ice_cream’s world II
[**HDU 4009**](https://vjudge.net/problem/HDU-4009) Transfer water
[**UVA 10766**](https://vjudge.net/problem/UVA-10766) Organising the Organisation
[**SPOJ DETER3**](https://vjudge.net/problem/SPOJ-DETER3) Find The Determinant III
[**URAL 1627**](https://vjudge.net/problem/URAL-1627) Join
[**HDU 4305**](https://vjudge.net/problem/HDU-4305) Lightning
[**HDU 4408**](https://vjudge.net/problem/HDU-4408) Minimum Spanning Tree
[**SPOJ HIGH**](https://vjudge.net/problem/SPOJ-HIGH) Highways

### 专题九 连通图

[**POJ 1236**](https://vjudge.net/problem/POJ-1236) Network of Schools
[**UVA 315**](https://vjudge.net/problem/UVA-315) Network
[**UVA 796**](https://vjudge.net/problem/UVA-796) Critical Links
[**POJ 3694**](https://vjudge.net/problem/POJ-3694) Network
[**POJ 3177**](https://vjudge.net/problem/POJ-3177) Redundant Paths
[**HDU 4612**](https://vjudge.net/problem/HDU-4612) Warm up
[**HDU 4635**](https://vjudge.net/problem/HDU-4635) Strongly connected
[**HDU 4685**](https://vjudge.net/problem/HDU-4685) Prince and Princess
[**HDU 4738**](https://vjudge.net/problem/HDU-4738) Caocao's Bridges

### 专题十 匹配问题

[**HDU 1045**](https://vjudge.net/problem/HDU-1045) Fire Net
[**HDU 2444**](https://vjudge.net/problem/HDU-2444) The Accomodation of Students
[**HDU 1083**](https://vjudge.net/problem/HDU-1083) Courses
[**HDU 1281**](https://vjudge.net/problem/HDU-1281) 棋盘游戏
[**HDU 2819**](https://vjudge.net/problem/HDU-2819) Swap
[**HDU 2389**](https://vjudge.net/problem/HDU-2389) Rain on your Parade
[**HDU 4185**](https://vjudge.net/problem/HDU-4185) Oil Skimming
[**POJ 3020**](https://vjudge.net/problem/POJ-3020) Antenna Placement
[**HDU 1054**](https://vjudge.net/problem/HDU-1054) Strategic Game
[**HDU 1151**](https://vjudge.net/problem/HDU-1151) Air Raid
[**POJ 2594**](https://vjudge.net/problem/POJ-2594) Treasure Exploration
[**HDU 3829**](https://vjudge.net/problem/HDU-3829) Cat VS Dog
[**POJ 2289**](https://vjudge.net/problem/POJ-2289) Jamie's Contact Groups
[**POJ 2112**](https://vjudge.net/problem/POJ-2112) Optimal Milking
[**POJ 3189**](https://vjudge.net/problem/POJ-3189) Steady Cow Assignment
[**HDU 2255**](https://vjudge.net/problem/HDU-2255) 奔小康赚大钱
[**HDU 3488**](https://vjudge.net/problem/HDU-3488) Tour
[**URAL 1099**](https://vjudge.net/problem/URAL-1099) Work Scheduling
[**HDU 4687**](https://vjudge.net/problem/HDU-4687) Boke and Tsukkomi

## 专题十一 网络流

[**POJ 3436**](https://vjudge.net/problem/POJ-3436) ACM Computer Factory
[**POJ 3281**](https://vjudge.net/problem/POJ-3281) Dining
[**POJ 1087**](https://vjudge.net/problem/POJ-1087) A Plug for UNIX
[**POJ 2195**](https://vjudge.net/problem/POJ-2195) Going Home
[**POJ 2516**](https://vjudge.net/problem/POJ-2516) Minimum Cost
[**POJ 1459**](https://vjudge.net/problem/POJ-1459) Power Network
[**HDU 4280**](https://vjudge.net/problem/HDU-4280) Island Transport
[**HDU 4292**](https://vjudge.net/problem/HDU-4292) Food
[**HDU 4289**](https://vjudge.net/problem/HDU-4289) Control
[**UVA 10480**](https://vjudge.net/problem/UVA-10480) Sabotage
[**HDU 2732**](https://vjudge.net/problem/HDU-2732) Leapin' Lizards
[**HDU 3338**](https://vjudge.net/problem/HDU-3338) Kakuro Extension
[**HDU 3605**](https://vjudge.net/problem/HDU-3605) Escape
[**HDU 3081**](https://vjudge.net/problem/HDU-3081) Marriage Match II
[**HDU 3416**](https://vjudge.net/problem/HDU-3416) Marriage Match IV

## 专题十二 基础DP1

[**HDU 1024**](https://vjudge.net/problem/HDU-1024) Max Sum Plus Plus
[**HDU 1029**](https://vjudge.net/problem/HDU-1029) Ignatius and the Princess IV
[**HDU 1069**](https://vjudge.net/problem/HDU-1069) Monkey and Banana
[**HDU 1074**](https://vjudge.net/problem/HDU-1074) Doing Homework
[**HDU 1087**](https://vjudge.net/problem/HDU-1087) Super Jumping! Jumping! Jumping!
[**HDU 1114**](https://vjudge.net/problem/HDU-1114) Piggy-Bank
[**HDU 1176**](https://vjudge.net/problem/HDU-1176) 免费馅饼
[**HDU 1260**](https://vjudge.net/problem/HDU-1260) Tickets
[**HDU 1257**](https://vjudge.net/problem/HDU-1257) 最少拦截系统
[**HDU 1160**](https://vjudge.net/problem/HDU-1160) FatMouse's Speed
[**POJ 1015**](https://vjudge.net/problem/POJ-1015) Jury Compromise
[**POJ 1458**](https://vjudge.net/problem/POJ-1458) Common Subsequence
[**POJ 1661**](https://vjudge.net/problem/POJ-1661) Help Jimmy
[**POJ 2533**](https://vjudge.net/problem/POJ-2533) Longest Ordered Subsequence
[**POJ 3186**](https://vjudge.net/problem/POJ-3186) Treats for the Cows
[**HDU 1078**](https://vjudge.net/problem/HDU-1078) FatMouse and Cheese
[**HDU 2859**](https://vjudge.net/problem/HDU-2859) Phalanx
[**POJ 3616**](https://vjudge.net/problem/POJ-3616) Milking Time
[**POJ 3666**](https://vjudge.net/problem/POJ-3666) Making the Grade

## 专题十三 基础计算几何

[**POJ 2318**](https://vjudge.net/problem/POJ-2318) TOYS
[**POJ 2398**](https://vjudge.net/problem/POJ-2398) Toy Storage
[**POJ 3304**](https://vjudge.net/problem/POJ-3304) Segments
[**POJ 1269**](https://vjudge.net/problem/POJ-1269) Intersecting Lines
[**POJ 1556**](https://vjudge.net/problem/POJ-1556) The Doors
[**POJ 2653**](https://vjudge.net/problem/POJ-2653) Pick-up sticks
[**POJ 1066**](https://vjudge.net/problem/POJ-1066) Treasure Hunt
[**POJ 1410**](https://vjudge.net/problem/POJ-1410) Intersection
[**POJ 1696**](https://vjudge.net/problem/POJ-1696) Space Ant
[**POJ 3347**](https://vjudge.net/problem/POJ-3347) Kadj Squares
[**POJ 2826**](https://vjudge.net/problem/POJ-2826) An Easy Problem?!
[**POJ 1039**](https://vjudge.net/problem/POJ-1039) Pipe
[**POJ 3449**](https://vjudge.net/problem/POJ-3449) Geometric Shapes
[**POJ 1584**](https://vjudge.net/problem/POJ-1584) A Round Peg in a Ground Hole

## 专题十四 数论基础

[**LightOJ 1370**](https://vjudge.net/problem/LightOJ-1370) Bi-shoe and Phi-shoe
[**LightOJ 1356**](https://vjudge.net/problem/LightOJ-1356) Prime Independence
[**LightOJ 1341**](https://vjudge.net/problem/LightOJ-1341) Aladdin and the Flying Carpet
[**LightOJ 1336**](https://vjudge.net/problem/LightOJ-1336) Sigma Function
[**LightOJ 1282**](https://vjudge.net/problem/LightOJ-1282) Leading and Trailing
[**LightOJ 1259**](https://vjudge.net/problem/LightOJ-1259) Goldbach`s Conjecture
[**LightOJ 1245**](https://vjudge.net/problem/LightOJ-1245) Harmonic Number (II)
[**LightOJ 1236**](https://vjudge.net/problem/LightOJ-1236) Pairs Forming LCM
[**LightOJ 1234**](https://vjudge.net/problem/LightOJ-1234) Harmonic Number
[**LightOJ 1220**](https://vjudge.net/problem/LightOJ-1220) Mysterious Bacteria
[**LightOJ 1214**](https://vjudge.net/problem/LightOJ-1214) Large Division
[**LightOJ 1213**](https://vjudge.net/problem/LightOJ-1213) Fantasy of a Summation
[**LightOJ 1197**](https://vjudge.net/problem/LightOJ-1197) Help Hanzo
[**LightOJ 1138**](https://vjudge.net/problem/LightOJ-1138) Trailing Zeroes (III)
[**UVA 11426**](https://vjudge.net/problem/UVA-11426) GCD - Extreme (II)
[**UVA 11754**](https://vjudge.net/problem/UVA-11754) Code Feat
[**UVA 11916**](https://vjudge.net/problem/UVA-11916) Emoogle Grid
[**POJ 1061**](https://vjudge.net/problem/POJ-1061) 青蛙的约会
[**POJ 2115**](https://vjudge.net/problem/POJ-2115) C Looooops
[**POJ 2116**](https://vjudge.net/problem/POJ-2116) Death to Binary?
[**HDU 2161**](https://vjudge.net/problem/HDU-2161) Primes
[**UVA 11827**](https://vjudge.net/problem/UVA-11827) Maximum GCD
[**UVA 10200**](https://vjudge.net/problem/UVA-10200) Prime Time
[**SGU 106**](https://vjudge.net/problem/SGU-106) The equation
[**POJ 2478**](https://vjudge.net/problem/POJ-2478) Farey Sequence
[**UVA 11752**](https://vjudge.net/problem/UVA-11752) The Super Powers

## 专题十五 数位DP

[**CodeForces 55D**](https://vjudge.net/problem/CodeForces-55D) Beautiful numbers
[**HDU 4352**](https://vjudge.net/problem/HDU-4352) XHXJ's LIS
[**HDU 2089**](https://vjudge.net/problem/HDU-2089) 不要62
[**HDU 3555**](https://vjudge.net/problem/HDU-3555) Bomb
[**POJ 3252**](https://vjudge.net/problem/POJ-3252) Round Numbers
[**HDU 3709**](https://vjudge.net/problem/HDU-3709) Balanced Number
[**HDU 3652**](https://vjudge.net/problem/HDU-3652) B-number
[**HDU 4734**](https://vjudge.net/problem/HDU-4734) F(x)
[**ZOJ 3494**](https://vjudge.net/problem/ZOJ-3494) BCD Code
[**HDU 4507**](https://vjudge.net/problem/HDU-4507) 吉哥系列故事――恨7不成妻
[**SPOJ BALNUM**](https://vjudge.net/problem/SPOJ-BALNUM) Balanced Numbers

## 专题十六 KMP & 扩展KMP & Manacher

[**HDU 1711**](https://vjudge.net/problem/HDU-1711) Number Sequence
[**HDU 1686**](https://vjudge.net/problem/HDU-1686) Oulipo
[**HDU 2087**](https://vjudge.net/problem/HDU-2087) 剪花布条
[**HDU 3746**](https://vjudge.net/problem/HDU-3746) Cyclic Nacklace
[**HDU 1358**](https://vjudge.net/problem/HDU-1358) Period
[**HUST 1010**](https://vjudge.net/problem/HUST-1010) The Minimum Length
[**POJ 2406**](https://vjudge.net/problem/POJ-2406) Power Strings
[**POJ 2752**](https://vjudge.net/problem/POJ-2752) Seek the Name, Seek the Fame
[**POJ 3080**](https://vjudge.net/problem/POJ-3080) Blue Jeans
[**HDU 2594**](https://vjudge.net/problem/HDU-2594) Simpsons’ Hidden Talents
[**HDU 3336**](https://vjudge.net/problem/HDU-3336) Count the string
[**HDU 4300**](https://vjudge.net/problem/HDU-4300) Clairewd’s message
[**HDU 1238**](https://vjudge.net/problem/HDU-1238) Substrings
[**HDU 2328**](https://vjudge.net/problem/HDU-2328) Corporate Identity
[**HDU 3374**](https://vjudge.net/problem/HDU-3374) String Problem
[**HDU 2609**](https://vjudge.net/problem/HDU-2609) How many
[**FZU 1901**](https://vjudge.net/problem/FZU-1901) Period II
[**POJ 3746**](https://vjudge.net/problem/POJ-3746) Teacher YYF
[**HDU 3613**](https://vjudge.net/problem/HDU-3613) Best Reward
[**POJ 3376**](https://vjudge.net/problem/POJ-3376) Finding Palindromes
[**POJ 3974**](https://vjudge.net/problem/POJ-3974) Palindrome
[**HDU 4513**](https://vjudge.net/problem/HDU-4513) 吉哥系列故事――完美队形II
[**HDU 3294**](https://vjudge.net/problem/HDU-3294) Girls' research
[**HDU 3068**](https://vjudge.net/problem/HDU-3068) 最长回文
[**HDU 4847**](https://vjudge.net/problem/HDU-4847) Wow! Such Doge!
[**HDU 4763**](https://vjudge.net/problem/HDU-4763) Theme Section

## 专题十七 AC自动机

[**HDU 2222**](https://vjudge.net/problem/HDU-2222) Keywords Search
[**HDU 2896**](https://vjudge.net/problem/HDU-2896) 病毒侵袭
[**HDU 3065**](https://vjudge.net/problem/HDU-3065) 病毒侵袭持续中
[**ZOJ 3430**](https://vjudge.net/problem/ZOJ-3430) Detect the Virus
[**POJ 2778**](https://vjudge.net/problem/POJ-2778) DNA Sequence
[**HDU 2243**](https://vjudge.net/problem/HDU-2243) 考研路茫茫――单词情结
[**POJ 1625**](https://vjudge.net/problem/POJ-1625) Censored!
[**HDU 2825**](https://vjudge.net/problem/HDU-2825) Wireless Password
[**HDU 2296**](https://vjudge.net/problem/HDU-2296) Ring
[**HDU 2457**](https://vjudge.net/problem/HDU-2457) DNA repair
[**ZOJ 3228**](https://vjudge.net/problem/ZOJ-3228) Searching the String
[**HDU 3341**](https://vjudge.net/problem/HDU-3341) Lost's revenge
[**HDU 3247**](https://vjudge.net/problem/HDU-3247) Resource Archiver
[**ZOJ 3494**](https://vjudge.net/problem/ZOJ-3494) BCD Code
[**HDU 4758**](https://vjudge.net/problem/HDU-4758) Walk Through Squares
[**HDU 4511**](https://vjudge.net/problem/HDU-4511) 小明系列故事――女友的考验

## 专题十八 后缀数组

[**POJ 1743**](https://vjudge.net/problem/POJ-1743) Musical Theme
[**POJ 3261**](https://vjudge.net/problem/POJ-3261) Milk Patterns
[**SPOJ DISUBSTR**](https://vjudge.net/problem/SPOJ-DISUBSTR) Distinct Substrings
[**SPOJ SUBST1**](https://vjudge.net/problem/SPOJ-SUBST1) New Distinct Substrings
[**POJ 2406**](https://vjudge.net/problem/POJ-2406) Power Strings
[**SPOJ REPEATS**](https://vjudge.net/problem/SPOJ-REPEATS) Repeats
[**POJ 3693**](https://vjudge.net/problem/POJ-3693) Maximum repetition substring
[**POJ 2774**](https://vjudge.net/problem/POJ-2774) Long Long Message
[**POJ 3415**](https://vjudge.net/problem/POJ-3415) Common Substrings
[**POJ 3294**](https://vjudge.net/problem/POJ-3294) Life Forms
[**SPOJ PHRASES**](https://vjudge.net/problem/SPOJ-PHRASES) Relevant Phrases of Annihilation
[**POJ 1226**](https://vjudge.net/problem/POJ-1226) Substrings
[**UVA 11475**](https://vjudge.net/problem/UVA-11475) Extend to Palindrome
[**POJ 3581**](https://vjudge.net/problem/POJ-3581) Sequence
[**POJ 3450**](https://vjudge.net/problem/POJ-3450) Corporate Identity
[**POJ 3080**](https://vjudge.net/problem/POJ-3080) Blue Jeans
[**POJ 2758**](https://vjudge.net/problem/POJ-2758) Checking the Text

## 专题十九 矩阵

[**CodeForces 450B**](https://vjudge.net/problem/CodeForces-450B) Jzzhu and Sequences
[**HDU 5015**](https://vjudge.net/problem/HDU-5015) 233 Matrix
[**HDU 4990**](https://vjudge.net/problem/HDU-4990) Reading comprehension
[**UVA 11651**](https://vjudge.net/problem/UVA-11651) Krypton Number System
[**HDU 4965**](https://vjudge.net/problem/HDU-4965) Fast Matrix Calculation
[**UVA 11551**](https://vjudge.net/problem/UVA-11551) Experienced Endeavour
[**UVA 10689**](https://vjudge.net/problem/UVA-10689) Yet another Number Sequence
[**UVA 11149**](https://vjudge.net/problem/UVA-11149) Power of Matrix
[**UVA 10655**](https://vjudge.net/problem/UVA-10655) Contemplation! Algebra
[**UVA 1386**](https://vjudge.net/problem/UVA-1386) Cellular Automaton
[**UVA 10870**](https://vjudge.net/problem/UVA-10870) Recurrences
[**UVA 11885**](https://vjudge.net/problem/UVA-11885) Number of Battlefields
[**HDU 4565**](https://vjudge.net/problem/HDU-4565) So Easy!
[**CodeForces 392C**](https://vjudge.net/problem/CodeForces-392C) Yet Another Number Sequence
[**CodeForces 385E**](https://vjudge.net/problem/CodeForces-385E) Bear in the Field
[**FZU 1911**](https://vjudge.net/problem/FZU-1911) Construct a Matrix
[**UVA 10518**](https://vjudge.net/problem/UVA-10518) How Many Calls?
[**HDU 4549**](https://vjudge.net/problem/HDU-4549) M斐波那契数列
[**HDU 4686**](https://vjudge.net/problem/HDU-4686) Arc of Dream

## 专题二十 斜率DP

[**HDU 3507**](https://vjudge.net/problem/HDU-3507) Print Article
[**HDU 2829**](https://vjudge.net/problem/HDU-2829) Lawrence
[**HDU 4528**](https://vjudge.net/problem/HDU-4528) 小明系列故事――捉迷藏
[**HDU 1300**](https://vjudge.net/problem/HDU-1300) Pearls
[**HDU 2993**](https://vjudge.net/problem/HDU-2993) MAX Average Problem
[**UVALive 5097**](https://vjudge.net/problem/UVALive-5097) Cross the Wall
[**HDU 3045**](https://vjudge.net/problem/HDU-3045) Picnic Cows
[**HDU 3516**](https://vjudge.net/problem/HDU-3516) Tree Construction
[**POJ 1160**](https://vjudge.net/problem/POJ-1160) Post Office
[**POJ 1180**](https://vjudge.net/problem/POJ-1180) Batch Scheduling
[**POJ 2018**](https://vjudge.net/problem/POJ-2018) Best Cow Fences
[**POJ 3709**](https://vjudge.net/problem/POJ-3709) K-Anonymous Sequence
[**POJ 2841**](https://vjudge.net/problem/POJ-2841) Navigation Game
[**POJ 1260**](https://vjudge.net/problem/POJ-1260) Pearls
[**UVA 12594**](https://vjudge.net/problem/UVA-12594) Naming Babies
[**HDU 3480**](https://vjudge.net/problem/HDU-3480) Division
[**UVALive 6771**](https://vjudge.net/problem/UVALive-6771) Buffed Buffet

## 专题二十一 概率&期望

[**LightOJ 1027**](https://vjudge.net/problem/LightOJ-1027) A Dangerous Maze
[**LightOJ 1030**](https://vjudge.net/problem/LightOJ-1030) Discovering Gold
[**LightOJ 1038**](https://vjudge.net/problem/LightOJ-1038) Race to 1 Again
[**LightOJ 1079**](https://vjudge.net/problem/LightOJ-1079) Just another Robbery
[**LightOJ 1104**](https://vjudge.net/problem/LightOJ-1104) Birthday Paradox
[**LightOJ 1151**](https://vjudge.net/problem/LightOJ-1151) Snakes and Ladders
[**LightOJ 1248**](https://vjudge.net/problem/LightOJ-1248) Dice (III)
[**LightOJ 1265**](https://vjudge.net/problem/LightOJ-1265) Island of Survival
[**LightOJ 1274**](https://vjudge.net/problem/LightOJ-1274) Beating the Dataset
[**LightOJ 1284**](https://vjudge.net/problem/LightOJ-1284) Lights inside 3D Grid
[**LightOJ 1287**](https://vjudge.net/problem/LightOJ-1287) Where to Run
[**LightOJ 1317**](https://vjudge.net/problem/LightOJ-1317) Throwing Balls into the Baskets
[**LightOJ 1321**](https://vjudge.net/problem/LightOJ-1321) Sending Packets
[**LightOJ 1342**](https://vjudge.net/problem/LightOJ-1342) Aladdin and the Magical Sticks
[**LightOJ 1364**](https://vjudge.net/problem/LightOJ-1364) Expected Cards
[**LightOJ 1395**](https://vjudge.net/problem/LightOJ-1395) A Dangerous Maze (II)
[**LightOJ 1408**](https://vjudge.net/problem/LightOJ-1408) Batting Practice

## 专题二十二 区间DP

[**ZOJ 3537**](https://vjudge.net/problem/ZOJ-3537) Cake
[**LightOJ 1422**](https://vjudge.net/problem/LightOJ-1422) Halloween Costumes
[**POJ 2955**](https://vjudge.net/problem/POJ-2955) Brackets
[**CodeForces 149D**](https://vjudge.net/problem/CodeForces-149D) Coloring Brackets
[**POJ 1651**](https://vjudge.net/problem/POJ-1651) Multiplication Puzzle
[**ZOJ 3469**](https://vjudge.net/problem/ZOJ-3469) Food Delivery
[**HDU 4283**](https://vjudge.net/problem/HDU-4283) You Are the One
[**HDU 2476**](https://vjudge.net/problem/HDU-2476) String painter

## 专题二十三 计算几何之半平面交

[**POJ 3335**](https://vjudge.net/problem/POJ-3335) Rotating Scoreboard
[**POJ 3130**](https://vjudge.net/problem/POJ-3130) How I Mathematician Wonder What You Are!
[**POJ 1474**](https://vjudge.net/problem/POJ-1474) Video Surveillance
[**POJ 1279**](https://vjudge.net/problem/POJ-1279) Art Gallery
[**POJ 3525**](https://vjudge.net/problem/POJ-3525) Most Distant Point from the Sea
[**POJ 3384**](https://vjudge.net/problem/POJ-3384) Feng Shui
[**POJ 1755**](https://vjudge.net/problem/POJ-1755) Triathlon
[**POJ 2540**](https://vjudge.net/problem/POJ-2540) Hotter Colder
[**POJ 2451**](https://vjudge.net/problem/POJ-2451) Uyuw's Concert
[**POJ 1271**](https://vjudge.net/problem/POJ-1271) Nice Milk
[**UVA 11722**](https://vjudge.net/problem/UVA-11722) Joining with Friend
