n = int(input())
text = input()
sentences, letter, sentence, result, cur_text_length, i = [], 0, "", 0, 0, 0
for letter in range(len(text)):
    sentence += text[letter]
    if text[letter] == "." or text[letter] == "!" or text[letter] == "?":
        sentences.append(sentence.lstrip())
        sentence = ""
sentences = list(map(len, sentences))
while i < len(sentences):
    if cur_text_length == 0:
        if sentences[i] > n:
            print("Impossible")
            break
        else:
            cur_text_length = sentences[i]
            result += 1
            i += 1
    else:
        if sentences[i] + 1 + cur_text_length > n:
            cur_text_length = 0
        else:
            cur_text_length += sentences[i] + 1
            i += 1
else:
    print(result)