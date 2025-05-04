game = {"rock": [], "paper": [], "scissors": []}
game[input()].append("F")
game[input()].append("M")
game[input()].append("S")
if len(game["rock"]) == 2 and len(game["paper"]) == 1:
    print(game["paper"][0])
elif len(game["paper"]) == 2 and len(game["scissors"]) == 1:
    print(game["scissors"][0])
elif len(game["scissors"]) == 2 and len(game["rock"]) == 1:
    print(game["rock"][0])
else:
    print("?")