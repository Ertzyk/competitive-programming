s = input()
for i in range(len(s)):
    if s[i]=="A" and i<len(s)-1 and s[i+1]=="B" and s[i+2:].find("BA") != -1 or s[i]=="B" and i<len(s)-1 and s[i+1]=="A" and s[i+2:].find("AB") != -1:
        print("YES")
        break
else:
    print("NO")