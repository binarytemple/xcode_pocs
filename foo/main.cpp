#include <iostream>

struct ResizeOp{
    int percent;
};

struct TextOp{
    char * text;
};

/*
 Positioning is relative to the top left corner of the image
 */
struct CropOp{
    int x1, y1, x2,y2;
};


enum Optype {
    Resize,Text,Crop,Unknown
};

union Opinst {
    ResizeOp resize;
    TextOp text;
    CropOp crop;
};

struct Operation {
    Optype op_type = Unknown;
    Opinst op;
};


struct Opstack {
    Operation  * ops ;
    int ops_count;
};



Operation newResizeOp(int percent) {
    Operation resize_op;
    resize_op.op_type = Resize;
    Opinst inst ;
    resize_op.op = inst;
    resize_op.op.resize.percent =percent;
    return resize_op;
}


Operation newTextOp(char * text) {
    Operation text_op;
    text_op.op_type = Text;
    Opinst inst ;
    text_op.op = inst;
    text_op.op.text.text =text ;
    return text_op;
}

Operation newCropOp(int x1,int y1, int x2, int y2) {
    Operation crop_op;
    crop_op.op_type = Crop;
    Opinst inst ;
    crop_op.op = inst;
    crop_op.op.crop.x1 = x1 ;
    crop_op.op.crop.y1 = y1 ;
    crop_op.op.crop.x2 = x2 ;
    crop_op.op.crop.y2 = y2 ;
    return crop_op;
}

using namespace std;

void printOp(Operation * op) {
    switch (op->op_type) {
        case Resize:
            printf("resize operation - percentage = %d\n", op->op.resize.percent );
            break;
        case Text:
            printf("text operation - text = %s \n", op->op.text.text);
            break;
        case Crop:
            printf("crop operation - start = (%d,%d), end =(%d, %d) \n",
                   op->op.crop.x1,
                   op->op.crop.y1,
                   op->op.crop.x2,
                   op->op.crop.y2
                   );
            break;
            
            
        default:
            printf("unknown operation \n");
            break;
    }
}

void print_opstack(Opstack * opstack) {
    for (int i = 0; i < opstack->ops_count;i++) {
        printOp((opstack->ops +i));
    }
}

int main(int argc, const char * argv[]){

    Operation resize = newResizeOp(50);
    Operation text = newTextOp((char *)"foo");
    Operation crop = newCropOp(0,0,20,20);

    Opstack opstack_raw;
    Opstack * opstack = &opstack_raw;
    Operation ops [3]   = {resize,text,crop};
    opstack->ops = ops   ;
    opstack->ops_count = 3;
    
    cout << "--------------------------------" << endl;
    cout << "Printing operations individually" << endl;
    cout << "--------------------------------" << endl;
    
    printOp(&resize);
    printOp(&text);
    printOp(&crop);

    cout << "--------------------" << endl;
    cout << "Printing the opstack" << endl;
    cout << "--------------------" << endl;
    print_opstack(opstack);
    
    return 0;
}