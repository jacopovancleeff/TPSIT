
/*                          push

void push(struct stack_node **head,struct stack_node *element){
    if(is_empty(*head)){
        *head = element;
        element ->next = NULL;
    }else
    {
        element ->next = head;
        *head = element;
    }
}

*/

/*                          pop

struct stack_node * pop (struct stack_node **head){
    struct stack_node *ret = *head;

    if(is_empty(*head)){
        return NULL;
    }else{
        *head = ret-> next;

        return ret;

        
    }
}

void enqueue(stuct queue_node **head,struct queue_node **tail,struct queeu_node *element){
    
    if (is_empty(*head))
    {
        *head = element;
    }else
    {
        (*tail)-> = element;
    }
    
    *tail = element;
    element -> next = null
    
}


struct queue_node * pop (struct queue_node **head,struct queue_node **tail){
    struct queue_node *ret = *head;

    if(is_empty(*head)){
        return NULL;
    }else{
        *head = ret-> next;
    }
    if(*head == NULl)
        *tail = NULL;

    return ret;

        
    }
}
*/