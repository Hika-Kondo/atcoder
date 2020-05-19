// copy from 
// https://qiita.com/drken/items/ecd1a472d3a0e7db8dce

// 「条件」を満たす区間(連続する部分列) のうち、最小の長さを求める
// 「条件」を満たす区間(連続する部分列) のうち、最大の長さを求める
// 「条件」を満たす区間(連続する部分列) を数え上げる

int right = 0;
for (int left = 0; left < n; ++left)
{
    while (right < n && (right を 1 個進めたときに条件を満たす))
    {
        /* 実際に right を 1 進める */
        // ex: sum += a[right];
        ++right;
    }

    /* break した状態で right は条件を満たす最大なので、何かする */
    // ex: res += (right - left);

    /* left をインクリメントする準備 */
    // ex: if (right == left) ++right;
    // ex: else sum -= a[left];  

}