n = int(input())
y = list(map(int, input().split()))
a = y[1] - y[0]
for i in range(2, n):
    if y[i] != (i-1)*a+y[1]:
        b = y[0]
        d = y[i] - i*a
        for j in range(2, n):
            if a*j + b != y[j] and a*j + d != y[j]:
                a = (y[i] - y[0])/i
                d = y[1] - a
                for k in range(2, n):
                    if a*k + b != y[k] and a*k + d != y[k]:
                        a = (y[i] - y[1])/(i - 1)
                        b = y[1] - a
                        d = y[0]
                        for l in range(2, n):
                            if a*l + b != y[l] and a*l + d != y[l]:
                                print("No")
                                break
                        else:
                            print("Yes")
                        break
                else:
                    print("Yes")
                break
        else:
            print("Yes")
        break
else:
    print("No")