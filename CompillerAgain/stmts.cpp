#include "stmts.h"



stmts::stmts(){
    
}


stmts::~stmts(){
    
}
// <stmts>::= <stmts><stmt>  | <stmt>
// < stmt>::= <ass>; | <ass> | <cycle_stmt> | <if_stmt>
void stmts::deriving(int pos){
    int index = pos;
    int startOfLasStatement{};
    while(lexStream[index].type == KEY_WORD && KeyWords[lexStream[index].numInValidTable].val == "END" && lexStream[index+1].type == KEY_WORD && KeyWords[lexStream[index+1].numInValidTable].val == "."){
        startOfLasStatement = index;
    if((lexStream[pos].type == IDENT && (lexStream[pos+1].type == DIVIDE && Dividers[lexStream[pos+1].numInValidTable].val == "=") && lexStream[pos+2].type == IDENT) || (lexStream[pos].type == KEY_WORD && (KeyWords[lexStream[pos].numInValidTable].val == "if" || KeyWords[lexStream[pos].numInValidTable].val == "while" || KeyWords[lexStream[pos].numInValidTable].val == "for"  ))){
        continue;
        }
    else{
        //Добавить последнее выражение в дерево и вызвать свертку, после добавить еще стейтменсы хуейтменсы
    }
    }
}
