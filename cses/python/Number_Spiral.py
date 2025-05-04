for _ in range(int(input())):
    y, x = map(int, input().split())
    print(((y>>1)<<1)**2+(y&1)+((y&1)*2-1)*(x-1) if y >= x else (((x+1)>>1<<1)-1)**2+(x-1&1)-((x&1)*2-1)*(y-1))