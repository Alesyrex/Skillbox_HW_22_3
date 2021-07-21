#include <iostream>
#include <map>
#include <string>

bool correct_data (std::string word) {
    for (int i=0;i < word.length();i++) {
        if (word[i] < 'a' || word[i] > 'z')
            return false;
    }
    return true;
}

std::map<char,int> word_ordering(std::string word) {
    std::map<char,int> order;
    for (int i=0;i < word.length();++i){
        order[word[i]] += 1;
    }
    return order;
}

int main() {

    std::string firstWord, secondWord;

    do {
        std::cout << "Input two words to check for anagram:";
        std::cin >> firstWord >> secondWord;
        if (!(correct_data(firstWord) && correct_data(secondWord)))
            std::cout << "Incorrect input data." << std::endl;
    } while (!(correct_data(firstWord) && correct_data(secondWord)));


    if (firstWord.length() == secondWord.length()) {
        std::map<char, int> firstMap = word_ordering(firstWord);
        std::map<char, int> secondMap = word_ordering(secondWord);

        if (firstMap == secondMap)
            std::cout << "These words are anagrams!" << std::endl;
        else
            std::cout << "These words are not anagrams :(" << std::endl;
    }
    else
        std::cout << "These words are not anagrams." << std::endl;

    return 0;
}
