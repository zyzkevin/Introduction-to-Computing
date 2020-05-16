#ifndef CHESS_H
#define CHESS_H

class Cmap
{
public:
    Cmap();
    Cmap& operator=(const Cmap& c);
    int map[10][10];
    double Eval();                                  //评估函数
    void setSide(short s);
    short Side();                                   //判断下棋方
    bool empty();                                   //判断棋局是否为空
    void setEmpty() { emp = 0; }
    void setStep(int s);
private:
    int queenMark(int x, int y, int base);             //queenmove的辅助函数
    int** queenMove();                                 //获得queenmove
    double territory(int** q);                        //控制权局势
    double position(int** q);                        //位置局势
    int as1, as2;                                   //双方可行步数，下棋方问题
    short side;                                     //下棋方，+表示AI方
    int step;
    int **queen;
    bool emp;                                    //棋盘是否为空,0为空
};
class AI
{
public:
    void inmap(Cmap& cp,int st);                                             //输入棋局
    Cmap& outmap();                                                    //处理并输出棋局
    void learn();                                                      //学习(未完成）
    Cmap* getnext(Cmap& mp);                                            //着法生成
    void setbarier(Cmap* cmap, int x, int y, int &c);
    double search(Cmap& cmap, int deepth, double alph, double beta);  //搜索
    bool isLost();
    bool isWin();
private:
    Cmap omap, ct;
    int step;
};

//


class chess
{
public:
    chess();
    void setchess(int x, int y, int ox,int oy);  //下棋
    void setbarrier(int x, int y);                //放箭
    bool isAvail(int x, int y, int ox,int oy);   //判断是否可行
    bool AIsetchess();                           //AI下棋
    bool youLost();                              //你输了吗？
    void withdraw();                            //悔棋
    void clear();                               //清棋盘
    int val(int x,int y);
private:
    AI ai;
    Cmap chmap;
    Cmap mapst[250];
    int step;
};
#endif // CHESS_H
