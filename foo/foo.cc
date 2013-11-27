//
//  foo.cc
//  foo
//
//  Created by bryan hunt on 27/11/2013.
//  Copyright (c) 2013 bryan hunt. All rights reserved.
//

#include "foo.h"

extern "C" {
    
Operation * newResizeOp(int percent) {
    Operation * resize_op =  (Operation *)malloc(sizeof(Operation));
    resize_op->op_type = Resize;
    Opinst inst ;
    resize_op->op = inst;
    resize_op->op.resize.percent =percent;
    return resize_op;
}


Operation * newTextOp(char * text) {
    Operation * text_op =  (Operation *)malloc(sizeof(Operation));
    text_op->op_type = Text;
    Opinst inst ;
    text_op->op = inst;
    text_op->op.text.text =text ;
    return text_op;
}

Operation * newCropOp(int x1,int y1, int x2, int y2) {
    Operation * crop_op =  (Operation *)malloc(sizeof(Operation));
    crop_op->op_type = Crop;
    Opinst inst ;
    crop_op->op = inst;
    crop_op->op.crop.x1 = x1 ;
    crop_op->op.crop.y1 = y1 ;
    crop_op->op.crop.x2 = x2 ;
    crop_op->op.crop.y2 = y2 ;
    return crop_op;
}

using namespace std;

void printOp(const Operation * op) {
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

void print_opstack(const Opstack * opstack) {
    for (int i = 0; i < opstack->ops_count;i++) {
        printOp(*(opstack->ops +i));
    }
}
    
}