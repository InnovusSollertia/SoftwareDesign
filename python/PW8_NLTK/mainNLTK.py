import nltk
from nltk.tokenize import word_tokenize
from nltk import pos_tag

# Download NLTK data (you only need to do this once)
nltk.download('punkt')
nltk.download('averaged_perceptron_tagger')

# Sample text
text = "NLTK это великолепная библиотека для обработки естественного языка"

# Tokenize the text
tokens = word_tokenize(text)

# Part-of-speech tagging
pos_tags = pos_tag(tokens)

# Display the results
print("Токены:", tokens)
print("Поисковый запрос:", pos_tags)