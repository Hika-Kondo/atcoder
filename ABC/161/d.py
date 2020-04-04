k = int(input())

counter = 0
num_object = [i for i in range(1,10)]

ketaflag_min = 0
ketaflag_max = len(num_object)
index = 1
if k <= 10:
    print(k)

else:
    while True:
        # print(ketaflag_min,ketaflag_max)
        for i in range(ketaflag_min,ketaflag_max):
            last_keta = num_object[i] % 10
            # print(i, num_object[i])
            if last_keta != 9 and last_keta != 0:
                max_keta = last_keta + 1
                min_keta = last_keta - 1
                newnum_max =  num_object[i] * 10 + max_keta
                newnum_mid =  num_object[i] * 10 + last_keta
                newnum_min =  num_object[i] * 10 + min_keta
                num_object.append(min(newnum_max,newnum_min))
                num_object.append(newnum_mid)
                num_object.append(max(newnum_max,newnum_min))
            elif last_keta == 9:
                newnum_min = num_object[i] * 10 + 8
                newnum_mid = num_object[i] * 10 + 9
                num_object.append(newnum_min)
                num_object.append(newnum_mid)
            else:
                newnum_min = num_object[i] * 10 + 0
                newnum_mid = num_object[i] * 10 + 1
                num_object.append(newnum_min)
                num_object.append(newnum_mid)
            if len(num_object) >= k:
                print(num_object[k-1])
                exit()
        ketaflag_min = ketaflag_max
        ketaflag_max = len(num_object)
        # print(num_object)
