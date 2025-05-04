n = int(input())
first = input()
second = input()
both, ad = 0, 0
for i in range(2*n):
    if first[i] == "1" and second[i] == "1":
        both += 1
    elif first[i] == "1" and second[i] == "0":
        ad += 1
    elif first[i] == "0" and second[i] == "1":
        ad -= 1
x = both%2 + ad
print("First" if x > 0 else "Second" if x < -1 else "Draw")