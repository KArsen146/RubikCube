//
// Created by Арсений Карпов on 21.05.2020.
//

#ifndef PROGA8_RUBIK_S_CUBE_SOLVER_H
#define PROGA8_RUBIK_S_CUBE_SOLVER_H
#include "cube_sweep.h"
class cube_sweep {
    friend  class cube_solver;
public:
    cube_sweep();
    cube_sweep(cube_sweep const &obj);
    explicit cube_sweep(std::vector<brink> const & v);
    explicit cube_sweep(std::ifstream &F);
    void generation();
    bool solver();
    void print();
    std::vector<char> answer();
    std::vector<char> _ans;
    std::vector<brink> _cube;
};
class cube_solver {
    friend class cube_sweep;
public:
    cube_solver () = default;
    explicit cube_solver (cube_sweep *a)
    : _c(a) {}
private:
    cube_sweep* _c;
    void R()
    {
        _c -> _ans.push_back('R');
        std::vector<int> tmp = {_c -> _cube[0][0][2], _c -> _cube[0][1][2], _c -> _cube[0][2][2]};
        for (int i = 0; i < 3; i++) {
            _c -> _cube[0][i][2] = _c -> _cube[2][i][2];
            _c -> _cube[2][i][2] = _c -> _cube[5][2 - i][0];
            _c -> _cube[5][2 - i][0] = _c -> _cube[4][i][2];
            _c -> _cube[4][i][2] = tmp[i];
        }
        tmp.resize(0);
        _c -> _cube[1].right_wise();
    }

    void R1()
    {
        _c -> _ans.push_back('r');
        std::vector<int> tmp = {_c -> _cube[0][0][2], _c -> _cube[0][1][2], _c -> _cube[0][2][2]};
        for (int i = 0; i < 3; i++) {
            _c -> _cube[0][i][2] = _c -> _cube[4][i][2];
            _c -> _cube[4][i][2] = _c -> _cube[5][2 - i][0];
            _c -> _cube[5][2 - i][0] = _c -> _cube[2][i][2];
            _c -> _cube[2][i][2] = tmp[i];
        }
        tmp.resize(0);
        _c -> _cube[1].left_wise();
    }

    void L()
    {
        _c -> _ans.push_back('L');
        std::vector<int> tmp = {_c -> _cube[0][0][0], _c -> _cube[0][1][0], _c -> _cube[0][2][0]};
        tmp.push_back(_c -> _cube[0][0][0]);
        tmp.push_back(_c -> _cube[0][1][0]);
        tmp.push_back(_c -> _cube[0][2][0]);
        for (int i = 0; i < 3; i++) {
            _c -> _cube[0][i][0] = _c -> _cube[4][i][0];
            _c -> _cube[4][i][0] = _c -> _cube[5][2 - i][2];
            _c -> _cube[5][2 - i][2] = _c -> _cube[2][i][0];
            _c -> _cube[2][i][0] = tmp[i];
        }
        tmp.resize(0);
        _c -> _cube[3].right_wise();
    }

    void L1()
    {
        _c -> _ans.push_back('l');
        std::vector<int> tmp = {_c -> _cube[0][0][0], _c -> _cube[0][1][0], _c -> _cube[0][2][0]};
        for (int i = 0; i < 3; i++) {
            _c -> _cube[0][i][0] = _c -> _cube[2][i][0];
            _c -> _cube[2][i][0] = _c -> _cube[5][2 - i][2];
            _c -> _cube[5][2 - i][2] = _c -> _cube[4][i][0];
            _c -> _cube[4][i][0] = tmp[i];
        }
        tmp.resize(0);
        _c -> _cube[3].left_wise();
    }

    void U()
    {
        _c -> _ans.push_back('U');
        std::vector<int> tmp = {_c -> _cube[0][0][0], _c -> _cube[0][0][1], _c -> _cube[0][0][2]};
        for (int i = 0; i < 3; i++) {
            _c -> _cube[0][0][i] = _c -> _cube[1][0][i];
            _c -> _cube[1][0][i] = _c -> _cube[5][0][i];
            _c -> _cube[5][0][i] = _c -> _cube[3][0][i];
            _c -> _cube[3][0][i] = tmp[i];
        }
        tmp.resize(0);
        _c -> _cube[4].right_wise();
    }

    void U1()
    {
        _c -> _ans.push_back('u');
        std::vector<int> tmp = {_c -> _cube[0][0][0], _c -> _cube[0][0][1], _c -> _cube[0][0][2]};
        for (int i = 0; i < 3; i++) {
            _c -> _cube[0][0][i] = _c -> _cube[3][0][i];
            _c -> _cube[3][0][i] = _c -> _cube[5][0][i];
            _c -> _cube[5][0][i] = _c -> _cube[1][0][i];
            _c -> _cube[1][0][i] = tmp[i];
        }
        tmp.resize(0);
        _c -> _cube[4].left_wise();
    }

    void F()
    {
        _c -> _ans.push_back('F');
        std::vector<int> tmp = {_c -> _cube[3][0][2], _c -> _cube[3][1][2], _c -> _cube[3][2][2]};
        for (int i = 0; i < 3; i++) {
            _c -> _cube[3][i][2] = _c -> _cube[2][0][i];
            _c -> _cube[2][0][i] = _c -> _cube[1][2 - i][0];
            _c -> _cube[1][2 - i][0] = _c -> _cube[4][2][2 - i];
            _c -> _cube[4][2][2 - i] = tmp[i];
        }
        tmp.resize(0);
        _c -> _cube[0].right_wise();
    }

    void F1()
    {
        _c -> _ans.push_back('f');
        std::vector<int> tmp = {_c -> _cube[3][0][2], _c -> _cube[3][1][2], _c -> _cube[3][2][2]};
        for (int i = 0; i < 3; i++) {
            _c -> _cube[3][i][2] = _c -> _cube[4][2][2 - i];
            _c -> _cube[4][2][2 - i] = _c -> _cube[1][2 - i][0];
            _c -> _cube[1][2 - i][0] = _c -> _cube[2][0][i];
            _c -> _cube[2][0][i] = tmp[i];
        }
        tmp.resize(0);
        _c -> _cube[0].left_wise();
    }

    void D()
    {
        _c -> _ans.push_back('D');
        std::vector<int> tmp = {_c -> _cube[0][2][0], _c -> _cube[0][2][1], _c -> _cube[0][2][2]};
        for (int i = 0; i < 3; i++) {
            _c -> _cube[0][2][i] = _c -> _cube[3][2][i];
            _c -> _cube[3][2][i] = _c -> _cube[5][2][i];
            _c -> _cube[5][2][i] = _c -> _cube[1][2][i];
            _c -> _cube[1][2][i] = tmp[i];
        }
        tmp.resize(0);
        _c -> _cube[2].right_wise();
    }

    void D1()
    {
        _c -> _ans.push_back('d');
        std::vector<int> tmp = {_c -> _cube[0][2][0], _c -> _cube[0][2][1], _c -> _cube[0][2][2]};
        for (int i = 0; i < 3; i++) {
            _c -> _cube[0][2][i] = _c -> _cube[1][2][i];
            _c -> _cube[1][2][i] = _c -> _cube[5][2][i];
            _c -> _cube[5][2][i] = _c -> _cube[3][2][i];
            _c -> _cube[3][2][i] = tmp[i];
        }
        tmp.resize(0);
        _c -> _cube[2].left_wise();
    }

    void B()
    {
        _c -> _ans.push_back('B');
        std::vector<int> tmp = {_c -> _cube[3][0][0], _c -> _cube[3][1][0], _c -> _cube[3][2][0]};
        for (int i = 0; i < 3; i++) {
            _c -> _cube[3][i][0] = _c -> _cube[4][0][2 - i];
            _c -> _cube[4][0][2 - i] = _c -> _cube[1][2 - i][2];
            _c -> _cube[1][2 - i][2] = _c -> _cube[2][2][i];
            _c -> _cube[2][2][i] = tmp[i];
        }
        tmp.resize(0);
        _c -> _cube[5].right_wise();
    }

    void B1()
    {
        _c -> _ans.push_back('b');
        std::vector<int> tmp = {_c -> _cube[3][0][0], _c -> _cube[3][1][0], _c -> _cube[3][2][0]};
        for (int i = 0; i < 3; i++) {
            _c -> _cube[3][i][0] = _c -> _cube[2][2][i];
            _c -> _cube[2][2][i] = _c -> _cube[1][2 - i][2];
            _c -> _cube[1][2 - i][2] = _c -> _cube[4][0][2 - i];
            _c -> _cube[4][0][2 - i] = tmp[i];
        }
        tmp.resize(0);
        _c -> _cube[5].left_wise();
    }

    void y()
    {
        _c -> _ans.push_back('<');
        brink _brink;
        _brink = _c -> _cube[0];
        _c -> _cube[0] = _c -> _cube[1];
        _c -> _cube[1] = _c -> _cube[5];
        _c -> _cube[5] = _c -> _cube[3];
        _c -> _cube[3] = _brink;
        _c -> _cube[4].right_wise();
        _c -> _cube[2].left_wise();
    }

    void pif_paf()
    {
        R();
        U();
        R1();
        U1();
    }

    void left_pif_paf()
    {
        L1();
        U1();
        L();
        U();
    }

    void raise_ribs()
    {
        pif_paf();
        F1();
        U1();
        F();
        U();
    }

    void edge_to_left()
    {
        U();
        R();
        U1();
        R1();
        U1();
        F1();
        U();
        F();
    }

    void edge_to_right()
    {
        U1();
        F1();
        U();
        F();
        U();
        R();
        U1();
        R1();
    }

    void nine_hours(int color)
    {
        while ((_c -> _cube[4][1][0] != color) || (_c -> _cube[4][0][1] != color))
            U();
        F();
        pif_paf();
        F1();
        line(color);
    }

    void line(int color)
    {
        while (_c -> _cube[4][1][0] != color)
            U();
        F();
        pif_paf();
        F1();
    }

    int count_edge(int color, int &c)
    {
        int max = 0;
        if (_c -> _cube[3][0][1]==_c -> _cube[3][1][1])
            c++;
        if (_c -> _cube[0][0][1]==_c -> _cube[0][1][1])
            c++;
        if (_c -> _cube[1][0][1]==_c -> _cube[1][1][1])
            c++;
        if (_c -> _cube[5][0][1]==_c -> _cube[5][1][1])
            c++;
        max = std::max(max, c);
        return max;
    }

    void edge_near(int color)
    {
        int c = 0;
        while (count_edge(color, c) != 2)  {
            U();
            c = 0;
        }
        while ((_c -> _cube[5][0][1] != _c -> _cube[5][1][1]) || (_c -> _cube[3][0][1] != _c -> _cube[3][1][1]))
            y();
        R();
        U();
        R1();
        U();
        R();
        U();
        U();
        R1();
        U();

    }

    void edge_opposite(int color)
    {
        int c = 0;
        while (count_edge(color, c) != 2) {
            U();
            c = 0;
        }
        while ((_c -> _cube[5][0][1] != _c -> _cube[5][1][1]) || (_c -> _cube[0][0][1] != _c -> _cube[0][1][1]))
            y();
        R();
        U();
        R1();
        U();
        R();
        U();
        U();
        R1();
        edge_near(color);
    }

    void switch_corner()
    {
        R();
        U1();
        L1();
        U();
        R1();
        U1();
        L();
        U();
    }

    int count_corners(int color)
    {
        bool t;
        int count = 0;
        for (int i = 0; i < 4; i++)
        {
            t = false;
            if ((_c -> _cube[0][0][0] == _c -> _cube[0][1][1]) && (_c -> _cube[3][0][2] == _c -> _cube[3][1][1]) && (_c -> _cube[4][2][0] == color))
                t = true;
            if ((_c -> _cube[0][0][0] == color) && (_c -> _cube[3][0][2] == _c -> _cube[0][1][1]) && (_c -> _cube[4][2][0] == _c -> _cube[3][1][1]))
                t = true;
            if ((_c -> _cube[0][0][0] == _c -> _cube[3][1][1]) && (_c -> _cube[3][0][2] == color) && (_c -> _cube[4][2][0] == _c -> _cube[0][1][1]))
                t = true;
            if (t)
                count++;
            y();
            _c -> _ans.pop_back();
        }
        return count;
    }

    void one_corner(int color)
    {
        bool t;
        while (count_corners(color) != 4) {
            t = false;
            while (!t) {
                if ((_c -> _cube[0][0][0]==_c -> _cube[0][1][1]) && (_c -> _cube[3][0][2]==_c -> _cube[3][1][1]) && (_c -> _cube[4][2][0]==color))
                    t = true;
                if ((_c -> _cube[0][0][0]==color) && (_c -> _cube[3][0][2]==_c -> _cube[0][1][1]) && (_c -> _cube[4][2][0]==_c -> _cube[3][1][1]))
                    t = true;
                if ((_c -> _cube[0][0][0]==_c -> _cube[3][1][1]) && (_c -> _cube[3][0][2]==color) && (_c -> _cube[4][2][0]==_c -> _cube[0][1][1]))
                    t = true;
                if (!t)
                    y();
            }
            switch_corner();
        }
    }

    void flip_corner()
    {
        L();
        D();
        L1();
        D1();
    }

    void flip_corners()
    {
        for (int i = 0; i < 4; i++)
        {
            while (_c -> _cube[4][2][0] != _c -> _cube[4][1][1])
                flip_corner();
            U();
        }
    }

    void cross()
    {
        int color = _c -> _cube[2][1][1];
        int c;
        for (int i = 0; i < 4; i++) {
            c = 1;
            while (c != 0) {
                c = 0;
                if (_c -> _cube[0][0][1]==color) {
                    F();
                    while (_c -> _cube[4][1][2]==color)
                        U();
                    R();
                    c++;
                }
                if (_c -> _cube[0][1][0]==color) {
                    while (_c -> _cube[4][1][0]==color)
                        U();
                    L1();
                    c++;
                }
                if (_c -> _cube[0][1][2]==color) {
                    while (_c -> _cube[4][1][2]==color)
                        U();
                    R();
                    c++;
                }
                if (_c -> _cube[0][2][1]==color) {
                    while (_c -> _cube[4][2][1]==color)
                        U();
                    F1();
                    U1();
                    R();
                    c++;
                }
                if (_c -> _cube[2][0][1]==color) {
                    while (_c -> _cube[4][2][1]==color)
                        U();
                    F();
                    F();
                    c++;
                }
                y();
            }
        }
        for (int i = 0; i < 4; i++)
        {
            while(_c -> _cube[0][0][1] != _c -> _cube[0][1][1])
                U();
            F();
            F();
            y();
        }
    }

    void first_layer()
    {
        int color = _c -> _cube[2][1][1];
        for (int i = 0; i < 2; i++) {
            if ((_c -> _cube[2][0][0]==color) || (_c -> _cube[0][2][0] == color) || (_c -> _cube[3][2][2] == color)) {
                while ((_c -> _cube[0][0][0] == color) || (_c -> _cube[3][0][2]==color) || (_c -> _cube[4][2][0]==color))
                    U();
                left_pif_paf();
            }
            if ((_c -> _cube[2][0][2]==color) || (_c -> _cube[0][2][2] == color) || (_c -> _cube[1][2][0] == color)) {
                while ((_c -> _cube[0][0][2] == color) || (_c -> _cube[1][0][0] == color) || (_c -> _cube[4][2][2] == color))
                    U();
                pif_paf();
            }
            y();
            y();
        }
        bool t;
        for (int i = 0; i < 4; i++)
        {
            t = false;
            while (!t)
            {
                if ((_c -> _cube[0][0][2] == _c -> _cube[0][1][1]) && (_c -> _cube[1][0][0] == color) && (_c -> _cube[4][2][2] == _c -> _cube[1][1][1]))
                    t = true;
                if ((_c -> _cube[0][0][2] == color) && (_c -> _cube[1][0][0] == _c -> _cube[1][1][1]) && (_c -> _cube[4][2][2] == _c -> _cube[0][1][1]))
                    t = true;
                if ((_c -> _cube[0][0][2] == _c -> _cube[1][1][1]) && (_c -> _cube[1][0][0] == _c -> _cube[0][1][1]) && (_c -> _cube[4][2][2] == color))
                    t = true;
                if (t)
                {
                    while (_c -> _cube[2][0][2] != color) {
                        pif_paf();
                    }
                    y();
                }
                else
                    U();
            }
        }
    }

    void second_layer()
    {
        int color = _c -> _cube[4][1][1];
        for (int i = 0; i < 4; i++)
        {
            while ((_c -> _cube[0][1][2] != color) && (_c -> _cube[1][1][0] != color))
                raise_ribs();
            y();
            _c -> _ans.pop_back();
        }
        bool t;
        for (int i = 0;i < 4; i++)
        {
            t = false;
            while(!t)
            {
                if ((_c -> _cube[1][0][1] == _c -> _cube[1][1][1]) && (_c -> _cube[4][1][2] == _c -> _cube[0][1][1])) {
                    edge_to_right();
                    t = true;
                }
                if ((_c -> _cube[0][0][1] == _c -> _cube[0][1][1]) && (_c -> _cube[4][2][1] == _c -> _cube[1][1][1])) {
                    edge_to_left();
                    t = true;
                }
                if (t)
                    y();
                else
                    U();
            }
        }
    }

    void last_layer(bool &tmp)
    {
        last_cross(tmp);
        if (tmp) {
            right_cross(tmp);
            if (tmp)
            {
                swap_corners(tmp);
                if (tmp)
                    flip_corners();
            }
        }
    }

    void last_cross(bool &tmp)
    {
        int c = 0;
        int color = _c -> _cube[4][1][1];
        if (_c -> _cube[4][1][0] == color)
            c++;
        if (_c -> _cube[4][0][1] == color)
            c++;
        if (_c -> _cube[4][1][2] == color)
            c++;
        if (_c -> _cube[4][2][1] == color)
            c++;
        switch (c) {
        case 0:
            F();
            pif_paf();
            F1();
            nine_hours(color);
            break;
        case 1:
            tmp = false;
            break;
        case 2:
            while (_c -> _cube[4][1][0]!=color)
                U();
            if (_c -> _cube[4][1][2]==color)
                line(color);
            else
                nine_hours(color);
            break;
        case 3:
            tmp = false;
            break;
        default:
            break;
        }
    }

    void right_cross(bool &tmp)
    {
        int color = _c -> _cube[2][1][1];
        int c = 0;
        bool check = true;
        int max = 0;
        for (int i = 0; i < 4; i++) {
            c = 0;
            max = std::max(max, count_edge(color, c));
            if ((c == 2) && (max == c))
            {
                if ((_c -> _cube[3][0][1]==_c -> _cube[3][1][1]) && (_c -> _cube[1][0][1]==_c -> _cube[1][1][1]))
                    check = false;
                if ((_c -> _cube[0][0][1]==_c -> _cube[0][1][1]) && (_c -> _cube[5][0][1]==_c -> _cube[5][1][1]))
                    check = false;
            }
            if (c == 4)
                break;
            U();
        }
        switch (max)
        {
        case 2:
            if (check)
                edge_near(color);
            else
                edge_opposite(color);
            break;
        case 4:
            while (_c -> _cube[3][0][1] != _c -> _cube[3][1][1])
                U();
            break;
        default:
            tmp = false;
        }
    }

    void swap_corners(bool &tmp)
    {
        int color = _c -> _cube[4][1][1];
        bool t;
        int count = count_corners(color);
        switch (count)
        {
        case 0:
            switch_corner();
            one_corner(color);
            break;
        case 1:
            one_corner(color);
            break;
        case 4:
            break;
        default:
            tmp = false;
        }
    }
};

#endif //PROGA8_RUBIK_S_c -> _cube_c -> _cube_SOLVER_H