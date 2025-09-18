#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_russian_char(unsigned char c) {
    return (c >= 128 && c <= 255) || c == '-';
}

void reverse_word(char *word, int length) {
    for (int i = 0; i < length / 2; i++) {
        char temp = word[i];
        word[i] = word[length - 1 - i];
        word[length - 1 - i] = temp;
    }
}

int main() {
    char input[81];
    fgets(input, sizeof(input), stdin);

    char result[81] = {0};
    char current_word[81] = {0};
    int result_index = 0;
    int word_index = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (is_russian_char((unsigned char)input[i])) {
            current_word[word_index++] = input[i];
        } else {
            if (word_index > 0) {
                reverse_word(current_word, word_index);
                memcpy(&result[result_index], current_word, word_index);
                result_index += word_index;
                word_index = 0;
                memset(current_word, 0, sizeof(current_word));
            }
            result[result_index++] = input[i];
        }
    }

    if (word_index > 0) {
        reverse_word(current_word, word_index);
        memcpy(&result[result_index], current_word, word_index);
    }

    printf("%s", result);
    return 0;
}
