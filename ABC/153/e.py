h, n = map(int,input().split())
dict_a = {} # コスパがキー　攻撃力がバリュー
dict_b = {} # 攻撃力がキー　魔力がバリュー
cost_per_majic = [] # コスパのリスト
a = []
for i in range(n):
    temp_a, temp_b = map(int, input().split())
    dict_a[temp_b/temp_a] = temp_a
    dict_b[temp_a] = temp_b
    cost_per_majic.append(temp_b/temp_a)
    a.append(temp_a)
cost_per_majic = sorted(cost_per_majic)
cost = 0
for i in range(len(cost_per_majic)):
    while True:
        if cost_per_majic[i] <= h:
            cost += dict_b[dict_a[cost_per_majic[i]]]
            h -= dict_a[cost_per_majic[i]]
            print("if {}".format(dict_a[cost_per_majic[i]]))
        else:
            # ワンパンできるリスト
            can_kill_majic = [i for i in a if i >= h]
            most_low_cost_majic_can_end = sorted([dict_b[i] for i in can_kill_majic])[0]
            if dict_b[dict_a[cost_per_majic[i]]] <= most_low_cost_majic_can_end:
                break
            else:
                print(cost+dict_b[dict_a[cost_per_majic[i]]])
                exit()
