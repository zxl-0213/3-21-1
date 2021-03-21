typedef struct stack
{
    int* a;
    int top;
    int capacity;
}stack;

void stackInit(stack* st)
{
    st->a=(int*)malloc(sizeof(int)*10000);
    if(st->a==NULL)
        exit(-1);
    st->top=0;
    st->capacity=10000;
}

void stackPush(stack* st,int x)
{
    st->a[st->top]=x;
    st->top++;
}

void stackPop(stack* st)
{
    st->top--;
}
int stackTop(stack* st)
{
    return st->a[st->top-1];
}
int stackEmpty(stack* st)
{
    return st->top==0?1:0;
}

void stackDestory(stack* st)
{
    free(st->a);
    st->top=0;
    st->capacity=0;
}
typedef struct {
    struct stack s1;//做入数据
    struct stack s2;////做出数据
    int front;
    int back;
} CQueue;


CQueue* cQueueCreate() {
    CQueue* cq=(CQueue*)malloc(sizeof(CQueue));
    stackInit(&cq->s1);
    stackInit(&cq->s2);
    cq->front=0;
    cq->back=0;
    return cq;
}

void cQueueAppendTail(CQueue* obj, int value) {
    stackPush(&obj->s1,value);
}

int cQueueDeleteHead(CQueue* obj) {
    if(stackEmpty(&obj->s2))
    {
        while(!stackEmpty(&obj->s1))
        {
            stackPush(&obj->s2,stackTop(&obj->s1));
            stackPop(&obj->s1);
        }
    }
    
    if(!stackEmpty(&obj->s2))
    {
        int ret=stackTop(&obj->s2);
        stackPop(&obj->s2);
        return ret;
    }
    return -1;
    
}

void cQueueFree(CQueue* obj) {
    stackDestory(&obj->s1);
    stackDestory(&obj->s2);
    free(obj);
}

/**
 * Your CQueue struct will be instantiated and called as such:
 * CQueue* obj = cQueueCreate();
 * cQueueAppendTail(obj, value);
 
 * int param_2 = cQueueDeleteHead(obj);
 
 * cQueueFree(obj);
*/