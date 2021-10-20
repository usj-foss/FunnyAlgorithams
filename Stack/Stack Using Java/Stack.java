public class Stack {

    stackNode head;

    public boolean isEmpty(){
        if(head == null){
            return true;
        }else{
            return false;
        }
    }

    public void push(char data){
        stackNode newNode = new stackNode(data);

        if(head == null){
            head = newNode;
        }else{
            newNode.next = head;
            head = newNode;
        }

    }

    public char pop(){
        char popped = Character.MIN_VALUE;
        if (head == null) {
            System.out.println("Stack is Empty");
        }
        else {
            popped = head.data;
            head = head.next;
        }
        return popped;
    }

    public char peek(){
        if (head == null) {
            System.out.println("Stack is empty");
            return Character.MIN_VALUE;
        }
        else {
            return head.data;
        }

    }

    public void display(){

        stackNode currentNode = head;

        while(currentNode != null){
            System.out.println(currentNode.data);

            currentNode = currentNode.next;
        }

    }

}

class Main {
    // Driver code
    public static void main(String[] args) {

        Stack sll = new Stack();

        sll.push('a');
        sll.push('b');
        sll.push('c');

        sll.display();

        sll.pop();
        System.out.println("popped from stack");

        System.out.println("Top element is " + sll.peek());
    }
}