//
//  nums.hpp
//  CompilerAgain
//
//  Created by Артем Шарапов on 10.01.2020.
//  Copyright © 2020 Артем Шарапов. All rights reserved.
//

#pragma once
#include "symbol.h"

class nums : public symbol{
public:
	vector<symbol*> _childs;
    nums();
    ~nums();
    void deriving(int pos);
};
