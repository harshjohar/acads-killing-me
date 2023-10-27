SHORT_FORMS = ["Dr", "Mr", "St"]
ENDING = [".", "?", "!"]

def myTokeniser(s):
    List = s.split()
    tokens = []

    token_string = ""
    for token in List:
        # End of a sentence Found
        if token[-1] in ENDING and token[0:len(token) - 1] not in SHORT_FORMS:
            token_string += token + " "
            tokens.append(token_string)
            token_string = ""
        else:
            token_string += token + " "

    if len(token_string) != 0:
        tokens.append(token_string)

    for i in range(len(tokens)):
        # Remove unneeded space
        if tokens[i][-1] == ' ':
            tokens[i] = tokens[i][0: len(tokens[i]) - 1]

    return tokens;

# from nltk.tokenize import sent_tokenize

sentence1 = "Mr. Harshpreet Singh is an aspiring engineer. He is trying very hard at competitive programming."

print(f"Tokens for {sentence1}")
for token in myTokeniser(sentence1):
    print(token)
# print_token_side_by_side(sent_tokenize(sentence1), myTokeniser(sentence1))

sentence2 = "Mr. Donald Trump was the president of US from 2016 to 2021. Mr. Joe biden is the current president of the US."

print(f"\nTokens for {sentence2}")
for token in myTokeniser(sentence2):
    print(token)
# print_token_side_by_side(sent_tokenize(sentence2), myTokeniser(sentence2))