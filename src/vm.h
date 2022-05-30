#ifndef nlang_vm_h
#define nlang_vm_h
#define STACK_MAX 256
#include "value.h"
#include "chunk.h"

typedef struct{
    Chunk* chunk;
    uint8_t* ip;
    Value stack[STACK_MAX];
    Value* stackTop;
    Obj* objects;
}VM;

typedef enum{
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR,
}InterpretResult;

extern VM vm;

Value pop();
void push(Value value);
void initVM();
void freeVM();
InterpretResult interpret(const char* source);

#endif
