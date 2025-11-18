#include <iostream>
#include <string>
#include "WordCount.h"
#include "tddFuncs.h"

int main() {
    WordCount words; 

    std::string word1 = "hello"; 
    std::string word2 = "HeLLo"; 
    std::string word3 = "55gamers55"; 
    std::string word4 = "*-'A-go-to-school-'asd-----"; 
    std::string word5 = "don't do it"; 
    std::string word6 = "DON'T  DO it";
    std::string word7 = "!!!!!";
    std::string word8 = "abc";
    std::string word9 = "cba";

    ASSERT_EQUALS(word1, words.makeValidWord(word1));
    ASSERT_EQUALS(word1, words.makeValidWord(word2));
    ASSERT_EQUALS("gamers", words.makeValidWord(word3));
    ASSERT_EQUALS("a-go-to-school-'asd", words.makeValidWord(word4));
    ASSERT_EQUALS("don'tdoit", words.makeValidWord(word5));
    ASSERT_EQUALS("don'tdoit", words.makeValidWord(word6));
    ASSERT_EQUALS("", words.makeValidWord(word7));

    ASSERT_EQUALS(0, words.getTotalWords()); 
    ASSERT_EQUALS(0, words.getNumUniqueWords()); 
    ASSERT_EQUALS(-1, words.decrWordCount(word1));

    words.incrWordCount(word1); 
    ASSERT_EQUALS(1, words.getWordCount(word1)); 
    ASSERT_EQUALS("HeLLo", word2); 
    words.incrWordCount(word2); 
    ASSERT_EQUALS(2, words.getWordCount(word1)); 
    ASSERT_EQUALS(2, words.getWordCount(word2)); 

    ASSERT_EQUALS(2, words.getTotalWords()); 
    ASSERT_EQUALS(1, words.getNumUniqueWords()); 

    words.incrWordCount(word1); 
    words.incrWordCount(word2); 
    words.incrWordCount(word3); 
    words.incrWordCount(word4); 
    words.incrWordCount(word5); 
    words.incrWordCount(word6); 

    ASSERT_EQUALS(8, words.getTotalWords()); 
    ASSERT_EQUALS(4, words.getNumUniqueWords()); 

    ASSERT_EQUALS(1, words.decrWordCount(word6));
    ASSERT_EQUALS(0, words.decrWordCount(word6));

    ASSERT_EQUALS(6, words.getTotalWords()); 
    ASSERT_EQUALS(3, words.getNumUniqueWords()); 

    ASSERT_EQUALS(0, words.decrWordCount(word4));
    words.decrWordCount(word4);
    ASSERT_EQUALS(-1, words.decrWordCount(word4));
    ASSERT_EQUALS(0, words.getWordCount(word4)); 

    ASSERT_EQUALS(5, words.getTotalWords()); 

    words.incrWordCount(word7); 
    words.incrWordCount(word7); 
    ASSERT_EQUALS(0, words.getWordCount(word7));
    ASSERT_EQUALS(5, words.getTotalWords()); 
    ASSERT_EQUALS(2, words.getNumUniqueWords()); 

    WordCount words2; 

    words2.incrWordCount(word8); 
    words2.incrWordCount(word9); 

    ASSERT_EQUALS(1, words2.getWordCount(word8));
    ASSERT_EQUALS(2, words2.getTotalWords()); 
    ASSERT_EQUALS(2, words2.getNumUniqueWords()); 


    return 0;
}