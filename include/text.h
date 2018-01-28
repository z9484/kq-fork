#pragma once

#include <string>
#include <vector>

class KText
{
public:
    explicit KText(const std::string& text = "");
    ~KText() = default;

    /**
     * Wrap text onto multiple lines if they exceed a number of characters, with "\n" between each line.
     *
     * All adjacent non-whitespace characters are considered "words" including punctuation.
     *
     * @param charactersPerLine Maximum length of text before it is broken.
     * @param bSplitUnbrokenWords If a single word is longer than charactersPerLine,
     *        TRUE will split the word apart at that column;
     *        FALSE will split as soon as possible after the word.
     */
    std::string WordWrap(size_t charactersPerLine, bool bSplitUnbrokenWords = false) const;

    /**
     * Wrap text onto multiple lines if they exceed a number of characters, with each line in a separate array.
     *
     * All adjacent non-whitespace characters are considered "words" including punctuation.
     *
     * @param charactersPerLine Maximum length of text before it is broken.
     * @param bSplitUnbrokenWords If a single word is longer than charactersPerLine,
     *        TRUE will split the word apart at that column;
     *        FALSE will split as soon as possible after the word.
     */
    std::vector<std::string> WordWrapArray(size_t charactersPerLine, bool bSplitUnbrokenWords = false) const;

private:
    /**
     * Given "longtext1 longtext2 longtext3 longtext4 longtext5 longtext6"
     * split into up to MSG_ROWS lines of text:
     *     "longtext1"
     *     "longtext2"
     *     "longtext3"
     *     "longtext4"
     * with all remaining text returned to the caller:
     *     "longtext5 longtext6"
     * for it to be processed later.
     */
    std::string splitTextOverMultipleLines(const std::string& stringToSplit);

    std::string m_text;
};

extern KText kText;

int square(const int value);
