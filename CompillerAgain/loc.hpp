//
//  loc.hpp
//  CompilerAgain
//
//  Created by Артем Шарапов on 10.01.2020.
//  Copyright © 2020 Артем Шарапов. All rights reserved.
//
#pragma once
#include "symbol.h"

class loc : public symbol{
public:
	vector<symbol*> _childs;
    void deriving(int pos);
    loc();
    ~loc();
};
