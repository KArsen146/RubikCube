//
// Created by Арсений Карпов on 20.05.2020.
//

#ifndef PROGA8_RUBIK_S_brink_BRINK_H
#define PROGA8_RUBIK_S_brink_BRINK_H
#include <vector>
class brink {
public:
    std::vector<std::vector<int>> _brink;

    explicit brink()
    {
        _brink.resize(3, std::vector<int>(3));
    }

    explicit brink(std::vector<std::vector<int>> const &obj)
    {
        _brink = obj;
    }

    void create(int color)
    {
        for (auto &i:_brink)
            for(auto &j:i)
                j = color;
    }

    std::vector<int>& operator [](int ind)
    {
        return _brink[ind];
    }

    void right_wise()
    {
        int t = _brink[0][0];
        _brink[0][0] = _brink[2][0];
        _brink[2][0] = _brink[2][2];
        _brink[2][2] = _brink[0][2];
        _brink[0][2] = t;
        t = _brink[0][1];
        _brink[0][1] = _brink[1][0];
        _brink[1][0] = _brink[2][1];
        _brink[2][1] = _brink[1][2];
        _brink[1][2] = t;
    }
    
    void left_wise()
    {
        int t = _brink[0][0];
        _brink[0][0] = _brink[0][2];
        _brink[0][2] = _brink[2][2];
        _brink[2][2] = _brink[2][0];
        _brink[2][0] = t;
        t = _brink[0][1];
        _brink[0][1] = _brink[1][2];
        _brink[1][2] = _brink[2][1];
        _brink[2][1] = _brink[1][0];
        _brink[1][0] = t;
    }

    bool operator ==(brink const & a) const
    {
        return a._brink == _brink;
    }

    ~brink() = default;
};

#endif //PROGA8_RUBIK_S_brink_BRINK_H