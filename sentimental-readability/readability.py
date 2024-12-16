def main():
    text = input("Text: ")
    grade = int(round(calc(text)))
    if grade < 1:
        print("Before Grade 1...")
    elif grade >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {int(round(calc(text)))}")


def calc(text):
    letters = 0
    words = 0
    sentences = 0
    index = 0
    for char in text:
        if char.isalpha():
            letters += 1
        if char == ' ':
            words += 1
        if (char == '.' or char == '?' or char == '!') and text[index - 1].isalpha():
            sentences += 1
        index += 1
    if letters > 0:
        words += 1
    grade = grading(letters, words, sentences)
    return grade


def grading(letters, words, sentences):
    l = l_calc(letters, words)
    s = s_calc(sentences, words)
    return (0.0588 * l - 0.296 * s - 15.8)


def l_calc(letters, words):
    return (100 * letters) / words


def s_calc(sentences, words):
    return (100 * sentences) / words

main()
