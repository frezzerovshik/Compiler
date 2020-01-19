#include "expr.h"



expr::expr(){
}


expr::~expr(){
}


// <expr> ::=< expr> +< term> |< expr>  – <term> |< term> | <call_func>
// <factor> ::= (<expr>)|<loc>|<num>|true|false
//<term> ::=< term>*<factor> |< term>/<factor> |< factor>
void expr::deriving(int pos) {

}