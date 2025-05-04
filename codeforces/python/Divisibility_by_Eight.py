n = "00"+input()
for c in range(len(n)-1, 1, -1):
    if int(n[c]) % 2 == 0:
        for a in range(c):
            for b in range(a+1, c):
                x = int(n[a]+n[b]+n[c])
                if x%8==0:
                    print("YES")
                    print(x)
                    break
            else:
                continue
            break
        else:
            continue
        break
else:
    print("NO")