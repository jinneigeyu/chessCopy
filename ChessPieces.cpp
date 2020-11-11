﻿/*
 * Copyright (C)  2019~2020  偕臧  All rights reserved.
 *
 * Author:  xmuli(偕臧) xmulitech@gmail.com
 *
 * github:  https://github.com/xmuli
 * blogs:   https://xmuli.tech
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://touwoyimuli.github.io/>.
 */
#include "ChessPieces.h"

//1、定义结构体tPOS
struct POS
{
    int t_nRow;
    int t_nCol;
    ChessPieces::m_emTYPE t_emType;
};

//定义基础的16棋子[预定作为上方使用，黑棋使用]
POS tPos[16]= {
              {0, 0, ChessPieces::CHE},
              {0, 1, ChessPieces::MA},
              {0, 2, ChessPieces::XIANG},
              {0, 3, ChessPieces::SHI},
              {0, 4, ChessPieces::JIANG},
              {0, 5, ChessPieces::SHI},
              {0, 6, ChessPieces::XIANG},
              {0, 7, ChessPieces::MA},
              {0, 8, ChessPieces::CHE},

              {2, 1, ChessPieces::PAO},
              {2, 7, ChessPieces::PAO},
              {3, 0, ChessPieces::BING},
              {3, 2, ChessPieces::BING},
              {3, 4, ChessPieces::BING},
              {3, 6, ChessPieces::BING},
              {3, 8, ChessPieces::BING}
              };

ChessPieces::ChessPieces()
{
}

ChessPieces::~ChessPieces()
{
}

//初始化  对每一个棋子进行检验判断而后赋相应的值
void ChessPieces::init(int id)
{
    if(id <16)
    {
        m_nRow = tPos[id].t_nRow;
        m_nCol = tPos[id].t_nCol;
        m_emType = tPos[id].t_emType;
        m_bRed = false;
    }
    else
    {
        m_nRow = 9-tPos[id-16].t_nRow;
        m_nCol = 8-tPos[id-16].t_nCol;
        m_emType = tPos[id-16].t_emType;
        m_bRed = true;
    }

    m_bDead = false;
}

QString ChessPieces::getnName()
{
    //enum m_emTYPE{JIANG, SHI, XIANG, MA, CHE, PAO, BING};
    switch(m_emType)
    {
    case CHE:
        return QString::fromLocal8Bit("车");
    case MA:
        return  QString::fromLocal8Bit("马");
    case PAO:
        return  QString::fromLocal8Bit("炮");
    case BING:
        return  QString::fromLocal8Bit("兵");
    case JIANG:
        return  QString::fromLocal8Bit("将");
    case SHI:
        return  QString::fromLocal8Bit("士");
    case XIANG:
        return  QString::fromLocal8Bit("相");
    default:
        return QString::fromLocal8Bit("显示出错");
    }

    return "ERROR";
}
