//
//  foo.h
//  foo
//
//  Created by bryan hunt on 27/11/2013.
//  Copyright (c) 2013 bryan hunt. All rights reserved.
//

#ifndef __foo__foo__
#define __foo__foo__

#include <iostream>

extern "C" {

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
    int ops_count;
    Operation  * ops [];
};

Operation * newResizeOp(int percent);

Operation * newTextOp(char * text) ;

Operation * newCropOp(int x1,int y1, int x2, int y2) ;

void printOp(const Operation * op);

void print_opstack(const Opstack * opstack) ;
}

#endif /* defined(__foo__foo__) */
