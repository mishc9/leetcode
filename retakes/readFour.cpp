//
// Created by Михаил Степанов on 03.09.2020.
//

int read4(char *c) {
    return 0;
}


class Solution{
public:
    int read(char *buf, int n) {

        int readTotal = 0;
        int readThisStep = 4;
        char buf4[4];

        while (readTotal < n and readThisStep == 4) {
            readThisStep = read4(buf4);
            for (int i = 0; i < readThisStep; i++) {
                if (readTotal == n) {
                    return readTotal;
                }
                buf[readTotal] = buf4[i];
                readTotal++;
            }
        }
        return readTotal;
    }
};

