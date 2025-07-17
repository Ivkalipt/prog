import re

def is_suspicious_word(word):
    cleaned_word = re.sub(r'^[\W_]+|[\W_]+$', '', word)
    if not cleaned_word:
        return False
    unique_letters = set(cleaned_word)
    return len(unique_letters) <= 3

def process_phrase(phrase):
    words = re.findall(r"[\w'-]+|[\W_]", phrase)
    filtered_words = [word for word in words if re.search(r'[^\W_]', word)]
    
    if not filtered_words:
        return False
    
    suspicious_count = 0
    for word in filtered_words:
        if is_suspicious_word(word):
            suspicious_count += 1
    
    return suspicious_count * 2 >= len(filtered_words)

def main():
    input_lines = []
    a = input()
    while a:
        input_lines.append(a)
        a = input()
    
    output_lines = []
    for line in input_lines:
        if not process_phrase(line):
            output_lines.append(line)
    
    print('\n'.join(output_lines))

if __name__ == "__main__":
    main()
