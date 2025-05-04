def convert_to_num(string):
    lst = string.split(".")
    if len(lst) == 1:
        return int(lst[0])
    num = ""
    if len(lst[-1]) == 2:
        for i in range(len(lst) - 1):
            num += lst[i]
        num += "."
        num += lst[-1]
        return float(num)
    for i in range(len(lst)):
        num += lst[i]
    return int(num)
s = input()
prices, i = [], 0
while i < len(s):
    if not s[i].isalpha():
        price = s[i]
        i += 1
        while i < len(s) and not s[i].isalpha():
            price += s[i]
            i += 1
        prices.append(price)
    else:
        i += 1
for i in range(len(prices)):
    prices[i] = convert_to_num(prices[i])
res, result = 0, ""
for i in range(len(prices)):
    res += round(prices[i]*100)
res = str(res/100).split(".")
if len(res[1]) == 1 and res[1] != "0":
    res[1] += "0"
for i in range(len(res[0])):
    if i%3 == len(res[0])%3 and i != 0:
        result += "."
    result += res[0][i]
if len(res) == 2 and res[1] != "0":
    result += "." + res[1]
print(result)