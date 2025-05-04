for _ in range(int(input())):
    n, m = map(int, input().split())
    print("? 1 1", flush = True)
    a = int(input())
    if a == 0:
        print("! 1 1", flush = True)
    elif n < a + 1:
        print(f"? 1 {a + 1}", flush = True)
        print(f"! {int(input()) + 1} {a + 1}", flush = True)
    elif m < a + 1:
        print(f"? {a + 1} 1", flush = True)
        print(f"! {a + 1} {int(input()) + 1}", flush = True)
    else:
        print(f"? {a + 1} {a + 1}", flush = True)
        b = int(input())
        if b == 0:
            print(f"! {a + 1} {a + 1}", flush = True)
        else:
            print(f"? {a + 1} {a - b + 1}", flush = True)
            if int(input()) == 0:
                print(f"! {a + 1} {a - b + 1}", flush = True)
            else:
                print(f"! {a - b + 1} {a + 1}", flush = True)