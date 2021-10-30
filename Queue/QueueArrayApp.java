/*
    Author -Yashmi Kumarasiri
    Date Modified - 30/10/2021
*/ 


public class QueueArrayApp {

    
    public static void main(String[] args) {
        
        QueueArray x = new QueueArray(5);
        
        x.display();
        x.enqueue(7);
        x.enqueue(5);
        x.enqueue(2);
        x.display();
        try{
            x.dequeue();
            x.display();
            System.out.println("peek is "+x.peek());
        }catch(Exception e){
            System.out.println(e.toString());
        }
    }
    
}

class QueueArray
{
    private int maxSize;
    private int[] queArray;
    private int front;
    private int rear;
    private int nItems;//how many eles are currently holding
    
    public QueueArray(int s){
        this.queArray=new int[s];
        this.maxSize=s;
        this.front=0;
        this.rear=-1;
        this.nItems=0;
        
    }
    
    public boolean isEmpty(){
        return this.nItems==0;
    
    }
    public boolean isFull(){
        return this.nItems==this.maxSize;
    }
    
    public int size(){
        return this.nItems;
    }
    public void enqueue(int value){
        if(isFull()){
            System.out.println("Queue is full");
            return;
        }
//        if(this.rear == this.maxSize - 1){
//            this.rear=0;
//        }
//        else{
//        this.rear++;
//        }
            rear=(rear+1) % maxSize;
        this.queArray[rear]=value;
        this.nItems++;
    }
    
    public int dequeue() throws Exception{
        if(isEmpty()){
            throw new Exception("Que is empty. cannot remove");
        }
        int removedItem = this.queArray[front];
//        if(this.front == this.maxSize-1){
//            this.front=0;
//        }
//        else{
//            front++;
//        }

       front=(front+1) % maxSize;
        nItems--;
        return removedItem;
    }
    
    public int peek()throws Exception{
        if (isEmpty()){
        throw new Exception("Que is empty. cannot remove");
        
        }
        return this.queArray[this.front];
    }
    
    public void display(){
        if(isEmpty()){
            System.out.println("Queue is Empty.Nothing to print");
            return;
        }
        int i = this.front;
        while(i != rear){
            System.out.println(this.queArray[i]+" ");
            if(i==maxSize-1){
                i=0;
            }else{
                i++;
            }
            System.out.println(this.queArray[rear]);
            System.out.println();
      }
    }
}
