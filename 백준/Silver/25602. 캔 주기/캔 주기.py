input = __import__('sys').stdin.readline

N, K = map(int, input().rstrip().split())
A = list(map(int, input().rstrip().split()))
Rang = []
Mery = []
flavor_max = 0

for i in range(K) :
    Rang.append(list(map(int, input().rstrip().split())))
for i in range(K) :
    Mery.append(list(map(int, input().rstrip().split())))

def Feed(day, flavor) :
    global flavor_max

    if day == K :
        if flavor > flavor_max :
            flavor_max = flavor
        return 

    for i in range(N) :
        if A[i] > 0 :
            A[i] -= 1
        else :
            continue
        for j in range(N) :
            if A[j] > 0 :
                A[j] -= 1
                Feed(day + 1, flavor + Rang[day][i] + Mery[day][j])
            else :
                continue
            A[j] += 1
        A[i] += 1

Feed(0, 0)
print(flavor_max)