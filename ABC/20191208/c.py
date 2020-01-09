n = int(input())
comments = {}
for i in range(n):
    a = int(input())
    comments[i] = []
    for _ in range(a):
        x,y = map(int, input().split())
        comments[i].append([x-1, y == 1])

ans = 0

for i in range(2 ** n):
    fail = False #　うまく行かなかったとき,矛盾が生じたときTrue
    results = [None] * n # 結果用のリスト
    for j in range(n):
        # 嘘つきと仮定している人以外の証言の整合性を図る
        candidate = ((i >> j) & 1 ) == 1
        # iを2進数としてjだけビットシフトその一番下の桁が1かどうか判定する
        # i >> jでiをjだけシフトした10進数の値が得られる.
        # (i >> j) & 1 でビットのしもひと桁が1かどうか判定する
        # ((i >> j) & 1) == 1で下一桁が1のときTrue
        # Trueのとき,正直者認定
        if results[j] == None:
            results[j] = candidate
        elif results[j] != candidate:
            # 矛盾が生じたとき
            fail = True
            break
        if candidate == False:
            continue
        else:
            for comment in comments[j]:
                if results[comment[0]] == None:
                    results[comment[0]] = comment[1]
                if results[comment[0]] != comment[1]:
                    fail = True
                    break
            if fail:
                break
    if not fail:
        
        counter = 0
        for k in results:
            if k:
                counter += 1
        if counter >= ans:
            ans = counter
print(ans)
