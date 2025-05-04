from collections import Counter

def find_words(letter, cur_word):
    if not letter:
        words.append(cur_word)
    else:
        x = letter.copy().keys()
        for i in x:
            if letter[i] > 1:
                letter[i] -= 1
                find_words(letter, cur_word + i)
                letter[i] += 1
            else:
                del letter[i]
                find_words(letter, cur_word + i)
                letter[i] = 1
s = input()
letters, words = Counter(s), []
find_words(letters, "")
words.sort()
print(len(words))
for word in words:
    print(word)