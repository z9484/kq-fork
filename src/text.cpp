#include "text.h"

#include <cctype>
#include <string>
#include <vector>

// Given: most whitespace are [ \t\r\n]
// Punctuation is considered part of a word:
//   1.2  this,  "Hello."  I...dunno  HE-E-E-E-ELP!!!!
//
// It may be more optimized, instead of tracking the beginning of each new word on a line
// and backtracking to that point if the line extends beyond the maximum width, to start
// looking for whitespace at the max width offset. If the string is shorter than the max
// width, return the entire string. If the cursor lands on a whitespace, replace it with
// a newline (or split into separate array elements as the case may require).
// If it is non-whitespace, move the cursor left one character at a time until a
// whitespace is found OR the cursor is at the beginning of the line. In that case, the
// length of the word exceeds the maximum width, and can be handled.
// 
// This way, a wrap column of 120 characters doesn't have to evaluate nearly 119
// characters to find the "last" occurrence of a word: it can jump ahead immediately and
// potentially move to the left fewer times than it would take to walk it forward. This
// would only be an optimization issue when using extremely long words that require a lot
// of backtracking.
//
// Issues: Large amounts of whitespace may remain at beginning/end of each line.
// Alternately, starting cursor at 0, 

KText::KText(const std::string& text)
    : m_text(text)
{
}


void printwrap(const char* s, size_t lineSize, const char *prefix)
{
    return;
    const char *head = s;
    size_t pos = 0;
    size_t lastSpace = 0;

    while (head[pos] != 0)
    {
        int isLf = (head[pos] == '\n');
        if (isLf || pos == lineSize)
        {
            // Just cut it.
            if (isLf || lastSpace == 0)
            {
                lastSpace = pos;
            }

            if (prefix != nullptr)
            {
                printf("%s", prefix);
            }

            while (*head != 0 && lastSpace-- > 0)
            {
                printf("%c", *head++);
            }
            printf("\n");

            // Jump the line feed.
            if (isLf)
            {
                head++;
            }

            // Clear the leading space.
            while (*head != 0 && *head == ' ')
            {
                head++;
            }
            lastSpace = pos = 0;
        }
        else
        {
            if (head[pos] == ' ')
            {
                lastSpace = pos;
            }
            pos++;
        }
    }
    printf("%s\n", head);
}


std::string KText::WordWrap(size_t charactersPerLine, bool bSplitUnbrokenWords) const
{
    std::string text;

    // Prevent division by zero.
    if (charactersPerLine == 0)
    {
        charactersPerLine = 1;
    }

    // Integer division: 10/2==5, 10/3==3, 10/4==2, 10/5==2, etc.
    size_t estimatedSplits = m_text.length() / charactersPerLine;

    text.reserve(m_text.length() + estimatedSplits);

    size_t charPosition = 0;
    while (charPosition + charactersPerLine < m_text.length()) {
        text.append(m_text, charPosition, charactersPerLine);
        text.append("\n");
        charPosition += charactersPerLine;
    }
    text.append(m_text, charPosition, charactersPerLine);
    return text;


    size_t line_begin = 0;
    while (line_begin < text.size())
    {
        const size_t ideal_end = line_begin + charactersPerLine;
        size_t line_end = ideal_end < text.size() ? ideal_end : text.size() - 1;

        if (line_end == text.size() - 1)
        {
            ++line_end;
        }
        else if (std::isspace(text[line_end]))
        {
            text[line_end] = '\n';
            ++line_end;
        }
        else    // backtrack
        {
            unsigned end = line_end;
            while (end > line_begin && !std::isspace(text[end]))
            {
                --end;
            }

            if (end != line_begin)
            {
                line_end = end;
                text[line_end++] = '\n';
            }
            else
            {
                text.insert(line_end++, 1, '\n');
            }
        }

        line_begin = line_end;
    }

    return text;
}

std::vector<std::string> KText::WordWrapArray(size_t charactersPerLine, bool bSplitUnbrokenWords) const
{
    return std::vector<std::string>();
}

KText kText;
