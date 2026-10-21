class Queue
{
    private int[] arr;
    private int front, size;
    private int capacity;

    public Queue(int c)
    {
        arr = new int[c];
        capacity = c;
        size = 0;
        front = 0;
    }

    public int getFront()
    {
        if (size == 0)
            return -1;
        return arr[front];
    }

    public int getRear()
    {
        if (size == 0)
            return -1;
        int rear = (front + size - 1) % capacity;
        return arr[rear];
    }

    public void enqueue(int x)
    {
        if (size == capacity)
            return;
        int rear = (front + size) % capacity;
        arr[rear] = x;
        size++;
    }

    public int dequeue()
    {
        if (size == 0)
            return -1;
        int res = arr[front];
        front = (front + 1) % capacity;
        size--;
        return res;
    }
}

public class CircularQueue
{
    public static void main(String[] args)
    {
        Queue q = new Queue(4);
        q.enqueue(10);
        System.out.println(q.getFront() + " " + q.getRear());
        q.enqueue(20);
        System.out.println(q.getFront() + " " + q.getRear());
        q.enqueue(30);
        System.out.println(q.getFront() + " " + q.getRear());
        q.enqueue(40);
        System.out.println(q.getFront() + " " + q.getRear());
        q.dequeue();
        System.out.println(q.getFront() + " " + q.getRear());

        q.dequeue();
        System.out.println(q.getFront() + " " + q.getRear());
        q.enqueue(50);
        System.out.println(q.getFront() + " " + q.getRear());
    }
}
