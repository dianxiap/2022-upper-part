#define _CRT_SECURE_NO_WARNINGS 1

//������ʵ�ֶ���Ҫ�ļܹ�

//����һ����
heap[++sz] = x; //��һά�������һ��λ�����x
up(sz);       //�����һ��Ԫ�ز�������


//����Сֵ
heap[1]

//ɾ����Сֵ
heap[1] = heap[sz--]; //���ǰ�β�����һ��Ԫ���滻��ͷԪ�أ�Ȼ��sz--
down(1);            //Ȼ����down(1)������

//ɾ������һ��Ԫ��
heap[k] = heap[sz--];
down(k);
up(k);   //��ʵֻ��ִ��һ������Ϊ���������ߡ�С����������

//�޸�����һ��Ԫ��
heap[k] = x;
down(k);
up(k);

//down�Ƚ�����
void down(int u) {
    int t = u;
    if (u * 2 <= sz && heap[u * 2] < heap[t])t = u * 2;
    if (u * 2 + 1 <= sz && heap[u * 2 + 1] < heap[t]) t = u * 2 + 1;
    if (u != t) {
        swap(heap[u], heap[t]);
        down(t);
    }
}

//�Ƚ�����
void up(int u) {
    //������ڵ���ڣ����Ҹ��ڵ�ֵ����u�ڵ�ֵ
    while (u / 2 && heap[u / 2] > heap[u]) {
        swap(heap[u / 2], heap[u]);
        u /= 2;
    }
}