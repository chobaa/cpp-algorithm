#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> arr;
vector<int> tree;

// node가 담고 있는 구간: [left, right]
// 내가 변경하고자 하고 싶은 구간: [start, end]
void updateTree(int node, int left, int right, int index, int diff) {
    if (index < left || right < index) return;

    tree[node] += diff;

    if (left != right) {
        int mid = (left + right) / 2;
        updateTree(node * 2, left, mid, index, diff);
        updateTree(node * 2 + 1, mid + 1, right, index, diff);
    }
}

// 내 앞에 나보다 큰 사람들이 몇명이나 있나?
int queryTree(int node, int left, int right, int start, int end) {
    if (end < left || right < start) return 0;
    if (start <= left && right <= end) return tree[node];
    int mid = (left + right) / 2;
    return queryTree(node * 2, left, mid, start, end) + queryTree(node * 2 + 1, mid + 1, right, start, end);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    arr.resize(n);

    // first: 선수들의 기본 index
    // second: 선수들의 실력 정보
    for (int i = 0; i < n; ++i) {
        arr[i].first = i;
        cin >> arr[i].second;
    }

    // 모든 선수들의 실력을 낮은 순서대로 정렬
    sort(arr.begin(), arr.end(), [](const auto &a, const auto &b) {
        return a.second < b.second;
    });

    // Renumbering
    for (int i = 0; i < n; ++i)
        arr[i].second = i;

    int treeHeight = ceil(log2(n));
    int treeSize = 1 << (treeHeight + 1);
    tree.resize(treeSize, 0);

    vector<pair<int, int>> result(n);

    // 능력치가 큰 사람부터 삽입합니다.
    for (int i = n - 1; i >= 0; --i) {
        result[i].first = arr[i].first;
        result[i].second = queryTree(1, 0, n - 1, 0, arr[i].first - 1) + 1;
        updateTree(1, 0, n - 1, arr[i].first, 1);
    }

    sort(result.begin(), result.end());
    for (auto e : result) {
        cout << e.second << "\n";
    }

    return 0;
}