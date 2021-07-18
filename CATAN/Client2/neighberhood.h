#ifndef NEIGHBERHOOD_H
#define NEIGHBERHOOD_H

#include <QMap>
#include <QVector>

#include "ground/node.h"
#include "ground/ground.h"

namespace  {

}
QMap<int,Qvector<node*>> map={
        {0,{m_nodes[19],m_nodes[20],m_nodes[21],m_nodes[32],m_nodes[33],m_nodes[34]}},
        {1,{m_nodes[21],m_nodes[22],m_nodes[23],m_nodes[34],m_nodes[35],m_nodes[36]}},
        {2,{m_nodes[23],m_nodes[24],m_nodes[25],m_nodes[36],m_nodes[37],m_nodes[38]}},
        {3,{m_nodes[31],m_nodes[32],m_nodes[33],m_nodes[45],m_nodes[46],m_nodes[47]}},
        {4,{m_nodes[33],m_nodes[34],m_nodes[35],m_nodes[47],m_nodes[48],m_nodes[49]}},
        {5,{m_nodes[35],m_nodes[36],m_nodes[37],m_nodes[49],m_nodes[50],m_nodes[51]}},
        {6,{m_nodes[37],m_nodes[38],m_nodes[39],m_nodes[51],m_nodes[52],m_nodes[53]}},
        {7,{m_nodes[44],m_nodes[45],m_nodes[46],m_nodes[58],m_nodes[59],m_nodes[60]}},
        {8,{m_nodes[46],m_nodes[47],m_nodes[48],m_nodes[60],m_nodes[61],m_nodes[62]}},
        {9,{m_nodes[48],m_nodes[49],m_nodes[50],m_nodes[62],m_nodes[63],m_nodes[64]}},
        {10,{m_nodes[50],m_nodes[51],m_nodes[52],m_nodes[64],m_nodes[65],m_nodes[66]}},
        {11,{m_nodes[52],m_nodes[53],m_nodes[54],m_nodes[66],m_nodes[67],m_nodes[68]}},
        {12,{m_nodes[59],m_nodes[60],m_nodes[61],m_nodes[72],m_nodes[73],m_nodes[74]}},
        {13,{m_nodes[61],m_nodes[62],m_nodes[63],m_nodes[74],m_nodes[75],m_nodes[76]}},
        {14,{m_nodes[63],m_nodes[64],m_nodes[65],m_nodes[76],m_nodes[77],m_nodes[78]}},
        {15,{m_nodes[65],m_nodes[66],m_nodes[67],m_nodes[78],m_nodes[77],m_nodes[78]}},
        {16,{m_nodes[73],m_nodes[74],m_nodes[75],m_nodes[],m_nodes[77],m_nodes[78]}},
    };
#endif // NEIGHBERHOOD_H
