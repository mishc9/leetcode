//
// Created by Михаил Степанов on 01.09.2020.
//

using namespace std;


class Solution
{
    int read4(char *buf4) { return 0; }

public:
    int read(char *buf, int n)
    {
        int copiedChars = 0, readChars = 4;
        char buf4[4];

        while (copiedChars < n && readChars == 4) {
            readChars = read4(buf4);

            for (int i = 0; i < readChars; ++i) {
                if (copiedChars == n)
                    return copiedChars;
                buf[copiedChars] = buf4[i];
                ++copiedChars;
            }
        }
        return copiedChars;
    }
};

