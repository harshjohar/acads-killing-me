import re
from nltk.corpus import stopwords
from nltk.stem import WordNetLemmatizer
from nltk.stem import PorterStemmer

def Porter_Stemmer(documents):
    port = PorterStemmer()
    corpus = []
    i = 0
    for doc in documents:
        # replacing special characters except (A-Z, a-z, 0-9) with space
        stemming = re.sub('[^A-Za-z0-9]', ' ', doc)
        stemming = stemming.lower()  # converting the whole string to lowercase
        stemming = stemming.split()  # splitting the doc into words based on spaces
        sentences = [port.stem(word) for word in stemming if word not in set(
            stopwords.words('english'))]  # removing stopwords and stemming the rest of the doc
        sentences = ' '.join(sentences)  # joining the list to make a string
        corpus.append(sentences)
        i += 1
    return corpus


def Lemmatization(documents):
    lemma = WordNetLemmatizer()
    corpus = []
    for doc in documents:
        lemmatizer = re.sub('[^A-Za-z0-9]', ' ', doc)
        lemmatizer = lemmatizer.lower()
        lemmatizer = lemmatizer.split()
        sentences = [lemma.lemmatize(word) for word in lemmatizer if word not in set(
            stopwords.words('english'))]  # removing stopwords and stemming the rest of the doc
        sentences = ' '.join(sentences)  # joining the list to make a string
        corpus.append(sentences)
    return corpus


if __name__ == '__main__':
    # A dummy code to see how the above function works
    para = ['''He is eating Veg.
    She is eating Non-Veg.
    Both are eating Food.''', "He is very-rich, poor/but;not many bad:this'is~how`it is."]

    print("Stemmed: \n", Porter_Stemmer(para))
    para = ['''He is eating Veg.
    She is eating Non-Veg.
    Both are eating Food.''', "He is very-rich, poor/but;not many bad:this'is~how`it is."]

    print("\nLemmatized: \n", Lemmatization(para))
