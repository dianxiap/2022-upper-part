#define _CRT_SECURE_NO_WARNINGS 1

//用数组实现堆主要的架构

//插入一个数
heap[++sz] = x; //在一维数组最后一个位置填充x
up(sz);       //将最后一个元素不断上移


//求最小值
heap[1]

//删除最小值
heap[1] = heap[sz--]; //就是把尾部最后一个元素替换掉头元素，然后sz--
down(1);            //然后再down(1)就行了

//删除任意一个元素
heap[k] = heap[sz--];
down(k);
up(k);   //其实只能执行一个，因为大了向下走。小了向上走嘛

//修改任意一个元素
heap[k] = x;
down(k);
up(k);

//down比较下移
void down(int u) {
    int t = u;
    if (u * 2 <= sz && heap[u * 2] < heap[t])t = u * 2;
    if (u * 2 + 1 <= sz && heap[u * 2 + 1] < heap[t]) t = u * 2 + 1;
    if (u != t) {
        swap(heap[u], heap[t]);
        down(t);
    }
}

//比较上移
void up(int u) {
    //如果父节点存在，并且父节点值大于u节点值
    while (u / 2 && heap[u / 2] > heap[u]) {
        swap(heap[u / 2], heap[u]);
        u /= 2;
    }
}