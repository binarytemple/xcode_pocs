#include <iostream>

#include "foo.h"

int main(int argc, const char * argv[]){
    using namespace std;

    Operation * resize = newResizeOp(50);
    Operation * text = newTextOp((char *)"foo");
    Operation * crop = newCropOp(0,0,20,20);

    Opstack * opstack = (Opstack *)malloc(sizeof(Opstack)) ;

    opstack->ops[0] = (Operation *) resize;
    opstack->ops[1]  = (Operation *)text;
    opstack->ops[2] =  (Operation *)crop;
    opstack->ops_count = 3;
    
    cout << "--------------------------------" << endl;
    cout << "Printing operations individually" << endl;
    cout << "--------------------------------" << endl;
    
    printOp(resize);
    printOp(text);
    printOp(crop);


    
    cout << "--------------------" << endl;
    cout << "Printing the opstack" << endl;
    cout << "--------------------" << endl;
    print_opstack(opstack);

    free(opstack);
    free(resize);
    free(text);
    free(crop);

    
    return 0;
}