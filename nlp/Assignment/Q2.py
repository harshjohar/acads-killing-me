import Assignment.stemmer as stemmer

def bag(documents, status = 0):
    if status:
        corpus = stemmer.Lemmatization(documents)
    else:
        corpus = stemmer.Porter_Stemmer(documents)
    # corpus = corpus.split()
    words = {}
    for seqn in corpus:
        seqn = seqn.split()
        # print(seqn)
        for word in seqn:
            if word not in words.keys():
                words[word] = 0
            # doc = doc.split()
            # print(word, doc, tf_idf.term_freq(doc, word))
            words[word] += 1
    return words

if __name__ == '__main__':
    strings = [x for x in input().split()]
    para = ['''He is eating Veg.
        She is eating Non-Veg.
        Both are eating Food.''', "He is very-rich, poor/but;not many bad:this'is~how`it is."]
    words = bag(para)
    for s in strings:
        print(f"{s} is {'' if (s in words.keys()) else 'not'} found")