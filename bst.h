template<typename T>
class Node{
    private:
        T data;
        Node<T>* left;
        Node<T>* right;
        template<typename U>
        friend class BST;
    public:
        Node(T data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};


template<typename T>
class BST{
  private:
    Node<T> * root;
    
    // Recursive insertion method
    void insert(Node<T> * & node, T data){
      if(node== NULL){                          //O(1)
        node = new Node<T>(data);                  //O(1)
      }else{
        if(data < node->data){ // <
          insert(node->left, data);             //O(1)
        }else if(data > node->data){ // >       //O(1)
          insert(node->right, data);            //O(1)
        }
        
      }
    }
    // recursive lenght() 
    int length(Node<T> * & node){
      if(node == NULL) return 0;                          //O(1)
      else return(length(node->left) + 1 + length(node->right)); 
    }
    // recursive max()
    int max(Node<T> * & node){
      if(node == NULL) return 0;                          //O(1)
      int node_data = node->data;                         //O(n)
      int left_max = max(node->left);                     //O(1)
      int right_max = max(node->right);                   //O(1)
      if(left_max>=node_data) return left_max;            //O(1)
      if(right_max>=node_data) return right_max;          //O(1)
      return node_data;                                   //O(1)
    }
    // recursive min()
    int min(Node<T> * & node){
      if(node == NULL) return 10000000;                   //O(1)
      int node_data = node->data;                         //O(n)
      int left_min = min(node->left);                     //O(1)
      int right_min = min(node->right);                   //O(1)
      if(left_min<=node_data) return left_min;            //O(1)
      if(right_min<=node_data) return right_min;          //O(1)
      return node_data;                                   //O(1)
    }   
    // recursive preOrden()
    void preOrden(Node<T> * & node){
      if(node != NULL){                                   //O(1)
        cout << node-> data << ":";                       //O(1)
        preOrden(node->left);                             //O(n)
        preOrden(node->right);                            //O(n)
      }
    }
    // recurisve postOrden
    void postOrden(Node<T> * & node){
      if(node != NULL){                                             
                //O(1)
        postOrden(node->left);
                //O(n)
        postOrden(node->right);
                //O(n)
        cout << node-> data << ":";
                //O(1)
      }
    }
    // recursive inOrden()
    void inOrden(Node<T> * & node){
      if(node != NULL){
                //O(1)
        inOrden(node->left);
                //O(n)
        cout << node-> data << ":";
                //O(1)
        inOrden(node->right);
                //O(n)
      }
    } 
    // recursive search
    bool search(Node<T> * & node, T data){
      if(node == NULL) return false;                          //O(1)
      if(data == node->data) return true;
                   //O(1)
      if(data < node->data) return search(node->left, data);  //O(1)
      if(data > node->data) return search(node->right, data); //O(1)
    }
    // recursive height
    int height(Node<T> * & node){
      if(node == NULL) return 0;    //O(1)
      else{
        int right_height = height(node->right);  //O(1)
        int left_height  = height(node->left);   //O(1)
        if(left_height>right_height) return left_height + 1;    //O(n)
        else return right_height+1;   //O(n)
      }
    }
    // recurisve levels
    void levels(Node<T> * & node, int level){
      if(node == NULL) return;    //O(1)
      if(level == 1) cout << node->data << ":";  //O(1)
      else if(level>1){ 
        levels(node->left, level-1);    //O(n)
        levels(node->right, level-1);   //O(n)
      }
    }
    // recursive ancestors
    void ancestors(Node<T> * & node, int value){
      if(node == NULL) return;  //O(1)
      if(!search(node, value)) return;
      cout << node->data << ":";  //O(1)
      if(search(node->left, value)) ancestors(node->left, value);   //O(n)
      else if(search(node->right, value)) ancestors(node->right, value);  //O(n)
    }
    // recurise level
    int level(Node<T> * & node, int value){
      if(node == NULL) return 0;    //O(1)
      if(!search(node, value)) return 0;  //O(1)
      if(search(node->left, value)) return 1+ level(node->left, value);   //O(n)
      else if(search(node->right, value)) return 1+ level(node->right, value);  //O(n)
      else return 1;    //O(1)
    }
    // recursive flatten
    LinkedList<T> flatten(Node<T> * & node, LinkedList<T> & lista_ligada){
      if(node != NULL){                                   //O(1)
        lista_ligada.addLast(node->data);
        flatten(node->left, lista_ligada);                             //O(n)
        flatten(node->right, lista_ligada);                            //O(n)
      }
      return lista_ligada;
    }
    // recurise tree_print
    void tree_print(Node<T> * & node, int spaces=0){
      if(node == NULL) return;    //O(n)
      spaces += 10;
      
      tree_print(node->right, spaces);  //O(n)

      cout << endl;                   //O(1)
      for(int i = 10; i < spaces; i++) cout << " "; //O(n) y  O(1)
      cout << node->data << endl; //O(n)

      tree_print(node->left, spaces); //O(n)
    }

    // recursive if_full
    bool is_full(Node<T> * & node){
      if(node == NULL) return true;                                               //O(1)
      if(node->right == NULL && node->left == NULL) return true;                  //O(1)
      if(node->right != NULL && node->left) return (is_full(node->right) && is_full(node->left)); //O(1)
      return false;
    }
    // recurise leaf_count()
    int leaf_count(Node<T> * & node){
      if(node == NULL) return 0;    //O(1)
      if(node->left == NULL && node->right == NULL) return 1;   //O(1)
      return leaf_count(node->left) + leaf_count(node->right);    //O(n)
    }
    // recurise is_perfect()
    bool is_perfect(Node<T> * & node, int height, int level = 0){
      if(node==NULL) return true;   //O(1)
      if(node->left == NULL && node->right == NULL) return height == level + 1;   //O(n)
      if(node->left == NULL || node->right == NULL) return false;   //O(1)
      return is_perfect(node->left, height, level + 1) && is_perfect(node->right, height, level + 1);   //O(n)
    }
    // recurise is_degenerate()
    bool is_degenerate(Node<T> * & node){
      if(node->left != NULL){   //O(1)
        if(node->right != NULL) return false;   //O(1)
        else return is_degenerate(node->left);  //O(n)
      }
      else{
        if(node->right != NULL) return is_degenerate(node->right);    //O(n)
        else return true; //O(1)
      }
    }
    // recursive infected_servers()
    int num_infected = 0;
    float infected_servers(Node<T> * & node){
      if(node == NULL) return 0;                          //O(1)
      if(node->data.infected == 1) num_infected += 1;      
         //O(1)
      return(infected_servers(node->left) + 1 + infected_servers(node->right));   //O(n)
    }
    // recurise search_ip()
    bool search_ip(Node<T> * & node, string ip){
      if(node == NULL) return false;    //O(1)
      int p = node->data.size();
      Server dat;   //O(1)
      bool found = false;
      for(int i = 0; i < p; i++){   //O(n)
        dat = node->data.get(i);    //O(n)
        if(dat.getIp() == ip) found = true; //O(1)
      }
      if(found == true){
      return true;   //O(1)
      }
      else return search_ip(node->left, ip) || search_ip(node->right, ip);    //O(n)
    }

  public:
    BST(){
      root = NULL;                              //O(1)
    }
    
    bool isEmpty(){
      return root == NULL;                      //O(1)
    }
    
    void insert(T data){
      if(isEmpty()){                            //O(1)
        root = new Node<T>(data);                  //O(1)
      }else{
        insert(root, data);
      }
    }

    /*
    Method to get the number of elements in binary tree.
    Uses a recursive method.
    */
    int length(){
      if(isEmpty()) return 0;                     //O(1)
      else return length(root);                   //O(1)
    }

    /*
    Method to get the max value element in the binary tree.
    Uses a recursive method.
    */
    int max(){
      if(isEmpty()) return 0;                     //O(1)
      else return max(root);                      //O(1)
    }
    /*
    Method to get the min value element in the binary tree.
    Uses a recursive method.
    */
    int min(){
      if(isEmpty()) return 0;                      //O(1)
      else return min(root);                      //O(1)
    }
    /*
    Method to check existance of value in vinary tree. Has 
    a recursive method.
    */
    bool search(T data){
      if(isEmpty()) return 0;                   //O(1)
      else return search(root, data);          //O(1)
    }


    /*
    Method to print binary tree. Uses a private method(function
    overloaded).
    */
    void preOrden(){
      preOrden(root);
      cout << endl;                           //O(1)
    }

    void postOrden(){
      postOrden(root);
      cout << endl;                           //O(1)
    }
    void inOrden(){
      inOrden(root);
      cout << endl;
    }

    /*
    Method to get the maximun hight of binary tree
    */
    int height(){
      return height(root);                    //O(1)
    }

    /*
    Method to print binary tree, level by level, from left to 
    right. Applied an stack for managing this method.
    */
    void levels(){
      int h = height();
      for(int i = 1; i<h; i++)levels(root, i);
      cout << endl;                          //O(1)
    }
    /*
    Method to print the route taken for location of some value
    */
    void ancestors(int value){
      ancestors(root, value);
      cout << endl;                          //O(1)
    }
    void path(int value){
      ancestors(root, value);
      cout << endl;                          //O(1)
    } 
    /*
    Method to get the level in which a value is found
    */
    int level(int value){
      return level(root, value);              //O(1)
    }
    /*
    Mehtod to transform binary tree into linked list, 
    following pre-order sequence
    */
    LinkedList<T> flatten(){
      LinkedList<T>  lista_ligada = LinkedList<T>();
      return flatten(root, lista_ligada); // a linked list 
    }
    /*
    Method for printing the tree horizontally, presentis the leaves
    and nodes. 
    */
    void tree_print(){
      tree_print(root);                     //O(1)
    }
    /*
    Method for checking whether the bst is full, meaning that each
    node has to leaves or non leaves.
    */
    bool is_full(){
      if(root == NULL) return true;
      return is_full(root);                 //O(1)
    }
    /*
    Method for couting how many leaves the bst Has. Meaning to check
    how many nodes in the bst have no other leave.
    */
    int leaf_count(){
      return leaf_count(root);            //O(1)
    }
    /*
    Method for checking whether the bst is perfect, meaning to check
    wether the bst is_full() and the depth of each leave is at the
    same level. Here we are considering the height the same as the
    depth.
    */
    bool is_perfect(){
      int h = height();     //O(1)
      return is_perfect(root, h);         //O(1)
    }
    /*
    Method for checking whether each father node has just one kid node.
    In casi it is a degenerative tree, it would be almost the same as
    linked list. 
    */
    bool is_degenerate(){
      return is_degenerate(root);         //O(1)
    }
    // SPECIAL METHODS JUST FOR THE CURRENT PROJECT (delete in case of using
    // This class any other time).
    /*
    method for getting the percentage of infected servers in bst
    */
    float infected_servers(){
      float total = infected_servers(root); //O(n)
      return (num_infected * 100) / total;  //O(log(n))
    }
    /*
    method for looking for some ip in each linked list in the binary tree
    */
    bool search_ip(string ip){
      return search_ip(root, ip);   //O(n)
    }
};
