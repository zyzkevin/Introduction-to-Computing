#include"chess.h"
Cmap::Cmap()
{
    emp = 1;
    side = 1;
    step=0;
}
Cmap& Cmap::operator=(const Cmap& c)
{
    for (int i = 0; i<10; i++)
        for (int j = 0; j<10; j++)
            map[i][j] = c.map[i][j];
    step=c.step;
    return *this;
}
void Cmap::setSide(short s)
{
    side = s;
}
bool Cmap::empty()
{
    return emp;
}
short Cmap::Side()
{
    return side;
}
void Cmap::setStep(int s)
{
    if(s==-1) step++;
    step=s;
}
double Cmap::Eval()    //分阶段评估
{
    int** q = queenMove();
    double terr = territory(q);
    double posi = position(q);
    double w1, w2, w3;
    if(step<21)
    {
        w1=0.14;
        w2=0.13;
        w3=0.2;
    }
    if(step>20&&step<50)
    {
        w1=0.30;
        w2=0.20;
        w3=0.05;
    }
    else
    {
        w1=0.8;
        w2=0.05;
        w3=0;
    }
    return terr*w1 + posi*w2 + (as1 - as2)*w3;
}
double Cmap::territory(int** q)
{
    double terr = 0;
    for (int i = 0; i<10; i++)
        for (int j = 0; j < 10; j++)
        {
            if (map[i][j] != 0) continue;
            if (q[i][j] == queen[i][j] && q[i][j] == 10000) continue;
            if (q[i][j] < queen[i][j]) terr += 1;
            else if (q[i][j] == queen[i][j] && q[i][j] < 10000) terr += 0.5;
            else terr -= 1;
        }
    return terr;
}
double Cmap::position(int **q)
{
    double po = 0;
    for (int i = 0; i<10; i++)
        for (int j = 0; j < 10; j++)
        {
            if (map[i][j] != 0) continue;
            po += 1 / (q[i][j] * q[i][j]) - 1 / (queen[i][j] * queen[i][j]);
        }
    for (int i = 0; i < 10; i++)
    {
        delete[] q[i];
        delete[] queen[i];
    }
    delete[]q;    delete[]queen;
    return po;
}
int** Cmap::queenMove()
{
    int **q1;
    q1 = new int*[10];
    queen = new int*[10];
    int pos[9][2];
    for (int i = 0; i < 10; i++)
    {
        queen[i] = new int[10];
        q1[i] = new int[10];
        for (int j = 0; j < 10; j++)
        {
            q1[i][j] = queen[i][j] = 10000;
            if (map[i][j] != 0 && map[i][j] != -1)
            {
                pos[map[i][j]][0] = i;
                pos[map[i][j]][1] = j;
                q1[i][j] = queen[i][j] = 0;
            }
        }
    }
    for (int mk = 1; mk < 5; mk++)
    {
        int x = pos[mk][0], y = pos[mk][1];
        as1 = queenMark(x, y, queen[x][y] + 1);
    }
    for (int k = 1;; k++)
    {
        int count = 0;
        for (int i = 0; i<10; i++)
            for (int j = 0; j < 10; j++)
            {
                if (queen[i][j] == k) count += queenMark(i, j, k + 1);
            }
        if (count == 0) break;
    }
    int **qt = queen;
    queen = q1;
    q1 = qt;
    for (int mk = 5; mk < 9; mk++)
    {
        int x = pos[mk][0], y = pos[mk][1];
        as2 = queenMark(x, y, queen[x][y] + 1);
    }
    for (int k = 1;; k++)
    {
        int count = 0;
        for (int i = 0; i<10; i++)
            for (int j = 0; j < 10; j++)
            {
                if (queen[i][j] == k) count += queenMark(i, j, k + 1);
            }
        if (count == 0) break;
    }
    return q1;
}
int min(int m, int n)
{
    if (m < n) return m;
    else return n;
};
int Cmap::queenMark(int x, int y, int base)
{
    int c = 0;                    //向八个方向遍历并标记
    for (int i = 1; i < 10; i++)
    {
        if (x + i > 9 || map[x + i][y] != 0) break;
        if (queen[x + i][y] <= queen[x][y]) break;
        queen[x + i][y] = min(queen[x + i][y], base);
        c++;
    }
    for (int i = 1; i < 10; i++)
    {
        if (y + i > 9 || map[x][y + i] != 0) break;
        if (queen[x][y + i] <= queen[x][y]) break;
        queen[x][y + 1] = min(queen[x][y + i], base); c++;
    }
    for (int i = 1; i < 10; i++)
    {
        if (x - i <0 || map[x - i][y] != 0) break;
        if (queen[x - i][y] <= queen[x][y]) break;
        queen[x - i][y] = min(queen[x - i][y], base); c++;
    }
    for (int i = 1; i < 10; i++)
    {
        if (y - i <0 || map[x][y - i] != 0) break;
        if (queen[x][y - i] <= queen[x][y]) break;
        queen[x][y - i] = min(queen[x][y - i], base); c++;
    }
    for (int i = 1; i < 10; i++)
    {
        if (x + i > 9 || y + i>9 || map[x + i][y + i] != 0) break;
        if (queen[x + i][y + i] <= queen[x][y]) break;
        queen[x + i][y + i] = min(queen[x + i][y + i], base); c++;
    }
    for (int i = 1; i < 10; i++)
    {
        if (x + i > 9 || y - i<0 || map[x + i][y - i] != 0) break;
        if (queen[x + i][y - i] <= queen[x][y]) break;
        queen[x + i][y - i] = min(queen[x + i][y - i], base); c++;
    }
    for (int i = 1; i < 10; i++)
    {
        if (x - i <0 || y + i>9 || map[x - i][y + i] != 0) break;
        if (queen[x - i][y + i] <= queen[x][y]) break;
        queen[x - i][y + i] = min(queen[x - i][y + i], base); c++;
    }
    for (int i = 1; i < 10; i++)
    {
        if (x - i <0 || y - i<0 || map[x - i][y - i] != 0) break;
        if (queen[x - i][y - i] <= queen[x][y]) break;
        queen[x - i][y - i] = min(queen[x - i][y - i], base); c++;
    }
    return c;
}


void AI::inmap(Cmap& cp,int st)
{
     omap = cp;
     ct = cp;
     step = st;
}
Cmap& AI::outmap()     //迭代加深
{
    int d;
    if (step < 15) d = 2;
    else if (step < 40) d = 3;
    else d = 4;
    search(omap, d, 10000,-10000);
    return ct;
}
bool AI::isLost()
{
    Cmap *pc;
    pc = getnext(omap);
    if (!pc[0].empty())
    {
        delete[] pc;
        return 1;
    }
    delete[] pc;
    return 0;
}
bool AI::isWin()
{
    Cmap *pc;
    ct.setSide(-1);
    pc = getnext(ct);
    if (!pc[0].empty())
    {
        delete[] pc;
        return 1;
    }
    delete[] pc;
    return 0;
}
Cmap* AI::getnext(Cmap& mp)  //未释放内存
{
    int pos[4][2], c = 0, pd = 0;                   //棋子坐标，辅助变量
    Cmap* cm = new Cmap[2500];                     //待优化
    cm[0] = mp;
    int count = 0;
    short side = -mp.Side();
    for (int i = 0; i < 2500; i++)
    {
        cm[i].setStep(-1);
        cm[i].setSide(side);
    }
    for (int i = 0; i<10; i++)
        for (int j = 0; j<10; j++)
        {
            if (side <0)
            {
                if (mp.map[i][j] == 1 || mp.map[i][j] == 2 || mp.map[i][j] == 3 || mp.map[i][j] == 4)
                {
                    pos[mp.map[i][j] - 1][0] = i;
                    pos[mp.map[i][j] - 1][1] = j;
                    c++;
                }
            }
            else
            {
                if (mp.map[i][j] == 5 || mp.map[i][j] == 6 || mp.map[i][j] == 7 || mp.map[i][j] == 8)
                {
                    pos[mp.map[i][j] - 5][0] = i;
                    pos[mp.map[i][j] - 5][1] = j;
                    c++;
                }
            }
            if (c == 4) break;
        }
    if (side >0) pd = 4;
    for (int mk = 0; mk<4; mk++)
    {

        for (int i = 1; i<10; i++)
        {
            if (pos[mk][0] + i>9) break;
            if (mp.map[pos[mk][0] + i][pos[mk][1]] != 0) break;
            cm[count].map[pos[mk][0] + i][pos[mk][1]] = mk + 1 + pd;
            cm[count].map[pos[mk][0]][pos[mk][1]] = 0;
            setbarier(cm, pos[mk][0] + i, pos[mk][1], count);
            cm[count] = mp;
            cm[count].setStep(-1);
        }
        for (int i = 1; i<10; i++)
        {
            if (pos[mk][1] + i>9) break;
            if (mp.map[pos[mk][0]][pos[mk][1] + i] != 0) break;
            cm[count].map[pos[mk][0]][pos[mk][1] + i] = mk + 1 + pd;
            cm[count].map[pos[mk][0]][pos[mk][1]] = 0;
            setbarier(cm, pos[mk][0], pos[mk][1] + i, count);
            cm[count] = mp;
        }
        for (int i = 1; i<10; i++)
        {
            if (pos[mk][0] - i<0) break;
            if (mp.map[pos[mk][0] - i][pos[mk][1]] != 0) break;
            cm[count].map[pos[mk][0] - i][pos[mk][1]] = mk + 1 + pd;
            cm[count].map[pos[mk][0]][pos[mk][1]] = 0;
            setbarier(cm, pos[mk][0] - i, pos[mk][1], count);
            cm[count] = mp;
        }
        for (int i = 1; i<10; i++)
        {
            if (pos[mk][1] - i<0) break;
            if (mp.map[pos[mk][0]][pos[mk][1] - i] != 0) break;
            cm[count].map[pos[mk][0]][pos[mk][1] - i] = mk + 1 + pd;
            cm[count].map[pos[mk][0]][pos[mk][1]] = 0;
            setbarier(cm, pos[mk][0], pos[mk][1] - i, count);
            cm[count] = mp;
        }
        for (int i = 1; i<10; i++)
        {
            if (pos[mk][0] + i>9 || pos[mk][1] + i>9) break;
            if (mp.map[pos[mk][0] + i][pos[mk][1] + i] != 0) break;
            cm[count].map[pos[mk][0] + i][pos[mk][1] + i] = mk + 1 + pd;
            cm[count].map[pos[mk][0]][pos[mk][1]] = 0;
            setbarier(cm, pos[mk][0] + i, pos[mk][1] + i, count);
            cm[count] = mp;
        }
        for (int i = 1; i<10; i++)
        {
            if (pos[mk][0] + i>9 || pos[mk][1] - i<0) break;
            if (mp.map[pos[mk][0] + i][pos[mk][1] - i] != 0) break;
            cm[count].map[pos[mk][0] + i][pos[mk][1] - i] = mk + 1 + pd;
            cm[count].map[pos[mk][0]][pos[mk][1]] = 0;
            setbarier(cm, pos[mk][0] + i, pos[mk][1] - i, count);
            cm[count] = mp;
        }
        for (int i = 1; i<10; i++)
        {
            if (pos[mk][0] - i<0 || pos[mk][1] - i<0) break;
            if (mp.map[pos[mk][0] - i][pos[mk][1] - i] != 0) break;
            cm[count].map[pos[mk][0] - i][pos[mk][1] - i] = mk + 1 + pd;
            cm[count].map[pos[mk][0]][pos[mk][1]] = 0;
            setbarier(cm, pos[mk][0] - i, pos[mk][1] - i, count);
            cm[count] = mp;
        }
        for (int i = 1; i<10; i++)
        {
            if (pos[mk][0] - i<0 || pos[mk][1] + i>9) break;
            if (mp.map[pos[mk][0] - i][pos[mk][1] + i] != 0) break;
            cm[count].map[pos[mk][0] - i][pos[mk][1] + i] = mk + 1 + pd;
            cm[count].map[pos[mk][0]][pos[mk][1]] = 0;
            setbarier(cm, pos[mk][0] - i, pos[mk][1] + i, count);
            cm[count] = mp;
        }
    }
    cm[count].setEmpty();
    return cm;
}
void AI::setbarier(Cmap* cmap, int x, int y, int &c)  //设置障碍
{
    Cmap oc;
    oc = cmap[c];
    for (int i = 1; i<10; i++)
    {
        if (x + i>9) break;
        if (cmap[c].map[x + i][y] != 0) break;
        cmap[c + 1] = oc;
        cmap[c].map[x + i][y] = -1;
        ++c;
    }
    for (int i = 1; i<10; i++)
    {
        if (x - i<0) break;
        if (cmap[c].map[x - i][y] != 0) break;
        cmap[c + 1] = oc;
        cmap[c].map[x - i][y] = -1;
        ++c;
    }
    for (int i = 1; i<10; i++)
    {
        if (y + i>9) break;
        if (cmap[c].map[x][y + i] != 0) break;
        cmap[c + 1] = oc;
        cmap[c].map[x][y + i] = -1;
        ++c;
    }
    for (int i = 1; i<10; i++)
    {
        if (y - i<0) break;
        if (cmap[c].map[x][y - i] != 0) break;
        cmap[c + 1] = oc;
        cmap[c].map[x][y - i] = -1;
        ++c;
    }
    for (int i = 1; i<10; i++)
    {
        if (x + i>9 || y + i>9) break;
        if (cmap[c].map[x + i][y + i] != 0) break;
        cmap[c + 1] = oc;
        cmap[c].map[x + i][y + i] = -1;
        ++c;
    }
    for (int i = 1; i<10; i++)
    {
        if (x - i<0 || y - i<0) break;
        if (cmap[c].map[x - i][y - i] != 0) break;
        cmap[c + 1] = oc;
        cmap[c].map[x - i][y - i] = -1;
        ++c;
    }
    for (int i = 1; i<10; i++)
    {
        if (y + i>9 || x - i<0) break;
        if (cmap[c].map[x - i][y + i] != 0) break;
        cmap[c + 1] = oc;
        cmap[c].map[x - i][y + i] = -1;
        ++c;
    }
    for (int i = 1; i<10; i++)
    {
        if (y - i<0 || x + i>9) break;
        if (cmap[c].map[x + i][y - i] != 0) break;
        cmap[c + 1] = oc;
        cmap[c].map[x + i][y - i] = -1;
        ++c;
    }
}
double AI::search(Cmap& cmap, int deepth, double alph, double beta)
{
    Cmap *cm = getnext(cmap);
    double best=cm[0].Eval();
    ct = cm[0];
    Cmap bc = cm[0];
    if (deepth == 1)
    {
        for (int i = 0; cm[i].empty(); i++)
        {
            double t = cm[i].Eval();
            if (cmap.Side() > 0)
            {
                if (t > alph)
                {
                    delete[] cm;
                    return alph;
                }
                if (t > best)
                {
                    best = t;
                    bc = cm[i];
                }
            }
            else
            {
                if (t < beta)
                {
                    delete[] cm;
                    return beta;
                }
                if (t < best)
                {
                    best = t;
                    bc = cm[i];
                }
            }
        }
        delete[] cm;
        ct = bc;
        return best;
    }
    else
    {
        cm[0].setSide(-cmap.Side());
        double ft = search(cm[0], deepth - 1,10000,-10000);
        for (int i = 1; cm[i].empty(); i++)
        {
            cm[i].setSide(-cmap.Side());
            if (cmap.Side() > 0)
            {
                double t = search(cm[i], deepth - 1,10000,ft);
                if (t > alph)
                {
                    delete[] cm;
                    return alph;
                }
                if (t > ft)
                {
                    ct = bc = cm[i];
                    ft = t;
                }
            }
            else
            {
                double t = search(cm[i], deepth - 1, ft, -10000);
                if (t < beta)
                {
                    delete[] cm;
                    return beta;
                }
                if (t < ft)
                {
                    ct = bc = cm[i];
                    ft = t;
                }
            }
            ct = bc;
        }
        delete[] cm;
        return ft;
    }
}


chess::chess()
{
    for (int i = 0; i<10; i++)
        for (int j = 0; j<10; j++)
            chmap.map[i][j] = 0;
    chmap.map[0][3] = 1;
    chmap.map[0][6] = 2;
    chmap.map[3][0] = 3;
    chmap.map[3][9] = 4;
    chmap.map[6][0] = 5;
    chmap.map[6][9] = 6;
    chmap.map[9][3] = 7;
    chmap.map[9][6] = 8;
    step = 1;
    mapst[0]=chmap;
}
bool chess::isAvail(int x, int y, int ox, int oy)
{
    if (x == ox)
    {
        if (y == oy) return 0;
        if (oy < y)
            for (; oy < y; y--)
            {
                if (chmap.map[x][y] != 0) return 0;
            }
        if(oy>y)
            for (; oy > y; y++)
                if (chmap.map[x][y] != 0) return 0;
    }
    if (y == oy)
    {
        if (ox < x)
            for (; ox < x; x--)
            {
                if (chmap.map[x][y] != 0) return 0;
            }
        else
            for (; ox > x; x++)
                if (chmap.map[x][y] != 0) return 0;
    }
    if (x - ox != y - oy && x - ox != oy - y) return 0;
    else
    {
        if (x < ox)
        {
            if (y < oy)
            {
                for (; x < ox; x++, y++)
                    if (chmap.map[x][y] != 0) return 0;
            }
            else
            {
                for (; x < ox; x++, y--)
                    if (chmap.map[x][y] != 0) return 0;
            }
        }
        else
        {
            if (y < oy)
            {
                for (; x > ox; x--, y++)
                    if (chmap.map[x][y] != 0) return 0;
            }
            else
            {
                for (; x > ox; x--, y--)
                    if (chmap.map[x][y] != 0) return 0;
            }
        }
    }
    return 1;
}
void chess::setchess(int x, int y, int ox, int oy)
{
        chmap.map[x][y] = chmap.map[ox][oy];
        chmap.map[ox][oy] = 0;
        chmap.setStep(-1);
}
void chess::setbarrier(int x, int y)
{
        chmap.map[x][y] = -1;
}
int chess::val(int x, int y)
{
    return chmap.map[x][y];
}
bool chess::AIsetchess()
{
    ai.inmap(chmap,step);
    if(ai.isLost()) return 0;
    chmap=ai.outmap();
    mapst[step]=chmap;
    step++;
    return 1;
}
bool chess::youLost()
{
    ai.inmap(chmap,step);
    return ai.isWin();
}
void chess::clear()
{
    step = 1;
    chmap=mapst[0];
}
void chess::withdraw()
{
    if(step==1) return;
    step--;
    chmap=mapst[step-1];
}
