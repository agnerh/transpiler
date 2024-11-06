#include "compiler/compiler.h"
#include <string>
/*
To perform the transformation, however, we will not work directly on code. 
Instead, we will work on a representation of the code that would make this operation easier and more maintainable. 
This representation is the abstract syntax tree (AST).

So our transpiler will have these stages:

Parsing stage: we will adopt a parser to obtain an AST from the code of the original language

Transformation stage: we will transform in one or more steps the AST of the original language into 
the corresponding AST of the target language

Generation stage: once we have the AST of the target language we generate the corresponding code out of it
*/

int main() {
    //TODO: Add CLI arguments
    std::string entry_point = "testfiles/test.ts";
    
    Compiler* cmp = new Compiler();
    cmp->SetEntryPoint(entry_point);
    cmp->Compile();
}